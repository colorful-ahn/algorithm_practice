#include<stdio.h>

int getP(int p[],int x){
    if(p[x]==x) return x;
    return p[x] = getP(p,p[x]);
}

int unionf(int p[],int a, int b){
    a = getP(p,a);
    b = getP(p,b);
    if(a<b) p[b] = a;
    else p[a] = b;

}

int findf(int p[], int a, int b){
    a= getP(p,a);
    b= getP(p,b);
    if(a==b) return 1;
    return 0;
}

int main(){
    int p[11];
    for(int i=1; i<=10; i++){
        p[i]=i;
    }
    unionf(p,1,2);
    unionf(p,2,3);
    unionf(p,3,4);
    unionf(p,5,6);
    unionf(p,6,7);
    unionf(p,7,8);
    printf("1과 5는 연결되어 있을까?   %d\n",findf(p,1,5));
    unionf(p,1,5);
    printf("1과 5는 연결되어 있을까?   %d\n",findf(p,1,5));


}