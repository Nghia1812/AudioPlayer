#include "Playlist.hpp"
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

Playlist::Playlist(std::string name = "default")
    :name(name), currentIndex(0), isPlaying(false)
{
}

void Playlist::addFile(File &file)
{
    files.push_back(file);
}

void Playlist::nextFile()
{
    if(!files.empty()){
        currentIndex = (currentIndex + 1) % files.size();
        files[currentIndex].play();
    } else {
        std::cout << "No more files to play\n";
    }
}

void Playlist::previousFile()
{
    if (!files.empty()) {
        if (currentIndex == 0) {
            currentIndex = files.size() - 1;
        } else {
            currentIndex--;
        }
        files[currentIndex].play();
    } else {
        std::cout << "No more files in the playlist." << std::endl;
    }
}



void Playlist::deleteFile(File& file)
{
    auto it = std::find_if(files.begin(), files.end(), [&](File& f) {
        return f.getFilePath() == file.getFilePath();  
    });

    if(it != files.end()){
        files.erase(it);
        std::cout << "File deleted\n";
    }else {
        std::cout << "File not found\n";
    }
}

void Playlist::playPL()
{
    // SDL init
    if(SDL_Init(SDL_INIT_AUDIO) < 0){
        throw std::runtime_error("SDL can't init: " + std::string(SDL_GetError()));
    }

    // Mixer init
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2,2048) < 0){
        SDL_Quit();
        throw std::runtime_error("SDL can't init: "+ std::string(Mix_GetError()));
    }
    isPlaying = true;
    files[currentIndex].play();
}

void Playlist::pausePL()
{
    files[currentIndex].pause();
    isPlaying = false;
}

std::string Playlist::getName()
{
    return name;
}

std::vector<File> Playlist::getFiles()
{
    return files;
}

File Playlist::getCurrentFile()
{
    return files[currentIndex];
}

bool Playlist::hasFiles()
{
    return files.empty();
}

void Playlist::editFileMetadata(int fileIndex, std::string &key, std::string &value) {
    if (fileIndex < 0 || fileIndex >= files.size()) {
        std::cout << "Invalid file index.\n";
        return;
    }
    files[fileIndex].editMetadata(key, value);
}