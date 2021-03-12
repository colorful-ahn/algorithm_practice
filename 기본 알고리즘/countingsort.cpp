#include<stdio.h>

int main(){
    int temp;
    int count[5]={0,};
    int arr[30]={
        1,3,2,4,5,1,2,4,3,5,
        5,4,2,1,1,1,2,3,4,3,
        5,1,2,5,2,4,3,4,5,2

    };
    for(int i=0; i<30; i++){
        count[arr[i]-1]++;
    }
    for(int i=0; i<5; i++){
        if(count[i]!=0){
            for(int j=0; j<count[i]; j++){
                printf("%d ", i+1);
            }
        }
    }
}