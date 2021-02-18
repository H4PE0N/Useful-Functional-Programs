
#ifndef CLIENT_SOCKET_PROGRAM_H
#define CLIENT_SOCKET_PROGRAM_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <limits.h>

typedef struct sockaddr_in serv_addr;
typedef struct sockaddr sock_addr;

serv_addr generate_server_address(int, char*);
int generate_server_socket(int, char*);
int communicate_with_server(int);

#endif
