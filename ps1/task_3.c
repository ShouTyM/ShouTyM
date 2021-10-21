#include <superkarel.h>

void turn_around();
void praca();
void ukladanie();
void navrat();
void turn_right();

int main(){

    turn_on("task_3.kw");
    set_step_delay(20);
   

    praca();


    turn_off();
    return 0;
}

void turn_around(){
    turn_left();
    turn_left();
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

void praca(){
    while(not_facing_south()){
        turn_left();
    }
    if(front_is_clear()){
    step();
    }else{
        navrat();
    }
    while(not_facing_east()){
        turn_left();
    }
    while(front_is_clear()){
        if(beepers_present()){
            pick_beeper();
        }
        step();
    }
    if(beepers_present()){
        pick_beeper();
    }
    ukladanie();
}

void ukladanie(){
while(beepers_in_bag()){
   while(not_facing_north()){
        turn_left();
    }
    step();
    if(beepers_present()){
        turn_around();
        step();
        if(beepers_in_bag()){
        put_beeper();
        }
        turn_right();
        if(front_is_clear()){
            step();
            ukladanie();
        }else{
            praca();
        }
        }else{
        turn_around();
        step();
        turn_right();
        if(front_is_clear()){
            step();
            ukladanie();
        }else{
            praca();
        }
    }
}
while(not_facing_west()){
    turn_left();
}
while(front_is_clear()){
    step();
}
praca();
}

void navrat(){
    while(not_facing_north()){
        turn_left();
    }
    while(front_is_clear()){
        step();
    }
   do{ 
   while(not_facing_east()){
        turn_left();
   }
    while(front_is_clear()&&no_beepers_present()){
        step();
    }
    if(beepers_present()){
        turn_around();
       while(front_is_clear()){
        step();
        }
        while(not_facing_east()){
            turn_left();
        }
        turn_off();
    }else{
            turn_around();
            while(front_is_clear()){
            step();
            }
            turn_left();
            step();
    }
    }while(beepers_present()==false);
    turn_off();
}
