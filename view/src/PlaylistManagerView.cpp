#include "PlaylistManagerView.hpp"

void PlaylistManagerView::displayOptions()
{
    //std::cout << "\033[2J\033[1;1H";
    std::cout << "Media player menu\n";
    std::cout << "1. Play a playlist\n";
    std::cout << "2. Create a playlist/ Load existing playlist\n";
    std::cout << "3. Delete a playlist\n";
    std::cout << "4. List all playlists\n";
    std::cout << "5. Update a playlist\n";
    std::cout << "6. Exit media player menu\n";

}

void PlaylistManagerView::displayPL(std::string name)
{
    std::cout << "\033[2J\033[1;1H";
    std::cout << "List of all playlists:\n";
    std::cout << name;
}

void PlaylistManagerView::displayUpdateOptions()
{
    std::cout << "Update playlist menu:\n";
    std::cout << "1. Add file\n";
    std::cout << "2. Delete file\n";
    std::cout << "3. List file\n";
    std::cout << "4. Edit file metadata\n";
    std::cout << "5. Exit update playlist menu\n";
}

void PlaylistManagerView::displayPlayerOptions()
{
    //std::cout << "\033[2J\033[1;1H";
    std::cout << "Audio player menu:\n";
    std::cout << "1. Play song\n";
    std::cout << "2. Pause song\n";
    std::cout << "3. Next song\n";
    std::cout << "4. Previous song\n";
    std::cout << "5. Change volume\n";
    std::cout << "6. Resume song\n";
    std::cout << "7. View duration\n";
    std::cout << "8. Exit audio player menu\n";
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

int PlaylistManagerView::getFileIndex()
{
    int index = -1;
    std::cout << "Enter the number of the file: ";
    std::cin >> index;
    return index - 1;
    
}

std::string PlaylistManagerView::getMetadataKey()
{
    std::string key;
    std::cout << "Enter the metadata key to edit (e.g., title, artist): ";
    std::cin >> key;
    return key;
}

std::string PlaylistManagerView::getMetadataValue()
{
    std::string value;
    std::cout << "Enter the new metadata value: ";
    std::cin.ignore();
    std::getline(std::cin, value);
    return value;
}

std::string PlaylistManagerView::getFilePath()
{
    std::string path;
    std::cout << "Enter file path: ";
    std::cin.ignore();
    std::getline(std::cin, path);
    return path;
}

int PlaylistManagerView::getVolumeValue()
{
    int value;
    std::cout << "Enter the new value [0-100]: ";
    std::cin >> value;
    std::cin.ignore();
    return value;
}


