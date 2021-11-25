#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

void encode_char(const char character, bool bits[8]);

char decode_byte(const bool bits[8]);

void encode_string(const char string[], bool bytes[strlen(string)+1][8]);

void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]);

void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);

void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]);

int main(){
    
/*    bool bits1[8];
    encode_char('A', bits1);
    for(int i = 0; i < 8; i++){
        printf("%d", bits1[i]);
        }
        printf("\n");
        // prints: 01000001

    bool bits2[8] = {0,1,0,0,0,0,0,1};
    printf("%c\n", decode_byte(bits2));

    char* text = "Hello, how are you?";
    const int len = strlen(text);
    bool bytes1[len+1][8];
    encode_string(text, bytes1);
    for(int j = 0; j <= len; j++){
        printf("%c: ", text[j]);
        for(int i = 0; i < 8; i++){
            printf("%d", bytes1[j][i]);
        }
        printf("\n");
    }

    bool bytes2[7][8] = {
        {0,1,0,0,1,0,0,0},
        {0,1,1,0,0,1,0,1},
        {0,1,1,0,1,1,0,0},
        {0,1,1,0,1,1,0,0},
        {0,1,1,0,1,1,1,1},
        {0,0,1,0,0,0,0,1},
        {0,0,0,0,0,0,0,0}
    };
    char string[7];
    decode_bytes(7, bytes2, string);
    printf("%s\n", string);


    int length = 4+1, cols = 3, offset = 2;
    bool bytes1[4+1][8] = {
        {0,1,0,0,0,0,0,1},
        {0,1,1,0,1,0,0,0},
        {0,1,1,0,1,1,1,1},
        {0,1,1,0,1,0,1,0},
        {0,0,0,0,0,0,0,0}
    };
    bool blocks1[offset*8][cols];
    bytes_to_blocks(cols, offset, blocks1, length, bytes1);
    for(int j = 0; j < offset*8; j++){
        for(int i = 0; i < cols; i++){
            printf("%d", (blocks1[j][i] == true) ? 1 : 0);
        }
        printf("\n");
        if(j %8 == 7){
            printf("\n");
        }
    }
*/
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

char decode_byte(const bool bits[8]){
    int i;
    int p = 1;
    int cislo = 0;
    int desiatkova = 0;
    int a = 1;
    int b;
    char pismeno;
    
    for(i = 7; i >= 0; i--){
        cislo = cislo + (bits[i] * p);

        p = p * 10;
    }

    while(cislo != 0){
        b = cislo %10;

        desiatkova = desiatkova + b * a;

        cislo = cislo / 10;

        a = a * 2;
    }
    pismeno = desiatkova;

    return pismeno;
}

void encode_string(const char string[], bool bytes[strlen(string)+1][8]){
    int i;

    for(i = 0; i < (strlen(string)+1); i++){
        encode_char(string[i], bytes[i]);
    }
}

void decode_bytes(const int rows, bool bytes[rows][8], char string[rows]){
    int i;

    for(i = 0; i < rows; i++){
        string[i] = decode_byte(bytes[i]);
    }
}

void bytes_to_blocks(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
    int off;
    
    for(off = offset; off >= 0; off--){
        for(int riadok = 0; riadok < offset*8; riadok++){
            for(int stlpec = 0; stlpec < rows; stlpec++){
                if(riadok <= 8){
                blocks[riadok][stlpec] = bytes[stlpec][riadok];
                }else{
                    if(rows < riadok){
                        blocks[riadok][stlpec] = 0;
                    }
                    blocks[riadok][stlpec] = bytes[stlpec+2][riadok];
                }
            }
        }
    }
}
void blocks_to_bytes(const int cols, const int offset, bool blocks[offset*8][cols], const int rows, bool bytes[rows][8]){
        
}
