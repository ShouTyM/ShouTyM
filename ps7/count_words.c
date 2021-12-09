#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(){

    FILE *subor;
    int pocet = 0;
    int i = 0;
    char ch;
    subor = fopen("bananas.txt", "r+");
    char array[7] = "bananas";
//    void* buffer = malloc(1000);
    int pos;

    while(1){
        ch = fgetc(subor);
        pos = ftell(subor);

        if(ch == EOF){
            break;
        }

        if(isupper(ch)){
            ch = tolower(ch);
        }
        
        while(1){
            if( ch == array[i]){
                fseek(subor, 1, SEEK_CUR);
                i++;
                if(i == 7){
                    pocet++;
                    i = 0;
                    break;
                }
            }else{
                fseek(subor, pos, SEEK_SET);
                i = 0;
                break;
            }
        }
    }
    fclose(subor);
    return 0;
}
