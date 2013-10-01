chatapp
=======

Easy and secure Chat application

Objectives as on 30th Oct/2013
==========
Completely fun project. 

1. Simple Chat application
2. Secure/encrypted and Fast file transfer
3. Server/client Chat-log Auto-archiving
4. User/Password authentication host user ID or LDAP.
5. File sharing cloude style using Fuse shared files, live editing across all clients.


Outside of current Design
========================
1. GUI application as current release will only have Windows and Linux command line.


Future Goals
================
1. Full GUI
2. Android application
3. Ability to chat on the browser.

Design Layout V-0.1
==============

User Interaction
----------------
Start up:
After executing client application, it will ask for clinet nickname and Server hostname, if no client config is found in home directory. It will open a new terminal listing all online users connected to servers. Once you choose the user, it will send a chat request to the remote user if he/she accepts the communication the conservation will commence.

File Transfer:
If user press zz within 10 ms, it will create a new thread that will ask for file location to be transfered. File transfer will only commence if the remote user agrees to recieve the file. The file will transferd rsync way, ie compress+encrypt and then send. A rolling checksum will be appended at end of the file to ensure safe integrity.

Termination:
Either ctl-c or bb(bye bye) will close the connection with server.

Server Design
--------------
For now, it will be single threaded and will proactor design pattern of boost asio module. For all server info will be on ram using list/vectors till we move it to some light weight nosql database.

Client Connect:
Now client connection requirs no authentication. On connect the server will send list of users already logged in, if the incoming client is the first then it will add the client right into logged user list. The data type will be simple hash/map with nickname and IP.

Communication:
Chat between clients will be via server with AES or DES encryption. Server will create a internal message queue for each client. It will be in FIFO.

File Transfer:
As the file transfer will also have to go through server, it will be directly pushed to respective client blindly. Compression will take care by Client app. We can either choose to have a ssl tunnel or merely encrypt each message.

Chat log:
All chat will be archived on server disk.


