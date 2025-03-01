#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxsize 25 //The maximum size of a word


int check(char word[], char guess); //Function declaration that checks if a letter is contained inside the word we are guessing


int main()
{
    int i = 0, size = 0, attempts = 10, lsize = 0;
    char word[maxsize] = {0}, gword[maxsize] = {0}, list[26] = {0}, guess;


    printf("Give word to guess: ");
    scanf("%s", word);

    size = strlen(word); //Retrieving the word length

    while (size > maxsize) //In case the word is bigger than the max size defined
    {
        printf("\nThe word is too big, please try a smaller one:");
        scanf("%s", word);
        size = strlen(word);
    }

    for(i=0; i<size; i++)
    {
        gword[i] = '_'; //Initializing the guess word
    }

    while ((strcmp(word, gword)) != 0) //Main while loop
    {

       system("cls"); //Clearing the screen from previous prints to make way for new values

       for(i=0; i<size; i++)
       {

          printf("%c ", gword[i]); //Printing the guess word

       }

       printf("\nAttempts remaining: %d\n", attempts);
       printf("Previous guesses: ");

       for(i=0; i < strlen(list); i++)
       {

           printf("%c ", list[i]); //Printing the previous guesses

       }

       printf("\nGuess a letter: ");
       scanf(" %c", &guess);

       while(check(list, guess) == 1) //Checking the list of previous guesses
       {
            system("cls"); //Printing everything again but with a new message at the end

            for(i=0; i<size; i++)
            {

                printf("%c ", gword[i]);

            }

            printf("\nAttempts remaining: %d\n", attempts);
            printf("Previous guesses: ");

            for(i=0; i < strlen(list); i++)
            {

                printf("%c ", list[i]);

            }
            printf("\nGuess a letter: ");

            printf("\nYou have already tried that letter, please try another: "); //The new message informing the user to try a different letter
            scanf(" %c", &guess);
       }

        if (check(word, guess) == 1) //Correct guess of a letter in the word
        {
             for(i=0; i<size; i++)
             {
                 if(word[i] == guess)
                 {
                     gword[i] = word[i]; //Replacing the '_' with the correct letter
                 }
             }

        }

        if (check(word, guess) == 0) //Incorrect guess of a letter in the word
        {

             attempts = attempts - 1; //Lost an attempt
             list[strlen(list)] = guess;
             if(attempts == 0)
             {
                 printf("You ran out of attempts\n"); //User losing
                 exit(0);
             }

        }

    }//end of while

    system("cls"); //Printing the info one last time with the final message at the end after finding the word

    for(i=0; i<size; i++)
    {

       printf("%c ", gword[i]);

    }

    printf("\nAttempts remaining: %d\n", attempts);
    printf("Previous guesses: ");

    for(i=0; i < strlen(list); i++)
    {
         printf("%c ", list[i]);

    }

    printf("\nYou found the word!\n"); //Final message informing the user he has won
    return 0;
}

int check(char array[], char letter) //Check function implementation
{
  int i;
  for(i=0; i < strlen(array); i++)
  {

    if(array[i] == letter) return 1;

  }
  return 0;

}
