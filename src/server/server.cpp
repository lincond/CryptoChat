//============================================================================
// Name        : Server.cpp
// Author      : Lincon Dias
// Version     : 0.0.1a
// Copyright   : MIT License
// Description : An instance of a CryptoChat server
//============================================================================

#include "server.h"

Server::Server(const char* host, const char* port)
{
    this->host = (char*) malloc(strlen(host) + 1);
    this->port = atoi(port);

    if ( this->host == NULL || this->port <= 0 )
        exit(1);

    strcpy(this->host, host);

    std::cout << "CryptoChat  Server v0.0.1a" << '\n';
    std::cout << "This software is under construction, may be unstable." << '\n';
    std::cout << "Read more at https://github.com/lincond/CryptoChat" << '\n';
    std::cout << "\nTrying to start server at " << this->host << ':' << this->port << '\n';
}

int Server::run(void)
{
    socklen_t cli_len = 0;

    // Make the socket configurations
    if ( !this->ConfigSocket() )
        return 1;

    if ( !this->ConfigDatabase() )
        return 1;

    std::cout << "Server socket config done. Listening for connections." << '\n';

    while (true)
    {
        // Accept connections
        this->client = accept(this->server, (struct sockaddr*) &this->cli_addr, &cli_len);
        if ( this->client < 0 ) {
            std::cout << "Fail to accept connection from a client." << '\n';
            continue;
        }

        memset(this->buffer, '\0', sizeof buffer);
        // Read from client
        read(this->client, buffer, BUFLEN);
        std::cout << "Recived from client: " << buffer << '\n';

        shutdown(this->client, SHUT_WR);
    }

    return 0;
}


bool Server::ConfigSocket(void)
{
    // Create socket for server
    this->server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if ( this->server < 0 )
        return false;

    // Config the new socket
    bzero((char *) &this->srv_addr, sizeof(this->srv_addr));
    this->srv_addr.sin_family = AF_INET;
    this->srv_addr.sin_addr.s_addr = inet_addr (this->host);
    this->srv_addr.sin_port = htons(this->port);

    // Bind socket to ip addr
    if ( bind(this->server, (struct sockaddr*)&this->srv_addr, sizeof(this->srv_addr)) < 0 )
        return false;

    // Listen for connections
    if ( listen(this->server, LISTEN) < 0 )
        return false;

    return true;
}

bool Server::ConfigDatabase(void)
{
    std::cout << "Trying to start database..." << '\n';
    this->db = new Database;

    if ( !this->db->init )
        return false;

    return true;
}

Server::~Server(void)
{
    free(this->host);
    delete this->db;
    close(server);
}
