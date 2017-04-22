all: server.o main.o
	g++ -o server server.o main.o

server.o:
	g++ -o server.o -c server.cpp

main.o:
	g++ -o main.o -c main.cpp

clean:
	rm -rf *.o
