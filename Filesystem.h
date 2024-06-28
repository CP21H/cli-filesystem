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

        Node(std::string name, Node* parent = nullptr, T data = T()) : name(name), parent(parent), data(data){}
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
            // parameters: name, directory(parent), data
            Node<T>* newDir = new Node(dirName, currentDirectory);
            currentDirectory->children.push_back(newDir);
        }

        void changeDirectory(const std::string& dirName) {
            // move back to parent directory
            if (dirName == "..") {
                // if the currentDirectory != the root of the file system
                if (currentDirectory->parent != nullptr) {
                    currentDirectory = currentDirectory->parent;
                }
            } else {
                for (auto child : currentDirectory->children) {
                    if (child->name == dirName) {
                        currentDirectory = child;
                        return;
                    }
                }
                std::cout << "Directory not found.\n" << std::endl;
            }
        }

        void listDirectories() {
            for (auto child : currentDirectory->children) {
                std::cout << child->name << " ";
            }
            std::cout << "\n";
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