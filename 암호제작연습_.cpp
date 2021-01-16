#include <bits/stdc++.h>
using namespace std;


bool visited[1000000]; 
int K;
string P;

bool check(int num){
	int mod = 0;	
	
	for(int i=0; P[i];i++) 
		mod = (mod*10+(P[i]-'0'))%num;
	if(mod==0) return true;
	return false;
}
int main(){
ios_base::sync_with_stdio(false); 
cout.tie(NULL); 
cin.tie(NULL);

cin >> P >> K;
bool good = true;
int ans = 0;

for(int i=2; i<K; ++i){
	if(visited[i]) continue;

	if(check(i)){
		good = false;
		ans = i;
		break;
	}

	for(int j=2*i; j<K; j+=i) visited[j] = true;
}
if(good) cout << "GOOD" << '\n';
else cout << "BAD " << ans << '\n';

return 0;
}
