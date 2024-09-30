#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H

#include "FileSystemHandler.hpp"
#include "FileView.hpp"

class FileController{
    private:
    FileSystemHandler fileSystemControl;
    FileView view;
    public:

    //set path to the running folder of app
    FileController(FileView view) 
    : fileSystemControl("."), view(view){}

    void listFile();
    void editMetadata();
    void FileControlMenu();

    void displayFileMetadata();
};

#endif