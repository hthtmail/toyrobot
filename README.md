# Toy Robot

This project created a toy robot which can accept interactive command or command script to move on a 5*5 table.

##Prepare for Build

To build this project, you need setup a Linux machine (e.g. Ubuntu 20.04) and install the following tools:
g++, make, cmake
for Ubuntu, use this command to install these depencencies:
```
$sudo apt install g++ make cmake
```

##How to Build

Clone this repo to your local machine, and run these commands to build the project:
```
$mkdir build && cd build && cmake .. && make
```

##How to Run

There are 2 modes to run it, interactive shell or running script

###Interactive Shell Mode

Directly run the application, it will enter the interactive shell mode:
```
$./toyrobot
>
```
In this mode, you can input the command to control the robot, the valid commands can be:
```
place <x> <y> <f>
move
left
right
report
exit
```

###Script Mode

Directly run the application, it will enter the interactive shell mode:
```
$./toyrobot <script file>
```
The script file is a text file which can contains any above commands except 'exit'. Each command should be a single line