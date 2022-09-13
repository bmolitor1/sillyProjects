# sillyProjects
anything i developed in wsl ubuntu and compiled with gcc without any flags unless otherwise noted

no, these aren't well developed with documentation or a --help option, srry

somethings will probably only work in ubuntu (aS4, for example, relies on a system call to get the size of the terminal)

Files:
--------------------------------------------------------
aS4.c

"autosnake v4"

it bounces a little ascii snake around the terminal window

gives dvd screensaver vibes

use if you need company while working on something.

automatically finds the size of window, but you should be able to enter your own custom values


how to use:

- ```gcc aS4.c -o as4```

- ```./as4 [width of window] [height of window] [length of snake, default=5]```

--------------------------------------------------------
mazeGen3.c

randomly generates a maze using Dijkstra's algorithm, outputed with 

I already knew the algorithm from a couple networks classes in both grad and undergrad, so when I saw that Prim's algorithm is literally the first picture on the wikipedia page for "maze generation algorithms," and is apparently the same thing more or less, i just hacked the code together.

automatically scales to size of terminal. if you want a maze of specific size, you'll have to modify the code (just change int sizej to your desired height/3 and sizek to your desired width/3).

i doubt anyone will use this for like a maze solving program, but you'd have to modify the code slightly to add the start and end characters since i just have an opening in the border.


how to use:
- ```gcc mazeGen3.c -o maze```
- ```./maze```

note:
if you actually want to solve a maze by hand instead of writing a bot to do it (if you need to kill a few minutes, as well as shave a couple off the end of your life), i'd recommend outputing to a file then using a cursor to navigate. it works well with vim because the minimal padding around the maze accidentally fits the vim interface perfectly:
-```./maze > solveThis.txt```
-```vim solveThis.txt```

--------------------------------------------------------
ring.c

prints the bell character. just wanted to know what happens (i was playing with control characters). wsl interprets it as the notification bell and rings it.

the option1, when filled with literally anything, adds text to the output. it's a short poem but i really just wanted to test vertical tabs as well


how to use:

- ```gcc ring.c -o ding```

- ```./ding [option1]```
