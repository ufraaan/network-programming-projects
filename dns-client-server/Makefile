all: dns_client dns_server

dns_client: dns_client.c
	gcc -o dns_client dns_client.c

dns_server: dns_server.c
	gcc -o dns_server dns_server.c

clean:
	rm -f dns_client dns_server
