#ifndef __H__SERVER
#define __H__SERVER

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>

#define LISTEN 10
#define BUFLEN 512

class Server
{
    private:
        char* host;
        int port;
        char buffer[BUFLEN];

        // Socket vars
        int server, client;
        struct sockaddr_in srv_addr, cli_addr;

        // Private methods
        bool ConfigSocket(void);

    public:
        Server (const char* host, const char* port);
        int run(void);
        virtual ~Server ();
};

#endif
