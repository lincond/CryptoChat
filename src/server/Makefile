# Dependecies
# sudo apt-get install libmysqlclient-dev
# sudo apt-get install libmysqlcppconn-dev


all: user.o database.o server.o main.o
	g++ -I/usr/include/cppconn -L/usr/lib -lmysqlcppconn -o server user.o database.o server.o main.o

user.o:
	g++ -c base/user.cpp -o user.o

database.o:
	g++ -I/usr/include/cppconn -L/usr/lib -lmysqlcppconn -c database.cpp -o database.o

server.o:
	g++ -o server.o -c server.cpp

main.o:
	g++ -o main.o -c main.cpp

clean:
	rm -rf *.o
