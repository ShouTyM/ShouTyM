#include <stdio.h>
#include <math.h>

float lift_a_car(const int stick_length, const int human_weight, const int car_weight);

float unit_price(const float pack_price, const int rolls_count, const int pieces_count);

int collatz(const int number);

int opposite_number(const int n, const int number);

int main(){


return 0;
}

float lift_a_car(const int stick_length, const int human_weight, const int car_weight){
   float lift_a_car;
   
   lift_a_car = (float)stick_length * (float)human_weight / (human_weight + (float)car_weight);
   lift_a_car = round(lift_a_car * 100) / 100;
   return lift_a_car;
}

float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
   double unit_price = (rolls_count * pieces_count) / (float)pack_price;
   return unit_price;
}

int collatz(const int number){
    int pocet = 1; 
    int cislo = number;

    while(cislo != 1){
        if(cislo %2 == 0){
            cislo = cislo / 2;
            pocet++;
        }else{
            cislo = (cislo * 3) + 1;
            pocet++;
        }

    }
    return pocet;
}

int opposite_number(const int n, const int number){
    int opacne;
    int i = n;
    int c = number;

    if (i/2 == c){
        opacne = 0;
    }else if(i/2 > c){
        opacne = (i/2) + c;
    }else if(i/2 < c){
        opacne = (i/2) - c;
        opacne = (opacne - (opacne)) - opacne;
    }
    return opacne++;
}
