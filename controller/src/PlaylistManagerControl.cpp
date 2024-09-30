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

void PlaylistManagerControl::playPL()
{
    std::string name = view.getPLName();
    model.playPL(name);
}

void PlaylistManagerControl::deletePL()
{
    std::string name = view.getPLName();
    model.deletePL(name);
}

void PlaylistManagerControl::updatePL()
{
    //delegate to PlaylistController
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
    default:
        break;
    }
}
