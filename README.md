<b>Filler is a game, where two players / algorithm are fighting on a map.</b>

A virtual machine organizes the game :

- calls the players alternatively

- give each a random piece

On each turn, the current player have to put his piece on the map, and try to bother the ennemy. To put a piece, the player have to write its coordinates in the "Y X\n" format on the standard input (stdin).

The game appears on the standard input.

The aim of the game is to put more pieces on the map than the ennemy.

<b>Installation:</b>

make

<b>Run:</b>

"./filler_vm" - is in the folder ressources-filler.

./filler_vm -f [map] -p1 [player1] -p2 [player2]

<b>Example:</b>

./filler_vm -p1 ../ashypilo.filler -p2 players/abanlin.filler -v -f maps/map00
