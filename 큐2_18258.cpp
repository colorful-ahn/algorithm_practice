#include<bits/stdc++.h>
using namespace std; 

int n;

queue<int> q;


int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		char str[10];
		int x;
		scanf("%s",&str);
		if(str[0]=='p'){
			if(str[1]=='u'){
				scanf("%d",&x);
				q.push(x);
				}else if(str[1]=='o'){
				if(!q.empty()){
					printf("%d\n",q.front());
					q.pop();
				}else{
					printf("-1\n");
				}
			}	
		}else if(str[0]=='s'){
			printf("%d\n",q.size());
		}else if(str[0]=='e'){
			printf("%d\n",q.empty());
		}else if(str[0]=='f'){
			if(!q.empty()){
				printf("%d\n",q.front());
			}else{
				printf("-1\n");
			}
		}else if(str[0]=='b'){
			if(!q.empty()){
				printf("%d\n",q.back());
			}else{
				printf("-1\n");
			}
		}
	}
}
