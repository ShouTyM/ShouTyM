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

    //spustenie mapy v

    for(int p = 8; p < 30; p++){
        for(int o = 8; o < 80; o++){
            if(o == 8 || o == 79 || p == 8 || p == 29){
            mvprintw(p, o, "#");
            refresh();
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
