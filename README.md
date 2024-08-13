### Introduction
---
`CLI-Filesystem` is a command line interface that, on a very rudimentary level, experiments with how a file system is created through a command line. This project serves as an application of binary trees in the form of an **M-ary Tree** serving as the background implementation. 

The **M-ary tree** is created through the usage of **Nodes**, where each Node has a name, parent, data if it is a file, and then a vector of Node-pointers, which allows for each node to have multiple 'files' or 'directories' below it, thus making each node a directory.

A node is only classified as a directory if the **data** variable within it is null. If it is not null, then it is a file and thus will not have children. 



### Filesystem.h
---
The File system created for this program is done through the implementation of both a **Node** class and a **FileSystem** class, which serves as an implementation of the **M-ary tree**.

> **Node contains**:
>- `name` represented as a string
>- `parent` represented as a Node pointer
>- `data` represented as a templated type
>- `children` represented as a vector of Node pointers

> **Filesystem contains**:
>- `root` represented as a Node of type T pointer
>- `currentDirectory` represented as a Node of type T pointer
>- `history` represented as a stack of string variables

As general functionalities for a command line file system, the Filesystem class contains the following functions listed below, all of which are aptly named for their function:
>- addDirectory()
>- removeDirectory()
>- changeDirectory()
>- listDirectories()
>- addFile()
>- removeFile()
>- getFileData()
>- getRoot()
>- storeHistory()
>- printHistory()



### Main.cpp
---
...
