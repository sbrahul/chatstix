## Instructions ##

### Compiling ###

To compile, just run the Makefile in the _client_ or _server_ folder.
```
make
```
The compiled binary will be stored in _dist/Debug/GNU-Linux-x86_ folder.

(Note: gcc must be installed for successful compilation).

### Executing ###

Executing the server is very simple as no arguments are required. The following is for executing from the src folder.
```
./srv
```

The client on the other hand takes a single argument which is the IP(v4) address of the server.
```
./cli 192.168.1.10
```
(where 192.168.1.10 is the machine running the server)