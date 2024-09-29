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
};

#endif