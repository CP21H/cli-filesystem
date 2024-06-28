#include <iostream>
#include "Filesystem.h"

int main() {
    FileSystem<std::string> fs;

    fs.addDirectory("root");
    fs.addDirectory("childNode1");
    fs.addDirectory("childNode2");

    fs.listDirectories();

    fs.changeDirectory("childNode1");
    fs.addDirectory("grandchildNode1");
    fs.listDirectories();

    fs.changeDirectory("..");
    fs.listDirectories();

    return 0;
}
