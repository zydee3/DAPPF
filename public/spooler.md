# Spooler API Reference  
## predictor

#### get_new_pair_entry()

```cpp
std::pair<int, int> dappf::data::spooler::predictor::get_new_pair_entry(int value)
```

> Returns a new pair with a value being parameter value and an occurrence being 1  
> @param value Value of pair.left  
> @return pair (value, 1)  

#### get_new_vector_entry()

```cpp
std::vector<std::pair<int, int>> dappf::data::spooler::predictor::get_new_vector_entry(int initial_value)
```

> Returns a new vector with an initial element where vector[0] is set to  
> a new pair with value being the parameter initial_value and the occurrence being 1  
> @param initial_value Value of vector[0].left  
> @return vector {pair (initial_value, 1) }  

#### increment()

```cpp
void dappf::data::spooler::predictor::increment(int key, int value)
```

> Increments the number of occurrences of value in key. If the key doesn't exist, insert  
> a new entry with the key and a new vector with the default value of the parameter value.  
> If the key exists, then increment the occurrence of value, or insert it if the occurrence  
> counter does not exist. If the number of values exceeds the max lookback (max allowed  
> occurrences), then the least recently used value is removed.  
> @param key  
> @param value  

#### decrement()

```cpp
void dappf::data::spooler::predictor::decrement(int key, int value)
```

> Decrements the number of occurrences of value in key. If the number of  
> occurrences reaches 0, that occurrence is removed instead.  
> @param key The value which the parameter value is being associated to  
> @param value The value which key is being associated with.  

#### associate()

```cpp
void dappf::data::spooler::predictor::associate(int value)
```

> Associates the newest element to the last k (most recent) elements  
> of the previously seen elements by incrementing the occurrence of  
> value in the last k elements.  
> @param value Newly inserted value into previously seen values vector  

#### unassociate()

```cpp
void dappf::data::spooler::predictor::unassociate(int value)
```

> Unassociates the oldest element in the previously seen elements  
> by decrementing the occurrence in the vector of lookback values  
> @param value  

#### move()

```cpp
void dappf::data::spooler::predictor::move()
```

> Moves the oldest element from the previously seen elements E  
> to the vector of lookback values. This is so we can unassociate  
> E from the k-range of numbers prior.  

#### )

```cpp
```

> [lookback_values] [ previous_values ] (value)  
> [ a b c         ] [ y x x x x i j k ] (z)  
>   
>   
> INSERT z INTO previous_values  
> FOR EACH element IN [i, j, k]: (ASSOCIATE)  
> IF references CONTAINS element THEN:  
> LET v BE value AT element IN references  
> LET p BE std::pair WHERE pair.first == value IN v  
> IF p EXISTS THEN:  
> INCREMENT p.second  
> ELSE:  
> p = std::pair(value, 1)  
> INSERT p INTO v  
> LET l BE length OF v  
> IF l >= max_lookback THEN:  
> REMOVE first element OF V  
> ELSE:  
> LET v BE std::vector OF integers  
> LET p = std::pair(value, 1)  
> INSERT p INTO v  
> INSERT v INTO references AS std::pair(element, v)  
>   
> REMOVE y FROM previous_values  
> FOR EACH element IN [a, b, c]: (UNASSOCIATE)  
> LET v BE value AT element IN lookback_values  
> LET p BE std::pair WHERE pair.first == y IN v  
> DECREMENT p.second  
> IF p.second == 0 THEN:  
> REMOVE p FROM v  
> INSERT y INTO lookback_values  
> Let l BE length OF lookback_values  
> IF l >= max_lookback THEN:  
> REMOVE a  

#### insert()

```cpp
void dappf::data::spooler::predictor::insert(int value)
```

> Required for dappf::data::spooler::predictor::predict(int) to work. Inserts a  
> value into a list of previously seen values. See pseudo code above current function  
> or the documentation for dappf::data::spooler::predictor::predict(int) for an in  
> depth look at how the process works for inserting and predicting  
> @param value  

#### predict()

```cpp
std::vector<int> dappf::data::spooler::predictor::predict(int key)
```

> This predict only works given a set of data accumulated by values inserted  
> through dappf::data::spooler::predictor::insert(int). Using a k-range (lookback),  
> the predictor determines a value which represents how likely a future number is to  
> appear given the history. Everytime a value is inserted, the k values before the current  
> value are associated to the current value. This association is used to determine the  
> likelihood mentioned. A max size on the number of previous values can be set (default is  
> 500). Once the max size has been reached, the first element of our list of previous values  
> (the oldest value) is removed and de-associated to the k-elements before it. This ensures  
> local min and maxes in fluctuation of predictions are accounted for.  
> @param key  
> @return  

#### set()

```cpp
void dappf::data::spooler::predictor::set(std::function<std::vector<int>(int)>* _handle)
```

> Sets function pointer to handle for predicting potential future values  
> @return dappf::data::spooler::predictor::handle  

#### get()

```cpp
std::function<std::vector<int>(int)>* dappf::data::spooler::predictor::get()
```

> Returns function pointer to handle for predicting potential future values  
> @return dappf::data::spooler::predictor::handle  

<hr>

## spooler

#### fetch_handler()

```cpp
dappf::data::handlers::handler* dappf::data::spooler::spooler::fetch_handler(int key)
```

> Fetches a handler from the handler_director. If the handler_director does not have  
> a handler to the associated key, then nullptr is returned and we throw an  
> error where appropriate  
> @param key value associated to handler which acts as the handler id  
> @return handler if present in handler_director, otherwise nullptr  

#### spool()

```cpp
void dappf::data::spooler::spooler::spool(std::string source, int value)
```

> Using the predictor, we fetch handlers which could be needed in the future  
> and pre-process the data such that the data is available for when the  
> handle request does come in. The predictor returns a vector of values which  
> is associated to a handler. For each value in the vector, we fetch the  
> handler. If the handler is present and valid, we pre-process it and cache  
> the handler. If the pre-process fails, we don't cache the handler and an  
> exception is thrown where appropriate.  
> @param source Requester, generally an Ipv4  
> @param value op code  

<hr>

