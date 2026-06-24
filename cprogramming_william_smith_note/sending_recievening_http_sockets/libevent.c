

#include <event2/buffer.h>
#include <event2/event.h>
#include <event2/http.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PORT 8080

void generic_handler(struct evhttp_request *req, void *arg) {
  struct evbuffer *response = evbuffer_new();
  if (!response) {
    evhttp_send_error(req, 500, "Internal Server Error");
    return;
  }

  enum evhttp_cmd_type method = evhttp_request_get_command(req);

  // Extract request URI
  const char *uri = evhttp_request_get_uri(req);
  printf("Request URI: %s\n", uri);

  // Handle POST and PUT body
  if (method == EVHTTP_REQ_POST || method == EVHTTP_REQ_PUT) {
    struct evbuffer *input_buffer = evhttp_request_get_input_buffer(req);
    size_t len = evbuffer_get_length(input_buffer);

    unsigned char *data = evbuffer_pullup(input_buffer, -1);
    if (data && len > 0) {
      printf("Body (%zu bytes): %.*s\n", len, (int)len, data);
    }
  }

  // Route based on method
  switch (method) {

  case EVHTTP_REQ_GET:
    printf("Received GET request\n");
    evbuffer_add_printf(response, "Hello, GET!");
    break;

  case EVHTTP_REQ_POST:
    printf("Received POST request\n");
    evbuffer_add_printf(response, "Hello, POST!");
    break;

  case EVHTTP_REQ_PUT:
    printf("Received PUT request\n");
    evbuffer_add_printf(response, "Hello, PUT!");
    break;

  case EVHTTP_REQ_DELETE:
    printf("Received DELETE request\n");
    evbuffer_add_printf(response, "Hello, DELETE!");
    break;

  default:
    printf("Unknown request type\n");
    evbuffer_add_printf(response, "Unsupported HTTP Method");
    evhttp_send_reply(req, HTTP_BADMETHOD, "Bad Method", response);
    evbuffer_free(response);
    return;
  }

  evhttp_send_reply(req, HTTP_OK, "OK", response);
  evbuffer_free(response);
}

int main() {
  struct event_base *base;
  struct evhttp *http;

  base = event_base_new();
  if (!base) {
    fprintf(stderr, "Could not initialize libevent!\n");
    return 1;
  }

  http = evhttp_new(base);
  if (!http) {
    fprintf(stderr, "Could not create evhttp.\n");
    return 1;
  }

  evhttp_set_gencb(http, generic_handler, NULL);

  if (evhttp_bind_socket(http, "0.0.0.0", PORT) != 0) {
    fprintf(stderr, "Could not bind to port %d\n", PORT);
    return 1;
  }

  printf("Libevent HTTP server running on port %d...\n", PORT);

  event_base_dispatch(base);

  evhttp_free(http);
  event_base_free(base);

  return 0;
}

// sudo apt update -o Acquire::ForceIPv4=true
// sudo apt install libevent-dev
