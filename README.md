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

```
No.  | Module                                      | Status        | Who
-----|---------------------------------------------|---------------| :-------------
1.   | Network Node Connect and Disconnect         | In Progress   | Kirill
2.   | Network Node Analyzer                       | Incomplete    | 
3.   | Network API                                 | In Progress   | Garrett
4.   | Packet Reader and Writer                    | Completed     | Vincent
5.   | Packet Compress and Decompress              | Incomplete    | 
6.   | Packet Encrypt and Decrypt                  | Incomplete    | 
7.   | Data Serializer and Deserializer            | Incomplete    | 
8.   | Data Validator                              | Incomplete    | 
9.   | Data Cache                                  | In Progress   | Vincent
10.  | Data Spooler                                | Incomplete    |
11.  | Task Pool                                   | Incomplete    |
12.  | Delegates                                   | Incomplete    |
13.  | Handlers                                    | Incomplete    | 
14.  | Listeners                                   | Incomplete    |
15.  | Example Project                             | In Progress   | *
```

# Module Functionality

1.  Network Node Connect and Disconnect
2.  Network Node Analyzer
3.  Network API
4.  Packet Reader and Writer
5.  Packet Compress and Decompress
6.  Packet Encrypt and Decrypt
7.  Data Serializer and Deserializer
8.  Data Validator
9.  Data Cache 
10. Data Spooler
11. Task Pool 
12. Delegates 
13. Handlers
14. Listeners
15. Example Project 
