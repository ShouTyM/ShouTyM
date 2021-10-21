#include <superkarel.h>
    
void turn_right();
void skakanie();
void naspat();
void kotva();

int main(){
    turn_on("test00.kw");
    
    set_step_delay(100);

    kotva();

    while(beepers_present()==false){
        skakanie();
    }

    pick_beeper();

    while(beepers_present()==false){
        naspat();
    }
    
    pick_beeper();
    
     do{
        turn_left();
     }while(not_facing_west());

    turn_off();
    return 0;
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

    
void skakanie(){ 

    if(front_is_blocked()){
        turn_left();
    }

    if(front_is_clear()){
        step();
    }
    
    if(right_is_clear()){
        turn_right();
    }
}

void naspat(){

    if(front_is_blocked()){
        turn_right();
    }
    
    if(left_is_clear()){
        turn_left();
    }

    if(front_is_clear()){
        step();
    }
}

void kotva(){
    while(no_beepers_in_bag()==false){
        put_beeper();
    }
    while(front_is_blocked()){
    turn_left();
    }
   step();
}
