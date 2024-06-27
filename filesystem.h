#ifndef FILESYSTEM_FILESYSTEM_H
#define FILESYSTEM_FILESYSTEM_H

#include <vector>
#include <iostream>
#include <string>

template <typename T>
class Node {
    public:
        std::string name;
        T data;                         // should the Node be a directory, this will be empty
        std::vector<Node*> children;    // should the Node be a file, this will be empty
        Node* parent;

        Node(std::string name, Node* parent = nullptr, T data = NULL) : name(name), parent(parent), data(data){}
};

// FUNCTIONS AS AN M-ARY TREE
template <typename T>
class FileSystem {
    public:
        /*
         *  //- CONSTRUCTORS
         * */
        // Default Constructor
        FileSystem() {
            root = new Node<T>("/");
            currentDirectory = root;
        }

        // Destructor
        ~FileSystem() {
            delete root;
        }


        /*
         *  //- DIRECTORIES
         * */
        void addDirectory(const std::string& dirName) {

        }

        void changeDirectory(const std::string& dirName) {

        }

        void listDirectories() {

        }


        /*
        *  //- FILES
        * */
        void addFile(const std::string& fileName, const T fileData) {

        }

        void getFileData() {

        }


        /*
         *  //- MISC.
         * */
        // getRoot() - Used to return to root directory
        Node<T>* getRoot() {
            return root;
        }








    private:
        Node<T>* root;
        Node<T>* currentDirectory;
};


#endif //FILESYSTEM_FILESYSTEM_H