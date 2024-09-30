#ifndef PLAYLISTMANAGERVIEW_H
#define PLAYLISTMANAGERVIEW_H

#include <iostream>
#include <string>

class PlaylistManagerView {
    public:
    void displayOptions();
    void displayPL(std::string);


    char getUserInput();
    std::string getPLName();
    
};



#endif