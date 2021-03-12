#include<stdio.h>

int main(){
    int arr[10]={2,5,4,7,8,6,1,3,10,9};
    int temp,idx;
    
    for(int i=0; i<10; i++){
        idx=i;
        while(arr[idx]>arr[idx+1]){
            temp = arr[idx];
            arr[idx]=arr[idx+1];
            arr[idx+1]=temp;
            idx--;
            }
        }

    for(int i=0; i<10; i++){
        printf("%d ",arr[i]);
    }
}