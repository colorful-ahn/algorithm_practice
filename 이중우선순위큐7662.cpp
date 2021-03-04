#include<bits/stdc++.h>

using namespace std; 

int t,n; 

int main(){
	
	scanf("%d",&t);
	while(t-->0){
		multiset<int> m;
		multiset<int>::iterator iter;
		scanf("%d",&n);
		
		for(int i=0; i<n; i++){
			char ch;
			int x;
			cin >> ch >> x;
			if(ch == 'I'){
				m.insert(x);
			}else{
				if(m.empty()) continue;
				if(x==1){
					iter = m.end();
					iter--;
					m.erase(iter);
				}
				else{
					m.erase(m.begin());
				}
			}
		}
		if(m.empty()) printf("EMPTY\n");
		else{
			iter=m.end();
			iter--;
			printf("%d %d\n",*iter,*m.begin());
		}
		
	}
}

