import socket

# Create a TCP/IP socket
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Connect the socket to the port where the server is listening
sock.connect(('localhost', 9090))

while True:
    data = sock.recv(1024 * 4)
    print(data)
