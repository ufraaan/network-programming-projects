all: time_client time_server

time_client: time_client.c
	gcc -o time_client time_client.c

time_server: time_server.c
	gcc -o time_server time_server.c

clean:
	rm -f time_client time_server
