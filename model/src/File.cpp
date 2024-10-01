#include "File.hpp"

#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

File::File(std::string path) : filePath(path)
{
    determineFileType();
    loadMetadata();
}

void File::loadMetadata()
{
if (fileType == "audio") {
    TagLib::FileRef fileRef(filePath.c_str());

    if (!fileRef.isNull() && fileRef.tag()) {
        TagLib::Tag *tag = fileRef.tag();

        title = tag->title().to8Bit(true);
        artist = tag->artist().to8Bit(true);
        //album = tag->album().to8Bit(true);
        //genre = tag->genre().to8Bit(true);

        // Get audio properties (like duration)
        if (fileRef.audioProperties()) {
            TagLib::AudioProperties *properties = fileRef.audioProperties();
            duration = properties->length();
            codec = "Unknown";  // TagLib doesn't provide codec info directly
        } else {
            duration = 0;
        }
    }
} else if (fileType == "video") {
    // Video metadata extraction
}
}

void File::editMetadata(std::string key, std::string value)
{
    if (fileType == "audio") {
    TagLib::FileRef fileRef(filePath.c_str());

    if (!fileRef.isNull() && fileRef.tag()) {
        TagLib::Tag *tag = fileRef.tag();

        if (key == "title") {
            tag->setTitle(TagLib::String(value, TagLib::String::UTF8));
        } else if (key == "artist") {
            tag->setArtist(TagLib::String(value, TagLib::String::UTF8));
        } else if (key == "album") {
            tag->setAlbum(TagLib::String(value, TagLib::String::UTF8));
        } else if (key == "genre") {
            tag->setGenre(TagLib::String(value, TagLib::String::UTF8));
        }
        fileRef.save();
    }
    } else {
        std::cout << "Editing metadata for video files is not supported yet." << std::endl;
    }
}

std::string File::getFileExtension()
{
    size_t dotPos = filePath.find_last_of('.');
    if(dotPos != std::string::npos){
        std::string extension = filePath.substr(dotPos);
        return extension;
    }
    return "";
}


void File::determineFileType()
{
    std::string extension = getFileExtension();

    if(extension == ".mp3"){
        fileType = "audio";
        return;
    }else if (extension == ".mp4"){
        fileType = "video";
        return;
    }
    fileType = "unknown";

}

void File::play()
{
    Mix_Music* music = Mix_LoadMUS(filePath.c_str());
    if(!music){
        std::cout << "Can't load music: " << Mix_GetError() << std::endl;
        Mix_CloseAudio();
        SDL_Quit();
        return ;
    }

    if(Mix_PlayMusic(music, -1) == -1){
        std::cout << "Can't play " << Mix_GetError() << std::endl;
    }
}

void File::pause()
{
    if (Mix_PlayingMusic()) {
        Mix_PauseMusic();
        std::cout << "Audio paused." << std::endl;
    }
}

void File::resume() {
    if (Mix_PausedMusic()) {
        Mix_ResumeMusic();
        std::cout << "Audio resumed." << std::endl;
    }
}
/**********/


std::string File::getMetadata()
{
    return "Title: " + title + "\nArtist: " + artist + "\n";
}

std::string File::displayDuration(int seconds)
{
    int minutes = seconds / 60;
    int remainingSeconds = seconds % 60;
    return std::to_string(minutes) + ":" + (remainingSeconds < 10 ? "0" : "") + std::to_string(remainingSeconds);
}



