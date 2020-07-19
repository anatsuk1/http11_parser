# http11_parser

## Abstract

The parser library written on Lex and C.  
Applications get Filed Name and Value contained in HTTP/1.1 Header.

## How to use

Include the below header file.
```
#include http_parser.h
```
The APIs, function signatures and specifications as Doxygen's javadoc format, are written into the header.

## Evaluation

A simple application is ready to build and run.  
Type the build command.  
```
make -f Makefile.gmk all
```
Type the run command.
```
./http11_parser
```
The simple application prints the followings double.
```
name    10: User-Agent: curl/7.16.3 libcurl/7.16.3 OpenSSL/0.9.7l zlib/1.2.3
value   52: curl/7.16.3 libcurl/7.16.3 OpenSSL/0.9.7l zlib/1.2.3
name     4: Host: www.example.com
value   15: www.example.com
name    15: Accept-Language: en, mi
value    6: en, mi
result: 1
cmp: 0
```

## Environment  

The development environmant.

Needed for building the parser.
* gcc
* flex

For building the simple application.
* gmake
