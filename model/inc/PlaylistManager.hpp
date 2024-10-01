#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H
#include <algorithm>
#include <vector>
#include <fstream>
#include "Playlist.hpp"

class PlaylistManager{
    private:
    std::vector<Playlist> list;


    public:
    PlaylistManager(){}
    void createPL(std::string name);
    void deletePL(std::string& name);
    std::string listPL();
    void changeVolume();
    void playPL(std::string&);
    void pausePL(std::string&);
    void nextPL(std::string&);
    void previousPL(std::string&);
    void resumePL(std::string&);
    Playlist& getPL(std::string name);

    void addFile(std::string name, std::string& path);
    void deleteFile(std::string name, int fileIndex);
    void listFile(std::string name);
    void editMetadata(std::string name, int fileIndex, std::string& key, std::string& value);
};

#endif