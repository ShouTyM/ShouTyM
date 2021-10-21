#include <superkarel.h>

void turn_right();
void chod();
void turn_around();
void navrat();

int main(){

    turn_on("task_2.kw");

    set_step_delay(150);

    while(no_beepers_present()){
        chod();
    }
    navrat();

    turn_off();
    return 0;
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

void chod(){
    while(left_is_blocked()&&front_is_clear()){
    if(beepers_present()){
        turn_around();
        navrat();

    }
    step();
    }
    if(beepers_present()){
        turn_around();
        navrat();
    }
    if(front_is_blocked()){
    turn_left();
    step();
    }
}

void turn_around(){
    turn_left();
    turn_left();
}

void navrat(){
    while(beepers_present()){
        pick_beeper();
    }
    if(front_is_blocked()){
        turn_around();
    }
    while(beepers_in_bag()){
        while(front_is_blocked()){
        turn_right();
        }
            step();
            if(right_is_blocked()&&left_is_blocked()&&front_is_blocked()){
            turn_off();
            }
      }
}
