#ifndef PLAYLISTVIEW_H
#define PLAYLISTVIEW_H

#include "Playlist.hpp"

class PlaylistView{
    public:
    void displayPL(Playlist& PL);
    void displayNowPlaying(File file);
    char getUserInput();
    void displayUpdateOptions();
    
};


#endif