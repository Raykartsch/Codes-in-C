#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

void cronometer(){
    int cronometro[6] = {0,0,0,0,0,0};
    while((cronometro[0] != 2) || (cronometro[1] != 4)){
        printf(" %d%d:%d%d:%d%d \n", cronometro[0], cronometro[1], cronometro[2], cronometro[3], cronometro[4], cronometro[5]); 

        switch(cronometro[5]){
            case 9:
                cronometro[4] += 1;
                cronometro[5] = 0; 
                Sleep(1000);
                break;
            default:
                cronometro[5] += 1;
                Sleep(1000);
                break;
        }
        switch(cronometro[4]){
            case 6:
                cronometro[3] += 1;
                cronometro[5] = 0;
                cronometro[4] = 0; 
                Sleep(1000);        
                break;  
        }
        switch (cronometro[3]){
            case 10:
                cronometro[2] += 1;
                cronometro[3] = 0;
                Sleep(1000);
                break;
        }
        switch(cronometro[2]){
            case 6:
                cronometro[1] += 1;
                cronometro[2] = 0;
                cronometro[3] = 0;
                Sleep(1000);  
                break;
        }
        switch(cronometro[1]){
            case 10:
                cronometro[0] += 1;
                cronometro[1] = 0;
                Sleep(1000);
                break;
        }
        switch(cronometro[0]){
            case 2:
                if(cronometro[1] == 4){
                    cronometro[0] = 0;
                    cronometro[1] = 0;
                    cronometro[2] = 0;
                    cronometro[3] = 0;
                    cronometro[4] = 0;
                    cronometro[5] = 0;
                    Sleep(1000);
                    break;
                }
        }             
    }
}
int main(){
    cronometer();
}