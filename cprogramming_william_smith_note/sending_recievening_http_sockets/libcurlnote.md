
// libcurl is a powerful and easy-to-use library for making HTTP requests in C.
// It supports a wide range of protocols, including HTTP, HTTPS, FTP, and more.
// Below is an example of how to use libcurl to send an HTTP GET request and
// receive the response. install libcurl using your package manager (e.g., `sudo
// apt-get install libcurl4-openssl-dev` on Debian-based systems).
//
// HTTP GET request example using libcurl:


### GET
```c
#include <curl/curl.h>
#include <stdio.h>

int main(void) {
  CURL *curl = curl_easy_init();
  if (curl) {
    CURLcode res;

    // Set the URL for the request
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8080/api/items");

    // Perform the request and check for errors
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));
    }

    // Clean up
    curl_easy_cleanup(curl);
  }
  return 0;
}
```


## POST
```c

#include <stdio.h>
#include <curl/curl.h>

int main() {
    CURL *curl = curl_easy_init();
    if(curl) {
    CURLcode res;
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8080/api/items");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"name\":\"NewItem\"}");
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
    fprintf(stderr, "curl_easy_perform() failed: %s\n",
    curl_easy_strerror(res));
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    }
    return 0;
    }
```


In the above examples, we initialize a CURL handle, set the URL for the request, and perform the request using `curl_easy_perform()`. For the POST request, we also set the appropriate headers and the JSON payload. Always remember to clean up resources after you're done to avoid memory leaks.

HTTP PUT Method (with JSON) Similar to the POST method, the PUT method can be implemented with a
JSON payload:
```c

#include <stdio.h>
#include <curl/curl.h>

int main() {
    CURL *curl = curl_easy_init();

    if(curl) {
    CURLcode res;
    struct curl_slist *headers = NULL;
    headers = curl_slist_append(headers, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8080/api/items/1");
    curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "PUT");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "{\"name\":\"UpdatedItem\"}");
    res = curl_easy_perform(curl);
    if(res != CURLE_OK)
    fprintf(stderr, "curl_easy_perform() failed: %s\n",
    curl_easy_strerror(res));
    curl_slist_free_all(headers);
    curl_easy_cleanup(curl);
    }
return 0;
}
```

HTTP DELETE Method The DELETE method can be used to remove a specified resource:
```c

#include <stdio.h>
#include <curl/curl.h>
int main() {
CURL *curl = curl_easy_init();
if(curl) {
CURLcode res;
curl_easy_setopt(curl, CURLOPT_URL, "http://localhost:8080/api/items/1");
curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
res
= curl_easy_perform(curl);
if(res != CURLE_OK)
fprintf(stderr, "curl_easy_perform() failed: %s\n",
curl_easy_strerror(res));
curl_easy_cleanup(curl);
}
return 0;
}
```


// gcc libcurl.c -o libcurl $(pkg-config --cflags --libs libcurl)
