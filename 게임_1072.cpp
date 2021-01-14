#include<iostream>


const int MAX = 1000000000;

using namespace std;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	long long X,Y;
	
	cin >> X >> Y;
	int Z = (Y * 100) / X;
	
	if(Z>=99){
		cout <<"-1";
		return 0;
	}
	
	
	int low=0;
	int hi=MAX+1;
	int ans=0;
	
	int mid;
	int change;
	
	while(low<hi){
		mid=(low+hi) / 2;
		change=(100 * (Y + mid)) / (X + mid);
		if(Z >= change){
			low = mid+1;
		}else{
			hi=mid;
		}
			
		}
		cout<<hi;
		
	return 0;
}

