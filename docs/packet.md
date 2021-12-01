# Packet API Reference  
## packet_processing

<hr>

## packet_writer

#### packet_writer()

```cpp
dappf::data::packet::packet_writer::packet_writer()
```

> Constructor; can be overloaded as long as packet is initialized.  

#### packet_writer()

```cpp
dappf::data::packet::packet_writer::~packet_writer()
```

> Destructor; necessary to release memory in packet and the collection itself.  

#### encode_1()

```cpp
void dappf::data::packet::packet_writer::encode_1(int8_t n)
```

> Writes a single byte to the packet.  
> @param n byte to be encoded.  

#### encode_2()

```cpp
void dappf::data::packet::packet_writer::encode_2(int16_t n)
```

> Converts a int16_t into two bytes and writes the bytes to the packet.  
> @param n int16_t to be encoded.  

#### encode_4()

```cpp
void dappf::data::packet::packet_writer::encode_4(int32_t n)
```

> Converts a int32_t into four bytes and writes the bytes to the packet.  
> @param n int32_t to be encoded.  

#### encode_8()

```cpp
void dappf::data::packet::packet_writer::encode_8(int64_t n)
```

> Converts a int64_t into eight bytes and writes the bytes to the packet.  
> @param n int64_t to be encoded.  

#### encode_string()

```cpp
void dappf::data::packet::packet_writer::encode_string(std::string s)
```

> Writes the provided string into the buffer by iterating character by character  
> and inserting at each iteration.  
> @param s String to be encoded.  

#### length()

```cpp
int32_t dappf::data::packet::packet_writer::length()
```

> Determines the number of bytes currently written to the packet.  
> @return The number of bytes current written to the packet.  

#### remove_n()

```cpp
void dappf::data::packet::packet_writer::remove_n(int32_t n)
```

> Removes the last n bytes written in the packet. If the number of bytes  
> to be removed is more than what is present, the packet is cleared instead.  
> @param n The number of bytes to removed.  

#### clear()

```cpp
void dappf::data::packet::packet_writer::clear()
```

> Removes all written bytes in the packet.  

#### to_array()

```cpp
int8_t* dappf::data::packet::packet_writer::to_array()
```

> Converts the packet to an array of bytes (int8_t).  
> @return Array of bytes (int8_t)  

<hr>

## packet_validation

#### is_valid_character()

```cpp
bool dappf::data::packet::packet_validation::is_valid_character(char c)
```

> Checks if the char is a valid char present inside the packet header  
> @param c Char to be tested  
> @return True if char c is valid, otherwise false  

#### validate_packet()

```cpp
bool dappf::data::packet::packet_validation::validate_packet(int8_t* packet, int length)
```

> Checks to see if the packet header is valid by iterating through the  
> packet header element by element and checking if the byte is a valid  
> byte to be contained in the packet header  
> @param packet Array of bytes  
> @param length Number of elements in packet  
> @return True if the entire packet header contains only valid characters, otherwise false  

<hr>

## packet_compression

#### compress()

```cpp
std::vector<int8_t>* dappf::data::packet::packet_compression::compress(int8_t* packet, int start, int end)
```

> Helper function for the public compress function. This function specifically  
> performs only the reduction of bytes using a lossless method. This function  
> compresses the packet's bytes with indexes between start and finish: [start, finish)  
> @param packet Array of bytes  
> @param start Where to begin compressing the packet  
> @param end Where to stop compressing the packet  
> @return The compressed packet  

#### compress()

```cpp
int dappf::data::packet::packet_compression::compress(int8_t** packet, int length)
```

> Tries to reduce the number of bytes in the array of bytes. If the packet_compression  
> inflates the packet, the original array of bytes is returned with a flag byte.  
> A flag is inserted into the packet to signify if the packet was compressed.  
> @param packet Array of bytes  
> @param length Number of bytes in the array  
> @return New size of the array. This is always guaranteed to change. If the  
> array of bytes does not change, then the packet increases by 1 to contain  
> the change flag. Otherwise, the new size is equal to the compressed bytes + 1.  

#### decompress()

```cpp
int dappf::data::packet::packet_compression::decompress(int8_t** packet, int length)
```

> Tries to undo the packet compression done by dappf::data::packet::packet_compression::compress(int8_t**, int).  
> First checks to see if the flag has been set signifying if the packet was compressed. Flag = 1 if compressed,  
> otherwise 0. If compressed, then perform the associated decompression.  
> @param packet Array of bytes  
> @param length Number of bytes in the packet  
> @return Decompressed packet if the given packet was compressed, otherwise the original packet.  

