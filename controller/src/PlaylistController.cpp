#include "PlaylistController.hpp"

PlaylistController::PlaylistController(Playlist playlist, PlaylistView view)
    : playlist(playlist), view(view) 
{
}

void PlaylistController::setPlaylist(std::string name)
{
    Playlist PL(name);
    playlist = PL;
}

void PlaylistController::displayPerPage()
{
    view.displayPL(playlist);
}

void PlaylistController::run()
{
    while (true) {
        view.displayPL(playlist);
        
        if (!playlist.hasFiles()) {
            break;
        }

        char input = view.getUserInput();

        if (input == 'P' || input == 'p') {
            playlist.playPL();
            view.displayNowPlaying(playlist.getCurrentFile());
        } else if (input == 'N' || input == 'n') {
            playlist.nextFile();
            view.displayNowPlaying(playlist.getCurrentFile());
        } else if (input == 'R' || input == 'r') {
            playlist.previousFile();
            view.displayNowPlaying(playlist.getCurrentFile());
        } else if (input == 'Q' || input == 'q') {
            playlist.pausePL();
            break;
        } else {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }
}
