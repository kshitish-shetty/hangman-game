#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
  char word[30];
} words;

words wordlist[1000];
char key[30];
int keys = 0, done;

int
getRandomWord (int choice)
{
  int len, index, x = 0, n = 0;
  FILE *ptr = fopen ("words.txt", "r");

  switch (choice)
    {
    case 1:
    case 2:
      if (ptr == NULL)
	{
	  printf ("no such file.");
	  exit (0);
	}
      char buf[100];
      while (fscanf (ptr, "%s ", buf) == 1)
	{
	  strcpy (wordlist[n].word, buf);
	  n++;
	}
      if (choice == 2)
	{
	  break;
	}
    case 3:
      printf ("Enter the number of words to add: ");
      scanf ("%d", &x);
      printf ("\nEnter %d words:\n", x);
      for (int i = n; i < n + x; i++)
	{
	  scanf ("%s", wordlist[i].word);
	  len = strlen (wordlist[i].word);
	  for (int j = 0; j < len; j++)
	    {
	      if (!isalpha (wordlist[i].word[j]))
		{
		  printf
		    ("\n****ONLY ALPHABETS PLEASE RENTER THE WORD****\n");
		  i--;
		}
	    }
	}
      n += x;
      break;
    default:
      exit (0);
    }
  srand (time (NULL));
  index = rand () % n;
  return index;
}

void
stickFigure (int index)
{
  int strikes = 0, len = strlen (wordlist[index].word), count = 0, flag = 0;
  for (int i = 0; i < keys + 1; i++)
    {
      for (int j = 0; j < len; j++)
	{
	  if (toupper (key[i]) == toupper (wordlist[index].word[j]))
	    {
	      flag = 1;
	    }
	}
      if (flag)
	{
	  count++;
	  flag = 0;
	}
    }
  strikes = keys + 1 - count;
  switch (strikes)
    {
    case 0:
      printf
	("\n\n    +---+\n    |   |\n        |\n        |\n        |\n        |\n  =========");
      break;
    case 1:
      printf
	("\n    +---+\n    |   |\n    O   |\n        |\n        |\n        |\n  =========");
      break;
    case 2:
      printf
	("\n    +---+\n    |   |\n    O   |\n    |   |\n        |\n        |\n  =========");
      break;
    case 3:
      printf
	("\n    +---+\n    |   |\n    O   |\n   /|   |\n        |\n        |\n  =========");
      break;
    case 4:
      printf
	("\n    +---+\n    |   |\n    O   |\n   /|\\  |\n        |\n        |\n  =========");
      break;
    case 5:
      printf
	("\n    +---+\n    |   |\n    O   |\n   /|\\  |\n   /    |\n        |\n  =========");
      break;
    case 6:
      printf
	("\n    +---+\n    |   |\n    O   |\n   /|\\  |\n   / \\  |\n        |\n  =========\n");
      printf ("\nTHE WORD WAS : %s\n", wordlist[index].word);
      printf ("\n********************************************\n");
      printf ("******************GAME OVER*****************\n");
      printf ("********************************************\n");
      done = 0;
      break;
    default:
      printf ("\n\n***ERROR STRIKES EXCCEDED***\n\n");
    }
}

void
displayWord (int index)
{
  int len = strlen (wordlist[index].word), flag = 1;
  printf ("\t");
  for (int i = 0; i < len; i++)
    {
      for (int j = 0; j < keys + 1; j++)
	{
	  if (toupper (key[j]) == toupper (wordlist[index].word[i]))
	    {
	      printf ("%c ", key[j]);
	      goto label;
	    }
	}
      flag = 0;
      printf ("_ ");
    label:continue;
    }
  printf ("\n");
  if (flag)
    {
      printf ("\n\n********************************************\n");
      printf ("******************YOU WON!!*****************\n");
      printf ("********************************************\n");
      done = 0;

    }
}

void
main ()
{
  int index, len, choice;
  char userkey;
  printf ("********************************************\n");
  printf ("****************HANGMAN GAME****************\n");
  printf ("********************************************");
  while (1)
    {
      printf ("\n\n\t****MENU****\n");
      printf ("PRESS 1 to ADD custom words.\n");
      printf ("PRESS 2 to PLAY.\n");
      printf ("PRESS 3 to play ONLY with custom words.\n");
      printf ("PRESS ANYKEY to EXIT.\n");
      scanf ("%d", &choice);
      index = getRandomWord (choice);
      len = strlen (wordlist[index].word);
      printf ("\nSTART:\n");
      printf
	("\n\n    +---+\n    |   |\n        |\n        |\n        |\n        |\n  =========");
      printf ("\t");
      for (int i = 0; i < len; i++)
	{
	  printf ("_ ");
	}
      done = 1;
      while (done)
	{
	  printf ("\n\nGUESS: ");
	  scanf (" %c", &key[keys]);
	  stickFigure (index);
	  if (done)
	    {
	      displayWord (index);
	    }
	  keys++;
	}
      keys = 0;
    }
}

