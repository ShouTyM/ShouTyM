#include <stdio.h>
#include <stdlib.h> 
#include "ballsortpuzzle.h"

bool check(const int rows, const int columns, char field[rows][columns]);

bool check(const int rows, const int columns, char field[rows][columns]){
    for(int i = 0; i < columns; i++){
        if(field[0][i] == '*'){
            if(field[1][i] == '*'){
                if(field[2][i] == '*'){
                    if(field[3][i] == '*'){
                        return true;
                    }
                }
            }
        }

        if(field[0][i] == '@'){
            if(field[1][i] == '@'){
                if(field[2][i] == '@'){
                    if(field[3][i] == '@'){
                        return true;
                    }
                }
            }
        }

        if(field[0][i] == '+'){
            if(field[1][i] == '+'){
                if(field[2][i] == '+'){
                    if(field[3][i] == '+'){
                        return true;
                    }
                }
            }
        }

        if(field[0][i] == '^'){
            if(field[1][i] == '^'){
                if(field[2][i] == '^'){
                    if(field[3][i] == '^'){
                        return true;
                    }
                }
            }
        }
    }
    return false;
}
