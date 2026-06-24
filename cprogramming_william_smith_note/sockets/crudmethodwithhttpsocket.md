### SENDING HTTP (CRUD) METHODS WITH SOCKETS
HTTP is built on top of the TCP protocol. The client establishes a TCP connection with the server, then sends HTTP requests over that connection,
and the server sends HTTP responses back. In this chapter, we'll demonstrate how to create a simple HTTP client in pure C, using only
standard libraries, that can send GET, POST, PUT, and DELETE requests. HTTP GET Method
Let's start with the GET method. Here's a simple function that sends an HTTP GET request to a server and prints out the response:


### HTTP GET Method
Let's start with the GET method. Here's a simple function that sends an HTTP GET request to a server and prints out the response:
```c

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 4096

void http_get(int socket_fd, const char *path) {
char buffer[MAX_BUFFER_SIZE];
sprintf(buffer, "GET %s HTTP/1.1\r\nHost: localhost\r\n\r\n", path);
send(socket_fd, buffer, strlen(buffer), 0);

memset(buffer, 0, sizeof(buffer));
while (recv(socket_fd, buffer, sizeof(buffer), 0) > 0) {
fputs(buffer, stdout);
}
}
int main() {
int socket_fd = socket(AF_INET, SOCK_STREAM, 0);
struct sockaddr_in server_addr = {0};
server_addr.sin_family = AF_INET;
server_addr.sin_port = htons(8080);
inet_pton(AF_INET, "127.0.0.1", &(server_addr.sin_addr));
connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr));
http_get(socket_fd, "/index.html");
close(socket_fd);
return 0;
}

```
In this example, we establish a TCP connection to the server using `socket()`, `connect()`, then we send an HTTP GET request using `send()`
and receive the response using `recv()`.


HTTP POST Method
Here's an example that sends an HTTP POST request:
```c
void http_post(int socket_fd, const char *path, const char *body) {
char buffer[MAX_BUFFER_SIZE];
sprintf(buffer, "POST %s HTTP/1.1\r\nHost: localhost\r\nContent-Length: %zu\r\n\r\n%s",
path, strlen(body), body);
send(socket_fd, buffer, strlen(buffer), 0);
memset(buffer, 0, sizeof(buffer));
while (recv(socket_fd, buffer, sizeof(buffer), 0) > 0) {
fputs(buffer, stdout);
}
}
// In main function, replace http_get with the following:
http_post(socket_fd, "/api/items", "{\"name\":\"My Item\"}");
```


This function is similar to `http_get()`, but it also includes a message body in the request, and it includes a "Content-Length" header that specifies the
length of the body.
HTTP PUT Method The PUT method is very similar to the POST method. Here's an example:
```c
void http_put(int socket_fd, const char *path, const char *body) {
char buffer[MAX_BUFFER_SIZE];
sprintf(buffer, "PUT %s HTTP/1.1\r\nHost: localhost\r\nContent-Length: %zu\r\n\r\n%s",
path, strlen(body), body);
send(socket_fd, buffer, strlen(buffer), 0);
memset(buffer, 0, sizeof(buffer));
while (recv(socket_fd, buffer, sizeof(buffer), 0) > 0) {
fputs(buffer, stdout);
}
}
// In main function , replace http_post with the following:
http_put(socket_fd, "/api/items/1", "{\"name\":\"Updated Item\"}");
```

### HTTP DELETE Method Finally, the DELETE method:
```c
void http_delete(int socket_fd, const char *path) {
char buffer[MAX_BUFFER_SIZE];
sprintf(buffer, "DELETE %s HTTP/1.1\r\nHost: localhost\r\n\r\n", path);
send(socket_fd, buffer, strlen(buffer), 0);
memset(buffer, 0, sizeof(buffer));
while (recv(socket_fd, buffer, sizeof(buffer), 0) > 0) {
fputs(buffer, stdout);
}
}
// In main function, replace http_put with the following:
http_delete(socket_fd, "/api/items/1");
```


The DELETE method is similar to the GET method, but it uses the DELETE verb instead of GET. It does not include a message body.
Note: This is a very basic HTTP client. It doesn't handle HTTP redirects, it doesn't support HTTPS, and it doesn't do any error checking. Also, this
code assumes that the server will close the connection after sending the response, which is typical for simple HTTP/1.1 servers. In a real-world
application, you would want to use a full-featured HTTP library, such as libcurl, which can handle all these details for you.


Full code:
```c
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

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_BUFFER_SIZE 4096
#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080
#define HOST_HEADER "localhost"

/* Utility function to print server response */
void receive_response(int socket_fd) {
    char buffer[MAX_BUFFER_SIZE];
    ssize_t bytes_received;

    memset(buffer, 0, sizeof(buffer));

    while ((bytes_received = recv(socket_fd, buffer, sizeof(buffer) - 1, 0)) > 0) {
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

    if (connect(socket_fd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
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
```
