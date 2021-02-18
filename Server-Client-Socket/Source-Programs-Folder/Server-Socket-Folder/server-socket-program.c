
// INCLUDING THE HEADER FILE  FOR  THIS  EXACT  PROGRAM
#include "server-socket-program.h"

// DEFINING SOME VARIABLES THAT ARE NICE TO HAVE  ALONE
#define SOCK_DOMAIN AF_INET //THIS IS THE SOCKET DOMAIN
#define SOCK_TYPE SOCK_STREAM //THIS IS THE SOCKET PORT

int main(int arg_amount, char* arguments[])
{
  if(arg_amount <= 2) return false; // TOO LITTLE  INFO
  //THIS IS THE PORT THAT THE TCP CONNECTION IS THROUGH
  int server_port = atoi(arguments[2]);
  //THIS IS THE IP ADDRESS OF THE COMPUTER (THE SERVER)
  char* string_address = arguments[1];
  // GENERATING THE FULL ADDRESS PROTOCOL WITH THE INFO
  serv_addr address = generate_server_address
    (SOCK_DOMAIN, server_port, string_address);
  //SETTING UP THE SERVER SOCKET AND STARTING THE THING
  int server_socket = setup_server_socket(address, 1,
    SOCK_DOMAIN, SOCK_TYPE);
  // ACCEPTING THE CONNECTING CLIENT AND STORING IN VAR
  int client_socket = accept_connecting_client
    (server_socket, address);
  // COMMUNICATING WHILE CONNECTION IS GOING ON OR QUIT
  while(communicate_with_socket(client_socket)== true);
  // CLOSING THE  SERVER-  AND  THE  SOCKET-CONNECTIONS
  close(server_socket); close(client_socket);
  return false;// THE FUNCTION RETURNS FALSE AT THE END
}

// THIS FUNCTION LETS THE USER COMMUNICATE WITH  CLIENT
int communicate_with_socket(int client_socket)
{
  //CREATING MESSAGE VARIABLE AND PROMT USER WITH INPUT
  char message[255]; printf("[INPUT MESSAGE]: ");
   scanf("%[^\n]%*c", message); // TAKE INPUT FROM USER
  // RETURN FALSE IF THE INPUT IS "QUIT" OR DONT  EXIST
  if(!strcmp(message, "QUIT") || strlen(message) == 0)
    return false;//THE PROGRAM WILL END WITHOUT SENDING
  //SENDS INPUT MESSAGE TO CLIENT, RETURN  SEND  RESULT
  int send_output = send(client_socket, message,
    sizeof(message), 0); return (send_output >= 0);
}

//THIS FUNCTION ACCEPTS CONNECTING CLIENT AND STORES IT
int accept_connecting_client(int server_socket,
  serv_addr address)
{
  // ACCEPTING CLIENT AND STORES IT TO LATER RETURN  IT
  int address_size = sizeof(address);// SIZE OF ADDRESS
  int client_socket = accept(server_socket,(sock_addr*)
    &address, &address_size);
  //IF THE ACCEPTING WHEN WELL, THE CLIENT GET RETURNED
  if(client_socket >= 0) return client_socket;
  // IF NOT, AN ERROR WILL BE PRINTED AND PROGRAM QUITS
  printf("[ERROR]: CLIENT CONNECTION\n"); exit(false);
}

// THIS FUNCTION CREATES AND MODIFY A SOCKET FOR SERVER
int setup_server_socket(serv_addr address, int backlog,
  int sock_domain, int sock_type)
{
  //CREATING THE SERVER SOCKET OUT OF A DOMAIN AND TYPE
  int server_socket=generate_server_socket(sock_domain,
    sock_type);
  // BINDING THE SERVER SOCKET WITH AN  ADDRESS  (IPV4)
  int bind_output = bind_server_socket(server_socket,
    address);
  // LISTENING FOR CONNECTING CLIENTS WITH  THE  SERVER
  int list_output=start_server_listening(server_socket,
    backlog);
  return server_socket; //RETURNING THE MODIFIED SERVER
}

// START THE SERVER LISTENING  FOR  CONNECTING  CLIENTS
int start_server_listening(int server_socket,
  int backlog)
{
  // START LISTENING AND  TAKE  OUTPUT  OF  THE  ACTION
  int listen_output = listen(server_socket, backlog);
  //CHECK IF THE LISTENING WENT WELL, THEN RETURN VALUE
  if(listen_output >= 0) return listen_output;
  // PRINTING THE ERROR THAT OCCURS AND EXITING PROGRAM
  printf("[ERROR]: SERVER LISTENING\n"); exit(false);
}

//GENERATES THE SERVER SOCKET WITH SOCK-DOMAIN AND TYPE
int generate_server_socket(int sock_domain,
  int sock_type)
{
  // CREATING THE SERVER SOCKET VARIABLE, STORE  RESULT
  int server_socket = socket(sock_domain,sock_type, 0);
  //CHECK IF THE OPERATION WENT WELL, THEN RETURN VLAUE
  if(server_socket >= 0) return server_socket;
  // PRINTING THE ERROR THAT OCCURS AND EXITING PROGRAM
  printf("[ERROR]: GENERATING SOCKET\n"); exit(false);
}

// THIS SERVER BINDS THE SERVER SOCKET WITH AN  ADDRESS
int bind_server_socket(int socket, serv_addr address)
{
  // BINDING THE SERVER SOCKET AND  STORES  THE  RESULT
  int bind_output = bind(socket, (sock_addr*) &address,
    sizeof(address));
  // CHECK IF THE BINDING WENT WELL, THEN RETURN  VALUE
  if(bind_output >= 0) return bind_output;
  // PRINTING THE ERROR THAT OCCURS AND EXITING PROGRAM
  printf("[ERROR]: BIND SERVER SOCKET\n"); exit(false);
}

// THIS FUNCTION GENERATES AN ADDRESS WITH SOME  VALUES
serv_addr generate_server_address(int sock_domain,
  int sock_port, char* string_address)
{
  serv_addr server_address; //CREATING ADDRESS VARIABLE
  // SETTING THE DOMAIN OF THE ADDRESS  TO  THE  DOMAIN
  server_address.sin_family = sock_domain;
  // SETTING THE  PORT  OF  THE  ADDRESS  TO  THE  PORT
  server_address.sin_port = htons(sock_port);
  // CONVERTING THE STRING ADDRESS AND STORE IT IN  VAR
  int inet_output=inet_pton(sock_domain,string_address,
    &server_address.sin_addr);
  // CHECK IF THE OPERATION WENT WELL, THE RETURN VALUE
  if(inet_output >= 1) return server_address;
  // PRINTING THE ERROR THAT OCCURS AND EXITING PROGRAM
  printf("[ERROR]: CREATING ADDRESS\n"); exit(false);
}
