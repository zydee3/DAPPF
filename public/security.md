# Security API Reference  
## packet_cipher

#### encrypt()

```cpp
//void dappf::meta::packet_cipher::encrypt(std::vector<int8_t> *packet)
```

> // * Encrypts the contents of a packet using Caesar's cipher  
> // * @param packet is the packet to be encrypted  

#### _encrypt()

```cpp
//void dappf::meta::packet_cipher::_encrypt(int8_t *current_byte)
```

> // * Helper function for packet_cipher::encrypt()  
> // * @param current_byte is the byte to be encrypted  

#### encrypt()

```cpp
void dappf::meta::packet_cipher::encrypt(int8_t *array, int32_t length)
```

> Encrypts the contents of a packet using Caesar's cipher  
> @param array is the array of bytes to be encrypted  
> @param length is the length of the array  

#### decrypt()

```cpp
void dappf::meta::packet_cipher::decrypt(int8_t *array, int32_t length)
```

> Decrypts the contents of a packet using Caesar's cipher  
> @param array is the array of bytes to be decrypted  
> @param length is the length of the array  

#### _decrypt()

```cpp
//void dappf::meta::packet_cipher::_decrypt(int8_t *current_byte)
```

> // * Helper function for packet_cipher::decrypt()  
> // * @param current_byte is the byte to be decrypted  

<hr>

