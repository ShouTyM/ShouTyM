#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//#define _XOPEN_SOURCE_EXTENDED 1
#include <unistd.h>

int main(){

    FILE *subor;
    int pocet = 0;
    int i = 0;
    char ch;
    subor = fopen("bananas.txt", "r+");
    char array[7] = "bananas";
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
            if( ch == array[i] && ch != EOF){
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
    printf("%d", pocet);
    fclose(subor);
    truncate("bananas.txt",1);
    subor = fopen("bananas.txt", "r+");
    printf("%d", pocet);
    fclose(subor);
    return 0;
}
