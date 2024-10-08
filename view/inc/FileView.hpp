#ifndef CLIVIEW_H
#define CLIVIEW_H

#include <iostream>
#include <vector>
class FileView{
    public:
    void displayFiles(const std::vector<std::string>& files, int currentPage, int totalPages);
    char getUserInput();
    int getFileSelection();
    std::string getMetadataKey();
    std::string getMetadataValue();
    void displayMetadataUpdated();
    void displayOptions();
    void displayMetadata(std::string & data);

    void clearScreen(){std::cout << "\033[2J\033[1;1H";}
};

#endif