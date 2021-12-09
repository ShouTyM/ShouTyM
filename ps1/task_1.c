#include <superkarel.h>
    
void test();    
void turn_right();
void skakanie();
void naspat();
void kotva();

int main(){
    turn_on("round1.kw");
    
    set_step_delay(100);

    step();
    while(no_beepers_present() == false){
        pick_beeper();
    }
    while(no_beepers_in_bag() == false){
        step();
        put_beeper();
        turn_left();
        turn_left();
    }
    while(not_facing_west()){
        turn_left();
    }
    while(front_is_clear()){
        step();
    }
    turn_left();
    turn_left();

    turn_off();
    return 0;
}
