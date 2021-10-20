#include <superkarel.h>

void turn_right();
void chod();
void navrat();

int main(){

    turn_on("task_2.kw");

    set_step_delay(50);

    while(beepers_present()==false){
        chod();
    }

    while(beepers_present()){
        pick_beeper();
    }

    while(no_beepers_in_bag()==false){
      turn_left();
      turn_left();
      navrat();
      if(front_is_blocked()&&left_is_blocked()&&right_is_blocked()){
        break;
      }
    }
    
    do{
        turn_left();
    }while(not_facing_north());

    turn_off();
    return 0;
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

void chod(){
    while(left_is_blocked()){
        step();
    }
    turn_left();
    step();
}

void navrat(){
   while(left_is_blocked()&&front_is_clear()){
        step();
    }
    do{
    turn_right();
    }while(front_is_clear());
}
