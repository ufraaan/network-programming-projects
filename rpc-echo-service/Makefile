all: echo_client echo_server

echo.h echo_clnt.c echo_svc.c: echo.x
	rpcgen echo.x

echo_server: echo_server.c echo_svc.c
	gcc -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -o echo_server echo_server.c echo_svc.c

echo_client: echo_client.c echo_clnt.c
	gcc -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -o echo_client echo_client.c echo_clnt.c

clean:
	rm -f echo_client echo_server echo.h echo_clnt.c echo_svc.c
