# 08_cub3d

## Project overview

This project is inspired by the world-famous eponymous 90's game, which was the first FPS ever: Wolfenstein 3D.

The goal was to make a dynamic view inside a maze, in which a player has to find his way.

It enabled me to explore Raycasting: a rendering technique to create a 3D perspective in a 2D map.

cub3d is the second:
- collaborative project of the 42 cursus (the first one being Minishell)
- project focused on the creation of a video game (the first one being so_long)

Both Minishell and so_long projects are available on my GitHub for more details.

The workload on this project was split as follows:
- My mate was responsible of the input map parsing
- I was responsible of the implementation of the RayCaster

For the ray-casting part:
- I had the constraint to use the MiniLibX, the 42 school graphical library
- I was inspired by the following algorithm, a valuable ressource for this project: https://lodev.org/cgtutor/raycasting.html

## How to use this repository?

### Recommended Operating System (OS)

I recommand to use a Linux distribution such as:

- Latest stable version (LTS) of Ubuntu
- Latest stable version (LTS) of Debian

### Steps to follow

1. Go to the directory where you want to clone the directory: `cd path/of/repository/`
2. Clone this repository: `git clone git@github.com:romainkassel/08_cub3d.git`
3. Enter into cloned repository: `cd 08_cub3d`
8. Build the project: `make`
9. Run executable with a map as argument: `./cub3D config_files/map_main_ok.cub`
10. Here you go! If everything went smoothly, the following window handled by the MiniLibX should open:

<img width="1111" height="723" alt="cub3d-ray-casting-video-game-mandatory" src="https://github.com/user-attachments/assets/d5371160-81d1-41f7-b33f-4b148a9cf6ef" />

## Notes to take in mind

### Maps as argument

Within steps above, I have chosen the `map_main_ok.cub` map as argument because it is a valid and very complete map.<br />

But feel free to select any map located in the folder `config_files/`.<br />

Just take in mind that, for testing purposes and to meet project requirements, some maps are valid while others are rejected by the program.

### Window size

In order to fit small screen sizes, the default size for the MiniLibX window is 962x601 px.<br />
If you want, you can update these parameters by:
1. Opening the file `/includes/cub3d.h`
2. Replacing the constants SCREEN_W and SCREEN_H by the values of your choice
3. Saving your new screen resolution
4. Building the project again by running `make fclean` and `make` or directly `make re` (if you just run `make`, changes will be ignored)

### Player movements and point of view (POV)

Here are the default keyboard keys for player movements and POV:
- Rotate view to left: `left arrow`
- Rotate view to right: `right arrow`
- Move forward: `W`
- Move back: `S`
- Move left: `A`
- Move right: `D`

These controls have been designed for a QWERTY keyboard.

If you want to customise them, for an AZERTY keyboard as example, you can:
1. Open the file `/includes/cub3d.h`
2. Replace the constants RIGHT_ARROW, LEFT_ARROW, UP_W, LEFT_A, DOWN_S and RIGHT_D by the keys of your choice
3. Save your new setup
4. Build the project again by running `make fclean` and `make` (or `make bonus`) or directly `make re` (if you just run `make` or `make bonus`, changes will be ignored)

### Building and running program with bonuses

For this project, we decided to implement bonuses: wall collision management, a minimap and the ability to rotate the player's viewpoint with the mouse (left and right).

In steps above, the `make` command built the program with mandatory constraints.

If you want to test bonuses, you just have to:
1. Build the project with `make bonus`
2. Run the executable `./cub3D_bonus` with the map of your choice (for instance: `./cub3D_bonus config_files/map_main_ok.cub`

<img width="1109" height="723" alt="cub3d-ray-casting-video-game-bonus-minimap" src="https://github.com/user-attachments/assets/d66c2f28-2e5a-4132-b2ae-794fd2c79648" />

You may notice a space under the minimap as follow:

<img width="1109" height="721" alt="cub3d-ray-casting-video-game-bonus-minimap-space" src="https://github.com/user-attachments/assets/280b60c4-2fb4-4e2e-8ec8-4ecf906f606d" />

It depends on your environment. If you experience this issue, you can fix it by:
1. Opening the file `/includes/cub3d.h`
2. Replacing the constant MINIMAP_PADDING_TOP by the value of your choice (for example, a value of `69` works at 42 school)
3. Saving your update
4. Building the project again by running `make fclean` and `make bonus` (if you just run `make bonus`, changes will be ignored)

## I tested the game and it's cool! Now I'd like to clean it up. What do I do?

1. Close the window by clicking on the cross at top right, by clicking on `CTRL + D` in your terminal or by pressing the `ESCAPE` touch
4. Go outside of the repository: `cd ..`
5. Remove the repository: `rm -rf 08_cub3d`
