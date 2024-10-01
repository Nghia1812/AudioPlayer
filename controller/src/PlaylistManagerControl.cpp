#include "PlaylistManagerControl.hpp"

PlaylistManagerControl::PlaylistManagerControl(PlaylistManagerView view, PlaylistManager model)
    : view(view), model(model)
{
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
}

void PlaylistManagerControl::plManagerMenu()
{
    view.displayOptions();
    char choice;
    choice = view.getUserInput();
    switch (choice)
    {
    case '1':
        playPL();
        break;
    case '2':
        createPL();
        break;
    case '3':
        deletePL();
        break;
    case '4':
        listPL();
        break;
    case '5':
        updatePL();
        break;
    default:
        break;
    }
}

void PlaylistManagerControl::updatePL()
{
    std::string name = view.getPLName();
    view.displayUpdateOptions();
    char choice = view.getUserInput();
    switch (choice)
    {
    case '1':{
        //add file
        std::string path = view.getFilePath();
        model.addFile(name,path);
        break;
    }
        
    case '2':{
        //delete file
        int index = view.getFileIndex();
        model.deleteFile(name, index);
        break;
    }
        
    case '3':{
        //list file
        model.listFile(name);
        break;
    }
        
    case '4':{
        //edit metadata
        int fileIndex = view.getFileIndex();
        std::string key = view.getMetadataKey();
        std::string value = view.getMetadataValue();
        model.editMetadata(name, fileIndex, key, value);
        break;
    }
        
    default:
        break;
    }
}

void PlaylistManagerControl::playPL()
{
    std::string name = view.getPLName();
    view.displayPlayerOptions();
    char choice = view.getUserInput();
    switch (choice)
    {
    case '1':{
        //play file
        model.playPL(name);
        break;
    }
        
    case '2':{
        //pause file
        model.pausePL(name);
        break;
    }
        
    case '3':{
        //next file
        model.nextPL(name);
        break;
    }
        
    case '4':{
        //previous file
        model.previousPL(name);
        break;
    }

    case '5':{
        //change volume
        model.changeVolume();
        break;
    }

    case '6':{
        model.resumePL(name);
        break;
    }
        
    default:
        break;
    }
}
