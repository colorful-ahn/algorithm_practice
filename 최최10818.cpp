#include<bits/stdc++.h>

int n;
int arr[1000001];

int getmin(int a, int b) {return a<b? a:b;}
int getmax(int a, int b) {return a>b? a:b;}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n;i++){
		scanf("%d",&arr[i]);
		
	}
	int min=arr[0];
	int max=arr[0];
	
	for(int i=1; i<n; i++){
		min = getmin(min,arr[i]);
		max = getmax(max,arr[i]);	
	}
	printf("%d %d",min,max); 
}
