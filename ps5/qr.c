#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void encode_char(const char character, bool bits[8]);

int main(){
    
    bool bits1[8];
    encode_char('A', bits1);
    for(int i = 0; i < 8; i++){
        printf("%d", bits1[i]);
        }
        printf("\n");
        // prints: 01000001

    return 0;
}

void encode_char(const char character, bool bits[8]){
    int i;
    int znak = character;

    for(i = 7; i >= 0; i--){
        if(znak %2 == 0){
            bits[i] = 0;
        }else{
            bits[i] = 1;
        }
        znak = znak / 2;
    }
}
