In Hangman there are at least two players where one thinks of a word and the other(s) try to guess it by suggesting letters. The player(s) only have a limited number of available guesses. When the player(s) do not have any guesses left, they loose the game and win if the word was found before that.

To run the game manually using the terminal :<br>
  First type ( clang -Wall game.c -o game )<br>
  Then, type ( ./game )


Example for the game:<br>


Word to look for:<br>
 > Tutors<br>
Attempts left: 5<br>
Enter a letter:<br>
 > T<br>
T _ T _ _ _ <br>
Attempts left: 5<br>
Enter a letter:<br>
 > a<br>
T _ T _ _ _ <br>
Attempts left: 4<br>
Enter a letter:<br>
 > S<br>
T _ T _ _ S <br>
Attempts left: 4<br>
Enter a letter:<br>
 > U<br>
T U T _ _ S <br>
Attempts left: 4<br>
Enter a letter:<br>
 > o<br>
T U T O _ S <br>
Attempts left: 4<br>
Enter a letter:<br>
 > P<br>
T U T O _ S <br>
Attempts left: 3<br>
Enter a letter:<br>
 > r<br>
T U T O R S <br>
Congratulations, you won!<br>
