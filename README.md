# Starting Off
The project is built in jetbrain's clion IDE. You should be able to just open the file and compile straight away as the project was set up already for you. Connect your github so you can make pull requests to the main branch.

# DAPPF
I created both the work [example] environment and library itself under a single project. The work enviornment compiles down and ran as an executable. The framework is compiled to a shared library which cannot be ran as a standalone. 

# Framework
Within the framework are four main directories which pertains to each layer of the framework:
 - Layer 1: Net (Communication Layer)
 - Layer 2: Security
 - Layer 3: Data
 - Layer 4: Handlers (Processing)

Within each directory the respective directories are meta files. The meta file will hold meta data to the main files within the module. A meta file is like that of an inner class to a parent class. Using a game as an example, an example of meta data to Player class is PlayerStats which holds the stats of the player. Meta data allows us to break apart classes into smaller more organized classes in order to premote clean code and precent god classes.

# Modules Task Sheet

| No.  | Module                                      | Status        | Who     |
| ---- | ------------------------------------------- | ------------- | ------- |
| 1.   | Network Node Connect and Disconnect         | In Progress   | Kirill |
| 2.   | Documentation Site                          | Incomplete    |  |
| 3.   | Packet Reader and Writer                    | Completed     | Vincent |
| 4.   | Packet Compress and Decompress              | Incomplete    |  |
| 5.   | Packet Encrypt and Decrypt                  | Incomplete    |  |
| 6.   | Data Serializer and Deserializer            | Incomplete    |  |
| 7.   | Data Validator                              | Incomplete    |  |
| 8.   | Data Cache                                  | In Progress   | Vincent |
| 9.   | Data Spooler                                | Incomplete    |  |
| 10.  | Task Pool                                   | Incomplete    |  |
| 11.  | Delegates                                   | Incomplete    |  |
| 12.  | Handlers                                    | Incomplete    |  |
| 13.  | Listeners                                   | Incomplete    |  |
| 14.  | Example Project                             | In Progress   | * |


# Module Functionality

| No.  | Module                                                           |
| ---- | ---------------------------------------------------------------- |
| 1.   |  Network Node Connect and Disconnect <br /><br />This feature handles the connection between any two or more nodes in a network. The questions we ask here are, in the absence of a direct target, how would a new node enter the network? When a node would like to leave the network, it remembers some nodes and is able to use those records to re-enter the network without needing to find a way in like it did when it was a new node. Here we note that it is entirely possible for all records to disconnect prior to the current node re-entering the network, thus it is possible for a non-new node to be subject to new-node entry proceedures of finding an entry point.|
| 2.   |  Documentation Site <br /><br /> We can create a website which has complete live documentation for future developers to use. The idea is since the github is hosted publically, the website can webscrape the repository for comments above functions and generate documentation. This is completely optional and should only be done towards the end.|
| 3.   |  Packet Reader and Writer <br /><br />A packet is a sequence of bytes normally in the form of an array of bytes. Packets contain data represented in bytes and is the general way to send data between a connection. The packet reader accepts bytes and allows you to read 2^n bytes depending on the data type you're trying to read while the packet writer does the opposite and allows you to feed bytes into the writer and then construct the array of bytes when the packet is completed and ready to be sent. |
| 4.   |  Packet Compress and Decompress  <br /><br />Packet Compression is when you take an array of bytes and reduce the total number of bytes in the array. Effectively, you're representing the same data, but in a way that uses less memory. This is good since you reduce the number of bytes on the local machine and being sent to peers. A simple approach to this is to use something called lossless compression. An example usage is as follows: lets say we have an array [a,a,b,c,d,d,d,d,d,d,f,f,f,f]. A simple way to compress this is to replace all the repeating values with a numerical representation. That is,  [a,a,b,c,d,d,d,d,d,d,f,f,f,f] => [2,a,1,b,1,c,6,d,4,f]. Though, it is entirely possible, using this method, for the array to get bigger but that is an edge case. For example, [a,b,c,d,e,f,g] => [1,a,1,b,1,c,1,d,1,e,1,f,1,g]|
| 5.   |  Packet Encrypt and Decrypt<br /><br />Packet encryption is where we alter the bytes which represent our data such that it becomes "scrambled" and ultimately represents something completely useless and/or is now unreadable. A very abstract example is to consider the string "hello". "hello" as an array of bytes is [68, 65, 6c, 6c, 6f]. If we subtract 100d from each of the bytes, we get [04, 01, 08, 08, 0B] which is read as unknown ascii characters and thus the string is now unreadable from a basic transformation of bytes.|
| 6.   |  Data Serializer and Deserializer |
| 7.   |  Data Validator |
| 8.   |  Data Cache |
| 9.   | Data Spooler |
| 10.  | Task Pool |
| 11.  | Delegates |
| 12.  | Handlers |
| 13.  | Listeners |
| 14.  | Example Project|
