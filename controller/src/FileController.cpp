#include "FileController.hpp"

void FileController::listFile()
{
    //list all files got from FileSystemHandler
    std::vector<std::string> files = fileSystemControl.getFiles();
    int currentPage = 0;
    const int totalPages = (files.size() + 24) / 25;

    while (true) {
        view.displayFiles(files, currentPage, totalPages);
        char choice = view.getUserInput();

        if (choice == 'P' || choice == 'p') {
            if (currentPage > 0) {
                currentPage--;
            }
        } else if (choice == 'N' || choice == 'n') {
            if (currentPage < totalPages - 1) {
                currentPage++;
            }
        } else if (choice == 'Q' || choice == 'q') {
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }
}

void FileController::editMetadata()
{
    //get file index, key, value
    int fileIndex = view.getFileSelection();

    std::string key = view.getMetadataKey();
    std::string value = view.getMetadataValue();

    fileSystemControl.editFileMetadata(fileIndex, key, value);

    view.displayMetadataUpdated();
}


void FileController::FileControlMenu()
{
    while(true){
        view.displayOptions();
        char choice = view.getUserInput();
        switch (choice)
        {
        case '1':
            view.clearScreen();
            listFile();
            break;
        case '2':
            view.clearScreen();
            editMetadata();
            break;
        case '3':
            view.clearScreen();
            displayFileMetadata();
            break;
        case '4':
            return;
        default:
            break;
        }
    }
}

void FileController::displayFileMetadata()
{
    int fileIndex = view.getFileSelection();
    std::string metadata = fileSystemControl.getFileMetadata(fileIndex);
    view.displayMetadata(metadata);
}
