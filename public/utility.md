# Utility API Reference  
## tree

<hr>

## array

#### copy_over()

```cpp
void dappf::utility::array::copy_over(int8_t* ref, int ref_start, int ref_end, int8_t* target, int target_start)
```

> Copies a specified range from the reference (ref) array to the target array.  
> @param ref Reference array being copied from  
> @param ref_start Where to start the copying  
> @param ref_end Where to stop the copying  
> @param target Where the elements will be copied to  
> @param target_start Where the elements will begin being copied to  

#### to_array()

```cpp
int8_t* dappf::utility::array::to_array(std::vector<int8_t>* ref)
```

> Converts a vector to an array  
> @param ref Reference vector to be converted to an array  
> @return int8_t* with the same elements as ref  

#### copy()

```cpp
int8_t* dappf::utility::array::copy(int8_t* ref, int length)
```

> Creates a copy from the reference (ref) array  
> @param ref Reference array being copied from  
> @param length Length of the reference array  
> @return copy of reference  

<hr>

