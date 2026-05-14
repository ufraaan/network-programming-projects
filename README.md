a collection of mini-projects i built during my computer networks lab course in college. mostly c, some rpc, sockets, and routing algorithms.

> [!NOTE]
> these programs use posix apis and require linux, macos, or any unix-like system. they will not work on windows without significant changes.

## projects

| project | description |
|---|---|
| **[udp-communication](./udp-communication/)** | basic [udp](https://en.wikipedia.org/wiki/User_Datagram_Protocol) client-server message exchange over loopback |
| **[tcp-echo-server-client](./tcp-echo-server-client/)** | [tcp](https://en.wikipedia.org/wiki/Transmission_Control_Protocol) echo server that bounces back whatever the client sends |
| **[tcp-time-server-client](./tcp-time-server-client/)** | [tcp](https://en.wikipedia.org/wiki/Transmission_Control_Protocol) server returning the current date and time |
| **[dns-client-server](./dns-client-server/)** | simple [dns](https://en.wikipedia.org/wiki/Domain_Name_System) server resolving hostnames to ip addresses |
| **[rpc-echo-service](./rpc-echo-service/)** | [rpc](https://en.wikipedia.org/wiki/Remote_procedure_call)-based echo service using rpcgen |
| **[rpc-daytime-service](./rpc-daytime-service/)** | [rpc](https://en.wikipedia.org/wiki/Remote_procedure_call)-based daytime service returning server time |
| **[rpc-addition-service](./rpc-addition-service/)** | [rpc](https://en.wikipedia.org/wiki/Remote_procedure_call)-based service that adds two integers |
| **[bit-stuffing](./bit-stuffing/)** | [bit stuffing](https://en.wikipedia.org/wiki/Bit_stuffing) implementation for hdlc-style framing |
| **[character-stuffing](./character-stuffing/)** | [character stuffing](https://en.wikipedia.org/wiki/Binary_Synchronous_Communications#:~:text=This%20technique%20became%20known%20as%20character%20stuffing) using escape bytes |
| **[link-state-routing](./link-state-routing/)** | [link state routing](https://en.wikipedia.org/wiki/Link-state_routing_protocol) using dijkstra's algorithm |
| **[distance-vector-routing](./distance-vector-routing/)** | [distance vector routing](https://en.wikipedia.org/wiki/Distance-vector_routing_protocol) using bellman-ford |

## build

```bash
make
```

that's it. `make` in any project folder compiles it. rpc projects run `rpcgen` automatically. rpc projects also need `rpcbind` running, start it with `sudo rpcbind` on linux/macos.

## resources

- [beej's guide to network programming](https://beej.us/guide/bgnet/)
- [building an http server in go (video course)](https://www.youtube.com/watch?v=FknTw9bJsXM)
- [man7.org: socket(7) - linux socket layer](https://man7.org/linux/man-pages/man7/socket.7.html)
- [man7.org: tcp(7) - tcp protocol](https://man7.org/linux/man-pages/man7/tcp.7.html)
- [man7.org: udp(7) - udp protocol](https://man7.org/linux/man-pages/man7/udp.7.html)
- [man7.org: ip(7) - ip protocol](https://man7.org/linux/man-pages/man7/ip.7.html)
- [man7.org: sockets introduction (tlpi/chapter 56)](http://blog.man7.org/2009/11/chapter-56-sockets-introduction.html)
- [pubs.opengroup.org: posix socket()](https://pubs.opengroup.org/onlinepubs/9699919799/functions/socket.html)
- [pubs.opengroup.org: posix `<sys/socket.h>`](https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/sys_socket.h.html)
- [gnu c library: sockets manual](https://www.gnu.org/s/libc/manual/html_node/Sockets.html)
- [rfc 791 - internet protocol](https://datatracker.ietf.org/doc/html/rfc791)
- [rfc 793 - transmission control protocol](https://datatracker.ietf.org/doc/html/rfc793)
- [unix network programming (stevens)](https://unpbook.com/)
- [rfc 768 - user datagram protocol](https://datatracker.ietf.org/doc/html/rfc768)
- [rfc 792 - internet control message protocol](https://datatracker.ietf.org/doc/html/rfc792)
- [rfc 826 - address resolution protocol](https://datatracker.ietf.org/doc/html/rfc826)
- [rfc 1035 - domain names (dns)](https://datatracker.ietf.org/doc/html/rfc1035)
- [rfc 1180 - tcp/ip tutorial](https://www.rfc-editor.org/rfc/rfc1180)
- [tcp/ip illustrated, vol 1 (stevens/fall)](https://unpbook.com/)
- [the linux programming interface (kerrisk)](https://man7.org/tlpi/)
- [wikibooks: c networking in unix](https://en.wikibooks.org/wiki/C_Programming/Networking_in_UNIX)
- [unix socket faq (comp.unix.programmer)](https://web.fe.up.pt/~jmcruz/etc/sockets/unix-socket-faq.html)
- [yolinux posix sockets tutorial](https://yolinux.com/TUTORIALS/Sockets.html)
