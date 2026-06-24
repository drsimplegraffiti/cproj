/*
SENDING HTTP (CRUD) METHODS WITH SOCKETS

HTTP is built on top of TCP. The client establishes a TCP connection
with the server, sends HTTP requests, and the server responds with
HTTP responses.

This example demonstrates a very simple HTTP client in pure C
that can send GET, POST, PUT, and DELETE requests.

NOTE:
- This is a basic educational example.
- No HTTPS support.
- No redirect handling.
- Minimal error checking.
- Assumes the server closes the connection after responding.
*/

#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX_BUFFER_SIZE 4096
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define HOST_HEADER "localhost"

/* Utility function to print server response */
void receive_response(int socket_fd) {
  char buffer[MAX_BUFFER_SIZE];
  ssize_t bytes_received;

  memset(buffer, 0, sizeof(buffer));

  while ((bytes_received = recv(socket_fd, buffer, sizeof(buffer) - 1, 0)) >
         0) {
    buffer[bytes_received] = '\0';
    fputs(buffer, stdout);
    memset(buffer, 0, sizeof(buffer));
  }
}

/* HTTP GET */
void http_get(int socket_fd, const char *path) {
  char buffer[MAX_BUFFER_SIZE];

  snprintf(buffer, sizeof(buffer),
           "GET %s HTTP/1.1\r\n"
           "Host: %s\r\n"
           "Connection: close\r\n"
           "\r\n",
           path, HOST_HEADER);

  send(socket_fd, buffer, strlen(buffer), 0);
  receive_response(socket_fd);
}

/* HTTP POST */
void http_post(int socket_fd, const char *path, const char *body) {
  char buffer[MAX_BUFFER_SIZE];

  snprintf(buffer, sizeof(buffer),
           "POST %s HTTP/1.1\r\n"
           "Host: %s\r\n"
           "Content-Type: application/json\r\n"
           "Content-Length: %zu\r\n"
           "Connection: close\r\n"
           "\r\n"
           "%s",
           path, HOST_HEADER, strlen(body), body);

  send(socket_fd, buffer, strlen(buffer), 0);
  receive_response(socket_fd);
}

/* HTTP PUT */
void http_put(int socket_fd, const char *path, const char *body) {
  char buffer[MAX_BUFFER_SIZE];

  snprintf(buffer, sizeof(buffer),
           "PUT %s HTTP/1.1\r\n"
           "Host: %s\r\n"
           "Content-Type: application/json\r\n"
           "Content-Length: %zu\r\n"
           "Connection: close\r\n"
           "\r\n"
           "%s",
           path, HOST_HEADER, strlen(body), body);

  send(socket_fd, buffer, strlen(buffer), 0);
  receive_response(socket_fd);
}

/* HTTP DELETE */
void http_delete(int socket_fd, const char *path) {
  char buffer[MAX_BUFFER_SIZE];

  snprintf(buffer, sizeof(buffer),
           "DELETE %s HTTP/1.1\r\n"
           "Host: %s\r\n"
           "Connection: close\r\n"
           "\r\n",
           path, HOST_HEADER);

  send(socket_fd, buffer, strlen(buffer), 0);
  receive_response(socket_fd);
}

/* Create and connect TCP socket */
int create_connection() {
  int socket_fd;
  struct sockaddr_in server_addr;

  socket_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (socket_fd < 0) {
    perror("Socket creation failed");
    exit(EXIT_FAILURE);
  }

  memset(&server_addr, 0, sizeof(server_addr));
  server_addr.sin_family = AF_INET;
  server_addr.sin_port = htons(SERVER_PORT);

  if (inet_pton(AF_INET, SERVER_IP, &server_addr.sin_addr) <= 0) {
    perror("Invalid address");
    exit(EXIT_FAILURE);
  }

  if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) <
      0) {
    perror("Connection failed");
    exit(EXIT_FAILURE);
  }

  return socket_fd;
}

int main() {
  int socket_fd;

  /* Example usage: Uncomment one at a time */

  // GET
  socket_fd = create_connection();
  http_get(socket_fd, "/index.html");
  close(socket_fd);

  // POST
  socket_fd = create_connection();
  http_post(socket_fd, "/api/items", "{\"name\":\"My Item\"}");
  close(socket_fd);

  // PUT
  socket_fd = create_connection();
  http_put(socket_fd, "/api/items/1", "{\"name\":\"Updated Item\"}");
  close(socket_fd);

  // DELETE
  socket_fd = create_connection();
  http_delete(socket_fd, "/api/items/1");
  close(socket_fd);

  return 0;
}

/*
Compile:
gcc http_client.c -o client

Run:
./client

IMPORTANT NOTES:
- This does NOT support HTTPS (TLS).
- No redirect handling.
- No advanced HTTP parsing.
- For production use, use a library like libcurl.
- Designed for learning how HTTP works over raw TCP sockets.
*/
