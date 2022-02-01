#include <stdio.h>
#include <stdlib.h>

int perfect_number(){
    int limit = 1, divisible_num = 0;
    while (limit < 32767){
        for(int i=1; i < limit; i++){
            if(limit % i == 0){
                divisible_num += i;
            }
        }
        if(divisible_num == limit){
            printf("%d, ", divisible_num);
        }
        limit += 1;
        divisible_num = 0;
    }
}
int main(){
    perfect_number();
}