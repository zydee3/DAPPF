# DAPPF User Guide

## Installation
Installing the DAPPF framework into your project is a fairly staightforward process. This guide will show you how to add it to your project in only 3 simple steps.

#### 1. Download the source code
The first step is to clone the DAPPF repository into a folder within your project. This can be either the root folder or its own directory
(which is preffered for better organization).

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

This framework contains event listeners that allow users to (fff).

#### 3. Packet Encryption

Encryption is a feature that allows users to encrypt packets as they are being sent throughout the framework. This adds an extra layer of security because
it prevents outside forces or malicious code from being able to access information that they are not privy to. By default, the framework has a simple encrpytion algorithm,
but if you would prefer to use your own method of packet encryption, you can override the encryption functions `get_encryptor()` and `get_decryptor()`. Changing only one
of these could lead to serious errors due to conflicts in the encryption and decryption algorithms. If these are not paired properly, data will not be recoverable once
encrpyted. The ability to modify the encrpytion algorithms increases the flexibility and security of our framework.

#### 4. Packet Compression

Users will also have the option to implement their own compression algorithms into the framework. By default there is a compression system within DAPPF, but like encryption,
this can be overridden by the user. In order to do this, both `compress()` and `decompress()` need to be overriden. Changing only one of these could lead to serious
errors due to conflicts in the compression and decompression algorithms. Allowing the user to modify the compression algorithm will allow flexibility between the amount of file
compression and the speed of the process.

## Example Installation/Usage

#### 1. Download the Source Code
f

#### 2. Run the Code
f

#### 3. Add More Instances
Repeat step 2 as many times as desired to add additional nodes to the system.

#### 4. Send Data?
f

#### 5. Read Data?
f
