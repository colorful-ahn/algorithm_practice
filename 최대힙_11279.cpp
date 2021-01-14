#include <bits/stdc++.h>

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	//pq
	priority_queue<int, vector<int>, less<int> > pq;
	
	int N,x;
	//total
	cin >> N;
	while(N--){
		cin >> x;
		// add
		if(x!=0){
			pq.push(x);
		}else{		// empty
			if(pq.empty()){
				cout << "0\n";
			}else{	// input == 0 and print
				cout << pq.top()<<"\n";
				pq.pop();
			}
		}
	}
	
}
