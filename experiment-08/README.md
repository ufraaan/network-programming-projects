# Experiment 08: Screenshot-Friendly Run Guide (8a, 8b, 8c)

This guide gives you exact commands to compile and run 8a, 8b, and 8c in two terminals so you can take clean screenshots of outputs.

## What You Need

- macOS terminal (Ghostty is fine)
- `gcc`, `rpcgen`, `rpcbind`
- Project path:
  `/Users/ufraan/Desktop/CN-lab-experiments`

## Open Two Terminals

- Terminal 1: server terminal (keep server running here)
- Terminal 2: client terminal (run client here and capture output)

## 0) Start rpcbind (once)

Run in Terminal 1:

```bash
sudo rpcbind
```

If rpcbind is already running, this is okay.

---

## 1) 8a (Echo RPC)

### Compile (run once)

```bash
cd /Users/ufraan/Desktop/CN-lab-experiments/experiment-08/8a
rpcgen echo.x
gcc -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-incompatible-function-pointer-types -o echo_server echo_server.c echo_svc.c
gcc -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-incompatible-function-pointer-types -o echo_client echo_client.c echo_clnt.c
```

### Run and capture

Terminal 1:

```bash
cd /Users/ufraan/Desktop/CN-lab-experiments/experiment-08/8a
./echo_server -F
```

Terminal 2:

```bash
cd /Users/ufraan/Desktop/CN-lab-experiments/experiment-08/8a
./echo_client 127.0.0.1 "hello-from-8a"
```

Expected client output:

```text
Message sent : hello-from-8a
Echo from server: hello-from-8a
```

After screenshot: press `Ctrl+C` in Terminal 1.

---

## 2) 8b (Day/Time RPC)

### Compile (run once)

```bash
cd /Users/ufraan/Desktop/CN-lab-experiments/experiment-08/8b
rpcgen day.x
gcc -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-incompatible-function-pointer-types -o day_server day_server.c day_svc.c day_xdr.c
gcc -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-incompatible-function-pointer-types -o day_client day_client.c day_clnt.c day_xdr.c
```

### Run and capture

Terminal 1:

```bash
cd /Users/ufraan/Desktop/CN-lab-experiments/experiment-08/8b
./day_server -F
```

Terminal 2:

```bash
cd /Users/ufraan/Desktop/CN-lab-experiments/experiment-08/8b
./day_client 127.0.0.1
```

Expected client output format:

```text
Current Date and Time from Server: Fri Apr 24 00:43:22 2026
```

Note: date/time value changes each run.

After screenshot: press `Ctrl+C` in Terminal 1.

---

## 3) 8c (Add RPC)

### Compile (run once)

```bash
cd /Users/ufraan/Desktop/CN-lab-experiments/experiment-08/8c
rpcgen add.x
gcc -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-incompatible-function-pointer-types -o add_server add_server.c add_svc.c add_xdr.c
gcc -Wno-deprecated-non-prototype -Wno-implicit-function-declaration -Wno-incompatible-function-pointer-types -o add_client add_client.c add_clnt.c add_xdr.c
```

### Run and capture

Terminal 1:

```bash
cd /Users/ufraan/Desktop/CN-lab-experiments/experiment-08/8c
./add_server -F
```

Terminal 2:

```bash
cd /Users/ufraan/Desktop/CN-lab-experiments/experiment-08/8c
./add_client 127.0.0.1 12 30
```

Expected client output:

```text
12 + 30 = 42
```

After screenshot: press `Ctrl+C` in Terminal 1.

---

## Quick Screenshot Flow (Best for Viva/Lab Submission)

For each part (8a, 8b, 8c):

1. Keep Terminal 1 visible with server running.
2. Run client in Terminal 2.
3. Take screenshot showing client output.
4. Stop server with `Ctrl+C`.
5. Move to next part.

---

## If You See Errors

- `RPC: Port mapper failure`:
  Start rpcbind: `sudo rpcbind`
- `Connection refused` or `RPC call failed`:
  Ensure server is running first in Terminal 1.
- Compile warnings/errors from old rpcgen style:
  Use the same compile flags shown above.

---

## One-Liner to Verify rpcbind

```bash
rpcinfo -p
```

You should see entries for `rpcbind` on port `111`.
