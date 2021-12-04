#include <stdio.h>
#include <stdlib.h>
#include <ncurses.h>
#include <time.h>
#include <unistd.h>

int timer();

int main(){

    srand(time(NULL));

    initscr();
    cbreak();
    noecho();
    keypad(stdscr, TRUE);
    curs_set(FALSE);
    nodelay(stdscr, TRUE);
    int y = 10, x = 10, a;
    int min_y = 9, max_y = 28;
    int min_x = 9, max_x = 78;
    int mapa = 0;
    int moznost = 0;


    nodelay(stdscr, FALSE);
    echo();
    mvprintw(12, 10, "1. Urovne");
    mvprintw(14, 10, "2. Ovladanie/info");
    mvprintw(10, 10, "Vyber si moznost: ");
    refresh();
    scanw("%d", &moznost);
//    nodelay(stdscr, TRUE);
  //  noecho();
    clear();

    if(moznost == 1){
        mvprintw(10, 10, "1. Lahke bludisko");
        mvprintw(12, 10, "2. Stredne tazke bludisko");
        mvprintw(14, 10, "3. Tazke bludisko");
        mvprintw(8, 10, "Tvoj vyber bludiska: ");
        scanw("%d", &mapa);
        nodelay(stdscr, TRUE);
        noecho();
        clear();
    }else if(moznost == 2){    
        mvprintw(10, 10, "X - Hrac");
        mvprintw(12, 10, "# - Stena");
        mvprintw(14, 10, "* - Bonusove body");
        mvprintw(16, 10, "C - Ciel");
        mvprintw(18, 10, "W - Pohyb hore");
        mvprintw(20, 10, "A - Pohyb dolava");
        mvprintw(22, 10, "S - Pohyb dole");
        mvprintw(24, 10, "D - Pohyb doprava");
    }









    //spustenie mapy v
    if(mapa == 1){
        for(int p = 8; p < 30; p++){
            for(int o = 8; o < 80; o++){
                if(o == 8 || o == 79 || p == 8 || p == 29){
                mvprintw(p, o, "#");
                refresh();
                }
            }
        }
    }

    while(1){
        
        mvprintw(y, x, "O");
        refresh();
        a = getch();
            if(a == 'W' || a == 'w'){
                if(y == min_y){
                }else{
                    y--;
                    mvprintw(y + 1, x," ");
                }
            }else if(a == 'A' || a == 'a'){
                if(x == min_x){
                }else{
                    x--;
                    mvprintw(y, x + 1, " ");
                }
            }else if(a == 'S' || a == 's'){
                if(y == max_y){
                }else{
                y++;
                mvprintw(y - 1, x, " ");
                }
            }else if(a == 'D' || a == 'd'){
                if(x == max_x){
                }else{
                x++;
                mvprintw(y, x - 1, " ");
                }
            }
    }

    getchar();
    endwin();
    return EXIT_SUCCESS;
}
