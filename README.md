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

```gcc aS4.c -o as4```

```./as4 [width of window] [height of window] [length of snake, default=5]```

--------------------------------------------------------
ring.c

prints the bell character. just wanted to know what happens (i was playing with control characters). wsl interprets it as the notification bell and rings it.

the option1, when filled with literally anything, adds text to the output. it's a short poem but i really just wanted to test vertical tabs as well


how to use:

```gcc ring.c -o ding```

```./ding [option1]```
