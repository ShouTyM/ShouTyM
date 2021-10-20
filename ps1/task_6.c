#include <superkarel.h>

void poklad();

int main(){

    turn_on("task_6.kw");
    set_step_delay(100);

    poklad();
    while(beepers_present()){
        poklad();
    }

    turn_off();
    return 0;
}

void poklad(){

    while(beepers_present()==false){
        step();
    }

    pick_beeper();
    if(beepers_present()==false){
        while(not_facing_north()){
            turn_left();
        }
        while(beepers_present()==false){
            step();
        }
        return;
    }else{
            pick_beeper();
            if(beepers_present()==false){
                while(not_facing_west()){
                    turn_left();
                }
                while(beepers_present()==false){
                    step();
                }
                return;
            }
     }
     if(beepers_present()){
        pick_beeper();
        if(beepers_present()==false){
            while(not_facing_south()){
                turn_left();
            }
            while(beepers_present()==false){
                step();
            }
            return;
        }else{
            pick_beeper();
            if(beepers_present()==false){
                while(not_facing_east()){
                    turn_left();
                }
                while(beepers_present()==false){
                    step();
                }
                return;
            }else{
            pick_beeper();
            turn_off();
        }
      }
    }
}
