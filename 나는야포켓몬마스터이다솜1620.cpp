#include<bits/stdc++.h>

using namespace std;

char str[21];
int n,m;
map<string, int> mp1;
string mp2[100001];

int main(){
	
	cin >> n;
	cin >> m;
	
	for(int i=0; i<n; i++){
		
		scanf("%s",str);
		mp1.insert(pair<string, int> (str,i));
		mp2[i] = str;
	}
	for(int i=0; i<m; i++){
		scanf("%s",str);
		if(isdigit(str[0])){
			cout << mp2[atoi(str)-1] << "\n";
		}else{
			printf("%d\n",mp1[str]+1);
		}
		
	}
}
