# Cards
Oftentimes, when a person is trying to adapt a card game into a program for playing it, they encounter the difficulties of 
1. Storing the game state as a file. 
2. Representing the game state in memory.

This library, written in portable C99, attempts to solve that problem, by providing ready-made structures for loading, storing, and manipulating decks of cards. 

I hope this is helpful to someone!

Note: There is no guarantee of cryptographical security in the random number generator of the shuffling. It might be helpful to implement your own shuffling algorithm, especially if you intend to use this library or a derivative commercially. 
