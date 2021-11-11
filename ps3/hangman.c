#include <ctype.h>
#include <string.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "hangman.h"

int get_word(char secret[]){
    // check if file exists first and is readable
    FILE *fp = fopen(WORDLIST_FILENAME, "rb");
    if( fp == NULL ){
        fprintf(stderr, "No such file or directory: %s\n", WORDLIST_FILENAME);
        return 1;
    }

    // get the filesize first
    struct stat st;
    stat(WORDLIST_FILENAME, &st);
    long int size = st.st_size;

    do{
        // generate random number between 0 and filesize
        long int random = (rand() % size) + 1;
        // seek to the random position of file
        fseek(fp, random, SEEK_SET);
        // get next word in row ;)
        int result = fscanf(fp, "%*s %20s", secret);
        if( result != EOF )
            break;
    }while(1);

    fclose(fp);

    return 0;
}

int is_word_guessed(const char secret[], const char letters_guessed[]){
    char *guessed;

    guessed = (char *) malloc(15);

    for(int i = 0; i < strlen(secret); i++ ){
        guessed = strchr(letters_guessed, secret[i]);
        while(guessed == NULL){
            return 0;
        }
    }
    return 1;
}

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){
    char *guessed;
    int i;
    int j = 0;

    guessed = (char *) malloc(15);

    for( i = 1; i < (strlen(secret) * 2); i++ ){
        if(i % 2 != 0){
            guessed = strchr(letters_guessed, secret[j++]);
            guessed_word[i - 1] = guessed != NULL ? *guessed : '_';
        }else{
            guessed_word[i - 1] = ' ';
        }
    }
    guessed_word[i - 1] = '\0';
    printf("%s",guessed_word);
}

void get_available_letters(const char letters_guessed[], char available_letters[]){
    int i;
    int j = 0;
    char *guessed;
    char abeceda[] = "abcdefghijklmnopqrstuvwxyz";

    guessed = (char *) malloc(15);


    for(i = 0; i < strlen(abeceda); i++){
        guessed = strchr(letters_guessed, abeceda[i]);
        if(guessed != NULL){
            continue;
        }else{
            available_letters[j++] = abeceda[i];
        }
    }
    available_letters[j] = '\0';
    printf("%s",available_letters);
}

void hangman(const char secret[]){
    int i = 0;
    int j;
    int a = 0;
    int hraj = 1;
    int pokus = 8;
    char b;
    char slovo[15];
    char abeceda[30];
    char hodnota1[50] = "";
    char hodnota2[30] = "";
    char medzera[30] = "";


    get_word(slovo);


    for(j = 0; j < strlen(slovo); j++){
        slovo[j] = tolower(slovo[j]);
    }

    for(j = 1; j < strlen(slovo) * 2; j++){
        medzera[j - 1] = j % 2 == 0 ? ' ' : slovo[a++];
    }
    medzera[j] = '\0';
    printf("Welcome to the game, Hangman!\n");
    printf("I am thinking of a word that is %ld letters long.", strlen(slovo));

    while(hraj){
        printf("\n-------------");
        printf("\nYou have %d guesses left.\nAvailable letters: ", pokus);
        get_available_letters(hodnota1, abeceda);
        
        printf("\nPlease guess a letter: ");
        scanf("%c", &b);

        while(getchar() != '\n'){
            ;
        }
        b = tolower(b);

        if(!strchr(abeceda, b)){
            printf("Oops! You've already guessed that letter: ");
            get_guessed_word(slovo, hodnota1, hodnota2);
            continue;
        }

        hodnota1[i++] = b;

        if(strchr(slovo, b)){
            printf("Good guess: ");
            get_guessed_word(slovo, hodnota1, hodnota2);
        
          if( strcmp(medzera, hodnota2) == 0){

            printf("\n-------------");
            printf("\nCongratulations, you won!\n");
            break;
        }
        }else{
            printf("Oops! That letter is not in my word: ");
            get_guessed_word(slovo, hodnota1, hodnota2);
            pokus--;
        
            if(pokus == 0){
                printf("\n-------------");
                printf("\nSorry, you ran out of guesses. The word was: %s.\n", slovo);
                break;
            }
        }
    }
    is_word_guessed(slovo, hodnota1);
}
