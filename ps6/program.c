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
//    int min_y = 9; 
//    int min_x = 9;
  //  int max_y = 0, max_x = 0;
   // int max_y1 = 36, max_x1 = 16;
   // int max_y2 = 28, max_x2 = 58;
   // int max_y3 = 38, max_x3 = 78;
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
        for(int c = 9; c < 14; c++){
            mvprintw(15, c, "X");
        }
        for(int r = 14; r < 16; r++){
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
    }

    while(mapa == 1 || mapa == 2 || mapa == 3 || mapa == 4){
        
        if(mapa == 1){
            y = 36; 
            x = 12;
            mvprintw(y, x, "O");
            mapa = 4;
        }

        if(mapa == 2){
            mvprintw(y, x, "O");
            mapa = 4;
        }

        if(mapa == 3){
            mvprintw(y, x, "O");
            mapa = 4;
        }
 
        a = getch();
            if(a == 'W' || a == 'w'){
                y--;
                if(isspace(y)){
                    mvprintw(y, x, "O");
                    mvprintw(y + 1, x," ");
                    refresh();
                }else{
                    y++;
                }
            }else if(a == 'A' || a == 'a'){
                x--;
                if(isspace(x)){
                    mvprintw(y, x, "O");
                    mvprintw(y, x + 1, " ");
                }else{
                    x++;
                }
            }else if(a == 'S' || a == 's'){ 
                y++;
                if(isspace(y)){
                    mvprintw(y, x, "O");
                    mvprintw(y - 1, x, " ");
                }else{
                    y--;
                }
            }else if(a == 'D' || a == 'd'){
                x++;
                if(isspace(x)){
                    mvprintw(y, x, "O");
                    mvprintw(y, x - 1, " ");
                }else{
                    x--;
                }
            }
    }

    getchar();
    endwin();
    return EXIT_SUCCESS;
}
