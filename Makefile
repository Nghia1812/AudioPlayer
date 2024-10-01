# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -I./model/inc -I./view/inc -I./controller/inc

# Directories
MODEL_SRC = model/src
VIEW_SRC = view/src
CONTROLLER_SRC = controller/src
OBJ_DIR = obj
INSTALL_DIR = /usr/local/bin

# Linker flags for TagLib and SDL2
LIBS = -lSDL2 -lSDL2_mixer -ltag
LDFLAGS = -lSDL2 -lSDL2_mixer -ltag

# Source files
SRCS = 	$(MODEL_SRC)/File.cpp \
		$(MODEL_SRC)/FileSystemHandler.cpp \
		$(MODEL_SRC)/Playlist.cpp \
		$(MODEL_SRC)/PlaylistManager.cpp \
		$(CONTROLLER_SRC)/FileController.cpp \
		$(CONTROLLER_SRC)/PlaylistManagerControl.cpp \
		$(VIEW_SRC)/PlaylistManagerView.cpp \
		$(VIEW_SRC)/FileView.cpp \
       	main.cpp

# Object files
OBJS = 	$(OBJ_DIR)/File.o \
		$(OBJ_DIR)/Playlist.o \
       	$(OBJ_DIR)/FileSystemHandler.o \
       	$(OBJ_DIR)/FileController.o \
		$(OBJ_DIR)/PlaylistManagerView.o \
		$(OBJ_DIR)/PlaylistManager.o \
		$(OBJ_DIR)/PlaylistManagerControl.o \
		$(OBJ_DIR)/FileView.o \
       	$(OBJ_DIR)/main.o

# Output executable
TARGET = app

# Create the object directory if it doesn't exist
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Rule to compile all sources
$(TARGET): $(OBJ_DIR) $(OBJS)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(OBJS) -o $(TARGET) $(LIBS)

# Custom rule to compile each source file into its corresponding object file in the obj/ directory
$(OBJ_DIR)/%.o: $(MODEL_SRC)/%.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(CONTROLLER_SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(VIEW_SRC)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -c $< -o $@

# Clean rule to remove generated files
clean:
	rm -rf $(OBJ_DIR) $(TARGET)


# Install the executable system-wide
install: $(TARGET)
	@echo "Installing $(TARGET) to $(INSTALL_DIR)..."
	@sudo cp $(TARGET) $(INSTALL_DIR)
	@sudo chmod +x $(INSTALL_DIR)/$(TARGET)
	@echo "$(TARGET) installed successfully!"

# Uninstall the executable
uninstall:
	@echo "Uninstalling $(TARGET) from $(INSTALL_DIR)..."
	@sudo rm -f $(INSTALL_DIR)/$(TARGET)
	@echo "$(TARGET) uninstalled successfully!"
