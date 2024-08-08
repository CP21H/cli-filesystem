### Introduction
---
`CLI-Filesystem` is a command line interface that, on a very rudimentary level, experiments with how a file system is created through a command line. This project serves as an application of binary trees in the form of an **M-ary Tree** serving as the background implementation. 

The **M-ary tree** is created through the usage of **Nodes**, where each Node has a name, parent, data if it is a file, and then a vector of Node-pointers, which allows for each node to have multiple 'files' or 'directories' below it, thus making each node a directory.

A node is only classified as a directory if the **data** variable within it is null. If it is not null, then it is a file and thus will not have children. 

---
