#include "PlaylistManager.hpp"
#include <thread>
#include <SDL2/SDL_mixer.h>
void PlaylistManager::createPL(std::string name)
{
    Playlist pl(name);
    std::fstream file(name + ".txt", std::ios::app|std::ios::ate);
    if(file.is_open()) {
        if(file.tellg() == 0){
            file << "Playlist: " << name << "\n";
            file.close();
        }
    }
    pl.loadPL();
    list.push_back(pl);
}

void PlaylistManager::deletePL(std::string& name)
{
    auto it = std::find_if(list.begin(), list.end(), [&](Playlist& f) {
        return f.getName() == name;  
    });

    if(it != list.end()){
        list.erase(it);
        if(remove((name + ".txt").c_str()) == 0) {
            std::cout << "deleted\n";
        }
        
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

void PlaylistManager::changeVolume(int value)
{
    value = (128 * value)/100;
    Mix_VolumeMusic(value);
}


void PlaylistManager::playPL(std::string& name)
{
    for(auto& pl : list){
        if(pl.getName() == name){
            Playlist::activePL = &pl;
            Playlist::activePL->playPL();
        }
    } 
}

void PlaylistManager::pausePL(std::string& name)
{
    for(auto& pl : list){
        if(pl.getName() == name){
            pl.pausePL();
        }
    } 
}

void PlaylistManager::nextPL(std::string& name)
{
    for(auto& pl : list){
        if(pl.getName() == name){
            pl.nextFile();
        }
    } 
}

void PlaylistManager::previousPL(std::string& name)
{
    for(auto& pl : list){
        if(pl.getName() == name){
            pl.previousFile();
        }
    } 
}

void PlaylistManager::resumePL(std::string& name)
{
    for(auto& pl : list){
        if(pl.getName() == name){
            pl.resumePL();
        }
    }
}



Playlist& PlaylistManager::getPL(std::string name)
{
    for(auto& p : list){
        if(p.getName() == name) return p;
    }
}

void PlaylistManager::addFile(std::string name, std::string &path)
{
    Playlist& playlist = getPL(name);
    // If playlist is found
    if (!playlist.getName().empty()) {
        File file(path);
        playlist.addFile(file);

        // Append file path to playlist's text file
        std::ofstream file_out(name + ".txt", std::ios_base::app);
        if (file_out.is_open()) {
            file_out << file.getFilePath() << "\n";
            file_out.close();
        }
        std::cout << "File added to playlist.\n";
    } else {
        std::cout << "Playlist not found.\n";
    }
}

void PlaylistManager::deleteFile(std::string name, int fileIndex)
{
    Playlist& playlist = getPL(name);

    // If playlist is found
    if (!playlist.getName().empty()) {
        if (fileIndex >= 0 && fileIndex < (int)playlist.getFiles().size()) {
            playlist.deleteFile(playlist.getFiles()[fileIndex]);
            
            // Rewrite the playlist's text file without the deleted file
            std::ofstream file_out(name + ".txt");
            if (file_out.is_open()) {
                file_out << "Playlist: " << name << "\n";
                for (auto file : playlist.getFiles()) {
                    file_out << file.getFilePath() << "\n";
                }
                file_out.close();
            }
            
            std::cout << "File deleted.\n";
        } else {
            std::cout << "Invalid file index.\n";
        }
    } else {
        std::cout << "Playlist not found.\n";
    }
}

void PlaylistManager::listFile(std::string name)
{
    Playlist& playlist = getPL(name);

    // If playlist is found
    if (!playlist.getName().empty()) {
        std::vector<File> files = playlist.getFiles();
        if (files.empty()) {
            std::cout << "No files in the playlist.\n";
        } else {
            std::cout << "Files in playlist:\n";
            for (size_t i = 0; i < files.size(); ++i) {
                std::cout << (i + 1) << ". " << files[i].getFilePath() << "\n";
            }
        }
    } else {
        std::cout << "Playlist not found.\n";
    }

}

void PlaylistManager::editMetadata(std::string name, int fileIndex, std::string &key, std::string &value)
{
    Playlist& playlist = getPL(name);

    // If playlist is found
    if (!playlist.getName().empty()) {
        if (fileIndex >= 0 && fileIndex < (int)playlist.getFiles().size()) {
            playlist.editFileMetadata(fileIndex, key, value);
            std::cout << "Metadata updated.\n";
        } else {
            std::cout << "Invalid file index.\n";
        }
    } else {
        std::cout << "Playlist not found.\n";
    }

}
