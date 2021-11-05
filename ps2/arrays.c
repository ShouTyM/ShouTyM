#include <stdio.h>

float lift_a_car(const int stick_length, const int human_weight, const int car_weight);

float unit_price(const float pack_price, const int rolls_count, const int pieces_count);

int collatz(const int number);

int main(){



return 0;
}

float lift_a_car(const int stick_length, const int human_weight, const int car_weight){
  /*  printf("Zadaj dlzku palice: \n");
    scanf("%d",&stick_length);
    
    printf("Zadaj hmotnost cloveka: \n");
    scanf("%d",&human_weight);

    printf("Zadaj hmotnost auta: \n");
    scanf("%d",&car_weight);*/

  double lift_a_car = (float)stick_length * human_weight / (human_weight + car_weight);
   return lift_a_car;

   // printf("Dvih auta je: %.2f",r2);
}

float unit_price(const float pack_price, const int rolls_count, const int pieces_count){
   double unit_price = (rolls_count * pieces_count) / (float)pack_price;
   return unit_price;
}

int collatz(const int number){
    collatz = 1;
    while(number != 1){
        if(number %2 == 0){
            number = number / 2;
            collatz++;
        }else{
            number = (number * 3) + 1;
            collatz++;
        }

    }
    return collatz;
}
