#include<stdio.h>

const int num=9;
int arr[num]={9,7,2,4,3,1,2,5,6};

int main(){
    for(int i=1; i<num; i++){
        int c=i;
        do{
            int root = (c-1)/2;
            if(arr[root]<arr[c]){
                int temp = arr[root];
                arr[root] = arr[c];
                arr[c] = temp;
            }
            c = root;
        }while(c!=0);
    }

    for(int i=num-1; i>=0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i]=temp;
        int root = 0;
        int c =1;
        do{
            c = 2*root+1;
            if(arr[c]<arr[c+1] && c<i-1){
                c++;
            }
            if(arr[root] < arr[c] && c<i){
                int temp = arr[root];
                arr[root] = arr[c];
                arr[c] = temp;
            }
            root = c;
        }while(c<i);
    }

    for(int i=0; i<num; i++){
        printf("%d ",arr[i]);
    }
}