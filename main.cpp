#include <iostream>
#include <string>
#include "Filesystem.h"

void init_menu();
void cli(FileSystem<std::string>& fs);
void help_menu();

int main() {
    FileSystem<std::string> fs;
    init_menu();
    cli(fs);
    return 0;
}

void init_menu() {
    std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
    std::cout << "%                              %" << std::endl;
    std::cout << "%       CLI - FILE SYSTEM      %" << std::endl;
    std::cout << "%        Cristhian Prado       %" << std::endl;
    std::cout << "%           run 'help'         %" << std::endl;
    std::cout << "%                              %" << std::endl;
    std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
    std::cout << std::endl;
}

void help_menu() {
    std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;
    std::cout << "%                              %" << std::endl;
    std::cout << "%           HELP MENU          %" << std::endl;
    std::cout << "%                              %" << std::endl;
    std::cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << std::endl;

    std::cout << "\n";
    std::cout << "%%% LIST OF COMMANDS" << std::endl;
    std::cout << "cd - change directory" << std::endl;
    std::cout << "ls - lists directory contents" << std::endl;
    std::cout << "mkdir - make directory" << std::endl;
    std::cout << "rmdir - remove directory" << std::endl;
    std::cout << "mkfil - make file" << std::endl;
    std::cout << "rmfil - remove file" << std::endl;
    std::cout << "peek - view file contents" << std::endl;
    std::cout << "history - list command history" << std::endl;
    std::cout << "q - quit CLI" << std::endl;
    std::cout << "\n";
}

void cli(FileSystem<std::string> &fs) {
    std::string clInput;
    std::string command;
    std::string file;
    std::string fileData;

    do {
        std::getline(std::cin, clInput);
        fs.storeHistory(clInput);

        command.clear();
        file.clear();
        fileData.clear();

        int i;
        // HANDLE COMMAND IDENTIFICATION
        for (i = 0; i < clInput.size() && clInput[i] != ' '; i++) {
            command.push_back(clInput[i]);
        }
        i++;
        // HANDLE FILE IDENTIFICATION
        for (i; i < clInput.size() && clInput[i] != ' '; i++) {
            file.push_back((clInput[i]));
        }
        i++;
        // HANDLE FILE_DATA IDENTIFICATION
        for (i; i < clInput.size(); i++) {
            fileData.push_back(clInput[i]);
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
        } else if (command == "mkfil") {
            if (file.empty()) {
                std::cout << "Error: Invalid Command Usage." << std::endl;
                std::cout << "Format: mkfil [FILE_NAME] [DATA]" << std::endl;
            } else {
                fs.addFile(file, fileData);
            }
        } else if (command == "rmfil") {
            if (file.empty()) {
                std::cout << "Error: Invalid Command Usage." << std::endl;
                std::cout << "Format: rmfil [FILE_NAME]" << std::endl;
            } else {
                fs.removeFile(file);
            }
        } else if (command == "peek") {
            if (file.empty()) {
                std::cout << "Error: Invalid Command Usage." << std::endl;
                std::cout << "Format: peek [FILE_NAME]" << std::endl;
            } else {
                fs.getFileData(file);
            }
        } else if (command == "history") {
            fs.printHistory();
        } else if (command == "help") {
            help_menu();
        } else if (command == "q") {
            std::cout << "Shutting Down..." << std::endl;
        } else {
            std::cout << "Error: Invalid Command." << std::endl;
        }


        // if those chars make up a valid command, move to proper command logic / code
        // if that command requires a directory name / file name then parse chars after white space
    } while (command != "q" && command != "Q");
}