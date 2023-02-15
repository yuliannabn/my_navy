# my_navy

This is a version of Battleship made for the Unix terminal, coded in C.

The gameplay is based around an 8 x 8 board, and is initially ran using a map of your positions as argument.

Example of the contents of map.txt:

> 2:C1:C2
>
> 3:D4:F4
>
> 4:B5:B8
>
> 5:D7:H7

These would be the positions of the ships, exclusively with sizes 2, 3, 4 and 5.

## compilation:
> make re

## usage:
To play, open two instances of the terminal. Each terminal will connect with each other by sending the PID of the first one to the second.

First player:
> ./my_navy [map]

Second player:
> ./my_navy [PID of first player] [map]


You cannot send out-of-range attacks. The game will end whenever all of the ships of any of the players have been defeated.
