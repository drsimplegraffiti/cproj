#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER 1024 // Maximum size of message buffer
#define PORT 8080       // Port number the server is listening on

int main() {
  char buffer[MAX_BUFFER];        // Buffer to store received message
  char *message = "Hello Server"; // Message to send to server
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
  serverAddr.sin_port = htons(PORT); // Convert port to network byte order
  serverAddr.sin_addr.s_addr =
      INADDR_ANY; // Use localhost / all interfaces for demo

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
