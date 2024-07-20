#include <iostream>
#include <string>
#include "Filesystem.h"

void init_menu();
void help_pages();
void cli(FileSystem<std::string> fs);

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
    cli(fs);

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

void cli(FileSystem<std::string> fs) {
    std::string clInput;
    std::string command;
    std::string file;

    do {
        std::getline(std::cin, clInput);
        fs.storeHistory(clInput);

        command.clear();
        file.clear();

        int i;
        // HANDLE COMMAND IDENTIFICATION
        for (i = 0; i < clInput.size() && clInput[i] != ' '; i++) {
            command.push_back(clInput[i]);
        }
        i++;
        // HANDLE FILE IDENTIFICATION
        for (i; i < clInput.size(); i++) {
            file.push_back((clInput[i]));
        }

        //- COMMAND LOGIC -//
        if (command == "cd") {
            if (file.empty()) {
                std::cout << "Error: Invalid Command Usage." << std::endl;
                std::cout << "Format: cd [FILE_NAME]" << std::endl;
            } else {
                fs.changeDirectory(file);
            }
        } else if (command == "ls") {
            fs.listDirectories();
        } else if (command == "mkdir") {
            if (file.empty()) {
                std::cout << "Error: Invalid Command Usage." << std::endl;
                std::cout << "Format: mkdir [DIRECTORY_NAME]" << std::endl;
            } else {
                fs.addDirectory(file);
            }
        } else if (command == "rmdir") {
            if (file.empty()) {
                std::cout << "Error: Invalid Command Usage." << std::endl;
                std::cout << "Format: rmdir [DIRECTORY_NAME]" << std::endl;
            } else {
                fs.removeDirectory(file);
            }
        } else if (command == "history") {
            fs.printHistory();
        } else {
            std::cout << "Error: Invalid Command." << std::endl;
        }


        // if those chars make up a valid command, move to proper command logic / code
        // if that command requires a directory name / file name then parse chars after white space
    } while (clInput != "q" && clInput != "Q");
}