#include <iostream>
#include <stdlib.h>
#include <conio.h>
#include <unistd.h>
#include <windows.h>
// windows.h for Win32 and unistd.h for Unix.


int Lock();
int Unlock();
std::string getpass();


int main() {

    char option;
    std::cout << "File Locker is running." << std::endl;
    std::cout << "Please choose an action: " << std::endl;
    std::cout << " 1: Lock File" << std::endl;
    std::cout << " 2: Unlock File" << std::endl;
    option = _getch();

    if (option == '1') {
        Lock();
        std::cout << "The file has been locked." << std::endl;
        // Then exit the program after 3 secs.
        sleep(3);

    } else if (option == '2') {
        std::string pass = "";
        std::cout << "Please enter your password:" << std::endl;
        pass = getpass();
        // Change to your password
        if (pass == "1234") {
                Unlock();
                std::cout << "\nFile unlocked." << std::endl;
                sleep(3);
            } else {
            std::cout << "\nThe entered password is incorrect." << std::endl;
            sleep(3);
        }

    } else {
        std::cout << "The option selected is invalid." << std::endl;
        sleep(3);
    }
    return 0;
}


// Can be applied to any file format 
int Lock() {
    system("ren File.zip locked.ans");
    system("attrib +h +s locked.ans");
    return 0;
}


int Unlock() {
    system("attrib -s -h locked.ans");
    system("ren locked.ans File.zip");
    return 0;
}


// Password configuration for the user input
std::string getpass() {

    std::string pass = "";
    char ch;
    ch = _getch();

    while (ch != 13) {
        if (ch != 8) {
            pass.push_back(ch);
            std::cout << "*";
        } else if (pass.length() > 0) {
            pass.pop_back();
            std::cout << "\b \b";
        }
        ch = _getch();
    }
    return pass;
}