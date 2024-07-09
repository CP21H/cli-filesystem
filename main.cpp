#include <iostream>
#include "Filesystem.h"

void init_menu();
void help_pages();
void cli();

int main() {
    FileSystem<std::string> fs;

    /*
    fs.addDirectory("root");
    fs.addDirectory("childNode1");
    fs.addDirectory("childNode2");

    fs.listDirectories();

    fs.changeDirectory("childNode1");
    fs.addDirectory("grandchildNode1");
    fs.listDirectories();

    fs.changeDirectory("..");
    fs.listDirectories();

    fs.changeDirectory("root");
    fs.addFile("subrootFile", "12");
    fs.listDirectories();

    fs.getFileData("subrootFile");
    */

    init_menu();

    return 0;
}

void init_menu() {
    std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
    std::cout << "%                              %" << std::endl;
    std::cout << "%       CLI - FILE SYSTEM      %" << std::endl;
    std::cout << "%        Cristhian Prado       %" << std::endl;
    std::cout << "%                              %" << std::endl;
    std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
    std::cout << std::endl;
}

void help_pages() {

}

void cli() {
    std::string clInput;

    do {
        // make a char by char parser here that takes in user input
        // and then once it reaches the first white space, creates a command out of those chars

        // if those chars make up a valid command, move to proper command logic / code

        // if that command requires a directory name / file name then parse chars after white space
    } while (clInput != "q" && clInput != "Q");
}