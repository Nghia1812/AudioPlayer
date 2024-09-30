#include "PlaylistManager.hpp"

void PlaylistManager::createPL(std::string name)
{
    Playlist pl(name);
    list.push_back(pl);
}

void PlaylistManager::deletePL(std::string& name)
{
    auto it = std::find_if(list.begin(), list.end(), [&](Playlist& f) {
        return f.getName() == name;  
    });

    if(it != list.end()){
        list.erase(it);
        std::cout << "File deleted\n";
    }else {
        std::cout << "File not found\n";
    }
}

std::string PlaylistManager::listPL()
{
    std::string plists;
    for(auto pl : list){
        std::string name = pl.getName() + '\n';
        plists += name;
    }
    return plists;
}

void PlaylistManager::updatePL()
{
    //Playlist add/delete/list files, edit file metadata all go here

}

void PlaylistManager::changeVolume()
{
}

void PlaylistManager::playPL(std::string& name)
{
    //Playlist next, prev, pause, play audio files all go here
    for(auto pl : list){
        if(pl.getName() == name){
            pl.playPL();
        }
    }
    
}
