#include <netinet/in.h> // sockaddr_in structure
#include <stdio.h>      // printf()
#include <stdlib.h>     // exit()
#include <string.h>     // bzero(), strncmp()
#include <sys/socket.h> // socket(), bind(), listen(), accept()
#include <unistd.h>     // read(), write(), close()

#define MAX 80             // Maximum buffer size
#define PORT 8080          // Port number server listens on
#define SA struct sockaddr // Alias for struct sockaddr

// Function to handle communication with client
void func(int connfd) {
  char buff[MAX]; // Buffer to store messages
  int n;

  for (;;) { // Infinite loop (server keeps running)

    bzero(buff, MAX); // Clear buffer (set all bytes to 0)

    read(connfd, buff, sizeof(buff)); // Read message from client

    printf("From client: %s\t To client : ", buff);

    bzero(buff, MAX); // Clear buffer again for reply

    n = 0;

    // Read input from server keyboard until newline
    while ((buff[n++] = getchar()) != '\n')
      ;

    write(connfd, buff, sizeof(buff)); // Send reply to client

    // If server types "exit", stop communication
    if (strncmp("exit", buff, 4) == 0) {
      printf("Server Exit...\n");
      break;
    }
  }
}

int main() {

  int sockfd, connfd, len; // sockfd = server socket, connfd = client connection
  struct sockaddr_in servaddr, cli; // Server and client address structures

  // Create socket
  // AF_INET = IPv4
  // SOCK_STREAM = TCP (connection-oriented)
  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  if (sockfd == -1) { // If socket creation failed
    printf("Socket creation failed...\n");
    exit(0);
  } else {
    printf("Socket successfully created..\n");
  }

  bzero(&servaddr, sizeof(servaddr)); // Clear server address structure

  // Fill server information
  servaddr.sin_family = AF_INET; // IPv4
  servaddr.sin_addr.s_addr =
      htonl(INADDR_ANY);           // Accept connections from any IP
  servaddr.sin_port = htons(PORT); // Convert port to network byte order

  // Bind socket to IP and PORT
  if ((bind(sockfd, (SA *)&servaddr, sizeof(servaddr))) != 0) {
    printf("Socket bind failed...\n");
    exit(0);
  } else {
    printf("Socket successfully binded..\n");
  }

  // Put server in listening mode
  // 5 = maximum number of queued clients
  if ((listen(sockfd, 5)) != 0) {
    printf("Listen failed...\n");
    exit(0);
  } else {
    printf("Server listening..\n");
  }

  len = sizeof(cli); // Size of client address

  // Accept client connection
  connfd = accept(sockfd, (SA *)&cli, &len);

  if (connfd < 0) { // If accept fails
    printf("Server accept failed...\n");
    exit(0);
  } else {
    printf("Server accepted the client...\n");
  }

  func(connfd); // Start communication with client

  close(sockfd); // Close server socket

  return 0;
}
