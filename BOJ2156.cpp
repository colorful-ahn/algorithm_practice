#include<stdio.h>

#define MAX 100001
int arr[MAX]={0,};
int dp[MAX]={0,};
int n;
int ans=0;

int get_max(int a, int b){
    return a>b?a:b;}

int main(){
    scanf("%d",&n);
    for(int i=1; i<=n; i++){
        scanf("%d",&arr[i]);
    }
    dp[1]=arr[1];
    dp[2]=dp[1]+arr[2];

    for(int i=3; i<=n; i++){
        dp[i]=get_max(arr[i-1]+dp[i-3]+arr[i],dp[i-2]+arr[i]);
        dp[i]=get_max(dp[i],dp[i-1]);
    }
    printf("%d",dp[n]);
    
}