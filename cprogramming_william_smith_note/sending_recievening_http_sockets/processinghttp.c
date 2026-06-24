//
// // PROCESSING HTTP CRUD METHODS WITH SOCKETS
// // CREATING THE SERVER
//
// #include <netinet/in.h>
// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <sys/socket.h>
// #include <unistd.h>
//
// #define MAX_BUFFER_SIZE 2048
// #define PORT 8080
//
// int main() {
//   int server_fd, client_fd;
//
//   struct sockaddr_in address;
//   int address_len = sizeof(address);
//   char buffer[MAX_BUFFER_SIZE] = {0};
//   // Create socket file descriptor
//   if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
//     perror("Socket creation failed");
//     exit(EXIT_FAILURE);
//   }
//   address.sin_family = AF_INET;
//   address.sin_addr.s_addr = INADDR_ANY;
//   address.sin_port = htons(PORT);
//   // Bind socket to port
//   if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
//     perror("Bind failed");
//     exit(EXIT_FAILURE);
//   }
//   // Start listening for client connections
//   if (listen(server_fd, 3) < 0) {
//     perror("Listen failed");
//     exit(EXIT_FAILURE);
//   }
//   while (1) {
//     printf("\n+++++++ Waiting for new connection ++++++++\n\n");
//
//     // Accept a client connection
//     if ((client_fd = accept(server_fd, (struct sockaddr *)&address,
//                             (socklen_t *)&address_len)) < 0) {
//       perror("Accept failed");
//       exit(EXIT_FAILURE);
//     }
//
//     // Read the client's request
//     read(client_fd, buffer, MAX_BUFFER_SIZE);
//     printf("%s\n", buffer);
//     // TODO: Handle the client's request and send back a response
//     close(client_fd);
//   }
//   return 0;
// }

// SIMPLE HTTP CRUD SERVER IN C (TCP SOCKETS)
// SERVER

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096
#define PORT 8080

void send_response(int client_fd, const char *status, const char *content_type,
                   const char *body) {
  char response[MAX_BUFFER_SIZE];

  if (body != NULL) {
    sprintf(response,
            "HTTP/1.1 %s\r\n"
            "Content-Type: %s\r\n"
            "Content-Length: %zu\r\n"
            "Connection: close\r\n"
            "\r\n"
            "%s",
            status, content_type, strlen(body), body);
  } else {
    sprintf(response,
            "HTTP/1.1 %s\r\n"
            "Content-Length: 0\r\n"
            "Connection: close\r\n"
            "\r\n",
            status);
  }

  send(client_fd, response, strlen(response), 0);
}

int main() {
  int server_fd, client_fd;
  struct sockaddr_in address;
  int address_len = sizeof(address);
  char buffer[MAX_BUFFER_SIZE];

  // Create socket
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  int opt = 1;
  setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons(PORT);

  // Bind
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    perror("Bind failed");
    exit(EXIT_FAILURE);
  }

  // Listen
  if (listen(server_fd, 10) < 0) {
    perror("Listen failed");
    exit(EXIT_FAILURE);
  }

  printf("HTTP Server running on port %d...\n", PORT);

  while (1) {
    printf("\nWaiting for connection...\n");

    if ((client_fd = accept(server_fd, (struct sockaddr *)&address,
                            (socklen_t *)&address_len)) < 0) {
      perror("Accept failed");
      continue;
    }

    memset(buffer, 0, MAX_BUFFER_SIZE);
    int bytes_read = recv(client_fd, buffer, MAX_BUFFER_SIZE - 1, 0);
    if (bytes_read <= 0) {
      close(client_fd);
      continue;
    }

    printf("Request:\n%s\n", buffer);

    // Parse request line
    char method[16], uri[256], version[16];
    sscanf(buffer, "%15s %255s %15s", method, uri, version);

    // Parse body if exists
    char body[MAX_BUFFER_SIZE] = {0};
    char *content_length_ptr = strstr(buffer, "Content-Length:");
    if (content_length_ptr != NULL) {
      int content_length = atoi(content_length_ptr + 15);

      char *body_ptr = strstr(buffer, "\r\n\r\n");
      if (body_ptr != NULL) {
        body_ptr += 4;

        int header_size = body_ptr - buffer;
        int already_read = bytes_read - header_size;

        strncpy(body, body_ptr, already_read);

        // Read remaining body if not fully received
        while (already_read < content_length) {
          int r = recv(client_fd, body + already_read,
                       content_length - already_read, 0);
          if (r <= 0)
            break;
          already_read += r;
        }

        printf("Body:\n%s\n", body);
      }
    }

    // Route handling
    if (strcmp(method, "GET") == 0) {

      if (strcmp(uri, "/") == 0) {
        send_response(client_fd, "200 OK", "text/plain", "Hello, GET!");
      } else {
        send_response(client_fd, "404 Not Found", "text/plain", "Not Found");
      }

    } else if (strcmp(method, "POST") == 0) {

      if (strcmp(uri, "/api/items") == 0) {
        send_response(client_fd, "200 OK", "text/plain", "Item created (POST)");
      } else {
        send_response(client_fd, "404 Not Found", "text/plain", "Not Found");
      }

    } else if (strcmp(method, "PUT") == 0) {

      if (strncmp(uri, "/api/items/", 11) == 0) {
        send_response(client_fd, "200 OK", "text/plain", "Item updated (PUT)");
      } else {
        send_response(client_fd, "404 Not Found", "text/plain", "Not Found");
      }

    } else if (strcmp(method, "DELETE") == 0) {

      if (strncmp(uri, "/api/items/", 11) == 0) {
        send_response(client_fd, "200 OK", "text/plain",
                      "Item deleted (DELETE)");
      } else {
        send_response(client_fd, "404 Not Found", "text/plain", "Not Found");
      }

    } else {
      send_response(client_fd, "400 Bad Request", "text/plain",
                    "Unsupported HTTP Method");
    }

    close(client_fd);
  }

  close(server_fd);
  return 0;
}
