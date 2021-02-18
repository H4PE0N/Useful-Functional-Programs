
//DO THE COMPILOR KNOW ALL THESE FUNCTIONS INSIDE HERE?
#ifndef SERVER_SOCKET_PROGRAM_H
// ELSE THE COMPILOR WILL LOOK AT THE VARIUOS FUNCTIONS
#define SERVER_SOCKET_PROGRAM_H

// INCLUDES ALL PACKAGES AND LIBRARIES FOR THIS PROGRAM
// THIS LIBRARY CONTAINS THE BASIC FUNCTIONS LIKE PRINT
#include <stdio.h>
// THIS LIBRARY CONTAINS
#include <stdlib.h>
//THE LIBRARY CONTAINS FUNCTIONS THAT HELP WITH STRINGS
#include <string.h>
// THIS LIBRARY CONTAINS THE SIZE  OF  EVERY  DATA-TYPE
#include <limits.h>
// THIS LIBRARY CONTAINS THE FALSE AND THE TRUE OBJECTS
#include <stdbool.h>
//
#include <unistd.h>
//
#include <sys/socket.h>
//
#include <netinet/in.h>
//
#include <arpa/inet.h>

//
typedef struct sockaddr_in serv_addr;
//
typedef struct sockaddr sock_addr;

//
serv_addr generate_server_address(int, int, char*);
//
int generate_server_socket(int, int);
//
int communicate_with_socket(int);
//
int accept_connecting_client(int, serv_addr);
//
int bind_server_socket(int, serv_addr);
//
int start_server_listening(int, int);
//
int setup_server_socket(serv_addr, int, int, int);

#endif // NOW THE COMPILOR IS DONE LOOKING AT FUNCTIONS
