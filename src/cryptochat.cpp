//============================================================================
// Name        : CryptoChat.cpp
// Author      : Lincon Dias
// Version     : 0.0.1a
// Copyright   : MIT License
// Description : A instance of CryptoChat program
//============================================================================

#include "cryptochat.h"

CryptoChat::CryptoChat(void)
{
    std::cout << "CryptoChat v0.0.1a" << '\n';
    std::cout << "This software is under construction, may be unstable." << '\n';
    std::cout << "Read more at https://github.com/lincond/CryptoChat" << '\n';
}

int CryptoChat::run(void)
{
    Network* n = new Network;
    n->hostname = "";
    n->port = "";

    if ( n->resolveHostname() )
        std::cout << "Hostname resolved." << '\n';
    else
        std::cout << "Failed to resolve hostname" << '\n';

    return EXIT_SUCCESS;
}
