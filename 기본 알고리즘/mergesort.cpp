#include<stdio.h>

int num = 10;
int sorted[10];
int arr[10]={1,9,8,6,7,3,2,5,10,4};

void merge(int m,int mid, int n){
    int i=m;
    int j=mid+1;
    int k=m;
    //작은 순서대로 배열에 삽입
    while(i<=mid && j<=n){
        if(arr[i]<=arr[j]){
            sorted[k]=arr[i];
            i++;
        }else{
            sorted[k]=arr[j];
            j++;
        }
        k++;
    }
    if(i>mid){
        for(int t=j; t<=n; t++){
            sorted[k]=arr[t];
            k++;
        }
    }else{
        for(int t=i; t<=mid; t++){
            sorted[k] = arr[t];
            k++;
        }
    }
    for(int t=m; t<=n; t++){
        arr[t]=sorted[t];
    }
}

void divide(int m, int n){
    if(m<n){
        int mid=(m+n)/2;
        divide(m,mid);
        divide(mid+1,n);
        merge(m,mid,n);
    }
}

int main(){
    divide(0,9);
    for(int i=0; i<10; i++){
        printf("%d ",arr[i]);
    }
}