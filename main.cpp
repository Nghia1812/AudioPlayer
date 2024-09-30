#include "FileController.hpp"
#include "FileView.hpp"


#include "PlaylistController.hpp"
#include "PlaylistView.hpp"


#include "PlaylistManagerControl.hpp"
#include "PlaylistManagerView.hpp"
#include "PlaylistManager.hpp"


#include <iostream>
#include <string>

int main() {
    FileView fileView;
    FileController fileController(fileView);


    // PlaylistView playlistView;
    // PlaylistController playlistController;

    PlaylistManagerView plManagerView;
    PlaylistManager plManagerModel;
    PlaylistManagerControl plManagerControl(plManagerView, plManagerModel);


    int command;

    std::cout << "Welcome to the Media Player CLI Application" << std::endl;
    while (true) {
        std::cout << "\nEnter a command:\n";
        std::cout << "1 - System file menu\n";
        std::cout << "2 - Media menu\n";
        std::cout << "3 - Exit\n";
        std::cout << ">> ";
        std::cin >> command;
        std::cin.ignore();
        switch (command)
        {
        case 1:
            fileController.FileControlMenu();
            break;
        case 2:
            plManagerControl.plManagerMenu();
            break;
        case 3:
            std::cout << "Exit";
            return 1;
        default:
            break;
        }

        
    }

    return 0;
}
