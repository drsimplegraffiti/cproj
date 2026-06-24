#include <curl/curl.h>
#include <curl/easy.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Struct to hold response data */
struct Memory {
  char *response;
  size_t size;
};

/* Callback to write data into a memory buffer */
size_t write_to_memory(void *buffer, size_t size, size_t nmemb, void *userp) {
  size_t total = size * nmemb;
  struct Memory *mem = (struct Memory *)userp;

  char *ptr = realloc(mem->response, mem->size + total + 1);
  if (!ptr) {
    fprintf(stderr, "realloc failed\n");
    return 0;
  }

  mem->response = ptr;
  memcpy(mem->response + mem->size, buffer, total);
  mem->size += total;
  mem->response[mem->size] = '\0'; // null terminate

  return total;
}

int main() {

  printf("http application\n");

  curl_global_init(CURL_GLOBAL_ALL);
  CURL *handle = curl_easy_init();

  if (!handle) {
    fprintf(stderr, "Failed to init curl\n");
    curl_global_cleanup();
    return 1;
  }

  struct Memory get_mem = {0};

  /* ---------------- GET request ---------------- */
  printf("\n=== GET Request ===\n");

  curl_easy_setopt(handle, CURLOPT_URL,
                   "https://jsonplaceholder.typicode.com/todos/1");
  curl_easy_setopt(handle, CURLOPT_HTTPGET, 1L);
  curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_to_memory);
  curl_easy_setopt(handle, CURLOPT_WRITEDATA, &get_mem);

  CURLcode response = curl_easy_perform(handle);

  long http_code = 0;
  curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &http_code);

  if (response == CURLE_OK && http_code >= 200 && http_code < 300) {
    printf("GET Success (HTTP %ld)\nResponse body:\n%s\n", http_code,
           get_mem.response);
  } else if (response == CURLE_OK) {
    printf("GET HTTP ERROR %ld\n", http_code);
  } else {
    printf("GET FAILED REQUEST : %s\n", curl_easy_strerror(response));
  }

  free(get_mem.response); // free GET response buffer

  /* ---------------- POST request ---------------- */
  printf("\n=== POST Request ===\n");

  struct Memory post_mem = {0};

  curl_easy_setopt(handle, CURLOPT_URL,
                   "https://jsonplaceholder.typicode.com/posts");

  curl_easy_setopt(handle, CURLOPT_POSTFIELDS,
                   "title=foo&body=bar&userId=1"); // automatically POST

  curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_to_memory);
  curl_easy_setopt(handle, CURLOPT_WRITEDATA, &post_mem);

  response = curl_easy_perform(handle);
  curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &http_code);

  if (response == CURLE_OK && http_code >= 200 && http_code < 300) {
    printf("POST Success (HTTP %ld)\nResponse body:\n%s\n", http_code,
           post_mem.response);
  } else if (response == CURLE_OK) {
    printf("POST HTTP ERROR %ld\n", http_code);
  } else {
    printf("POST FAILED REQUEST : %s\n", curl_easy_strerror(response));
  }

  free(post_mem.response);

  curl_easy_cleanup(handle);
  curl_global_cleanup();

  // return 0;
}
