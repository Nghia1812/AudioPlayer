#ifndef PLAYLISTCONTROLLER_H
#define PLAYLISTCONTROLLER_H
#include "Playlist.hpp"
#include "PlaylistView.hpp"

class PlaylistController {
private:
    Playlist playlist;
    PlaylistView view;

public:
    PlaylistController(){};
    PlaylistController(Playlist playlist, PlaylistView view);
    void setPlaylist(std::string name);
    void displayPerPage();
    void run();
};

#endif
