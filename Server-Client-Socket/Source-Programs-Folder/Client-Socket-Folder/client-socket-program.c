
#include "client-socket-program.h"

int main(int arg_amount, char* arguments[])
{
  if(arg_amount < 3) return 0;

  int server_port = atoi(arguments[2]);
  char* string_address = arguments[1];

  int server_socket = generate_server_socket(server_port, string_address);

  while(communicate_with_server(server_socket));

  close(server_socket);

  return 0;
}

int communicate_with_server(int server_socket)
{
  char server_response[255];

  int output = recv(server_socket, &server_response, sizeof(server_response), 0);
  if(output>0) printf("SERVER: %s\n", server_response);

  return (output > 0);
}

int generate_server_socket(int server_port, char* string_address)
{
  // (sock = socket(AF_INET, SOCK_STREAM, 0)) < 0
  int server_socket = socket(AF_INET, SOCK_STREAM, 0);

  if(server_socket < 0)
  {
    printf("SOCKET ERROR\n");
    exit(0);
  }

  serv_addr server_address = generate_server_address(server_port, string_address);

  // connect(sock, (struct sockaddr *)&serv_addr, sizeof(serv_addr)) < 0)
  int connect_output = connect(server_socket, (sock_addr*) &server_address, sizeof(server_address));

  if(connect_output < 0)
  {
    printf("CONNECTION ERROR\n");
    exit(0);
  }

  return server_socket;
}

serv_addr generate_server_address(int server_port, char* string_address)
{
  serv_addr server_address;

  server_address.sin_family = AF_INET;

  server_address.sin_port = htons(server_port);

  // inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
  int inet_output = inet_pton(AF_INET, string_address, &server_address.sin_addr);

  if(inet_output <= 0)
  {
    printf("INET ERROR\n");
    exit(0);
  }

  return server_address;
}
