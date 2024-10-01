#ifndef PLAYLIST_H
#define PLAYLIST_H
#include <fstream>
#include <iostream>
#include "File.hpp"

class Playlist {
    private:
    //vector of files in playlist
    std::vector<File> files;
    std::string name;
    int currentIndex;
    bool isPlaying;
    
    public:
    Playlist(){}
    Playlist(std::string name);

    //playlist options
    void addFile(File& file);
    void nextFile();
    void previousFile();
    void deleteFile(File& file);
    void playPL();
    void pausePL();
    void resumePL();
    void loadPL();

    void editFileMetadata(int fileIndex, std::string &key, std::string &value);

    std::string getName();
    std::vector <File> getFiles();
    File getCurrentFile();
    bool hasFiles();

    static Playlist* activePL;
    static void musicFinishedCallback() {
        activePL->playNext();
    }
    void playNext(){
        currentIndex = (currentIndex + 1) % files.size();
        files[currentIndex].play();
    }
};


#endif