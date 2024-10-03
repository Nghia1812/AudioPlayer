#ifndef PLAYLISTMANAGERVIEW_H
#define PLAYLISTMANAGERVIEW_H

#include <iostream>
#include <string>
#include <fstream>

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
    int getVolumeValue();

    void clearScreen(){std::cout << "\033[2J\033[1;1H";}
    void viewDuration(int elapsed, int total){
        std::cout << elapsed << "s / " << total << "s\n";
        std::cout.flush();  // Ensure output is written immediately    
    }

};




#endif