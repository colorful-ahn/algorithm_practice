#include<iostream>
#include <algorithm>
#include <vector>



using namespace std;

int N,M;
int start_=0 ,end_ =0;
int ans=0;

vector<int> v;


int sum(int s, int e){
	int sum;
	if(s == e){
		return v.at(s);
	}else{
	
	for(int i=s;i<=e;i++){
		sum +=v.at(i);
	}
	return sum;	
}
	
	
}

int main(void){
	int a;
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	
	cin >> N >> M;
	if(N<1 || N>10000 || M<1 || M>300000000){
		return 0;
	}
	else{
		for(int i=0; i<N; i++){
			cin >> a;
			if(a>30000 || a<1){
				return 0;
			}else{
				v.push_back(a);
			}
			
		}
		//v
//		while(1){
//		int s = sum(start_,end_);
//		if(start_ == end_){
//			++end_;
//			if(v.at(start_)==M){
//				ans+=1;
//			}		
//		}
//		else{
//			cout << "";
//			if(s == M){
//				ans+=1;
//				++start_;
//			}
//			else if(s < M){
//				++end_;
//			}
//			else if(s > M){
//				++start_;
//			}
//		}
//		if(v.size() <= end_){
//			break;
//		}
//		
//	}
	for(int start=0; start<N; start++){
            int sum = v.at(start);

            if(sum == M){
                ans++;
                continue;
            }
            for(int end=start+1; end<N; end++){
                sum+= v.at(end);
                if(sum == M){
                    ans++;
                    break;
                }
            }
        }
	cout << ans;
	}
	return 0;
	
	
}
