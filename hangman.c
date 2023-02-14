#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

typedef struct{
    char word[30];
}words;

words wordlist[20];
char key[30];
int keys=0;

int getRandomWord()
{
    int len,index,n;
    printf("Enter the number of words to play HANGMAN: ");
    scanf("%d",&n);
    printf("\nEnter %d words:\n",n);
    for(int i=0;i<n;i++)
    {   
        scanf("%s",wordlist[i].word);
        len=strlen(wordlist[i].word); 
        for(int j=0;j<len;j++)
        {
            if(!isalpha(wordlist[i].word[j]))
            {
                printf("\n**** ONLY ALPHABETS PLEASE RENTER THE WORD****\n");
                i--;
            }
        }
    }
    index = rand()%n;
    return index;
}

void stickFigure(int index)
{   
    int strikes,len=strlen(wordlist[index].word),count=0,flag=0;
    for(int i=0;i<keys+1;i++)
    {
        for(int j=0;j<len;j++)
        {
            if(toupper(key[i])==toupper(wordlist[index].word[j]))
            {
               flag=1;
            }
        }
        if(flag)
        {
            count++;
            flag=0;
        }
    }
    strikes = keys+1 - count ;
    switch(strikes)
    {
        case 0: printf("\n\n    +---+\n    |   |\n        |\n        |\n        |\n        |\n  =========");
                break;
        case 1: printf("\n    +---+\n    |   |\n    O   |\n        |\n        |\n        |\n  =========");
                break;
        case 2: printf("\n    +---+\n    |   |\n    O   |\n    |   |\n        |\n        |\n  =========");
                break;
        case 3: printf("\n    +---+\n    |   |\n    O   |\n   /|   |\n        |\n        |\n  =========");
                break;
        case 4: printf("\n    +---+\n    |   |\n    O   |\n   /|\\  |\n        |\n        |\n  =========");
                break;
        case 5: printf("\n    +---+\n    |   |\n    O   |\n   /|\\  |\n   /    |\n        |\n  =========");
                break;
        case 6: printf("\n    +---+\n    |   |\n    O   |\n   /|\\  |\n   / \\  |\n        |\n  =========");
                printf("\nTHE WORD WAS : %s\n\n",wordlist[index].word);
                printf("\n********************************************\n");
                printf("******************GAME OVER*****************\n");
                printf("********************************************\n");
                exit(0);
                break;
        default:printf("\n\n***ERROR STRIKES EXCCEDED***\n\n");
    }
}

int displayWord(int index)
{
    int len=strlen(wordlist[index].word),flag=1;
    printf("\t");
    for(int i=0;i<len;i++)
    {
        for(int j=0;j<keys+1;j++)
        {   
            if (toupper(key[j])==toupper(wordlist[index].word[i]))
            {
                printf("%c ",key[j]);
                goto label;
            }
        }
        flag=0;
        printf("_ ");
        label: continue;
    }
    printf("\n");
    if(flag)
    {
        printf("\n\n********************************************\n");
        printf("******************YOU WON!!*****************\n");
        printf("********************************************\n");
        exit(0);
    }
}

void main()
{   
    int index,len;
    char userkey;
    printf("********************************************\n");
    printf("****************HANGMAN GAME****************\n");
    printf("********************************************\n\n");
    index=getRandomWord();
    len=strlen(wordlist[index].word);
    printf("\nSTART:\n");
    printf("\n\n    +---+\n    |   |\n        |\n        |\n        |\n        |\n  =========");
    printf("\t");
    for(int i=0;i<len;i++)
    {
        printf("_ ");
    }
    while(1)
    {
        printf("\n\nGUESS: ");
        scanf(" %c",&key[keys]);
        stickFigure(index);
        displayWord(index);
        keys++;
    }
}

