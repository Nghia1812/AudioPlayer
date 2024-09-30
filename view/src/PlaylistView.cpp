#include "PlaylistView.hpp"

void PlaylistView::displayPL(Playlist &PL)
{
    std::cout << "Playlist: " << PL.getName() << std::endl;
    auto files = PL.getFiles();
    
    if (files.empty()) {
        std::cout << "No files in the playlist." << std::endl;
        return;
    }

    for (size_t i = 0; i < files.size(); ++i) {
        std::cout << (i + 1) << ". " << files[i].getFilePath() << std::endl;
    }
}

void PlaylistView::displayNowPlaying(File file)
{
    std::cout << "Now playing: " << file.getFilePath() << std::endl;
}

char PlaylistView::getUserInput()
{
    char input;
    std::cout << "Enter choice (P: Play, N: Next, R: Previous, Q: Quit): ";
    std::cin >> input;
    return input;
}

void PlaylistView::displayUpdateOptions()
{
    std::cout << "--Update File Menu--\n";
    std::cout << "1. Add files\n";
    std::cout << "2. List files\n";
    std::cout << "5. Edit metadata of files\n";
    std::cout << "6. View metadata of files\n";

}

