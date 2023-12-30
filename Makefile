CC = gcc
CFLAGS = -Wall -Iinc -std=c99
LDFLAGS = -L/opt/homebrew/Cellar/sdl2/2.28.5/lib -L/opt/homebrew/Cellar/sdl2_image/2.8.1/lib -L$(shell brew --prefix sdl2_ttf)/lib -lSDL2 -lSDL2_image -lSDL2_ttf


SRC_DIR = src
OBJ_DIR = build/debug
BIN_DIR = bin

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))
EXECUTABLE = $(BIN_DIR)/Pong

all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJ_FILES)
	mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

exec: $(EXECUTABLE)
	./$(EXECUTABLE)
	

clean:
	@echo Cleaning...
	rm -rf $(OBJ_DIR)/*.o $(EXECUTABLE)

.PHONY: all exec clean
