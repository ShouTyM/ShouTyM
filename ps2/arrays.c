#include <stdio.h>
#include <math.h>

float lift_a_car(const int stick_length, const int human_weight, const int car_weight);

float unit_price(const float pack_price, const int rolls_count, const int pieces_count);

int collatz(const int number);

int opposite_number(const int n, const int number);

void counter(const int input_array[], const int array_size, int result_array[2]);

int array_min(const int input_array[], const int array_size);

int array_max(const int input_array[], const int array_size);

unsigned long special_counter(const int input_array[], const int array_size);

int special_numbers(const int input_array[], const int array_size, int result_array[]);

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
   float kusy;
   float cena;
   
   kusy = (float) (rolls_count * pieces_count);

   cena = pack_price / kusy;
   
   cena = (100 * 100 * cena) + 0.5;
   
   cena = ((int)cena);
   
   cena = ((float)cena) / 100;

   return cena;
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

void counter(const int input_array[], const int array_size, int result_array[2]){
    for(int i = 0; i < array_size; i++){
        if(i%2 == 0){
            result_array[0] = result_array[0] + input_array[i];
        }else{
            result_array[1] = result_array[1] + input_array[i];
        }
    }
}

int array_min(const int input_array[], const int array_size){
    if(input_array == NULL){
        return -1;
    }else{
        int mini = input_array[0];
        for(int i = 1; i < array_size; i++){
            if(input_array[i] < mini){
                mini = input_array[i];
            }
        }
        return mini;
    }
}

int array_max(const int input_array[], const int array_size){
    if(input_array == NULL){
        return -1;
    }else{
        int maxi = input_array[0];
        for(int i = 1; i < array_size; i++){
            if(input_array[i] > maxi){
                maxi = input_array[i];
            }
        }
        return maxi;
    }
}

unsigned long special_counter(const int input_array[], const int array_size){
    unsigned long cislo1 = 0;
    long cislo2 = 0;

    for(int i = 0; i < array_size; i++){
        if(i%2 != 0){
            cislo2 = cislo2 + (pow((double)input_array[i],2));
        }else{
            cislo2 = cislo2 + input_array[i];
        }
    }
    cislo1 = cislo2;
    return cislo1;
}

int special_numbers(const int input_array[], const int array_size, int result_array[]){
    int cislo1 = 0;
    int cislo2 = 0;

    for(int i = 0; i < (array_size - 1); i++){
        for(int j = (i + 1); j < array_size; j++){
            cislo1 = cislo1 + (input_array[j]);
        }
            if(input_array[i] > cislo1){
                result_array[cislo2] = input_array[i];
                cislo2++;
            }
            cislo1 = 0;
    }
    result_array[cislo2] = input_array[array_size - 1];
    cislo2++;

    return cislo2;
}
