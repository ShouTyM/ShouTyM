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

    for( i = 1; i < strlen(secret); i++ ){
        if(i %2 != 0){
            guessed = strchr(letters_guessed, secret[j++]);
            guessed_word[i - 1] = guessed != NULL ? *guessed : '_';
        }else{
            guessed_word[i - 1] = ' ';
        }
    }
    guessed_word[i] = '\0';
    printf("%s",guessed_word);
}
