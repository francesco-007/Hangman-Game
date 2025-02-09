//---------------------------------------------------------------------------------------------------------------------
// a1.c
//
// Hangman game
// The program prompts the user to input a word. It then replaces each character of the word with an underscore,
// separating them by whitespace. The player's objective is to correctly guess the word within
// 5 attempts to win the game.
//
//
//---------------------------------------------------------------------------------------------------------------------
//
#include <stdio.h>
#include <ctype.h>

#define WORD_LENGTH 20
#define ALPHABETS 26

void guessedWord(char* word, char* guessed);
void letterInputLoop(char* word, char* guessed);
int compareStrings(char* word, char* guessed);
int lengthOfString(char* word);


//---------------------------------------------------------------------------------------------------------------------
///
/// This is the main function. The user enters the word, and then it replaces each character with an underscore
/// using guessedWord function. Then the user starts to guess the letters of the word and compare it to the main
/// word using letterInput function.
///
/// @return 0
//
int main ()
{
  char word[WORD_LENGTH];
  char guessed[WORD_LENGTH];

  printf("Word to look for:\n");
  printf(" > ");
  scanf("%s", word);

  guessedWord(word, guessed);

  letterInputLoop(word, guessed);


  return 0;
}


//---------------------------------------------------------------------------------------------------------------------
///
/// This function takes the length of word entered by the user.
///
/// @param word A pointer to the word entered by the user.
///
/// @return the length of the word
//
int lengthOfString(char* word)
{
  int length = 0;
  for(int i = 0; word[i] !='\0'; i++)
  {
    length++;
  }
  return length;
}


//---------------------------------------------------------------------------------------------------------------------
///
/// This function takes the length of word using lengthOfString function.
/// It then replace each character with an underscore.
///
/// @param word A pointer to the word entered by the user.
/// @param guessed A pointer to the guessed word, initially containing underscores.
///
///
/// @return void (no return)
//
void guessedWord(char* word, char* guessed)
{
  int length = lengthOfString(word);
  for (int i = 0; i < length; i++)
  {
    guessed[i] = '_';
  }

  guessed[length] = '\0'; //Null-terminator
}


//---------------------------------------------------------------------------------------------------------------------
///
/// This function compares each character of the word and the guessed word.
///
/// @param word A pointer to the word entered by the user.
/// @param guessed A pointer to the guessed word, initially containing underscores.
///
///
/// @return 1 if it doesn't match or one string is longer than the other.
/// @return 0 if string match
//
int compareStrings(char* word, char* guessed)
{
  while (*word != '\0' || *guessed != '\0')
  {
    if(toupper(*word) != toupper(*guessed))
    {
      return 1; //String don't match
    }
    word++; //Move to next character
    guessed++; //Move to next character
  }

  if (*word == '\0' && *guessed == '\0') //Check if both strings end at the same time
  {
    return 0; //String match
  }
  return 1; //One string is longer than the other
}


//---------------------------------------------------------------------------------------------------------------------
///
/// This function takes a letter guessed by the user, stores it in an array, and compares it to the original word.
/// It prompts the user for a letter, converts it to uppercase, and checks if it matches any letters
/// in the original word.
/// If all letters are correctly guessed within 5 attempts, the user wins; otherwise, they lose.
///
/// @param word A pointer to the word entered by the user.
/// @param guessed A pointer to the guessed word, initially containing underscores.
///
/// @return Void (no return)
//
void letterInputLoop(char* word,char* guessed)
{
  int attempts = 5;
  char letter;
  int guessed_letter[ALPHABETS] = {0}; //Create an array to store all guessed letters

  while ( attempts > 0 )
  {
    printf("Attempts left: %d\n", attempts);

    printf("Enter a letter:\n");
    printf(" > ");
    scanf(" %c", &letter);

    letter = toupper(letter);

    if (guessed_letter[letter - 'A'])
    {
      printf("Letter %c was used already!\n", letter);
      continue;
    }
    guessed_letter[letter - 'A'] = 1;

    int found = 0;

    for (int i = 0; word[i] != '\0'; i++)
    {
      if (toupper(word[i]) == letter)
      {
        guessed[i] = toupper(word[i]);
        found = 1;
      }
    }

    for (int i = 0; guessed[i] != '\0'; i++)
    {
      printf("%c ", guessed[i]);
    }
    printf("\n");

    if (compareStrings(word, guessed) == 0)
    {
      printf("Congratulations, you won!\n");
      break;
    }

    if(!found)
    {
      attempts--;
      if (attempts == 0)
      {
        printf("LOST! The Word was ");
        for ( int i = 0; word[i] != '\0' ; i++)
        {
          word[i] = toupper(word[i]);
        }
        printf("%s\n", word);
      }
    }
  }
}
