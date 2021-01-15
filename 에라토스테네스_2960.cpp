#include<bits/stdc++.h>

using namespace std;

vector<pair <int,int> > v;

int main(){
	
	int N,K;
	
	int x=2;
	int count = 0;
	
	
	cin >> N >> K;
	v.assign(N,{0,0});
	
	for(int i=0; i<N-1; i++){
		v[i].first=x;
		x++;
	}

	int p=0;
	for(int i=0; i<N-1; i++){
		p=v[i].first;
		for(int j=0;j<N-1;j++){
			if(v[j].first%p==0&&v[j].second ==0){
				v[j].second =1;
				count ++;
				if(count == K){
					cout << v[j].first;
					break;
				}
			}
		}
	}
}
