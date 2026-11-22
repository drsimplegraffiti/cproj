/*
 * Chapter 16 - Weather Dashboard with API Integration
 * weather_dashboard.c - fetches live weather data from OpenWeatherMap API
 * using libcurl and parses JSON using cJSON.
 *
 * NOTE: Requires libcurl and cJSON development libraries.
 *
 * Compile: gcc weather_dashboard.c -o weather_dashboard -lcurl -lcjson
 * Run:     ./weather_dashboard
 *          (Edit API_URL and API_KEY below before running.)
 */

#include <stdio.h>
#include <string.h>
#include <curl/curl.h>
#include <cjson/cJSON.h>

#define API_URL "http://api.openweathermap.org/data/2.5/weather?q=London&units=metric"
#define API_KEY "your_api_key"  /* Replace with your OpenWeatherMap API key */

static char response_buffer[16384];

/* libcurl write callback: appends received data to response_buffer */
static size_t write_callback(void* ptr, size_t size, size_t nmemb, void* userp) {
    size_t total = size * nmemb;
    size_t used = strlen((char*)userp);
    if (used + total < sizeof(response_buffer) - 1) {
        memcpy((char*)userp + used, ptr, total);
        ((char*)userp)[used + total] = '\0';
    }
    return total;
}

static int fetch_weather(const char* city) {
    CURL* curl;
    CURLcode res;

    /* Build URL with city and API key */
    char url[512];
    snprintf(url, sizeof(url), "%s&appid=%s&q=%s", API_URL, API_KEY, city);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (!curl) {
        fprintf(stderr, "Failed to initialize libcurl\n");
        curl_global_cleanup();
        return -1;
    }

    response_buffer[0] = '\0';

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, response_buffer);
    curl_easy_setopt(curl, CURLOPT_TIMEOUT, 10L);

    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "curl_easy_perform() failed: %s\n",
                curl_easy_strerror(res));
        curl_easy_cleanup(curl);
        curl_global_cleanup();
        return -1;
    }

    curl_easy_cleanup(curl);
    curl_global_cleanup();
    return 0;
}

static void parse_weather_data(const char* json_data) {
    cJSON* json = cJSON_Parse(json_data);
    if (!json) {
        printf("Error parsing JSON data\n");
        return;
    }

    cJSON* main = cJSON_GetObjectItem(json, "main");
    cJSON* temp = main ? cJSON_GetObjectItem(main, "temp") : NULL;
    cJSON* humidity = main ? cJSON_GetObjectItem(main, "humidity") : NULL;

    cJSON* weather_array = cJSON_GetObjectItem(json, "weather");
    cJSON* description = NULL;
    if (weather_array) {
        cJSON* weather_item = cJSON_GetArrayItem(weather_array, 0);
        if (weather_item)
            description = cJSON_GetObjectItem(weather_item, "description");
    }

    printf("\n=== Weather Dashboard ===\n");
    if (temp) printf("Temperature: %.2f°C\n", temp->valuedouble);
    if (humidity) printf("Humidity: %.2f%%\n", humidity->valuedouble);
    if (description) printf("Description: %s\n", description->valuestring);
    printf("=========================\n\n");

    cJSON_Delete(json);
}

int main(void) {
    char city[100];

    printf("=== Command-Line Weather Dashboard ===\n");
    printf("NOTE: Set a valid OpenWeatherMap API key in the source.\n\n");
    printf("Enter city name: ");
    if (!fgets(city, sizeof(city), stdin)) return 1;
    city[strcspn(city, "\n")] = '\0';

    if (fetch_weather(city) != 0) {
        printf("Failed to fetch weather data.\n");
        return 1;
    }

    parse_weather_data(response_buffer);

    return 0;
}
