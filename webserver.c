// this project aim myself to create simple http server
// include headers in our c program
// source from the program: https://medium.com/@nipunweerasiri/a-simple-web-server-written-in-c-cf7445002e6
#include <stdio.h> // console input/output
#include <stdlib.h> // exit
#include <string.h> //string manipulation
#include <netdb.h> // getname info

#include <sys/socket.h> // socket APIs
#include <netinet/in.h> //sockaddr_in
#include <unistd.h> // open, close

#include <signal.h> // signal handling
#include <time.h> // time

// function type void
void sourceCode(){
    char url_link[] = "https://medium.com/@nipunweerasiri/a-simple-web-server-written-in-c-cf7445002e6";
    printf("The source of this program is: %s\n", url_link);
}

// socket creation
// create data structure in memory, to group several related variable into one place
struct sockaddr_in serverAddress;
// sin_family attribute used for socket address, indicate the IPv4 address family
serverAddress.sin_family = AF_INET;
serverAddress.sin_port = htons(PORT);
// set value to loopback device
serverAddress.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

// create the socket for application
// function to create endpoint abd returns its file descriptor
serverSocket = socket(AF_INET, SOCK_STREAM, 0);
// we use pointer here, this function force application reuse an address it will bound to
setsockopt(serverSocket, SOL_SOCKET, SO_REUSEADDR, &(int){1}, sizeof(int));

// we then bind the socket to the server address and listen for connection
// we use bind function and give the function argument, and do comparison
if(bind(serverSocket, (struct sockaddr *)&serverAddress, sizeof(serverAddress)) < 0){
    printf("Error: The server is not bound to the address!!\n");
    return 1;
}
// we use listen function, and do comparison
if (listen(serverSocket, BACKLOG) < 0  ) {
   printf("Error: The server is not listening.\n");
   return 1;
}
// we then get the server address information and print it out
// to the console if there is no error
// create array string
char hostBuffer[], serviceBuffer[NI_MAXSER];
// create int variable, and give argument to getnameinfo function
// the argument using pointer
int error = getnameinfo(struct sockaddr *)&serverAddress, sizeof(serverAddress), hostBuffer, sizeof(hostBuffer), 
                        serviceBuffer, sizeof(serviceBuffer), 0;
if (error != 0){
    printf("Error: %s\n", gai_sterror(error));
    return 1;
}
// print information to the console
printf("\nServer is listening on http://%s:%s\n\n", hostBuffer,serviceBuffer);