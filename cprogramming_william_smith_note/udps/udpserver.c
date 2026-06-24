#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024 // Maximum size of message buffer
#define PORT 8080       // Port number the server listens on

int main() {
  char buffer[MAX_BUFFER];        // Buffer to store received message
  char *message = "Hello Client"; // Message to send to client
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
  if (bind(sockfd, (const struct sockaddr *)&serverAddr, sizeof(serverAddr)) <
      0) {
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
