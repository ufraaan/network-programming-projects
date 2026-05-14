all: day_client day_server

day.h day_clnt.c day_svc.c day_xdr.c: day.x
	rpcgen day.x

day_server: day_server.c day_svc.c day_xdr.c
	gcc -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -o day_server day_server.c day_svc.c day_xdr.c

day_client: day_client.c day_clnt.c day_xdr.c
	gcc -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -o day_client day_client.c day_clnt.c day_xdr.c

clean:
	rm -f day_client day_server day.h day_clnt.c day_svc.c day_xdr.c
