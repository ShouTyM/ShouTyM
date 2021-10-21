#include <superkarel.h>

void corner();
void ram();
void turn_around();
void kontrola();
void stred();
void turn_right();
void find_stred();
void kotva();

int main(){

    turn_on("task_5.kw");
    set_step_delay(100);

    corner();
    turn_left();
    stred();
    stred();
    put_beeper();
    corner();
    ram();
    ram();
    ram();
    ram();

    find_stred();
    while(not_facing_west()){
        turn_left();
    }
    find_stred();
    while(not_facing_north()){
        turn_left();
    }
    pick_beeper();

    turn_off();
    return 0;
}

void corner(){
    while(not_facing_south()){
        turn_left();
    }
    
    while(front_is_clear()){
        step();
    }

    while(not_facing_east()){
        turn_left();
    }

    while(front_is_clear()){
        step();   
    }

    while(not_facing_north()){
        turn_left();
    }
}

void ram(){
    while(front_is_clear()){ 
        if(beepers_present()==false){
            put_beeper();
        }
        step();
    }
    turn_left();
}

void turn_around(){
    turn_left();
    turn_left();
}

void kontrola(){
    if(beepers_present()){
        turn_around();
        step();
        if(beepers_present()==false){
        put_beeper();
        }
        step();
        while(beepers_present()||front_is_clear()){
            pick_beeper();
            if(front_is_clear()){
                step();
            }
        }
        turn_around();
        while(beepers_present()==false){
            step();
        }
        step();
        while(beepers_present()||front_is_clear()){
            pick_beeper();
            if(front_is_clear()){
                step();
            }
        }
        turn_around();
        while(beepers_present()==false){
            step();
        }
        while(not_facing_north()){
            turn_left();
        }
        pick_beeper();
        
    }else{
        return;
    }
}

void stred(){
    if(beepers_present()==false){
        put_beeper();
        }
    step();
    step();
    if(beepers_present()){
    kontrola();
    return;
    }
    while(beepers_present()==false&&front_is_clear()){
       step();
    }
    turn_around();
    if(beepers_present()==false){
        put_beeper();
    }else{
        step();
        put_beeper();
    }
   if(beepers_present()){
        stred();
   }
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

void find_stred(){
    if(front_is_clear()){
        step();
    }
    if(front_is_clear()){
        step();
    }
    if(front_is_clear()){
        find_stred();
    }else{
        turn_around();
    }
    step();
}
