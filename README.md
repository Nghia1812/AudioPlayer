Model
- File System Handler: Responsible for interacting with the file system to scan directories and retrieve media files.
- Metadata Handler (using Taglib): Manages extraction, modification, and storage of metadata for audio and video files.
- Playlist Manager: Manages playlists, including creation, deletion, updating, and retrieval of playlist contents.
View
- CLI View: Displays information and interacts with the user via command-line interface.
- Pagination Renderer: Displays media files in a paginated format (25 items per page).
- Playlist Renderer: Displays playlists and their contents.
Controller
- Application Controller: Orchestrates user inputs and manages flow between the model and view components.
- Playback Controller (using SDL2): Handles multimedia playback, including play, pause, next, previous, volume control, and time display.

//compile taglibs
g++ taglib_test.cpp -o read_tags -I/usr/include/taglib -L/usr/lib -ltag