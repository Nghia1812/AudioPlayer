#ifndef FILESYSTEMHANDLER_H
#define FILESYSTEMHANDLER_H

#include <vector>
#include <filesystem>
#include <iostream>

#include "File.hpp"

class FileSystemHandler {
    public:
    FileSystemHandler(std::string path);
    void scanFolder();
    std::vector<std::string> getFiles() {return list;}
    void editFileMetadata(int index, std::string &key,  std::string &value);
    std::string getFileMetadata(int index);
    private:
    //list of files
    std::vector<std::string> list;
    //folder path
    std::string path;

};

#endif