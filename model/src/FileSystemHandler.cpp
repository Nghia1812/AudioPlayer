#include "FileSystemHandler.hpp"

FileSystemHandler::FileSystemHandler(std::string path)
    : path(path)
{
    scanFolder();
}

void FileSystemHandler::scanFolder()
{
    //get all file name in folder
    for(auto entry : std::filesystem::recursive_directory_iterator(path)){
        if(entry.is_regular_file()){
            std::string fPath = entry.path().string();
            list.push_back(fPath);
        }
    }
}

void FileSystemHandler::editFileMetadata(int index, std::string &key, std::string &value) {
    if (index >= 0 && index < list.size()) {
        File file(list[index]);
        file.editMetadata(key, value);
        std::cout << "Metadata for file: " << list[index] << " has been updated.\n";
    } else {
        std::cout << "Invalid file index.\n";
    }
}

std::string FileSystemHandler::getFileMetadata(int index)
{
    if (index >= 0 && index < list.size()) {
        File file(list[index]);
        return file.getMetadata();
    } else {
        return "Invalid file index.\n";
    }
}
