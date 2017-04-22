//============================================================================
// Name        : CryptoChat.cpp
// Author      : Lincon Dias
// Version     : 0.0.1a
// Copyright   : MIT License
// Description : Main file that create an instance of CryptoChat
//============================================================================

#include "cryptochat.h"

int main(int argc, char const *argv[])
{
    CryptoChat* cc = new CryptoChat;
    return cc->run();
}
