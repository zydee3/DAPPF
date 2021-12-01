# DAPPF User Guide

## Compatibility
DAPPF is built on Linux libraries and as such it *must* be run on a Linux machine.

## Installation
Installing the DAPPF framework into your project is a fairly staightforward process. This guide will show you how to add it to your project in only 3 simple steps.

#### 1. Download the source code
The first step is to clone the DAPPF repository into a folder within your project. This can be either the root folder or its own directory
(which is preferred for better organization).

#### 2. Include the Framework Header
The second step is to add include the header file `dappf.h` into your main project file or wherever you need to access/use the framework. This will enable you to use the
functions provided and interact with the framework.

#### 3. Done
This is all that needs to be done in order to "install" the framework into your project. For instructions on how to actually use/implement it, see the **Usage** section below.

## Usage

#### 1. Basic Packet Functionality

The DAPPF framework relies on communication between multiple nodes. In order to do this, we have to be able to send data in an efficient manner through the network.
We do this by writing to and reading from packets.

#### 2. Event Listeners

This framework contains event listeners that allow users to have one of their functions called when a certain event happens. To assign a function to an event, call the `set()` function of the desired event listener with a pointer to the desired function as the argument. The availible event listeners are as follows: `on_connection_dropped`, `on_connection_established`, `on_connection_request`, `on_internal_error`, `on_packet_received`, `on_packet_sent`.

#### 3. Packet Encryption

Encryption is a feature that allows users to encrypt packets as they are being sent throughout the framework. This adds an extra layer of security because
it prevents outside forces or malicious code from being able to access information that they are not privy to. By default, the framework has a simple encrpytion algorithm,
but if you would prefer to use your own method of packet encryption, you can call the encryption functions `set_encryptor()` and `set_decryptor()` and input your own function pointers as arguments. Changing only one of these could lead to serious errors due to conflicts in the encryption and decryption algorithms. If these are not paired properly, data will not be recoverable once encrypted. The ability to modify the encryption algorithms increases the flexibility and security of our framework.

#### 4. Packet Compression

Users will also have the option to implement their own compression algorithms into the framework. By default there is a compression system within DAPPF, but like encryption,
this can be changed by the user. In order to do this, both `set_compressor()` and `set_decompressor()` need to be called with your own function pointers as arguments. Changing only one of these could lead to serious errors due to conflicts in the compression and decompression algorithms. Allowing the user to modify the compression algorithm will allow flexibility between the amount of file compression and the speed of the process.

## Example Project (Prototype) Installation/Usage

#### 1. Download the Executable
Download the executable file `prototype` of this project from GitHub to a local directory. It can be found in `\examples`.

#### 2. Create the First Node
First open up a terminal window and navigate to the directory where the executable is stored. Next, run the command `./prototype 6001` where `6001` is the desired port that you would like to run this instance on. Now an instance of the decentralized application will now be running in that window on port `6001`. This syntax indicates that this will be the first node in the system.

#### 3. Add More Nodes
Open up a new terminal window and navigate to the same directory. Since you want to connect to the same system as the first node, run the command `./prototype 127.0.0.1 6001 6002` where `127.0.0.1` is the ip address of the node you are trying to connect to (in this case it is local), `6001` is the port the node you are trying to connect to is on, and `6002` is the port that you would like to run this new instance on. You should now have two instances connected to the network. 

Repeat step 3 as many times as desired to add additional nodes to the system.

#### 4. Using the Example
You can type any string into the terminal window, and once you hit `enter`, it will be sent to all other nodes in the network and printed. You may have also noticed that all event listeners will be printed when activated. While this is a simple example, it is a good demonstration of our framework in action.

#### Source Code
The source code for this example can be found in the `\environment` directory.
