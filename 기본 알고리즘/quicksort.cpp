#include<stdio.h>

int num=10;
int arr[10]={1,10,8,5,4,6,3,7,2,9};

void qs(int s,int e){
    if(s>=e) return;  //원소가 1개인 경우
    int pivot = s;
    int i = s+1;
    int j = e;
    int temp;

    while(i<=j){    //엇갈릴 때 까지
        while(arr[i]<=arr[pivot]){ //피벗보다 큰 값을 만날 때 까지
            i++;
        }
        while(arr[j]>=arr[pivot] && j > s){     //피벗보다 작은 값을 만날 때 까지
            j--;
        }
        if(i>j){
            temp=arr[j];
            arr[j]=arr[pivot];
            arr[pivot]=temp;
        }else{
            temp=arr[j];
            arr[j]=arr[i];
            arr[i]=temp;
        }
    }

    qs(s,j-1);
    qs(j+1,e);


}

int main(){
    qs(0,num-1);
    for(int i=0; i<10; i++){
        printf("%d ",arr[i]);
    }
}