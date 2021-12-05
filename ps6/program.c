#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

int main(){

    srand(time(NULL));

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    int y = 0, x = 0, a;
    char b[5];
    int min_y = 9; 
    int min_x = 9;
    int max_y = 0, max_x = 0;
    int max_y1 = 36, max_x1 = 16;
    int max_y2 = 28, max_x2 = 58;
    int max_y3 = 38, max_x3 = 78;
    int mapa = 0;
    int moznost = 0;

while(moznost == 0 || moznost == 1 || moznost == 2){

    if(moznost == 0){
    nodelay(stdscr, FALSE);
    echo();
    mvprintw(12, 10, "1. Urovne");
    mvprintw(14, 10, "2. Ovladanie/info");
    mvprintw(10, 10, "Vyber si moznost: ");
    refresh();
    scanw("%d", &moznost);
    clear();
    }

    if(moznost == 1){
        mvprintw(10, 10, "1. Lahke bludisko");
        mvprintw(12, 10, "2. Stredne tazke bludisko");
        mvprintw(14, 10, "3. Tazke bludisko");
        mvprintw(8, 10, "Tvoj vyber bludiska: ");
        scanw("%d", &mapa);
        nodelay(stdscr, TRUE);
        noecho();
        clear();
        break;
    }
    
    if(moznost == 2){    
        mvprintw(10, 10, "O - Hrac");
        mvprintw(12, 10, "X - Stena");
        mvprintw(14, 10, "* - Bonusove body");
        mvprintw(16, 10, "C - Ciel");
        mvprintw(18, 10, "W - Pohyb hore");
        mvprintw(20, 10, "A - Pohyb dolava");
        mvprintw(22, 10, "S - Pohyb dole");
        mvprintw(24, 10, "D - Pohyb doprava");
        mvprintw(10, 10, "Potvrd R aby si sa vratil: ");
        scanw("%s", b);

        if(b[0] == 'R' || b[0] == 'r'){
            clear();
            moznost = 0;
            continue;
        }else{
            clear();
            mvprintw(10, 10, "Zly vyber!");
            mvprintw(11,10, "%c",b);
            refresh();
            sleep(3);
            exit(0);
        }
    }
}

    if(mapa == 3){
        for(int p = 8; p < 40; p++){
            for(int o = 8; o < 80; o++){
                if(p == 8 || o == 8 || o == 79 || p == 39){
                    mvprintw(p, o, "#");
                    refresh();
                }else{
                    mvprintw(p, o, "");
                }
            }
        }
    }

    if(mapa == 2){
        for(int p = 8; p < 30; p++){
            for(int o = 8; o < 60; o++){
                if(o == 8 || o == 59 || p == 8 || p == 29){
                    mvprintw(p, o, "X");
                    refresh();
                }
            }
        }
    }
    mvprintw(9,10, "X");
    mvprintw(9,11, "X");
    mvprintw(9,13, "X");
    mvprintw(9,14, "X");
    mvprintw(9,15, "X");
    mvprintw(9,16, "X");
    mvprintw(9,20, "X");
    mvprintw(9,21, "X");
    mvprintw(9,23, "X");
    mvprintw(9,25, "X");
    mvprintw(9,26, "X");
    mvprintw(9,27, "X");
    mvprintw(9,28, "X");
    mvprintw(9,32, "X");
    mvprintw(9,33, "X");
    mvprintw(9,34, "X");
    mvprintw(9,38, "X");
    mvprintw(9,40, "X");
    mvprintw(9,41, "X");
    mvprintw(9,42, "X");
    mvprintw(9,46, "X");
    mvprintw(9,48, "X");
    mvprintw(9,49, "X");
    mvprintw(9,50, "X");
    mvprintw(9,55, "X");
    mvprintw(9,56, "X");
    mvprintw(9,57, "X");
    mvprintw(10,11, "X");
    mvprintw(10,18, "X");
    mvprintw(10,21, "X");
    mvprintw(10,23, "X");
    mvprintw(10,27, "X");
    mvprintw(10,30, "X");
    mvprintw(10,34, "X");
    mvprintw(10,36, "X");
    mvprintw(10,38, "X");
    mvprintw(10,40, "X");
    mvprintw(10,43, "X");
    mvprintw(10,44, "X");
    mvprintw(10,46, "X");
    mvprintw(10,48, "X");
    mvprintw(10,50, "X");
    mvprintw(10,52, "X");
    mvprintw(10,53, "X");
    mvprintw(10,54, "X");
    mvprintw(10,55, "X");
    mvprintw(10,56, "C");
    mvprintw(11,10, "X");
    mvprintw(11,11, "X");
    mvprintw(11,12, "X");
    mvprintw(11,14, "X");
    mvprintw(11,15, "X");
    mvprintw(11,16, "X");
    mvprintw(11,18, "X");
    mvprintw(11,19, "X");
    mvprintw(11,25, "X");
    mvprintw(11,28, "X");
    mvprintw(11,30, "X");
    mvprintw(11,31, "X");
    mvprintw(11,32, "X");
    mvprintw(11,35, "X");
    mvprintw(11,40, "X");
    mvprintw(11,42, "X");
    mvprintw(11,46, "X");
    mvprintw(11,55, "X");
    mvprintw(11,56, "X");
    mvprintw(11,58, "X");
    mvprintw(12,10, "X");
    mvprintw(12,11, "X");
    mvprintw(12,12, "X");
    mvprintw(12,13, "X");
    mvprintw(12,14, "X");
    mvprintw(12,19, "X");
    mvprintw(12,21, "X");
    mvprintw(12,22, "X");
    mvprintw(12,23, "X");
    mvprintw(12,24, "X");
    mvprintw(12,25, "X");
    mvprintw(12,26, "X");
    mvprintw(12,30, "X");
    mvprintw(12,32, "X");
    mvprintw(12,33, "X");
    mvprintw(12,36, "X");
    mvprintw(12,38, "X");
    mvprintw(12,39, "X");
    mvprintw(12,40, "X");
    mvprintw(12,43, "X");
    mvprintw(12,44, "X");
    mvprintw(12,46, "X");
    mvprintw(12,48, "X");
    mvprintw(12,50, "X");
    mvprintw(12,51, "X");
    mvprintw(12,53, "X");
    mvprintw(12,58, "X");
   /* mvprintw(13,, "X");
    mvprintw(13,, "X");
    mvprintw(13,, "X");
    mvprintw(13,, "X");
    mvprintw(13,, "X");
    mvprintw(13,, "X");
    mvprintw(13,, "X");
    mvprintw(13,, "X");
    mvprintw(13,, "X");
    mvprintw(13,, "X");
    mvprintw(13,, "X");
    mvprintw(13,, "X");
    mvprintw(13,, "X");
    mvprintw(13,, "X");
    mvprintw(13,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");
    mvprintw(,, "X");*/

    if(mapa == 1){
        for(int p = 8; p < 38; p++){
            for(int o = 8; o < 18; o++){
                if(o == 8 || o == 17 || p == 8 || p == 37){
                    mvprintw(p, o, "X");
                    refresh();
                }
            }
        }
        for(int c = 9; c < 13; c++){
            mvprintw(11, c, "X");
            refresh();
        }
        mvprintw(12, 12, "X");
        for(int c = 12; c < 17; c++){
            mvprintw(13, c, "X");
        }
        for(int r = 13; r < 15; r++){
            mvprintw(r, 10, "X");
        }
        mvprintw(14, 9, "C");
        for(int c = 9; c < 15; c++){
            mvprintw(15, c, "X");
        }
        for(int r = 14; r < 17; r++){
            mvprintw(r, 16, "X");
        }
        for(int r = 16; r < 21; r++){
            mvprintw(r, 12, "X");
        }
        for(int c = 9; c < 12; c++){
            mvprintw(19, c, "X");
        }
        for(int r = 17; r < 19; r++){
            mvprintw(r, 14, "X");
        }
        for(int c = 15; c < 17; c++){
            mvprintw(18, c, "X");
        }
        for(int r = 19; r < 34; r++){
            mvprintw(r, 16, "X");
        }
        for(int c = 13; c < 15; c++){
            mvprintw(20, c, "X");
        }
        for(int c = 10; c < 15; c++){
            mvprintw(21, c, "X");
        }
        for(int r = 22; r < 28; r++){
            mvprintw(r, 10, "X");
        }
        for(int c = 12; c < 15; c++){
            mvprintw(23, c, "X");
        }
        for(int r = 24; r < 30; r++){
            mvprintw(r, 12, "X");
        }
        for(int c = 14; c < 16; c++){
            mvprintw(25, c, "X");
        }
        for(int r = 26; r < 32; r++){
            mvprintw(r, 14, "X");
        }
        for(int c = 9; c < 12; c++){
            mvprintw(29, c, "X");
        }
        for(int r = 30; r < 34; r++){
            mvprintw(r, 9, "X");
        }
        for(int c = 11; c < 14; c++){
            mvprintw(31, c, "X");
        }
        for(int r = 31; r < 36; r++){
            mvprintw(r, 11, "X");
        }
        mvprintw(35, 10, "X");
        for(int r = 32; r < 36; r++){
            mvprintw(r, 13, "X");
        }
        for(int c = 15; c < 17; c++){
            mvprintw(35, c, "X");
        }
        mvprintw(33, 15, "X");
    }

    while(mapa == 1 || mapa == 2 || mapa == 3 || mapa == 4){
        
        if(mapa == 1){
            y = 36; 
            x = 12;
            mvprintw(y, x, "O");
            max_x = max_x1;
            max_y = max_y1;
            mapa = 4;
        }

        if(mapa == 2){
            y = 28;
            x = 34;
            mvprintw(y, x, "O");
            max_x = max_x2;
            max_y = max_y2;
            mapa = 4;
        }

        if(mapa == 3){
            mvprintw(y, x, "O");
            max_x = max_x3;
            max_y = max_y3;
            mapa = 4;
        }
 
        a = getch();
            if(a == 'W' || a == 'w'){
                if(y != min_y){
                    y--;
                    mvprintw(y, x, "O");
                    mvprintw(y + 1, x," ");
                    refresh();
                }
            }else if(a == 'A' || a == 'a'){
                if(x != min_x){
                    x--;
                    mvprintw(y, x, "O");
                    mvprintw(y, x + 1, " ");
                }
            }else if(a == 'S' || a == 's'){ 
                if(y != max_y){
                    y++;
                    mvprintw(y, x, "O");
                    mvprintw(y - 1, x, " ");
                }
            }else if(a == 'D' || a == 'd'){
                if(x != max_x){
                    x++;
                    mvprintw(y, x, "O");
                    mvprintw(y, x - 1, " ");
                }
            }
    }

    getchar();
    endwin();
    return EXIT_SUCCESS;
}
