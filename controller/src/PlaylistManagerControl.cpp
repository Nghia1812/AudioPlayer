#include "PlaylistManagerControl.hpp"
#include <cstdlib>

PlaylistManagerControl::PlaylistManagerControl(PlaylistManagerView view, PlaylistManager model)
    : view(view), model(model), isPlaying(false)
{
    totalDuration = 0;
    elapsed = 0;
}

void PlaylistManagerControl::createPL()
{
    std::string name = view.getPLName();
    model.createPL(name);
    return;
}


void PlaylistManagerControl::deletePL()
{
    std::string name = view.getPLName();
    model.deletePL(name);
}

void PlaylistManagerControl::listPL()
{
    view.displayPL(model.listPL());
    std::cout << "Press any key to quit: ";
    char c;
    std::cin >> c;
    view.clearScreen();
}



void PlaylistManagerControl::plManagerMenu()
{
    while(true){
        view.displayOptions();
        char choice;
        choice = view.getUserInput();
        switch (choice)
        {
        case '1':
            view.clearScreen();
            playPL();
            
            break;
        case '2':
            view.clearScreen();
            createPL();
            break;
        case '3':
            view.clearScreen();
            deletePL();
            break;
        case '4':
            view.clearScreen();
            listPL();
            break;
        case '5':
            view.clearScreen();
            updatePL();
            break;
        case '6':
            return;
        default:
            break;
        }
        
    }
    
}

void PlaylistManagerControl::updateDuration()
{
    while (true) {
    if (isPlaying) {
        // Get duration of playing file
        totalDuration = Playlist::activePL->getDuration();
        elapsed = 0;
        // Update duration
        while (elapsed <= totalDuration && isPlaying) {
            std::ofstream outputFile("duration.txt");
            if (outputFile.is_open()) {
                outputFile << elapsed << ": " << totalDuration;
                outputFile.flush();
                outputFile.close();
            }
            std::this_thread::sleep_for(std::chrono::seconds(1)); // Update every second
            elapsed++;
        }
    }
}
}

void PlaylistManagerControl::updatePL()
{
    std::string name = view.getPLName();
    while(true){
        view.displayUpdateOptions();
        char choice = view.getUserInput();
        switch (choice)
        {
        case '1':{
            //add file
            view.clearScreen();
            std::string path = view.getFilePath();
            model.addFile(name,path);
            break;
        }
            
        case '2':{
            //delete file
            view.clearScreen();
            int index = view.getFileIndex();
            model.deleteFile(name, index);
            break;
        }
            
        case '3':{
            //list file
            view.clearScreen();
            model.listFile(name);
            std::cout << "Press any key to quit: ";
            char c;
            std::cin >> c;
            view.clearScreen();
            break;
        }
            
        case '4':{
            //edit metadata
            view.clearScreen();
            int fileIndex = view.getFileIndex();
            std::string key = view.getMetadataKey();
            std::string value = view.getMetadataValue();
            model.editMetadata(name, fileIndex, key, value);
            break;
        }

        case '5':{
            view.clearScreen();
            return;
        }
            
        default:
            break;
        }
    }
    
}

void PlaylistManagerControl::playPL()
{
    std::string name = view.getPLName();
    while(true){
        view.displayPlayerOptions();
    char choice = view.getUserInput();
    switch (choice)
    {
        case '1':{
            //play file
            view.clearScreen();
            model.playPL(name);
            isPlaying = true;

            //attach thread
            durationThread = std::thread(&PlaylistManagerControl::updateDuration, this);
            durationThread.detach();

            break;
        }
            
        case '2':{
            //pause file
            view.clearScreen();
            model.pausePL(name);
            isPlaying = false;
            break;
        }
            
        case '3':{
            //next file
            view.clearScreen();
            model.nextPL(name);
            isPlaying = true;
            break;
        }
            
        case '4':{
            //previous file
            view.clearScreen();
            model.previousPL(name);
            isPlaying = true;
            break;
        }

        case '5':{
            //change volume
            view.clearScreen();
            int value = view.getVolumeValue();
            model.changeVolume(value);
            break;
        }

        case '6':{
            view.clearScreen();
            model.resumePL(name);
            
            break;
        }

        case '7':{
            view.clearScreen();
            std::cout << Playlist::activePL->getCurrentFile().getFilePath() << ": ";
            view.viewDuration(elapsed, totalDuration);
            break;
        }

        case '8': 
            return;
            
        default:
            break;
        }
    }
    
}
