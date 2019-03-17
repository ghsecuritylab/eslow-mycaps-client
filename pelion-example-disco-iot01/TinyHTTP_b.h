/*
 * mbed Tiny HTTP Client for Ethernet Interface Library
 * Copyright (c) 2012 Hiroshi Suga
 * Released under the MIT License: http://mbed.org/license/mit
 */
 
/** @file
 * @brief Tiny HTTP Client
 */
 
#ifndef TinyHTTP_h
#define TinyHTTP_h
 
#include "mbed.h"
#include "NetworkStack.h"
#define METHOD_GET 0
#define METHOD_POST 1
 
typedef void (*onHttpReceiveFunc)(char *buf, int len);
 
/** send http request
 * @param method METHOD_GET or METHOD_POST
 * @param host http server
 * @param uri URI
 * @param head http header (CR+LF) (or NULL)
 * @param body POST body (or NULL)
 * @return http code, -1:failue
 */
int httpRequest (NetworkInterface *net, int method, char *host, int port, char *uri, char *head, char *body);
 
void createauth (char *user, char *pwd, char *buf, int len);
 
int base64enc(const char *input, unsigned int length, char *output, int len);
 
int urlencode(char *str, char *buf, int len);
 
#endif