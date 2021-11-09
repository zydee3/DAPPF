# Data API Reference  
## Cache

<hr>

## Compression

#### compress()

```cpp
int dappf::data::Compression::compress(int8_t** packet, int length)
```

> Tries to reduce the number of bytes in the array of bytes. If the compression  
> inflates the packet, the original array of bytes is returned with a flag byte.  
> A flag is inserted into the packet to signify if the packet was compressed.  
> @param packet Array of bytes  
> @param length Number of bytes in the array  
> @return New size of the array. This is always guaranteed to change. If the  
> array of bytes does not change, then the packet increases by 1 to contain  
> the change flag. Otherwise, the new size is equal to the compressed bytes + 1.  

<hr>

