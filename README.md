# Starting Off
The project is built in jetbrain's clion IDE. You should be able to just open the file and compile straight away as the project was set up already for you. Connect your github so you can make pull requests to the main branch.

# DAPPF
I created both the work [example] environment and library itself under a single project. The work enviornment compiles down and ran as an executable. The framework is compiled to a shared library which cannot be ran as a standalone.

# Framework
Within the framework are four main directories which pertains to each layer (1-3) of the framework. The fourth layer is written by the user however the framework provides an interface for interaction between handlers and the framework.
 - Layer 1: Net (Communication Layer)
 - Layer 2: Security
 - Layer 3: Data
 - Layer 4: Handlers (Processing)

Within each directory the respective directories are meta files. The meta file will hold meta data to the main files within the module. A meta file is like that of an inner class to a parent class. Using a game as an example, an example of meta data to Player class is PlayerStats which holds the stats of the player. Meta data allows us to break apart classes into smaller more organized classes in order to premote clean code and precent god classes.

# Modules Task Sheet

| No.  | Module                                      | Status        | Who     | Completed On    |
| ---- | ------------------------------------------- | ------------- | ------- | ------- |
| 1.   | Network Node Connect and Disconnect         | Completed     | Kirill | 11/1 |
| 2.   | Documentation Site                          | Completed     | Garrett | 11/1 |
| 3.  | Documentation Github (Readme)                | In Progress   | Vincent | 
| 4.   | Packet Reader and Writer                    | Completed     | Vincent | 10/23 |
| 5.   | Packet Compress and Decompress              | Completed     | Vincent | 11/6 |
| 6.   | Packet Encrypt and Decrypt                  | Completed     | Anthony | 11/2 |
| 7.   | Data Validator                              | In Progress   | Garrett | 11/10 |
| 8.   | Data Cache                                  | In Progress   | ~~Vincent~~ Shishir | |
| 9.   | Data Spooler                                | In Progress   | ~~Shishir~~ Vincent | |
| 10.   | Task Pool                                  | In Progress   | Anthony, Vincent | |
| 11.  | Delegates                                   | In Progress   | Shishir | |
| 12.  | Listeners                                   | Completed     | Vincent | 11/6 |
| 13.  | Handlers                                    | In Progress   | Vincent | | 
| 14.  | Example Project                             | In Progress   | Kirill | |
| 15.  | Combining Modules                           | In Progress   | Vincent | |


# Module Functionality

| No.  | Module                                                           |
| ---- | ---------------------------------------------------------------- |
| 1.   |  Network Node Connect and Disconnect <br /><br />This feature handles the connection between any two or more nodes in a network. The questions we ask here are, in the absence of a direct target, how would a new node enter the network? When a node would like to leave the network, it remembers some nodes and is able to use those records to re-enter the network without needing to find a way in like it did when it was a new node. Here we note that it is entirely possible for all records to disconnect prior to the current node re-entering the network, thus it is possible for a non-new node to be subject to new-node entry proceedures of finding an entry point.|
| 2.   |  Documentation Site <br /><br /> We can create a website which has complete live documentation for future developers to use. The idea is since the github is hosted publically, the website can webscrape the repository for comments above functions and generate documentation. This is completely optional and should only be done towards the end.|
| 3.   |  Packet Reader and Writer <br /><br />A packet is a sequence of bytes normally in the form of an array of bytes. Packets contain data represented in bytes and is the general way to send data between a connection. The packet reader accepts bytes and allows you to read 2^n bytes depending on the data type you're trying to read while the packet writer does the opposite and allows you to feed bytes into the writer and then construct the array of bytes when the packet is completed and ready to be sent. |
| 4.   |  Packet Compress and Decompress  <br /><br />Packet Compression is when you take an array of bytes and reduce the total number of bytes in the array. Effectively, you're representing the same data, but in a way that uses less memory. This is good since you reduce the number of bytes on the local machine and being sent to peers. A simple approach to this is to use something called lossless compression. An example usage is as follows: lets say we have an array [a,a,b,c,d,d,d,d,d,d,f,f,f,f]. A simple way to compress this is to replace all the repeating values with a numerical representation. That is,  [a,a,b,c,d,d,d,d,d,d,f,f,f,f] => [2,a,1,b,1,c,6,d,4,f]. Though, it is entirely possible, using this method, for the array to get bigger but that is an edge case. For example, [a,b,c,d,e,f,g] => [1,a,1,b,1,c,1,d,1,e,1,f,1,g]|
| 5.   |  Packet Encrypt and Decrypt<br /><br />Packet encryption is where we alter the bytes which represent our data such that it becomes "scrambled" and ultimately represents something completely useless and/or is now unreadable. A very abstract example is to consider the string "hello". "hello" as an array of bytes is [68, 65, 6c, 6c, 6f]. If we subtract 100d from each of the bytes, we get [04, 01, 08, 08, 0B] which is read as unknown ascii characters and thus the string is now unreadable from a basic transformation of bytes.|
| 6.   |  Data Validator<br /><br />There are two simple forms of data validation which can be used right now, packet validation and type validation. Packet validation ensures the packet structure is correct. For example, at minimum, every packet will have (this is abitrarily made up, though theres a good chance we will use this structure) 18 bytes at the beginning of the packet: 16 byte for the target ivp6 and 2 bytes for the type of request. Any byte after the 2 bytes (short) for the type of request will be apart of the body. Packet validation checks if there is at minimum 18 bytes present. Data validation checks if the number of bytes needed for a request is present. For example, if a request is asking for a certain request that requires x bytes of data to fulfil the request but the body contains < x bytes, then the packet is invalid. |
| 7.   | Data Cache<br /><br />This is a simple cache which keeps requests in memory in the event it can be used again so we don't have to repeatidly calculate the same data. This will be stored by key value as a hash and byte array. |
| 8.   | Data Spooler<br /><br />A spooler is a way to predict a potential incoming request. For example, lets say request X is typically followed by another request Y, then we can automatically queue Y if applicable when X is requested such that Y is available in the cache the moment the request is made in the future.|
| 9.   | Task Pool<br /><br />A task pool is a set of tasks which are executed after a delay. For example, if I want a function to be executed 5 minutes from now, I can add a task into the task pool with the current time + five minutes and then the task pool will execute the task when the time comes. |
| 10.  | Delegates <br /><br />Delegates are a way to pass a function into another function to be executed. A simple example of a delegate is a predicate which resolves to true or false when applied to some set of data. If you've ever used a filter, most likely you've used a predicate and therefore a delegate. For example, [1,2,3,4,5].filter(num -> num < 3) results in [1, 2] where (num -> num < 3) is the predicate.  |
| 11.  | Listeners <br /><br />Listeners, also known as event listeners, are handlers that get called when a specfic condition is met. For example, if you've ever played a browser game, then most likely theres an event listener for pressing a button on your keyboard where the developer than handles the input. A simple event listener like this would use a decorator @onKeyPressEvent and we label the function <br /><br />@onKeyPressEvent<br />function do_something(input)<br />    if input == "k" // do something |
| 12.  | Example Project<br /><br />The example project is a simple project whose design should be as simple as possible and should highlight the simplicity and quickness of using this framework to develop their project from idea to production.|

