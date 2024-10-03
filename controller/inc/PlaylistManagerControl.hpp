#ifndef PLAYLISTMANAGERCONTROL_H
#define PLAYLISTMANAGERCONTROL_H
#include "PlaylistManagerView.hpp"
#include "PlaylistManager.hpp"
#include <thread>

class PlaylistManagerControl{
    private:
    PlaylistManagerView view;
    PlaylistManager model;


    std::thread durationThread;
    bool isPlaying;
    int totalDuration;
    int elapsed;

    public:
    PlaylistManagerControl(PlaylistManagerView view, PlaylistManager model);
    void createPL();
    void playPL();
    void deletePL();
    void updatePL();
    void listPL();
    void plManagerMenu();

    void updateDuration();






};


#endif