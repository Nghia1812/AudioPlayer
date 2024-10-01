#ifndef PLAYLISTMANAGERVIEW_H
#define PLAYLISTMANAGERVIEW_H

#include <iostream>
#include <string>

class PlaylistManagerView {
    public:
    void displayOptions();
    void displayPL(std::string);
    void displayUpdateOptions();
    void displayPlayerOptions();


    char getUserInput();
    std::string getPLName();
    int getFileIndex();
    std::string getMetadataKey();
    std::string getMetadataValue();
    std::string getFilePath();

};



#endif