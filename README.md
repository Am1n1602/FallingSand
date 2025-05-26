# FallingSand [Work in Progress]

A simple falling sand simulation built with C++ and [Raylib](https://www.raylib.com/).

## Overview

This project simulates "falling sand" particles that can be spawned, frozen, and unfrozen within a grid-based sandbox environment. It is a minimal, educational, and interactive demonstration of basic particle physics and grid-based simulation.

## Features

- Click with the left mouse button (LMB) to spawn sand particles that fall under gravity.
- Particles freeze when they hit the bottom or another particle.
- Click with the right mouse button (RMB) to "unfreeze" individual sand particles so they fall again.
- Press `Q` to clear the simulation and reset the grid.
- Visual grid lines and colored sand for easy visualization.

## Controls

- **LMB (Left Mouse Button):** Spawn sand at the mouse cursor.
- **RMB (Right Mouse Button):** Unfreeze sand at the mouse cursor so it can fall again.
- **Q:** Reset/clear the board.
- **ESC:** Exit the simulation.

## Requirements

- C++17 or later
- [raylib](https://github.com/raysan5/raylib) (automatically fetched and built if not found)
- CMake 3.10 or higher

## Building and Running

1. Clone the repository:
   ```sh
   git clone https://github.com/Am1n1602/FallingSand.git
   cd FallingSand
   ```

2. Create a build directory and compile:
   ```sh
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```

3. Run the executable:
   ```sh
   ./FallingSand
   ```

## File Structure

- `Source.cpp`: Main simulation source code.
- `README.md`: Project documentation.


*Built with [Raylib](https://www.raylib.com/) by [Am1n1602](https://github.com/Am1n1602).*
