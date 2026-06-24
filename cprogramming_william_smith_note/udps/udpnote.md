UDP Server (udp_server.c)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

#define MAX_BUFFER 1024  // Maximum size of message buffer
#define PORT 8080        // Port number the server listens on

int main() {
    char buffer[MAX_BUFFER];         // Buffer to store received message
    char *message = "Hello Client";  // Message to send to client
    struct sockaddr_in serverAddr, clientAddr;
    
    // Create UDP socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Initialize server and client address structures to zero
    memset(&serverAddr, 0, sizeof(serverAddr));
    memset(&clientAddr, 0, sizeof(clientAddr));

    // Set server address family, IP, and port
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Bind to all local IP addresses
    serverAddr.sin_port = htons(PORT);       // Convert port to network byte order

    // Bind the socket to the IP and port
    if (bind(sockfd, (const struct sockaddr *)&serverAddr, sizeof(serverAddr)) < 0) {
        perror("Failed to bind");
        exit(EXIT_FAILURE);
    }

    int len, n;
    len = sizeof(clientAddr);

    // Wait to receive a message from client
    n = recvfrom(sockfd, (char *)buffer, MAX_BUFFER, MSG_WAITALL,
                 (struct sockaddr *)&clientAddr, &len);
    buffer[n] = '\0'; // Null-terminate the received string

    printf("Client : %s\n", buffer);

    // Send response back to client
    sendto(sockfd, (const char *)message, strlen(message), MSG_CONFIRM,
           (const struct sockaddr *)&clientAddr, len);
    printf("Hello message sent.\n");

    return 0;
}

/*
Notes:
- UDP is connectionless: server does not "connect" to client.
- Server must be running before client sends messages.
- INADDR_ANY allows binding to all local IPs.
- Useful for applications where speed is more important than reliability.
*/
```

UDP Client (udp_client.c)
```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netinet/in.h>

#define MAX_BUFFER 1024  // Maximum size of message buffer
#define PORT 8080        // Port number the server is listening on

int main() {
    char buffer[MAX_BUFFER];         // Buffer to store received message
    char *message = "Hello Server";  // Message to send to server
    struct sockaddr_in serverAddr;

    // Create UDP socket
    int sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (sockfd < 0) {
        perror("Failed to create socket");
        exit(EXIT_FAILURE);
    }

    // Initialize server address structure
    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);      // Convert port to network byte order
    serverAddr.sin_addr.s_addr = INADDR_ANY; // Use localhost / all interfaces for demo

    int n, len;

    // Send message to server
    sendto(sockfd, (const char *)message, strlen(message), MSG_CONFIRM,
           (const struct sockaddr *)&serverAddr, sizeof(serverAddr));
    printf("Hello message sent.\n");

    // Wait to receive response from server
    n = recvfrom(sockfd, (char *)buffer, MAX_BUFFER, MSG_WAITALL,
                 (struct sockaddr *)&serverAddr, &len);
    buffer[n] = '\0'; // Null-terminate the received string
    printf("Server : %s\n", buffer);

    // Close the socket
    shutdown(sockfd, SHUT_RDWR);

    return 0;
}

/*
Notes:
- Client sends a message and waits for a reply from the server.
- Must run server first; otherwise client will block/wait.
- UDP is fast but unreliable: packets may arrive out-of-order or be lost.
- Example is good for streaming scenarios or fast, simple communication.
- Compile with gcc: gcc udp_client.c -o client
- Run server and client in separate terminal windows.
*/
```



```bash
gcc udp_server.c -o server
gcc udp_client.c -o client

then in seperate terminal windows run:
./server
./client
```

