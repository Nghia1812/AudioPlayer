#include "PlaylistManagerView.hpp"

void PlaylistManagerView::displayOptions()
{
    std::cout << "Media menu\n";
    std::cout << "1. Play a playlist\n";
    std::cout << "2. Create a playlist\n";
    std::cout << "3. Delete a playlist\n";
    std::cout << "4. List all playlists\n";
    std::cout << "5. Update a playlist\n";

}

void PlaylistManagerView::displayPL(std::string name)
{
    std::cout << "List of all playlists:\n";
    std::cout << name;
}

char PlaylistManagerView::getUserInput() {
    char choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

std::string PlaylistManagerView::getPLName()
{
    std::cout << "Enter playlist name: ";
    std::cin.ignore();
    std::string name;
    std::getline(std::cin, name);
    return name;
}
