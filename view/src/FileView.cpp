#include "FileView.hpp"

void FileView::displayFiles(const std::vector<std::string> &files, int currentPage, int totalPages)
{
    int startIdx = currentPage * 25;
    int endIdx = std::min(startIdx + 25, (int)files.size());
    std::cout << "Files (Page " << (currentPage + 1) << " of " << totalPages << ")\n";
    std::cout << "------------------------------------------\n";

    for (int i = startIdx; i < endIdx; ++i) {
        std::cout << (i + 1) << ". " << files[i] << std::endl;
    }

    std::cout << "\nOptions:\n";
    if (currentPage > 0) {
        std::cout << "P - Previous page\n";
    }
    if (currentPage < totalPages - 1) {
        std::cout << "N - Next page\n";
    }
    std::cout << "Q - Quit\n";
}

char FileView::getUserInput() {
    char choice;
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    return choice;
}

int FileView::getFileSelection()
{
    int index = -1;
    std::cout << "Enter the number of the file: ";
    std::cin >> index;
    return index - 1;
}

std::string FileView::getMetadataKey()
{
    std::string key;
    std::cout << "Enter the metadata key to edit (e.g., title, artist): ";
    std::cin >> key;
    return key;
}

std::string FileView::getMetadataValue()
{
    std::string value;
    std::cout << "Enter the new metadata value: ";
    std::cin.ignore();
    std::getline(std::cin, value);
    return value;
}

void FileView::displayMetadataUpdated()
{
    std::cout << "Metadata has been successfully updated.\n";
}

void FileView::displayOptions()
{
    std::cout << "\033[2J\033[1;1H";
    std::cout << "--System File Menu--\n";
    std::cout << "1. View files\n";
    std::cout << "2. Edit metadata of files\n";
    std::cout << "3. View metadata of files\n";
    std::cout << "4. Exit system file menu\n";

}

void FileView::displayMetadata(std::string &data)
{
    std::cout << data << std::endl;
}
