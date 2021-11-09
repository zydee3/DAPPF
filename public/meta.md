# Meta API Reference  
## log

#### cout_hex()

```cpp
void dappf::meta::log::cout_hex(int32_t n)
```

> Converts a byte into a hexadecimal and prints it out. Its important to convert  
> the byte to an int as printing out a single byte and/or int8_t will result in the  
> char representation being printed out.  
> @param n byte to be printed as a hexadecimal.  

#### cout_hex_array()

```cpp
void dappf::meta::log::cout_hex_array(int8_t* a, int32_t length)
```

> Writes each byte (int8_t) as a hexadecimal and prints it out. The result  
> is a packet where each value is a hexadecimal.  
> @param a array of bytes (int8_t) to be printed.  
> @param length number of elements inside provided array of bytes (int8_t).  

<hr>

## packet_writer

#### packet_writer()

```cpp
dappf::meta::packet_writer::packet_writer()
```

> Constructor; can be overloaded as long as packet is initialized.  

#### packet_writer()

```cpp
dappf::meta::packet_writer::~packet_writer()
```

> Destructor; necessary to release memory in packet and the collection itself.  

#### encode_1()

```cpp
void dappf::meta::packet_writer::encode_1(int8_t n)
```

> Writes a single byte to the packet.  
> @param n byte to be encoded.  

#### encode_2()

```cpp
void dappf::meta::packet_writer::encode_2(int16_t n)
```

> Converts a int16_t into two bytes and writes the bytes to the packet.  
> @param n int16_t to be encoded.  

#### encode_4()

```cpp
void dappf::meta::packet_writer::encode_4(int32_t n)
```

> Converts a int32_t into four bytes and writes the bytes to the packet.  
> @param n int32_t to be encoded.  

#### encode_8()

```cpp
void dappf::meta::packet_writer::encode_8(int64_t n)
```

> Converts a int64_t into eight bytes and writes the bytes to the packet.  
> @param n int64_t to be encoded.  

#### encode_string()

```cpp
void dappf::meta::packet_writer::encode_string(std::string s)
```

> Writes the provided string into the buffer by iterating character by character  
> and inserting at each iteration.  
> @param s String to be encoded.  

#### length()

```cpp
int32_t dappf::meta::packet_writer::length()
```

> Determines the number of bytes currently written to the packet.  
> @return The number of bytes current written to the packet.  

#### remove_n()

```cpp
void dappf::meta::packet_writer::remove_n(int32_t n)
```

> Removes the last n bytes written in the packet. If the number of bytes  
> to be removed is more than what is present, the packet is cleared instead.  
> @param n The number of bytes to removed.  

#### clear()

```cpp
void dappf::meta::packet_writer::clear()
```

> Removes all written bytes in the packet.  

#### to_array()

```cpp
int8_t* dappf::meta::packet_writer::to_array()
```

> Converts the packet to an array of bytes (int8_t).  
> @return Array of bytes (int8_t)  

<hr>

## event_listeners

#### set_on_connection_request_event_listener()

```cpp
void dappf::meta::event_listeners::set_on_connection_request_event_listener(void(*handle)(std::string))
```

> Sets handler for handling connection requests.  
> @param handle Pointer to function that handles connection requests.  
> When invoked, the handler passes in a string parameter representing the ipv6  
> address of the requesting node.  

#### get_on_connection_request_event_listener()

```cpp
auto dappf::meta::event_listeners::get_on_connection_request_event_listener()
```

> Returns handler for handling connection requests.  
> @return Pointer to function that handles connection requests.  
> When invoked, the handler passes in a string parameter representing the ipv6  
> address of the requesting node.  

#### set_on_connection_established_event_listener()

```cpp
void dappf::meta::event_listeners::set_on_connection_established_event_listener(void(*handle)(std::string))
```

> Sets handler for handling post-connection events.  
> @param handle Pointer to function that handles post-connection events.  
> When invoked, the handler passes in a string parameter representing the ipv6  
> address of the connected neighbor.  

#### get_on_connection_established_event_listener()

```cpp
auto dappf::meta::event_listeners::get_on_connection_established_event_listener()
```

> Gets handler for handling post-connection events.  
> @return Pointer to function that handles post-connection events.  
> When invoked, the handler passes in a string parameter representing the ipv6  
> address of the connected neighbor.  

#### set_on_connection_dropped_event_listener()

```cpp
void dappf::meta::event_listeners::set_on_connection_dropped_event_listener(void(*handle)(std::string))
```

> Sets handler for handling post-disconnection events.  
> @param handle Pointer to function that handles post-disconnection events.  
> When invoked, the handler passes in a string parameter representing the ipv6  
> address of the disconnected neighbor.  