<hr>

## packet_cipher

#### encrypt()

```cpp
//void dappf::data::packet_cipher::encrypt(std::vector<int8_t> *packet)
```

> // * Encrypts the contents of a packet using Caesar's cipher  
> // * @param packet is the packet to be encrypted  

#### _encrypt()

```cpp
//void dappf::data::packet_cipher::_encrypt(int8_t *current_byte)
```

> // * Helper function for packet_cipher::encrypt()  
> // * @param current_byte is the byte to be encrypted  

#### encrypt()

```cpp
void dappf::data::packet::packet_cipher::encrypt(int8_t *array, int32_t length)
```

> Encrypts the contents of a packet using Caesar's cipher  
> @param array is the array of bytes to be encrypted  
> @param length is the length of the array  

#### decrypt()

```cpp
void dappf::data::packet::packet_cipher::decrypt(int8_t *array, int32_t length)
```

> Decrypts the contents of a packet using Caesar's cipher  
> @param array is the array of bytes to be decrypted  
> @param length is the length of the array  

#### set_encryptor()

```cpp
void dappf::data::packet::packet_cipher::set_encryptor(std::function<void(int8_t *, int32_t)> handle)
```

> Sets the function pointer used to encrypt a packet.  

#### void()

```cpp
std::function<void(int8_t*, int32_t)> dappf::data::packet::packet_cipher::get_encryptor()
```

> Returns the function pointer used to encrypt a packet.  
> @return dappf::data::packet::packet_cipher::encrypt(int8_t *, int32_t);  

#### set_decryptor()

```cpp
void dappf::data::packet::packet_cipher::set_decryptor(std::function<void(int8_t *, int32_t)> handle)
```

> Sets the function pointer used to decrypt a packet.  

#### void()

```cpp
std::function<void(int8_t*, int32_t)> dappf::data::packet::packet_cipher::get_decryptor()
```

> Returns the function pointer used to decrypt a packet.  
> @return dappf::data::packet::packet_cipher::decrypt(int8_t *, int32_t);  

<hr>

## packet_reader

#### packet_reader()

```cpp
dappf::data::packet::packet_reader::packet_reader(int8_t* a, int32_t length)
```

> Packet reader constructor. If overloaded, the present two parameters a and length  
> must be present otherwise the reader cannot run as intended.  
> @param a The bytes to be read.  
> @param length The number of bytes that are present inside of parameter a.  

#### packet_reader()

```cpp
dappf::data::packet::packet_reader::~packet_reader()
```

> Destructor to release the buffer holding the array of bytes.  

#### check_and_shift()

```cpp
void dappf::data::packet::packet_reader::check_and_shift(int32_t num_bytes)
```

> Checks if the packet has enough bytes to be consumed. If not, an exception is throw.  
> Otherwise, the position is moved forward by the number of bytes to be consumed.  
> @param num_bytes The number of bytes to be consumed.  

#### decode_1()

```cpp
int8_t dappf::data::packet::packet_reader::decode_1()
```

> Reads and consumes a single byte from the packet.  
> @return Byte consumed as an int8_t.  

#### decode_2()

```cpp
int16_t dappf::data::packet::packet_reader::decode_2()
```

> Reads and consumes two bytes from the packet.  
> @return Two bytes consumed as an int16_t.  

#### decode_4()

```cpp
int32_t dappf::data::packet::packet_reader::decode_4()
```

> Reads and consumes 4 bytes from the packet.  
> @return Four bytes consumed as an int32_t.  

#### decode_8()

```cpp
int64_t dappf::data::packet::packet_reader::decode_8()
```

> Reads and consumes 8 bytes from the packet.  
> @return Eight bytes consumed as an int64_t.  

#### decode_string()

```cpp
std::string dappf::data::packet::packet_reader::decode_string(int32_t num_chars)
```

> Reads a specified number of bytes from the buffer. Each byte read is appended  
> to a string and the string is returned once the specified number of bytes are consumed.  
> @param num_chars  
> @return  

#### remaining()

```cpp
int32_t dappf::data::packet::packet_reader::remaining()
```

> The number of bytes remaining that can be read and consumed.  
> @return Number of bytes remaining that can be read and consumed.  

#### get_packet()

```cpp
int8_t* dappf::data::packet::packet_reader::get_packet()
```

> Returns the original packet being interfaced.  
> @return packet  

<hr>

