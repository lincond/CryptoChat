#include "network.h"

Network::Network(void)
{
    this->hostname = "";
}

/**
 * Config the class socket from a resolved hostname
 */
void Network::socketConfig(struct addrinfo *rp)
{
    this->tcpSocket = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
    this->host = rp->ai_addr;
    this->hostlen = rp->ai_addrlen;
}

/**
 * Attemp to resolve a hostname for config the class socket
 */
bool Network::resolveHostname(void)
{
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int ret, test_socket;

    // Setup hints
    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;
    hints.ai_protocol = 0;

    // Try to resolve the name
    ret = getaddrinfo(this->hostname.c_str(), this->port.c_str(), &hints, &result);
    if ( ret != 0 )
        return false;

    // Finding the address that we can connect
    for(rp = result; rp != NULL; rp = rp->ai_next)
    {
        test_socket = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if ( test_socket < 0 )
            continue;
        if ( connect(test_socket, rp->ai_addr, rp->ai_addrlen) != -1 ) {
            std::cout << "Successfully connected to the hostname, setting up socket..." << '\n';
            close(test_socket);
            this->socketConfig(rp);
            break;  // Address founded!
        }
        close(test_socket);
    }

    // No address founded
    if ( rp == NULL )
        return false;

    freeaddrinfo(result);
    return true;
}

/**
 * Connect to hostname espcified on hostname var

bool Network::connect(void)
{

}*/

Network::~Network(void)
{
    close(this->tcpSocket);
}
