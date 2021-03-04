#include<bits/stdc++.h>

int main(){
	int arr[9];
	int max=-1;
	int maxidx=-1;
	for(int i=0; i<9; i++){
		scanf("%d",&arr[i]);
		if(arr[i]>max){
			max=arr[i];
			maxidx=i;
		}
	}
	printf("%d\n%d",max,maxidx+1);
}
