all: network.o cryptochat.o main.o
	g++ -o cryptochat network.o criptochat.o main.o

network.o:
	g++ -o network.o -c engine/network.cpp

cryptochat.o:
	g++ -c cryptochat.cpp -o criptochat.o

main.o:
	g++ -c main.cpp -o main.o

clean:
	rm -rf *.o
