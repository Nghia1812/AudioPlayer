#ifndef PLAYLISTMANAGERCONTROL_H
#define PLAYLISTMANAGERCONTROL_H
#include "PlaylistManagerView.hpp"
#include "PlaylistManager.hpp"
#include "Playlist.hpp"

class PlaylistManagerControl{
    private:
    PlaylistManagerView view;
    PlaylistManager model;

    public:
    PlaylistManagerControl(PlaylistManagerView view, PlaylistManager model);
    void createPL();
    void playPL();
    void deletePL();
    void updatePL();
    void listPL();
    void plManagerMenu();






};


#endif