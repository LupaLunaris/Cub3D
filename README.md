# Cub3D

A small 3D-style maze renderer built in C for the 42 curriculum.

It uses raycasting to create a first-person view of a 2D map, with MiniLibX for the window and drawing.

## Build and run

This project is configured for Linux with X11 and MiniLibX.

```bash
make
./cub3d maps/<map-file>.cub
```

Choose an existing `.cub` file from the `maps/` directory.

## Implementation

- `srcs/raycasting.c`: raycasting
- `srcs/player_move.c` and `srcs/player_rotate.c`: movement
- `srcs/render.c`: rendering
- `srcs/parser.c` and related files: map parsing and validation
- `textures/`: map textures

## What I learned

This was an introduction to rendering, geometry, input handling and the importance of validating external files. It is a school project rather than a finished game.
