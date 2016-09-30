# Checkers 

Project is programmed by:
- JackyChiu (https://github.com/JackyChiu)
- VikramBombhi (https://github.com/VikramBombhi)
- BenEmdon (https://github.com/BenEmdon)

A simple checkers game created in C++ using SDL2's frameworks. That is planned to have a single player mode that challenges our AI checkers player and to have multiplayer mode so you can play with a friend beside you.

<img src="https://raw.githubusercontent.com/VikramBombhi/Checkers/master/data/CheckersBoard.png" width="400">

## Current Features
- Movable pieces, along with being able to kill an opponents piece
- AI Player to play against
- AI vs AI mode (*Must keep moving mouse as game loop depends on mouse movement*)
- Scalability with code structure
- Local Multiplayer
- Menu

## Missing Features
- Different levels to the AI
- Double moves made by AI
- End game screen

## Installation (Linux) *Simplest*
[1] Download the dependencies

    sudo apt-get update
    apt-cache search libsdl2
    sudo apt-get install libsdl2-dev
    sudo apt-get install libsdl2-image-dev
    sudo apt-get install libsdl2-ttf-dev

[2] Change directory to where you want the project to be

    git clone https://github.com/VikramBombhi/Checkers.git
    cd Checkers
    make all
    bin/Checkers

## Installation (OS X & Windows)
- Download the following libraries and extract them in the same directory (Make sure you codesign frameworks if on Mac -> refer to reference)
    - SDL2
    - SDL2_image
    - SDL2_tff
- Clone the repo
- Create project in IDE of choice
- Add the files from the repo into the project
- Add reference to libraries where you extracted them
- Change the working directory of the project to the folder that contains the src, include and data folders
- Run project!

Reference for help: http://lazyfoo.net/tutorials/SDL/01_hello_SDL/index.php

SDL2 Library: https://www.libsdl.org/download-2.0.php

SDL2 Image: https://www.libsdl.org/projects/SDL_image/

SDL2 TFF: https://www.libsdl.org/projects/SDL_ttf/

