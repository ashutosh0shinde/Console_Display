# Terminal Text Renderer
A terminal based  dot matrix style display made in C language which renderes the user input text inside terminal.
It is a 8x100 pixel display which renderes text from custom bitmap font.

## Features
- Custom 5×7 bitmap font
- Framebuffer-style terminal rendering
- Scrolling text animation
- Direction control (left / right / static)
- Adjustable scroll speed
- ANSI terminal refresh


## How It Works

The program uses 2D character array to represent the screen.
All the characters are stored in 3D array where each character dimension is 5x7 pixels.
Program automatically selects the library for sleep functions based on the OS.

1. The program first sets the array to empty spaces and then renderes in to the terminal to represent the empty screen.
2. The character are drawn into the array using predefined bitmaps at a certain X nd Y postion.
3. To update the screen, the cursor is moved to the top left of the terminal using ANSI escape code ("\033[2J\033[H") creating the illusion of screen refresh.
4.  Then the updated array is printed on the screen
5.  This is done multiple times with updated matrix with specific time intervals to make it look like a scrolling display.


## Input & Controlls

User enters few things:
1. alhabetical text to display
2. direction of scrolling ('l' = left, 'r' = right, 'n' = static)
3. speed of scrolling (1-10)
   the time interval between each update is changed to change the speed of scrolling.


## Compiling & Running

Using the terminal
    gcc main.c -o renderer
    ./renderer


## Purpose of Project

This project was created to learn and practice-
1. Low level programming
2. Terminal rendering
3. Multidimensional Arrays
4. C language
