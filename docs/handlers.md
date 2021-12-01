# Handlers API Reference  
## handler

#### handler()

```cpp
dappf::data::handlers::handler::handler(int8_t* _ipv4, int8_t* _packet, long _timestamp)
```

> Super constructor to any class which implements this handler  
> @param _ipv4 Ipv4 address of target, nullptr if none / internal use. Ipv4 is an array  
> of 4 numbers [aaa,bbb,ccc,ddd] such that the ipv4 constructed is aaa.bbb.ccc.ddd  
> @param _packet The packet to be sent and/or constructed, nullptr if unneeded.  

#### handler()

```cpp
dappf::data::handlers::handler::~handler()
```

> Super deconstructor to any class which implements this handler  

#### throw_unhandled_exception()

```cpp
void dappf::data::handlers::handler::throw_unhandled_exception(std::string error)
```

> Used by other super methods when a class implementing this handler does not  
> implement their own methods for handling the associated member function.  
> @param error Error message to be outputted.  

#### process()

```cpp
bool dappf::data::handlers::handler::process()
```

> Super function for process. Only throws an error when the class implementing  
> this class does not implement / override this member function.  
>   
> The use of this function is to process any required information needed  
> for the handling part of the instruction set.  
>   
> @return False for not processed  

#### handle()

```cpp
bool dappf::data::handlers::handler::handle()
```

> Super function for handle. Only throws an error when the class implementing  
> this class does not implement / override this member function.  
>   
> The use of this function is to handle the designated set of instructions  
> after process has been called.  
>   
> @return False for not handled  

#### delay()

```cpp
bool dappf::data::handlers::handler::delay()
```

> Super function for delay. Only throws an error when the class implementing  
> this class does not implement / override this member function.  
>   
> The use of this function is to handle any task necessary for when this task  
> gets potentially delayed. A point of delay can be when not enough threads  
> are available in the task pool to execute this handler and thus we invoke  
> a set of instructions to be completed while waiting for the handle to be  
> completed.  
>   
> @return  

<hr>

## handler_director

#### check_state()

```cpp
bool dappf::data::handlers::handler_director::check_state(std::string source)
```

> Checks the current state of the framework. You can only modify an op code  
> and it's associated handler when the framework is not actively running.  
> @param source  
> @return  

#### remove()

```cpp
bool dappf::data::handlers::handler_director::remove(int16_t op_code)
```

> Removes a handler associated by the op_code.  
> @param op_code op_code to be removed  
> @return true if an associated op_code existed, otherwise false  

#### put()

```cpp
bool dappf::data::handlers::handler_director::put(int16_t op_code, dappf::data::handlers::handler* handler)
```

> Inserts a handler associated by the op_code. op_codes must be unique, however multiple  
> op_codes can contain the same instance of the same handler.  
> @param op_code value representing the op_code  
> @param handler instance of handler associated to the op_code  
> @return true  if previous instance of op_code was overwritten,  
> false if op_code was inserted without overwriting a previous instance.  

#### get()

```cpp
dappf::data::handlers::handler *dappf::data::handlers::handler_director::get(int16_t op_code)
```

> Returns the handler associated to the given op_code if it exists  
> @param op_code op code associated to the desired handler  
> @return handler associated to the op code  

<hr>

