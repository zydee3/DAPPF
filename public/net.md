# Net API Reference  
## connection

#### create_client_socket()

```cpp
int create_client_socket(std::string address, uint16_t port)
```

> Creates a socket for connecting to a server, listening on the specified port number.  
> Returns the socket file descriptor on success. On failure, throws error.  
> @param address the target's address  
> @param port the target's port  
> @return the file descriptor for the socket  

#### create_listen_socket()

```cpp
int create_listen_socket(uint16_t port)
```

> Creates a socket for listening for connections.  
> Throws error if anything goes wrong.  
> @param port the port on which the socket should be opened  
> @return the file descriptor for the socket  

#### listen_connection()

```cpp
[[noreturn]] void listen_connection(int connfd, void (*handler)(int8_t *, int32_t))
```

> Listens for data coming from a connection, and calls the provided function when data is received  
> @param connection the connection to listen to  
> @param handler the function that should be called when data is received  

#### add_connection()

```cpp
void add_connection(std::vector<dappf::connection::conn> *connections, std::string address, int connfd, void (*handler)(int8_t *, int32_t))
```

> Adds the new connection to the list, and creates a new thread which will listen to the connection for data  
> @param connections the list of active connections to add to  
> @param address the address of the new connection  
> @param connfd the file descriptor of the new connection  
> @param handler the function that should be called when data is received  

#### listen_for_connections()

```cpp
[[noreturn]] void listen_for_connections(std::vector<dappf::connection::conn> *connections, uint16_t port, void (*handler)(int8_t *, int32_t))
```

> Enters a non-busy infinite loop of accepting connections and adding them to a list  
> Call this from a dedicated thread - never exits unless an error occurs  
> @param connections pointer to a list of connections which will get added to  
> @param port the port on which to listen for incoming connections  
> @param handler the function that should be called when data is received  

#### join_network()

```cpp
dappf::connection::network dappf::connection::join_network(std::string address, uint16_t connect_port, uint16_t listen_port, void (*handler)(int8_t *, int32_t))
```

> Attempts to join the network given the address and connect_port of some node in that network  
> @param address the target node's address  
> @param connect_port the target node's port  
> @param listen_port the port on which the current node should listen for incoming connections  
> @param handler the function that should be called when data is received  
> @return the list of active connections, initialized with a single element  

#### broadcast_message()

```cpp
void dappf::connection::broadcast_message(std::vector<conn> *connections, int8_t* message, int32_t length)
```

> Sends a message to all connections  
> @param connections the list of connections to send the message to  
> @param message the message to send  
> @param length the length of the message  

#### leave_network()

```cpp
void dappf::connection::leave_network(std::vector<conn> *connections)
```

> Closes all connections, then frees the storage memory  
> @param connections the list of active connections to close and free  

<hr>

