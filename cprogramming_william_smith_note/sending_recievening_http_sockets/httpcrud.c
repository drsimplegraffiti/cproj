
// CLIENT THAT SENDS HTTP (CRUD) METHODS USING TCP SOCKETS

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096

// SENDING HTTP (CRUD) METHODS WITH SOCKETS IN C

void http_delete(int socket_fd, const char *path) {
  char buffer[MAX_BUFFER_SIZE];
  sprintf(buffer, "DELETE %s HTTP/1.1\r\nHost: localhost\r\n\r\n", path);
  send(socket_fd, buffer, strlen(buffer), 0);

  memset(buffer, 0, sizeof(buffer));
  while (recv(socket_fd, buffer, sizeof(buffer), 0) > 0) {
    fputs(buffer, stdout);
  }
}

void http_put(int socket_fd, const char *path, const char *body) {
  char buffer[MAX_BUFFER_SIZE];
  sprintf(buffer,
          "PUT %s HTTP/1.1\r\nHost: localhost\r\nContent-Length: %zu\r\n\r\n%s",
          path, strlen(body), body);
  send(socket_fd, buffer, strlen(buffer), 0);

  memset(buffer, 0, sizeof(buffer));
  while (recv(socket_fd, buffer, sizeof(buffer), 0) > 0) {
    fputs(buffer, stdout);
  }
}

void http_post(int socket_fd, const char *path, const char *body) {
  char buffer[MAX_BUFFER_SIZE]; // Buffer to hold the HTTP request and response
                                //

  // Create the HTTP POST request with the provided path and body
  // strlen(body) is used to calculate the Content-Length header, which tells
  // the server how many bytes of data are being sent in the body of the
  // request. socket_fd: This is the file descriptor for the socket that has
  // been created and connected to the server. It is used to send the HTTP
  // request and receive the response.
  // memset(buffer, 0, sizeof(buffer)); is used to clear the buffer before
  // receiving the response from the server. This ensures that any previous data
  // in the buffer does not interfere with the new response being received.
  sprintf(
      buffer,
      "POST %s HTTP/1.1\r\nHost: localhost\r\nContent-Length: %zu\r\n\r\n%s",
      path, strlen(body), body);
  send(socket_fd, buffer, strlen(buffer),
       0); // this is the send() function that sends the HTTP request to the
           // server

  memset(buffer, 0,
         sizeof(buffer)); // Clear the buffer before receiving the response
  while (recv(socket_fd, buffer, sizeof(buffer), 0) >
         0) { // this is the recv() function that receives the HTTP response
              // from the server
    fputs(buffer, stdout);
  }
}

void http_get(int socket_fd, const char *path) {
  char buffer[MAX_BUFFER_SIZE];
  sprintf(buffer, "GET %s HTTP/1.1\r\nHost: localhost\r\n\r\n", path);
  send(socket_fd, buffer, strlen(buffer),
       0); // this is the send() function that sends the HTTP request to the
           // server

  memset(buffer, 0,
         sizeof(buffer)); // Clear the buffer before receiving the response
  while (recv(socket_fd, buffer, sizeof(buffer), 0) >
         0) { // this is the recv() function that receives the HTTP response
              // from the server
    fputs(buffer, stdout);
  }
}

int main() {

  struct sockaddr_in server_addr = {0};
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(8080);
  inet_pton(AF_INET, "127.0.0.1", &(server_addr.sin_addr));

  // GET
  int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  http_get(socket_fd, "/");
  close(socket_fd);

  // POST
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  http_post(socket_fd, "/api/items", "{\"name\":\"Item 1\"}");
  close(socket_fd);

  // PUT
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  http_put(socket_fd, "/api/items/1", "{\"name\":\"Updated Item 1\"}");
  close(socket_fd);

  // DELETE
  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
  http_delete(socket_fd, "/api/items/1");
  close(socket_fd);

  return 0;
}

// int main() {
//
//   // AF_INET is the address family for IPv4. SOCK_STREAM indicates that we
//   want
//   // a TCP socket. The protocol parameter is set to 0, which means that the
//   // system will choose the appropriate protocol (TCP in this case) based on
//   the
//   // socket type.
//   int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
//
//   struct sockaddr_in server_addr = {0};
//   server_addr.sin_family =
//       AF_INET; // Set the address family to AF_INET for IPv4
//   server_addr.sin_port = htons(8080); // Set the port number to 8080 (htons
//                                       // converts it to network byte order)
//
//   inet_pton(AF_INET, "127.0.0.1", &(server_addr.sin_addr));
//   connect(socket_fd, (struct sockaddr *)&server_addr,
//           sizeof(server_addr)); // Connect to the server
//
//   // GET
//   http_get(socket_fd,
//            "/index.html"); // Send an HTTP GET request for /index.html
//
//   // POST
//   http_post(socket_fd, "/api/items",
//             "{\"name\" : \"Item 1\"}"); // Send an HTTP POST request to
//                                         // /api/items with a JSON body
//
//   // PUT
//   http_put(socket_fd, "/api/items/1",
//            "{\"name\" : \"Updated Item 1\"}"); // Send an HTTP PUT request to
//                                                // /api/items/1 with a JSON
//                                                body
//
//   // DELETE
//   http_delete(socket_fd,
//               "/api/items/1"); // Send an HTTP DELETE request for
//               /api/items/1
//   close(socket_fd);            // Close the socket after the request is
//   complete return 0;
// }
