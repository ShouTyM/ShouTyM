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
	int i;
	int j;
	int pismeno = 0;
	
	for(i = 0; i < strlen(secret); i++){
		for(j = 0; j < strlen(letters_guessed); j++){
			if(secret[i] == letters_guessed[j]){
				pismeno++;
			}
		}
	}
	
	if(pismeno == strlen(secret)){
		return 1;
	}else{
		return 0;
	}
}

void get_guessed_word(const char secret[], const char letters_guessed[], char guessed_word[]){
	int i;
	int j;
	
	for(i = 0; i < strlen(secret); i++){
		for(j = 0; j < strlen(letters_guessed); j++){
			if(secret[i] == letters_guessed[j]){
				guessed_word[i] = letters_guessed[j];
				break;
			}else{
				guessed_word[i] = '_';
			}
		}
	}
	printf("%s\n", guessed_word);
}

void get_available_letters(const char letters_guessed[], char available_letters[]){
	int i, j, x, y = 0;
	char abeceda[30] = "abcdefghijklmnopqrstuvwxyz";
	
	for(i = 0; i < strlen(letters_guessed); i++){
		for(j = 0; j < strlen(abeceda); j++){
			if(letters_guessed[i] == abeceda[j]){
				abeceda[j] = ' ';
			}
		}
	}
	for(x=0; abeceda[x]; x++){
     	abeceda[x] = abeceda[x + y];
     	if(abeceda[x] == ' '){
		  y++;
		  x--;
	    }
	}
	
	printf("%s\n", abeceda);
}

void hangman(const char secret[]){
	int pokus = 8;
	int hra = 1;
	char guess_a_letter;
	char letters_guessed[30];
	char abeceda[30] = "abcdefghijklmnopqrstuvwxyz";
	int a = 0;
	char hadane_slovo[30] = "";
	
	
	get_word(slovo);
	
	printf("Welcome to the game, Hangman!\n");
	printf("I am thinking of a word that is %d letters long.\n", strlen(slovo));
	
	while(hra){
		printf("-------------\n");
		printf("You have %d guesses left.\n", pokus);
		printf("Available letters: %s\n");
		get_available_letters(letters_guessed, abeceda);
		printf("Please guess a letter: \n");
		scanf("%c",&guess_a_letter);
		
			tolower(guess_a_letter);
			
			if(strchr(letters_guessed, guess_a_letter)){
				printf("Oops! You've already guessed that letter: %c", guess_a_letter);
				printf("%s");
				get_guessed_word(slovo, letters_guessed, hadane_slovo);
			}else{
				letters_guessed[a] = guess_a_letter;
				a++;
			}
			
			if(strchr(slovo, guess_a_letter)){
				printf("Good guess: %s");
				get_guessed_word(slovo, letters_guessed, hadane_slovo);
			}else{
				printf("Oops! That letter is not in my word: %s");
				get_guessed_word(slovo, letters_guessed, hadane_slovo);
				pokus--;
			}
		
			if(pokus == 0){
				printf("Sorry, you ran out of guesses. The word was %s", slovo);
				hra = 0;
			}
			
			if(is_word_guessed(slovo, letters_guessed)){
				printf("Congratulations, you won!");
			}
	}
	
	
}
