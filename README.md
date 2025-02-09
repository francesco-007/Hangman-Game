In Hangman there are at least two players where one thinks of a word and the other(s) try to guess it by suggesting letters. The player(s) only have a limited number of available guesses. When the player(s) do not have any guesses left, they loose the game and win if the word was found before that.

To run the game manually using the terminal :<br>
  First type ( clang -Wall game.c -o game )<br>
  Then, type ( ./game )


Example for the game:<br>

'''
Word to look for:
 > Tutors
Attempts left: 5
Enter a letter:
 > T
T _ T _ _ _ 
Attempts left: 5
Enter a letter:
 > a
T _ T _ _ _ 
Attempts left: 4
Enter a letter:
 > S
T _ T _ _ S 
Attempts left: 4
Enter a letter:
 > U
T U T _ _ S 
Attempts left: 4
Enter a letter:
 > o
T U T O _ S 
Attempts left: 4
Enter a letter:
 > P
T U T O _ S 
Attempts left: 3
Enter a letter:
 > r
T U T O R S 
Congratulations, you won!
'''