#### get_on_connection_dropped_event_listener()

```cpp
auto dappf::meta::event_listeners::get_on_connection_dropped_event_listener()
```

> Gets handler for handling post-disconnection events.  
> @param handle Pointer to function that handles post-disconnection events.  
> When invoked, the handler passes in a string parameter representing the ipv6  
> address of the disconnected neighbor.  

#### set_on_packet_received_event_listener()

```cpp
void dappf::meta::event_listeners::set_on_packet_received_event_listener(void(*handle)(dappf::meta::packet_reader*))
```

> Sets handler for handing received packets from neighbors.  
> @param handle Pointer to function that handles received packets from neighbors.  
> When invoked, the handler passes in an instantiated packet reader which contains  
> the bytes received.  

#### get_on_packet_received_event_listener()

```cpp
auto dappf::meta::event_listeners::get_on_packet_received_event_listener()
```

> Gets handler for handing received packets from neighbors.  
> @param handle Pointer to function that handles received packets from neighbors.  
> When invoked, the handler passes in an instantiated packet reader which contains  
> the bytes received.  

#### set_on_packet_sent_event_listener()

```cpp
void dappf::meta::event_listeners::set_on_packet_sent_event_listener(void(*handle)(dappf::meta::packet_writer*))
```

> Sets handler for handing sent packets to neighbors.  
> @param handle Pointer to function that handles sent packets to neighbors.  
> When invoked, the handler passes in an instantiated packet writer which contains  
> the bytes written and sent.  

#### get_on_packet_sent_event_listener()

```cpp
auto dappf::meta::event_listeners::get_on_packet_sent_event_listener()
```

> Gets handler for handing sent packets to neighbors.  
> @param handle Pointer to function that handles sent packets to neighbors.  
> When invoked, the handler passes in an instantiated packet writer which contains  
> the bytes written and sent.  

#### set_packet_validator()

```cpp
void dappf::meta::event_listeners::set_packet_validator(bool(*handle)(int8_t*, int))
```

> Sets the handler for validating an incoming packet.  
> @param handle Pointer to function that validates packets.  
> When invoked, the handler accepts the array of bytes, the length of the array of bytes  
> and whats returned is true or false representing the state; true if valid, otherwise false.  

#### get_packet_validator()

```cpp
auto dappf::meta::event_listeners::get_packet_validator()
```

> Gets the handler for validating an incoming packet.  
> @param handle Pointer to function that validates packets.  
> When invoked, the handler accepts the array of bytes, the length of the array of bytes  
> and whats returned is true or false representing the state; true if valid, otherwise false.  

<hr>

## packet_reader

#### packet_reader()

```cpp
dappf::meta::packet_reader::packet_reader(int8_t* a, int32_t length)
```

> Packet reader constructor. If overloaded, the present two parameters a and length  
> must be present otherwise the reader cannot run as intended.  
> @param a The bytes to be read.  
> @param length The number of bytes that are present inside of parameter a.  

#### packet_reader()

```cpp
dappf::meta::packet_reader::~packet_reader()
```

> Destructor to release the buffer holding the array of bytes.  

#### check_and_shift()

```cpp
void dappf::meta::packet_reader::check_and_shift(int32_t num_bytes)
```

> Checks if the packet has enough bytes to be consumed. If not, an exception is throw.  
> Otherwise, the position is moved forward by the number of bytes to be consumed.  
> @param num_bytes The number of bytes to be consumed.  

#### decode_1()

```cpp
int8_t dappf::meta::packet_reader::decode_1()
```

> Reads and consumes a single byte from the packet.  
> @return Byte consumed as an int8_t.  

#### decode_2()

```cpp
int16_t dappf::meta::packet_reader::decode_2()
```

> Reads and consumes two bytes from the packet.  
> @return Two bytes consumed as an int16_t.  

#### decode_4()

```cpp
int32_t dappf::meta::packet_reader::decode_4()
```

> Reads and consumes 4 bytes from the packet.  
> @return Four bytes consumed as an int32_t.  

#### decode_8()

```cpp
int64_t dappf::meta::packet_reader::decode_8()
```

> Reads and consumes 8 bytes from the packet.  
> @return Eight bytes consumed as an int64_t.  

#### decode_string()

```cpp
std::string dappf::meta::packet_reader::decode_string(int32_t num_chars)
```

> Reads a specified number of bytes from the buffer. Each byte read is appended  
> to a string and the string is returned once the specified number of bytes are consumed.  
> @param num_chars  
> @return  

#### remaining()

```cpp
int32_t dappf::meta::packet_reader::remaining()
```

> The number of bytes remaining that can be read and consumed.  
> @return Number of bytes remaining that can be read and consumed.  

<hr>

