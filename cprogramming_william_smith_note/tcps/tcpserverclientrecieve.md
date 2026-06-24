Here are your clean, corrected, production-ready versions —
one single c block for TCP Server, and one single c block for TCP Client,
using send() and recv() properly with handling for large messages.

### ✅ TCP SERVER (send/recv with large message handling)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int server_fd, new_socket;
    struct sockaddr_in address;
    int addrlen = sizeof(address);
    char buffer[BUFFER_SIZE];

    // Create TCP socket
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }

    // Allow reuse of address/port
    int opt = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    // Configure server address
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);

    // Bind socket to port
    if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    // Start listening
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", PORT);

    // Accept client
    if ((new_socket = accept(server_fd, (struct sockaddr *)&address,
                             (socklen_t*)&addrlen)) < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }

    // ---- RECEIVE large message safely ----
    int bytes_received;
    while ((bytes_received = recv(new_socket, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';  // Null terminate
        printf("Received: %s\n", buffer);
    }

    if (bytes_received < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    // ---- SEND large message safely ----
    char *large_message =
        "This is a large message sent from server to client. "
        "It may be bigger than the buffer size.";

    int total_sent = 0;
    int length = strlen(large_message);

    while (total_sent < length) {
        int sent = send(new_socket,
                        large_message + total_sent,
                        length - total_sent,
                        0);
        if (sent < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }
        total_sent += sent;  // Keep sending until complete
    }

    printf("Large message sent successfully.\n");

    close(new_socket);
    close(server_fd);
    return 0;
}
```

### ✅ TCP CLIENT (send/recv with large message handling)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 1024

int main() {
    int sock;
    struct sockaddr_in serv_addr;
    char buffer[BUFFER_SIZE];

    // Create TCP socket
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IP address
    if (inet_pton(AF_INET, "127.0.0.1",
                  &serv_addr.sin_addr) <= 0) {
        perror("Invalid address");
        return -1;
    }

    // Connect to server
    if (connect(sock, (struct sockaddr *)&serv_addr,
                sizeof(serv_addr)) < 0) {
        perror("Connection Failed");
        return -1;
    }

    // ---- SEND large message safely ----
    char *large_message =
        "This is a large message sent from client to server. "
        "It may exceed buffer size.";

    int total_sent = 0;
    int length = strlen(large_message);

    while (total_sent < length) {
        int sent = send(sock,
                        large_message + total_sent,
                        length - total_sent,
                        0);
        if (sent < 0) {
            perror("send");
            exit(EXIT_FAILURE);
        }
        total_sent += sent;
    }

    printf("Large message sent successfully.\n");

    // ---- RECEIVE large message safely ----
    int bytes_received;
    while ((bytes_received = recv(sock, buffer, BUFFER_SIZE, 0)) > 0) {
        buffer[bytes_received] = '\0';
        printf("Received: %s\n", buffer);
    }

    if (bytes_received < 0) {
        perror("recv");
        exit(EXIT_FAILURE);
    }

    close(sock);
    return 0;
}
```
🔎 TLDR — Important Notes (Concise but Complete)
Why use send() and recv() instead of write() / read()?
send() and recv() are socket-specific
They support a flags parameter
Better control for networking



| Feature                | write()             | send()         |
| ---------------------- | ------------------- | -------------- |
| Works on               | Any file descriptor | Sockets only   |
| Flags parameter        | ❌ No                | ✅ Yes          |
| SIGPIPE control        | ❌ No                | ✅ MSG_NOSIGNAL |
| Advanced routing flags | ❌ No                | ✅ Yes          |



⚠️ Critical Networking Rule
send() and recv() DO NOT guarantee:
Sending all bytes at once
Receiving full message at once
That’s why we use:
```bash
while (total_sent < length)
```
and

```c
while (recv(...) > 0)
```
This ensures:
Large messages are fully transmitted
Partial sends are handled correctly

⚠️ When connection closes:
recv() returns 0 → peer closed connection
send() may return -1
Always check return values
