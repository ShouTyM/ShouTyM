#include <stdio.h>
#include <stdlib.h> 
#include "ballsortpuzzle.h"

bool check(const int rows, const int columns, char field[rows][columns]);

bool check(const int rows, const int columns, char field[rows][columns]){
    for(int i = 0; i < columns; i++){
        for(int j = 0; j < rows; j++){
        if(field[j][i] == '*'){
            if(field[j][i] == '*'){
                if(field[j][i] == '*'){
                    if(field[j][i] == '*'){
                        return true;
                    }
                }
            }
        }

        if(field[j][i] == '@'){
            if(field[j][i] == '@'){
                if(field[j][i] == '@'){
                    if(field[j][i] == '@'){
                        return true;
                    }
                }
            }
        }

        if(field[j][i] == '+'){
            if(field[j][i] == '+'){
                if(field[j][i] == '+'){
                    if(field[j][i] == '+'){
                        return true;
                    }
                }
            }
        }

        if(field[j][i] == '^'){
            if(field[j][i] == '^'){
                if(field[j][i] == '^'){
                    if(field[j][i] == '^'){
                        return true;
                    }
                }
            }
        }
    }
    }
    return false;
}
