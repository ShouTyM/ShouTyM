#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "hangman.h"

int main(){

    char secret[15];

    srand(time(NULL));

    if(get_word(secret) == 0){
        hangman(secret);
    }
    return 0;
}
