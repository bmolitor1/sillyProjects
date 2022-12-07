# sillyProjects
anything i developed in wsl ubuntu (and now VS Code!!) and compiled with gcc without any flags unless otherwise noted

no, these aren't well developed with documentation or a --help option, srry

somethings will probably only work in ubuntu (aS4, for example, relies on a system call to get the size of the terminal)

Files:
--------------------------------------------------------
**colorPicker**

Uses the mouse to pick a color. vertically in the window for green, horizontal for red, scroll for blue. Press F to push RGB values to console. (Console also tells you what inputs are being taken by wasd and mouse, leftover from the first tutorial i followed). 

Future: I would like to figure out how to sync the refresh with the drawing because of visual artifacts (there is a flag in SDL_CreateRenderer for this, but I didn't try it before pushing)

my first foray into the world of SDL! Why SDL? Because I wanted to play with graphics! You know how hard it is to get people interested in programming when you spend like an hour talking about it, and it ends up just printing like "0.375" to console because that's the answer to a massive problem you were solving or perhaps it's the compression ratio from your 2 hour lecture on Huffman Coding, ending with the example "I love dog". Maybe, you can get it to take inputs. Maybe, it even connects to your other computer via TCP, and you can text yourself across the room.
Really cool stuff, but it can be dry to a lot of people. But imagine if you could move shapes around on a screen. And when you add ifs, loops, inputs, objects, structs, file i/o, etc, you can visualize it immediately. That's amazing. JavaScript with html kind of already does this easily, but JavaScript is a different world. I'm not saying people don't like coding in C because there's no pretty colors, but it certainly doesn't help. I'm also not gonna set off on a journey to make an educational library, but...
The colors are pretty. Pick a couple, stay awhile.

The base code came from Sonar Systems SDL2 tutorial series (https://www.youtube.com/watch?v=jUZZC9UXyFs)

how to use:
in command propmt:
- '''make.bat'''
it should run itself

- why make.bat? i was in a argument with MSYS2 
  - Because it didn't import '''make''' correctly, so i made a batch file. 
- Why does it make an executable called mGo? 
  - Because I horrible at naming executables. the first version was m, named because the MakeFile should have made it, then i wanted it to Go work. Feel free to rename
--------------------------------------------------------
**aS4.c**

"autosnake v4"

it bounces a little ascii snake around the terminal window

gives dvd screensaver vibes

use if you need company while working on something.

automatically finds the size of window, but you should be able to enter your own custom values


how to use:

- ```gcc aS4.c -o as4```

- ```./as4 [width of window] [height of window] [length of snake, default=5]```

--------------------------------------------------------
**mazeGen3.c**

randomly generates a maze using Dijkstra's algorithm, outputed with 

I already knew the algorithm from a couple networks classes in both grad and undergrad, so when I saw that Prim's algorithm is literally the first picture on the wikipedia page for "maze generation algorithms," and is apparently the same thing more or less, i just hacked the code together.

automatically scales to size of terminal. if you want a maze of specific size, you'll have to modify the code (just change int sizej to your desired height/3 and sizek to your desired width/3).

i doubt anyone will use this for like a maze solving program, but you'd have to modify the code slightly to add the start and end characters since i just have an opening in the border.

yes, it uses gotos, but idk an easy way to do vim block comments lol


how to use:
- ```gcc mazeGen3.c -o maze```
- ```./maze```

note:
if you actually want to solve a maze by hand instead of writing a bot to do it (if you need to kill a few minutes, as well as shave a couple off the end of your life), i'd recommend outputing to a file then using a cursor to navigate. it works well with vim because the minimal padding around the maze accidentally fits the vim interface perfectly:
- ```./maze > solveThis.txt```
- ```vim solveThis.txt```

--------------------------------------------------------
**mazeGen4.c**

literally just mazeGen3.c but prints with grey spaces instead of X's for walls.

can't be good if used for maze solving algorithms, but more human readable.

how to use:
- ```see above```

--------------------------------------------------------
**ring.c**

prints the bell character. just wanted to know what happens (i was playing with control characters). wsl interprets it as the notification bell and rings it.

the option1, when filled with literally anything, adds text to the output. it's a short poem but i really just wanted to test vertical tabs as well


how to use:

- ```gcc ring.c -o ding```

- ```./ding [option1]```
