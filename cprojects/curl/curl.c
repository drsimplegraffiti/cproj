
#include <curl/curl.h>
#include <curl/easy.h>
#include <stddef.h>
#include <stdio.h>

/* Callback to write data received from server */
size_t write_data(void *buffer, size_t size, size_t nmemb, void *userp) {
  size_t total = size * nmemb;
  fwrite(buffer, size, nmemb, stdout); // print to stdout
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

  /* ---------------- GET request ---------------- */
  printf("\n=== GET Request ===\n");

  curl_easy_setopt(handle, CURLOPT_URL,
                   "https://jsonplaceholder.typicode.com/todos/1");
  curl_easy_setopt(handle, CURLOPT_HTTPGET, 1L); // explicitly GET
  curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_data);

  CURLcode response = curl_easy_perform(handle);

  long http_code = 0;
  curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &http_code);

  if (response == CURLE_OK && http_code >= 200 && http_code < 300) {
    printf("\nGET Success (HTTP %ld)\n", http_code);
  } else if (response == CURLE_OK) {
    printf("\nGET HTTP ERROR %ld\n", http_code);
  } else {
    printf("\nGET FAILED REQUEST : %s\n", curl_easy_strerror(response));
  }

  /* ---------------- POST request ---------------- */
  printf("\n=== POST Request ===\n");

  curl_easy_setopt(handle, CURLOPT_URL,
                   "https://jsonplaceholder.typicode.com/posts");

  curl_easy_setopt(handle, CURLOPT_POSTFIELDS,
                   "title=foo&body=bar&userId=1"); // automatically POST

  curl_easy_setopt(handle, CURLOPT_WRITEFUNCTION, write_data);

  response = curl_easy_perform(handle);
  curl_easy_getinfo(handle, CURLINFO_RESPONSE_CODE, &http_code);

  if (response == CURLE_OK && http_code >= 200 && http_code < 300) {
    printf("\nPOST Success (HTTP %ld)\n", http_code);
  } else if (response == CURLE_OK) {
    printf("\nPOST HTTP ERROR %ld\n", http_code);
  } else {
    printf("\nPOST FAILED REQUEST : %s\n", curl_easy_strerror(response));
  }

  curl_easy_cleanup(handle);
  curl_global_cleanup();
}
