all: add_client add_server

add.h add_clnt.c add_svc.c add_xdr.c: add.x
	rpcgen add.x

add_server: add_server.c add_svc.c add_xdr.c
	gcc -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -o add_server add_server.c add_svc.c add_xdr.c

add_client: add_client.c add_clnt.c add_xdr.c
	gcc -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -o add_client add_client.c add_clnt.c add_xdr.c

clean:
	rm -f add_client add_server add.h add_clnt.c add_svc.c add_xdr.c
