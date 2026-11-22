/*
 * Chapter 15 - Mini HTTP Server
 * http_server.c - a minimal HTTP server that serves static files.
 *
 * Compile: gcc http_server.c -o http_server
 * Run:     ./http_server
 * Test:    curl http://localhost:8080/  (or open in a browser)
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define BUFFER_SIZE 4096
#define DOC_ROOT "."

void send_response(int client_socket, int status, const char* content_type,
                   const char* body, size_t body_len) {
    char header[256];
    int header_len = snprintf(header, sizeof(header),
        "HTTP/1.1 %d OK\r\n"
        "Content-Type: %s\r\n"
        "Content-Length: %zu\r\n"
        "Connection: close\r\n"
        "\r\n",
        status, content_type, body_len);

    write(client_socket, header, header_len);
    if (body && body_len > 0) {
        write(client_socket, body, body_len);
    }
}

void send_404(int client_socket) {
    const char* body = "<html><body><h1>404 Not Found</h1></body></html>";
    send_response(client_socket, 404, "text/html", body, strlen(body));
}

void serve_file(int client_socket, const char* path) {
    FILE* file = fopen(path, "rb");
    if (!file) {
        send_404(client_socket);
        return;
    }

    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* content = malloc(file_size + 1);
    if (!content) {
        fclose(file);
        send_404(client_socket);
        return;
    }

    size_t read_size = fread(content, 1, file_size, file);
    content[read_size] = '\0';
    fclose(file);

    const char* content_type = "text/plain";
    if (strstr(path, ".html")) content_type = "text/html";
    else if (strstr(path, ".css")) content_type = "text/css";
    else if (strstr(path, ".js")) content_type = "application/javascript";
    else if (strstr(path, ".png")) content_type = "image/png";
    else if (strstr(path, ".jpg") || strstr(path, ".jpeg"))
        content_type = "image/jpeg";

    send_response(client_socket, 200, content_type, content, read_size);
    free(content);
}

int main(void) {
    int server_socket, client_socket;
    struct sockaddr_in server_addr, client_addr;
    socklen_t client_len = sizeof(client_addr);
    char buffer[BUFFER_SIZE];

    server_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (server_socket < 0) {
        perror("Error creating socket");
        exit(EXIT_FAILURE);
    }

    int opt = 1;
    setsockopt(server_socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = INADDR_ANY;
    server_addr.sin_port = htons(PORT);

    if (bind(server_socket, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0) {
        perror("Error binding socket");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    if (listen(server_socket, 10) < 0) {
        perror("Error listening on socket");
        close(server_socket);
        exit(EXIT_FAILURE);
    }

    printf("Server is listening on port %d...\n", PORT);

    while (1) {
        client_socket = accept(server_socket, (struct sockaddr*)&client_addr, &client_len);
        if (client_socket < 0) {
            perror("Error accepting client connection");
            continue;
        }

        ssize_t n = read(client_socket, buffer, sizeof(buffer) - 1);
        if (n <= 0) {
            close(client_socket);
            continue;
        }
        buffer[n] = '\0';

        /* Parse request line: GET /path HTTP/1.1 */
        char method[16], path[256], protocol[16];
        if (sscanf(buffer, "%15s %255s %15s", method, path, protocol) != 3) {
            close(client_socket);
            continue;
        }

        printf("Request: %s %s\n", method, path);

        if (strcmp(method, "GET") != 0) {
            send_response(client_socket, 501, "text/plain",
                          "Not Implemented", 15);
            close(client_socket);
            continue;
        }

        /* Default to index.html */
        if (strcmp(path, "/") == 0) strcpy(path, "/index.html");

        char full_path[512];
        snprintf(full_path, sizeof(full_path), "%s%s", DOC_ROOT, path);

        serve_file(client_socket, full_path);
        close(client_socket);
    }

    close(server_socket);
    return 0;
}
