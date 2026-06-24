#include <arpa/inet.h>  // inet_addr()
#include <netdb.h>      // Network database operations
#include <stdio.h>      // printf()
#include <stdlib.h>     // exit()
#include <string.h>     // strncmp()
#include <strings.h>    // bzero()
#include <sys/socket.h> // socket(), connect()
#include <unistd.h>     // read(), write(), close()

#define MAX 80    // Maximum buffer size
#define PORT 8080 // Port number to connect to
#define SA struct sockaddr

// Function to handle communication with server
void func(int sockfd) {

  char buff[MAX]; // Buffer to store messages
  int n;

  for (;;) { // Infinite loop (client keeps running)

    bzero(buff, sizeof(buff)); // Clear buffer before taking input

    printf("Enter the string : ");

    n = 0;

    // Read input from keyboard until newline
    while ((buff[n++] = getchar()) != '\n')
      ;

    // Send message to server
    write(sockfd, buff, sizeof(buff));

    bzero(buff, sizeof(buff)); // Clear buffer before receiving reply

    // Read response from server
    read(sockfd, buff, sizeof(buff));

    printf("From Server : %s", buff);

    // If server sends "exit", stop client
    if ((strncmp(buff, "exit", 4)) == 0) {
      printf("Client Exit...\n");
      break;
    }
  }
}

int main() {

  int sockfd;                  // Client socket file descriptor
  struct sockaddr_in servaddr; // Server address structure

  // Create TCP socket
  // AF_INET = IPv4
  // SOCK_STREAM = TCP
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd == -1) {
    printf("Socket creation failed...\n");
    exit(0);
  } else {
    printf("Socket successfully created..\n");
  }

  bzero(&servaddr, sizeof(servaddr)); // Clear server address structure

  servaddr.sin_family = AF_INET; // IPv4
  servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");
  // Server IP address (localhost)

  servaddr.sin_port = htons(PORT); // Convert port to network byte order

  // Connect to server
  if (connect(sockfd, (SA *)&servaddr, sizeof(servaddr)) != 0) {
    printf("Connection with the server failed...\n");
    exit(0);
  } else {
    printf("Connected to the server..\n");
  }

  func(sockfd); // Start communication with server

  close(sockfd); // Close client socket

  return 0;
}
