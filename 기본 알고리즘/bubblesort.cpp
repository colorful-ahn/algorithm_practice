#include<stdio.h>

int main(){
    int arr[10]={2,5,4,7,8,6,1,3,10,9};
    int temp;
    
    for(int i=0; i<10; i++){
        for(int j=0; j<9-i; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
        
    }
    for(int i=0; i<10; i++){
        printf("%d ",arr[i]);
    }
}