#include<bits/stdc++.h>

int arr[128][128];
int blue = 0;
int white = 0;


void divide(int x,int y,int n){
	int temp = 0;
	for(int i=x; i<x+n; i++){
		for(int j=y; j<y+n; j++){
			if(arr[i][j]){
				temp++;
			}
		}
	}
	if(!temp) white++;
	else if (temp == n*n) blue++;
	else{
		divide(x,y,n/2);
		divide(x,y+n/2,n/2);
		divide(x+n/2,y,n/2);
		divide(x+n/2,y+n/2,n/2);
	}
	
}


int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	divide(0,0,n);
	printf("%d\n%d",white,blue);
}
