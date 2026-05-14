# network programming projects

a collection of mini-projects i built during my computer networks lab course in college. mostly c, some rpc, sockets, and routing algorithms.

## projects

| project | description |
|---|---|
| project | description |
|---|---|---|
| **[udp-communication](./udp-communication/)** | basic [udp](https://en.wikipedia.org/wiki/User_Datagram_Protocol) client-server chat |
| **[tcp-echo-server-client](./tcp-echo-server-client/)** | [tcp](https://en.wikipedia.org/wiki/Transmission_Control_Protocol) echo server and client |
| **[tcp-time-server-client](./tcp-time-server-client/)** | [tcp](https://en.wikipedia.org/wiki/Transmission_Control_Protocol) time-of-day server and client |
| **[dns-client-server](./dns-client-server/)** | simple [dns](https://en.wikipedia.org/wiki/Domain_Name_System) lookup server and client |
| **[rpc-echo-service](./rpc-echo-service/)** | [rpc](https://en.wikipedia.org/wiki/Remote_procedure_call)-based echo service |
| **[rpc-daytime-service](./rpc-daytime-service/)** | [rpc](https://en.wikipedia.org/wiki/Remote_procedure_call)-based daytime service |
| **[rpc-addition-service](./rpc-addition-service/)** | [rpc](https://en.wikipedia.org/wiki/Remote_procedure_call)-based addition service |
| **[bit-stuffing](./bit-stuffing/)** | [bit stuffing](https://en.wikipedia.org/wiki/Bit_stuffing) implementation |
| **[character-stuffing](./character-stuffing/)** | [character stuffing](https://en.wikipedia.org/wiki/Binary_Synchronous_Communications#:~:text=This%20technique%20became%20known%20as%20character%20stuffing) implementation |
| **[link-state-routing](./link-state-routing/)** | [link state routing](https://en.wikipedia.org/wiki/Link-state_routing_protocol) algorithm |
| **[distance-vector-routing](./distance-vector-routing/)** | [distance vector routing](https://en.wikipedia.org/wiki/Distance-vector_routing_protocol) algorithm |

## build

```bash
make
```

that's it. `make` in any project folder compiles it. rpc projects run `rpcgen` automatically.
