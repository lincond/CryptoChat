all: cryptochat.o main.o
	g++ -o cryptochat criptochat.o main.o

cryptochat.o:
	g++ -c cryptochat.cpp -o criptochat.o

main.o:
	g++ -c main.cpp -o main.o

clean:
	rm -rf *.o
