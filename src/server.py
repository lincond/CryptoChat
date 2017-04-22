import socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
sock.bind(("localhost", 8080))
sock.listen(2)
while 1:
	conn, addr = sock.accept()
	data= conn.recv(1024).decode("ascii")
	print(data) 
