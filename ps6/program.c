#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>
#include <ctype.h>

int main(){

    srand(time(NULL));

    initscr();
    start_color();
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
    init_pair(3, COLOR_BLUE, COLOR_GREEN);

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

    init_pair(1, COLOR_BLUE, COLOR_WHITE);
    attron(COLOR_PAIR(1));
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
    mvprintw(9,9,  "    X   X   X    X X XX  X X     XX  X   X   X       X  X X  XXX   X ");
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(3));
    mvprintw(9,78, "C");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(1));
    mvprintw(10,9, " XXXX XX XX  X X   X   X   X X X X X  XX   X   XX XX XX X  X X X X   X");
    mvprintw(11,9, "    X X   XX    X XXXX XXX  XXXX X  X X  X X X   X  XX   X   X X X XX ");
    mvprintw(12,9, " XX X X X   X X X         X X X   X     XX XX XXX  X X X X X     X  X ");
    mvprintw(13,9, " X  X XX  XXX XX X XX X X X X  XXX XX X          X   X X X  XXX X  XX ");
    mvprintw(14,9, "  XX   X X X  XX X  X XX  X  X   X      X X XX X X XXX   X  X X X X   ");
    mvprintw(15,9, " X   X   X   X    X X   X    XXX  X XXXX X   X  XX XX XX  X X      XX ");
    mvprintw(16,9, "   XX  X  XXXXX  X  X XX XX  X XX X   X  XX  X X   X  X  X   X XXX X  ");
    mvprintw(17,9, " X   XX  XX    X   XX    X  X     X X  X    X    X  X  X X X  X X X X ");
    mvprintw(18,9, " X X X X X  XX   X X  XX XXXX XX X X X  X   X XXX  X X  X  XXX  X     ");
    mvprintw(19,9, "  X XX X X X   X     X       X X X   X     X     X    X XX X X XX XXX ");
    mvprintw(20,9, " X     XX  X X X X X XX XX X     X X   X XX    X XXXX X    X   X  XX  ");
    mvprintw(21,9, " X XXX    X     XX   X X   XXX X X  XX XX    X X X   X X X X X  X X X ");
    mvprintw(22,9, " X  XX X X X X     XXX  XX   X  XXX     X  XX  X  XX X        X X X   ");
    mvprintw(23,9, "X X    XXX X XXX X   X XX X XX XX  X XX  XX    X X   X X XX X       X ");
    mvprintw(24,9, "   XX X    X   XX  XXX  X    X  XX    XX  X X XX   X   X  XX  X XXX X ");
    mvprintw(25,9, " X  X  XXX  XX X X  X X XX X X X X XX  XXX X  X  X XX  X X  XX   XX X ");
    mvprintw(26,9, " XX     XXX X XX  X X X   X  X X    X X      X   XX  XXX  X    X   X X");
    mvprintw(27,9, "   X X X  X     X X X   XX  X   X XX  X XXXXX X X  X   XX  X XX XX X X");
    mvprintw(28,9, " X  X  XX   X X   XXXXX X  X  X X  X XXX         X   X  XX X       X  ");
    mvprintw(29,9, "X X XX X  X X   X        X  XX    XX  X  XXX XXX  X X X X    XXXX X  X");
    mvprintw(30,9, "      X X X  XXXXXX X XXXXX   XX X  XX   X       X        XX       X  ");
    mvprintw(31,9, " X XX    X  X       X X   XXX   X       X XX X X X  X X XX  XX  XX XX ");
    mvprintw(32,9, " X   X X  X X XXXXX X X X X   XXX XX XXXX    XX  X XX  X   X XX    X  ");
    mvprintw(33,9, "   XX XXX X X X   X XXX X X X X     XXX X XX X X  XX  X  XX    X XX X ");
    mvprintw(34,9, "XX X    X    XX X X     X   X XX X X X    X          X  X   X XX X  X ");
    mvprintw(35,9, "    XXX X XX    XX  X XXX X X  X X   X   X  X   XXX    X   X     X X  ");
    mvprintw(36,9, " XX  X  X   X X X  XXXX X X XXXX XXX  X XX X X X X  X   X  XX XX    X ");
    mvprintw(37,9, " X X XX X X  X  X XX          XX  X X    X    X   XX XX X X      X X  ");
    mvprintw(38,9, "                  X  X X X XX    XX    X   XX   X      X  X X  X X   X");
    }

    if(mapa == 2){
        for(int p = 8; p < 30; p++){
            for(int o = 8; o < 60; o++){
                if(o == 8 || o == 59 || p == 8 || p == 29){
                    mvprintw(p, o, "X");
                    refresh();
                }else{
                    mvprintw(p, o, " ");
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
    attroff(COLOR_PAIR(1));
    attron(COLOR_PAIR(3));
    mvprintw(10,56, "C");
    attroff(COLOR_PAIR(3));
    attron(COLOR_PAIR(1));
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
    mvprintw(13,13, "X");
    mvprintw(13,14, "X");
    mvprintw(13,16, "X");
    mvprintw(13,17, "X");
    mvprintw(13,19, "X");
    mvprintw(13,22, "X");
    mvprintw(13,23, "X");
    mvprintw(13,26, "X");
    mvprintw(13,27, "X");
    mvprintw(13,28, "X");
    mvprintw(13,29, "X");
    mvprintw(13,30, "X");
    mvprintw(13,32, "X");
    mvprintw(13,33, "X");
    mvprintw(13,34, "X");
    mvprintw(13,42, "X");
    mvprintw(13,44, "X");
    mvprintw(13,48, "X");
    mvprintw(13,50, "X");
    mvprintw(13,53, "X");
    mvprintw(13,54, "X");
    mvprintw(13,56, "X");
    mvprintw(14,9, "X");
    mvprintw(14,11, "X");
    mvprintw(14,14, "X");
    mvprintw(14,16, "X");
    mvprintw(14,21, "X");
    mvprintw(14,22, "X");
    mvprintw(14,23, "X");
    mvprintw(14,25, "X");
    mvprintw(14,26, "X");
    mvprintw(14,34, "X");
    mvprintw(14,35, "X");
    mvprintw(14,36, "X");
    mvprintw(14,37, "X");
    mvprintw(14,38, "X");
    mvprintw(14,39, "X");
    mvprintw(14,40, "X");
    mvprintw(14,42, "X");
    mvprintw(14,46, "X");
    mvprintw(14,50, "X");
    mvprintw(14,51, "X");
    mvprintw(14,53, "X");
    mvprintw(14,56, "X");
    mvprintw(15,9, "X");
    mvprintw(15,11, "X");
    mvprintw(15,13, "X");
    mvprintw(15,14, "X");
    mvprintw(15,16, "X");
    mvprintw(15,17, "X");
    mvprintw(15,18, "X");
    mvprintw(15,19, "X");
    mvprintw(15,21, "X");
    mvprintw(15,22, "X");
    mvprintw(15,26, "X");
    mvprintw(15,27, "X");
    mvprintw(15,29, "X");
    mvprintw(15,30, "X");
    mvprintw(15,31, "X");
    mvprintw(15,32, "X");
    mvprintw(15,37, "X");
    mvprintw(15,44, "X");
    mvprintw(15,45, "X");
    mvprintw(15,46, "X");
    mvprintw(15,47, "X");
    mvprintw(15,48, "X");
    mvprintw(15,51, "X");
    mvprintw(15,53, "X");
    mvprintw(15,54, "X");
    mvprintw(15,56, "X");
    mvprintw(15,57, "X");
    mvprintw(16,9, "X");
    mvprintw(16,11, "X");
    mvprintw(16,13, "X");
    mvprintw(16,16, "X");
    mvprintw(16,22, "X");
    mvprintw(16,23, "X");
    mvprintw(16,24, "X");
    mvprintw(16,27, "X");
    mvprintw(16,28, "X");
    mvprintw(16,29, "X");
    mvprintw(16,33, "X");
    mvprintw(16,35, "X");
    mvprintw(16,37, "X");
    mvprintw(16,38, "X");
    mvprintw(16,39, "X");
    mvprintw(16,40, "X");
    mvprintw(16,41, "X");
    mvprintw(16,42, "X");
    mvprintw(16,43, "X");
    mvprintw(16,44, "X");
    mvprintw(16,46, "X");
    mvprintw(16,48, "X");
    mvprintw(16,51, "X");
    mvprintw(16,57, "X");
    mvprintw(17,10, "X");
    mvprintw(17,11, "X");
    mvprintw(17,13, "X");
    mvprintw(17,15, "X");
    mvprintw(17,16, "X");
    mvprintw(17,18, "X");
    mvprintw(17,19, "X");
    mvprintw(17,20, "X");
    mvprintw(17,22, "X");
    mvprintw(17,24, "X");
    mvprintw(17,25, "X");
    mvprintw(17,27, "X");
    mvprintw(17,31, "X");
    mvprintw(17,33, "X");
    mvprintw(17,35, "X");
    mvprintw(17,37, "X");
    mvprintw(17,41, "X");
    mvprintw(17,46, "X");
    mvprintw(17,49, "X");
    mvprintw(17,50, "X");
    mvprintw(17,51, "X");
    mvprintw(17,52, "X");
    mvprintw(17,54, "X");
    mvprintw(17,55, "X");
    mvprintw(17,56, "X");
    mvprintw(17,57, "X");
    mvprintw(18,13, "X");
    mvprintw(18,15, "X");
    mvprintw(18,20, "X");
    mvprintw(18,22, "X");
    mvprintw(18,24, "X");
    mvprintw(18,29, "X");
    mvprintw(18,31, "X");
    mvprintw(18,33, "X");
    mvprintw(18,39, "X");
    mvprintw(18,41, "X");
    mvprintw(18,42, "X");
    mvprintw(18,43, "X");
    mvprintw(18,44, "X");
    mvprintw(18,46, "X");
    mvprintw(18,48, "X");
    mvprintw(18,52, "X");
    mvprintw(18,55, "X");
    mvprintw(18,57, "X");
    mvprintw(19,9, "X");
    mvprintw(19,10, "X");
    mvprintw(19,12, "X");
    mvprintw(19,13, "X");
    mvprintw(19,15, "X");
    mvprintw(19,17, "X");
    mvprintw(19,18, "X");
    mvprintw(19,20, "X");
    mvprintw(19,22, "X");
    mvprintw(19,24, "X");
    mvprintw(19,25, "X");
    mvprintw(19,27, "X");
    mvprintw(19,28, "X");
    mvprintw(19,29, "X");
    mvprintw(19,31, "X");
    mvprintw(19,35, "X");
    mvprintw(19,36, "X");
    mvprintw(19,37, "X");
    mvprintw(19,38, "X");
    mvprintw(19,41, "X");
    mvprintw(19,42, "X");
    mvprintw(19,50, "X");
    mvprintw(19,52, "X");
    mvprintw(20,12, "X");
    mvprintw(20,13, "X");
    mvprintw(20,15, "X");
    mvprintw(20,18, "X");
    mvprintw(20,20, "X");
    mvprintw(20,24, "X");
    mvprintw(20,25, "X");
    mvprintw(20,26, "X");
    mvprintw(20,27, "X");
    mvprintw(20,31, "X");
    mvprintw(20,33, "X");
    mvprintw(20,38, "X");
    mvprintw(20,39, "X");
    mvprintw(20,44, "X");
    mvprintw(20,45, "X");
    mvprintw(20,46, "X");
    mvprintw(20,47, "X");
    mvprintw(20,48, "X");
    mvprintw(20,49, "X");
    mvprintw(20,52, "X");
    mvprintw(20,53, "X");
    mvprintw(20,54, "X");
    mvprintw(20,55, "X");
    mvprintw(20,56, "X");
    mvprintw(20,57, "X");
    mvprintw(20,58, "X");
    mvprintw(21,10, "X");
    mvprintw(21,11, "X");
    mvprintw(21,12, "X");
    mvprintw(21,13, "X");
    mvprintw(21,15, "X");
    mvprintw(21,16, "X");
    mvprintw(21,18, "X");
    mvprintw(21,20, "X");
    mvprintw(21,21, "X");
    mvprintw(21,22, "X");
    mvprintw(21,24, "X");
    mvprintw(21,29, "X");
    mvprintw(21,30, "X");
    mvprintw(21,31, "X");
    mvprintw(21,33, "X");
    mvprintw(21,34, "X");
    mvprintw(21,35, "X");
    mvprintw(21,36, "X");
    mvprintw(21,39, "X");
    mvprintw(21,41, "X");
    mvprintw(21,42, "X");
    mvprintw(21,43, "X");
    mvprintw(21,44, "X");
    mvprintw(21,49, "X");
    mvprintw(21,51, "X");
    mvprintw(21,52, "X");
    mvprintw(22,10, "X");
    mvprintw(22,11, "X");
    mvprintw(22,18, "X");
    mvprintw(22,22, "X");
    mvprintw(22,24, "X");
    mvprintw(22,26, "X");
    mvprintw(22,27, "X");
    mvprintw(22,28, "X");
    mvprintw(22,29, "X");
    mvprintw(22,33, "X");
    mvprintw(22,34, "X");
    mvprintw(22,36, "X");
    mvprintw(22,37, "X");
    mvprintw(22,39, "X");
    mvprintw(22,44, "X");
    mvprintw(22,45, "X");
    mvprintw(22,46, "X");
    mvprintw(22,47, "X");
    mvprintw(22,49, "X");
    mvprintw(22,50, "X");
    mvprintw(22,51, "X");
    mvprintw(22,54, "X");
    mvprintw(22,55, "X");
    mvprintw(22,56, "X");
    mvprintw(22,57, "X");
    mvprintw(23,11, "X");
    mvprintw(23,13, "X");
    mvprintw(23,14, "X");
    mvprintw(23,16, "X");
    mvprintw(23,18, "X");
    mvprintw(23,20, "X");
    mvprintw(23,22, "X");
    mvprintw(23,24, "X");
    mvprintw(23,26, "X");
    mvprintw(23,31, "X");
    mvprintw(23,33, "X");
    mvprintw(23,39, "X");
    mvprintw(23,41, "X");
    mvprintw(23,43, "X");
    mvprintw(23,44, "X");
    mvprintw(23,47, "X");
    mvprintw(23,49, "X");
    mvprintw(23,53, "X");
    mvprintw(23,54, "X");
    mvprintw(24,9, "X");
    mvprintw(24,11, "X");
    mvprintw(24,14, "X");
    mvprintw(24,16, "X");
    mvprintw(24,18, "X");
    mvprintw(24,20, "X");
    mvprintw(24,22, "X");
    mvprintw(24,26, "X");
    mvprintw(24,28, "X");
    mvprintw(24,29, "X");
    mvprintw(24,30, "X");
    mvprintw(24,31, "X");
    mvprintw(24,33, "X");
    mvprintw(24,35, "X");
    mvprintw(24,37, "X");
    mvprintw(24,39, "X");
    mvprintw(24,44, "X");
    mvprintw(24,45, "X");
    mvprintw(24,47, "X");
    mvprintw(24,51, "X");
    mvprintw(24,52, "X");
    mvprintw(24,56, "X");
    mvprintw(24,57, "X");
    mvprintw(25,9, "X");
    mvprintw(25,11, "X");
    mvprintw(25,12, "X");
    mvprintw(25,14, "X");
    mvprintw(25,16, "X");
    mvprintw(25,17, "X");
    mvprintw(25,18, "X");
    mvprintw(25,20, "X");
    mvprintw(25,22, "X");
    mvprintw(25,23, "X");
    mvprintw(25,24, "X");
    mvprintw(25,26, "X");
    mvprintw(25,28, "X");
    mvprintw(25,31, "X");
    mvprintw(25,33, "X");
    mvprintw(25,35, "X");
    mvprintw(25,37, "X");
    mvprintw(25,38, "X");
    mvprintw(25,39, "X");
    mvprintw(25,40, "X");
    mvprintw(25,41, "X");
    mvprintw(25,43, "X");
    mvprintw(25,44, "X");
    mvprintw(25,45, "X");
    mvprintw(25,47, "X");
    mvprintw(25,48, "X");
    mvprintw(25,49, "X");
    mvprintw(25,50, "X");
    mvprintw(25,51, "X");
    mvprintw(25,52, "X");
    mvprintw(25,54, "X");
    mvprintw(25,55, "X");
    mvprintw(25,56, "X");
    mvprintw(26,14, "X");
    mvprintw(26,20, "X");
    mvprintw(26,23, "X");
    mvprintw(26,26, "X");
    mvprintw(26,28, "X");
    mvprintw(26,30, "X");
    mvprintw(26,33, "X");
    mvprintw(26,35, "X");
    mvprintw(26,37, "X");
    mvprintw(26,55, "X");
    mvprintw(26,58, "X");
    for(int c = 9; c < 59; c++){
        mvprintw(27, c, "X");
    }
    mvprintw(27,9, " ");
    mvprintw(27,15, " ");
    mvprintw(27,22, " ");
    mvprintw(27,27, " ");
    mvprintw(27,29, " ");
    mvprintw(27,34, " ");
    mvprintw(27,39, " ");
    mvprintw(27,41, " ");
    mvprintw(27,44, " ");
    mvprintw(27,48, " ");
    mvprintw(27,50, " ");
    mvprintw(27,57, " ");
    }

    if(mapa == 1){
        for(int p = 8; p < 38; p++){
            for(int o = 8; o < 18; o++){
                if(o == 8 || o == 17 || p == 8 || p == 37){
                    mvprintw(p, o, "X");
                    refresh();
                }else{
                    mvprintw(p, o, " ");
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
        attroff(COLOR_PAIR(1));
        attron(COLOR_PAIR(3));
        mvprintw(14, 9, "C");
        attron(COLOR_PAIR(3));
        attron(COLOR_PAIR(1));
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
    attroff(COLOR_PAIR(1));

    while(mapa == 1 || mapa == 2 || mapa == 3 || mapa == 4){
        init_pair(2, COLOR_RED, COLOR_WHITE);
        attron(COLOR_PAIR(2));
        if(mapa == 1){
            y = 36; 
            x = 12;
            mvprintw(y, x, "O");
            refresh();
            max_x = max_x1;
            max_y = max_y1;
            mapa = 4;
        }

        if(mapa == 2){
            y = 28;
            x = 34;
            mvprintw(y, x, "O");
            refresh();
            max_x = max_x2;
            max_y = max_y2;
            mapa = 4;
        }

        if(mapa == 3){
            y = 38;
            x = 9;
            mvprintw(y, x, "O");
            refresh();
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
     attroff(COLOR_PAIR(2));
    }

    getchar();
    endwin();
    return EXIT_SUCCESS;
}
