#include <stdio.h>
#include <curl/curl.h>

size_t my_write_callback(char *ptr, size_t size, size_t nmemb, void *userdata);

int main() {
    CURL *curl = curl_easy_init();

    printf("curl=%p\n", curl);
    if (curl == NULL) {
        return 1;
    }

    CURLcode res;
    res = curl_easy_setopt(curl, CURLOPT_URL, "http://www.google.co.jp/");
    if (res != 0) {
        printf("curl_easy_setopt failed: res=%d\n", res);
        return 1;
    }
    res = curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, my_write_callback);

    res = curl_easy_perform(curl);
    printf("res=%d\n", res);

    curl_easy_cleanup(curl);
    return 0;
}

size_t my_write_callback(char *ptr, size_t size, size_t nmemb, void *userdata)
{
    if (size != 1) {
        printf("size=%ld\n", size);
        return 0;
    }
    size_t wrote_size = 0;
    while(nmemb > 0) {
        size_t n = nmemb;
        if (n > 80) n = 80;
        printf(">> ");
        fwrite(ptr, 1, n, stdout);
        printf("\n");
        ptr += n;
        nmemb -= n;
        wrote_size += n;
    }
    return wrote_size;
}