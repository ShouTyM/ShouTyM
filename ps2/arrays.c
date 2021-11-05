#include <stdio.h>

float lift_a_car(const int stick_length, const int human_weight, const int car_weight);

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

  double r2 = (float)stick_length * human_weight / (human_weight + car_weight);
   return r2;

   // printf("Dvih auta je: %.2f",r2);
}
