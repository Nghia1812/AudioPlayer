#ifndef FILE_H
#define FILE_H

#include <string>
#include <taglib/fileref.h>

class File{
    private:
    std::string filePath;
    std::string fileType;

    //metadata
    std::string title;
    std::string artist;
    std::string codec;

    //for duration display
    int duration;

    //helper func
    std::string displayDuration(int seconds);
    std::string getFileExtension();
    void determineFileType();

    public:
    File(std::string path);
    std::string getFilePath() { return filePath;}

    //metadata func
    void loadMetadata();
    void editMetadata(std::string key, std::string value);
    
    //
    std::string getMetadata();

    //audio options
    void play();
    void pause();

    
;
    

};



#endif