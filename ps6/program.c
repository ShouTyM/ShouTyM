#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>

int main(){

    srand(time(NULL));

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    int y = 10, x = 10, a;
    char b[5];
    int min_y = 9; 
    int min_x = 9;
    int max_y = 0, max_x = 0;
    int max_y1 = 38, max_x1 = 18;
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
        mvprintw(10, 10, "X - Hrac");
        mvprintw(12, 10, "# - Stena");
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
                }
            }
        }
    }

    if(mapa == 2){
        for(int p = 8; p < 30; p++){
            for(int o = 8; o < 60; o++){
                if(o == 8 || o == 59 || p == 8 || p == 29){
                mvprintw(p, o, "#");
                refresh();
                }
            }
        }
    }

    if(mapa == 1){
        for(int p = 8; p < 40; p++){
            for(int o = 8; o < 20; o++){
                if(o == 8 || o == 19 || p == 8 || p == 39){
                    mvprintw(p, o, "#");
                    refresh();
                }
            }
        }
        for(int o = 10; o < 14; o++){
            mvprintw(o, 16, "#");
            refresh();
        }
    }

    while(mapa == 1 || mapa == 2 || mapa == 3){
        
        if(mapa == 1){
            max_x = max_x1;
            max_y = max_y1;
        }

        if(mapa == 2){
            max_x = max_x2;
            max_y = max_y2;
        }

        if(mapa == 3){
            max_x = max_x3;
            max_y = max_y3;
        }

            mvprintw(y, x, "O");
            refresh();
 
        a = getch();
            if(a == 'W' || a == 'w'){
                if(y  != min_y){
                    y--;
                    mvprintw(y + 1, x," ");
                }
            }else if(a == 'A' || a == 'a'){
                if(x != min_x){
                    x--;
                    mvprintw(y, x + 1, " ");
                }
            }else if(a == 'S' || a == 's'){
                if(y != max_y){
                y++;
                mvprintw(y - 1, x, " ");
                }
            }else if(a == 'D' || a == 'd'){
                if(x != max_x){
                x++;
                mvprintw(y, x - 1, " ");
                }
            }
    }

    getchar();
    endwin();
    return EXIT_SUCCESS;
}
