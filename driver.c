/*
BSD 2-Clause License

Copyright (c) 2020, anatsuk1
All rights reserved.
*/
#include <stdio.h>
#include <string.h>
#include "http11_parser.h"

#define STRING_WITHOUT_NIL(name, http_header) char name[sizeof(http_header)-1] = {http_header}

STRING_WITHOUT_NIL(http_header, 
    "GET /hello.txt HTTP/1.1\x0d\x0a"
    "User-Agent: curl/7.16.3 libcurl/7.16.3 OpenSSL/0.9.7l zlib/1.2.3\x0d\x0a"
    "Host: www.example.com\x0d\x0a"
    "Accept-Language: en, mi\x0d\x0a"
    "\x0d\x0a"
//    "body\x00\xFF"
    "\0\0"
);

static void handler(const char *name, int name_length, const char *value, int value_length)
{
    printf("name  %4d: %s\n", name_length, name);
    printf("value %4d: %s\n", value_length, value);
}

int main(void)
{
    int text_size = sizeof(http_header);

    char verify[text_size];
    memcpy(verify, http_header, text_size);

    int result = parse_http11header(&http_header[0], text_size, handler);
    printf("result: %d\n", result);

    for(int i = 0; i < text_size; i++) {
        if (verify[i] != http_header[i]) {
            printf("unmatch index: %d\n", i);
        }
    }
    printf("cmp: %d\n", memcmp(verify, http_header, text_size));

    return 1;
}