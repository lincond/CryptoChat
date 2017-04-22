#include "server.h"

int main(int argc, char const *argv[])
{
    if ( argc < 3 ){
        std::cout << "usage: " << argv[0] << " ip port" << '\n';
        return 1;
    }

    Server* s = new Server(argv[1], argv[2]);
    s->run();
    return 0;
}
