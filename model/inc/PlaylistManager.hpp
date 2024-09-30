#ifndef PLAYLISTMANAGER_H
#define PLAYLISTMANAGER_H
#include <algorithm>
#include <vector>
#include "Playlist.hpp"

class PlaylistManager{
    private:
    std::vector<Playlist> list;


    public:
    PlaylistManager(){}
    void createPL(std::string name);
    void deletePL(std::string& name);
    std::string listPL();
    void updatePL();
    void changeVolume();
    void playPL(std::string&);
};

#endif