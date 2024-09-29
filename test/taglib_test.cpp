#include <taglib/fileref.h>
#include <taglib/mp4file.h>
#include <taglib/tag.h>
#include <iostream>
#include <fstream>

void viewMetadata(const std::string &filePath) {
    // Check if the file exists and can be opened
    std::ifstream fileCheck(filePath.c_str());
    if (!fileCheck.good()) {
        std::cerr << "File does not exist or cannot be opened: " << filePath << "\n";
        return;
    }
    fileCheck.close();

    // Open the media file with TagLib
    TagLib::FileRef file(filePath.c_str());
    if (!file.isNull() && file.tag()) {
        TagLib::Tag *tag = file.tag();

        if (tag != nullptr) {
            std::cout << "Metadata for file: " << filePath << "\n";
            std::cout << "------------------------------\n";

            // Only output if the string is not empty
            if (!tag->title().isEmpty())
                std::cout << "Title:  " << tag->title().to8Bit(true) << "\n";
            else
                std::cout << "Title: [No Title]\n";

            if (!tag->comment().isEmpty())
                std::cout << "Comment: " << tag->comment().to8Bit(true) << "\n";
            else
                std::cout << "Comment: [No Comment]\n";

            if (!tag->artist().isEmpty())
                std::cout << "Artist: " << tag->artist().to8Bit(true) << "\n";
            else
                std::cout << "Artist: [No Artist]\n";

            if (!tag->album().isEmpty())
                std::cout << "Album:  " << tag->album().to8Bit(true) << "\n";
            else
                std::cout << "Album: [No Album]\n";

            // Year and track are integers, so they don't need empty checks
            std::cout << "Year:   " << tag->year() << "\n";
            std::cout << "Track:  " << tag->track() << "\n";

            if (!tag->genre().isEmpty())
                std::cout << "Genre:  " << tag->genre().to8Bit(true) << "\n";
            else
                std::cout << "Genre: [No Genre]\n";
        } else {
            std::cerr << "Error: No tag information available in the file." << std::endl;
        }
    } else {
        std::cerr << "Error: Could not open file or file is invalid." << std::endl;
    }
}

int main(void) {
    std::string filePath = "/home/nghia1812/Documents/Fsoft/Mock/test/mysterious-sci-fi-30-sec-background-music-165790.mp3";
    viewMetadata(filePath);
    return 0;
}
