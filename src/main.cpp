#include "cryptochat.h"

int main(int argc, char const *argv[])
{
    CryptoChat* cc = new CryptoChat;
    return cc->run();
}
