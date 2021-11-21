#include <stdio.h>
#include <stdlib.h> 
#include "ballsortpuzzle.h"

bool check(const int rows, const int columns, char field[rows][columns]){

    for(int i = 0; i < columns; i++){
        for(int a = 0; a < rows; a++){
            if(field[a][i] != field[a+1][i]){
                return false;
            }
        }    
    }
    return true;
}
