
#include "DataReaderConnect.h"
#include <netinet/in.h>
#include "Command.h"
// Server side C/C++ program to demonstrate Socket programming]
#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>
#include <sys/socket.h>
#include <thread>
#include <pthread.h>
#include <sstream>
#include "Globals.h"

/**
 * connect to the server.
 * @param args args
 * @return void*
 */
void *DataReaderConnect::ConnectServer(void *args) {
    //get ip and port from parameters
    int port = ((ConnectServerParameters *) args)->port;
    string ip = ((ConnectServerParameters *) args)->ip;
    int sockfd, portno, n;
    struct sockaddr_in serv_addr;
    struct hostent *server;
    char buffer[1024];
    portno = port;
    // Create a socket point
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }
    server = gethostbyname(ip.c_str());

    if (server == NULL) {
        fprintf(stderr, "ERROR, no such host\n");
        exit(0);
    }

    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    bcopy((char *) server->h_addr, (char *) &serv_addr.sin_addr.s_addr, server->h_length);
    serv_addr.sin_port = htons(portno);

    // Now connect to the server
    if (connect(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR connecting");
        exit(1);
    }
    //send data to the simulator via the set command
    while (true) {
        bzero(buffer, 1024);
        //using an iterator to extract the values from the map and send to simulator
        map<string, double>::iterator it;
        for (it = ValuesOfPathMap.begin(); it != ValuesOfPathMap.end(); it++) {
            string path = it->first;
            double value = it->second;
            std::ostringstream osstream;
            osstream << value;
            string val = osstream.str();
            string setCommand = "set " + path + " " + val + "\r\n";
            strcpy(buffer,setCommand.c_str());
            //send set command to server
            n = write(sockfd, buffer, strlen(buffer));

            if (n < 0) {
                perror("ERROR writing to socket");
                exit(1);
            }

            // Now read server response
            bzero(buffer, 1024);
            n = read(sockfd, buffer, 1023);
            if (n < 0) {
                perror("ERROR reading from socket");
                exit(1);
            }
            printf("%s\n", buffer);
        }
    }
}
