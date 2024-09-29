#ifndef PLAYLIST_H
#define PLAYLIST_H

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

    void editFileMetadata(int fileIndex, std::string &key, std::string &value);

    std::string getName();
    std::vector <File> getFiles();
    File getCurrentFile();
    bool hasFiles();
};



#endif