# Available Utility

| No.  | Utility                                                         |
| ---- | --------------------------------------------------------------- |
| 1.   | **Packet Reader** <br /><br />The packet reader provides an interface for reading bytes sequentially in a safe and efficient way. The reader must be given an array to read from as well as the length of the array. See [dappf::meta::packet_reader](https://github.com/zydee3/DAPPF/blob/master/framework/meta/packet_reader.h) for documentation and [dappf::examples::example_usage_packet_reader](https://github.com/zydee3/DAPPF/blob/master/framework/examples/example_usage_packet_reader.cpp) for example usage(s).
| 2.   | **Packet Writer** <br /><br />The packet writer provides an interface for writing bytes sequentially in a safe and efficient way. The writer encodes most primitive data types and maintains the length of the total number of bytes encoded. See [dappf::meta::packet_writer](https://github.com/zydee3/DAPPF/blob/master/framework/meta/packet_writer.h) for documentation and [dappf::examples::example_usage_packet_writer](https://github.com/zydee3/DAPPF/blob/master/framework/examples/example_usage_packet_writer.cpp) for example usage(s). | 

# Available Internal Overrides
| No.  | Utility                                                         |
| ---- | --------------------------------------------------------------- |
| 1.   | **Packet Encryptor**  | 
| 2.   | **Packet Validator**  | 
| 3.   | **Packet Compressor** |



# Available Event Listeners
Event listeners provides a series of methods provided to the developer to execute certain tasks in addition to some background tasks performed by the framework. A simple example is if the developer implements a logging system which logs every incoming packet. The developer can implement the "on_packet_received" event listener which provides the developer access to an immutable instance of the packet reader which is used to handler the recieved bytes internally. From there, the developer can log the bytes received or a deserialized form of those bytes. All event listeners are of type void.

| No.  | Event Listener                                                  |
| ---- | --------------------------------------------------------------- |
| 1.   | void dappf::meta::event_listeners::[**on_connection_request**](https://github.com/zydee3/DAPPF/blob/master/framework/meta/event_listeners.cpp)(std::string);<br /><br />Called when a request to connect is made to the user. The given string parameter holds the ipv4 address of the requesting node. |
| 2.   | void dappf::meta::event_listeners::[**on_connection_established**](https://github.com/zydee3/DAPPF/blob/master/framework/meta/event_listeners.cpp)(std::string);<br /><br />Called when a previous request to connect has been fulfilled and connection between the two nodes has been established. The given string parameter holds the ipv4 address of the requesting node. |
| 3.   | void dappf::meta::event_listeners::[**on_connection_dropped**](https://github.com/zydee3/DAPPF/blob/master/framework/meta/event_listeners.cpp)(std::string);<br /><br />Called when an existing connection is dropped. The given string parameter holds the ipv4 address of the requesting node. |
| 4.   | void dappf::meta::event_listeners::[**on_packet_received**](https://github.com/zydee3/DAPPF/blob/master/framework/meta/event_listeners.cpp)([dappf::meta::packet_reader](https://github.com/zydee3/DAPPF/blob/master/framework/meta/packet_reader.h));<br /><br />Called when a packet is received from a current established connection.  |
| 5.   | void dappf::meta::event_listeners::[**on_packet_sent**](https://github.com/zydee3/DAPPF/blob/master/framework/meta/event_listeners.cpp)([dappf::meta::packet_reader](https://github.com/zydee3/DAPPF/blob/master/framework/meta/packet_writer.h));<br /><br />Called when a packet is sent to current established neighbors. The packet writer in this state is immutable. | 
