#ifndef __H__NETWORK
#define __H__NETWORK

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <string.h>

class Network
{
    private:


        // Socket vars
        int tcpSocket;
        struct sockaddr *host;
        socklen_t hostlen;

        void socketConfig(struct addrinfo *rp);
    public:
        std::string hostname;
        std::string port;


        bool resolveHostname(void);
        bool Connect(void);
        bool Send(std::string msg);
        void Close(void);
        Network(void);
        virtual ~Network();
};

#endif
