#include "FileController.hpp"
#include "FileView.hpp"
#include "PlaylistController.hpp"
#include "PlaylistView.hpp"
#include <iostream>
#include <string>

int main() {
    FileView fileView;
    FileController fileController(fileView);


    // PlaylistView playlistView;
    // PlaylistController playlistController;
    

    int command;

    std::cout << "Welcome to the Media Player CLI Application" << std::endl;
    while (true) {
        std::cout << "\nEnter a command:\n";
        std::cout << "1 - System file menu\n";
        std::cout << "2 - Playlist menu\n";
        std::cout << "3 - View a playlist\n";
        std::cout << "4 - Play a playlist\n";
        std::cout << "5 - Exit\n";
        std::cout << ">> ";
        std::cin >> command;
        std::cin.ignore();
        switch (command)
        {
        case 1:
            fileController.FileControlMenu();
            break;
        case 5:
            std::cout << "Exit";
            break;
        default:
            break;
        }

        
    }

    return 0;
}
