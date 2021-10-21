#include <superkarel.h>

void turn_right();
void vypln();
void hladaj();

int main(){
    turn_on("task_4.kw");
    set_step_delay(300);   


    hladaj();


    turn_off();
    return 0;
}

void turn_right(){
    turn_left();
    turn_left();
    turn_left();
}

void vypln(){
        while(not_facing_north()){
            turn_left();
        }

        while(front_is_clear()){
            step();
        }

        do{
            turn_left();
        }while(not_facing_south());

        while(front_is_clear()||beepers_present()){
           while(beepers_present()){
                pick_beeper();
            }
           if(front_is_clear()){
             step();
           }
        }

        do{
            turn_left();
        }while(not_facing_north());
         
        do{
        put_beeper();
        if(front_is_clear()){
        step();
        }
        }while(front_is_clear() || beepers_present() == false);

        while(not_facing_south()){
            turn_left();
        }
        while(front_is_clear()){
            step();
        }
        turn_left();
        if(front_is_clear()){
            step();
            hladaj();
        }else{
            turn_off();
        }
    }

void hladaj(){
        while(not_facing_north()){
            turn_left();
        }

        while(front_is_clear()){
           if(beepers_present()){
           vypln();
           }
           step();
           
        }

        do{
            turn_left();
        }while(not_facing_south());
    
        while(front_is_clear()){
            step();
        }
        turn_left();
        if(front_is_clear()){
            step();
            hladaj();
        }else{
            turn_off(); 
        }
    return;
}
