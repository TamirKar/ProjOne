#include "DataReaderServer.h"
#include <netinet/in.h>
#include "Command.h"
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
#include <iostream>
#include "Globals.h"
using namespace std;

/**
 * Create Server.
 * @param args args
 * @return void *
 */
void *DataReaderServer::CreateServer(void *args) {
    int port = ((OpenServerParameters *) args)->port;
    int speed = ((OpenServerParameters *) args)->speed;
    int sockfd, newsockfd, portno, clilen;
    char buffer[1024];
    struct sockaddr_in serv_addr, cli_addr;
    int n;
    int option = 1;

    // First call to socket() function
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(sockfd, SOL_SOCKET, SO_REUSEADDR, &option, sizeof(option));
    if (sockfd < 0) {
        perror("ERROR opening socket");
        exit(1);
    }

    // Initialize socket structure
    bzero((char *) &serv_addr, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("ERROR on binding");
        exit(1);
    }

    // Now start listening for the clients, here process will
    // go in sleep mode and will wait for the incoming connection
    listen(sockfd, speed);
    clilen = sizeof(cli_addr);

    /* Accept actual connection from the client */
    newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
    //send data from the simulator to update our map's values
    while (true) {
        if (newsockfd < 0) {
            perror("ERROR on accept");
            exit(1);
        }

        //If connection is established then start communicating
        bzero(buffer, 1024);
        n = read(newsockfd, buffer, 1023);
        if (n < 0) {
            perror("ERROR reading from socket");
            exit(1);
        }
        if (n < 0) {
            perror("ERROR writing to socket");
            exit(1);
        };

        //maps are updated by the data sent from the buffer
        UpdatePathValuesFromServer(buffer);
        std::this_thread::sleep_for(0.2s);
    }
}

