#include "FileController.hpp"
#include "FileView.hpp"
#include "PlaylistManagerControl.hpp"
#include "PlaylistManagerView.hpp"
#include "PlaylistManager.hpp"


#include <iostream>
#include <string>

int main() {
    FileView fileView;
    FileController fileController(fileView);

    PlaylistManagerView plManagerView;
    PlaylistManager plManagerModel;
    PlaylistManagerControl plManagerControl(plManagerView, plManagerModel);


    int command;

    std::cout << "Welcome to the Media Player CLI Application" << std::endl;
    while (true) {
        std::cout << "\033[2J\033[1;1H";
        
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
            std::cout << "\033[2J\033[1;1H";
            fileController.FileControlMenu();
            break;
        case 2:
            std::cout << "\033[2J\033[1;1H";
            plManagerControl.plManagerMenu();
            break;
        case 3:
            std::cout << "\033[2J\033[1;1H";
            return 1;
        default:
            break;
        }

        
    }

    return 0;
}
