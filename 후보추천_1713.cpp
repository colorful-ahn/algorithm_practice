#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int recommend_count[101];

int main(){
	
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	int N;
	cin >> N; //사진 
	if(N<=0 || N>20){
		return 0;
	}
	else{
		vector<pair <int,int> > v(N, { 0 , 0 });  //시간과 사진(후보 번호) 
		int recommend;
		bool replace;
		
		
		cin >> recommend; //추천회수 
		if(recommend<0 || recommend>=1000){
			return 0;
		}
		else{
		
			for (int i=0; i< recommend; i++){
				int st_num;
				cin >> st_num;
				replace=true;
				if(st_num <1 || st_num>100){
					return 0;
				} 
				else{
					recommend_count[st_num] +=1;
				
				
				for(int j=0; j<N;j++){
					//액자 비어있음 
					if(v[j].second == 0){
						v[j].second = st_num;
						v[j].first = i;
						
						replace = false;
						break;
					}
					else if(v[j].second == st_num){
						replace = false;
						break;
					}
				}
				
				//change picture
				if(replace)
				{
					int index = 0;
					for(int j=1;j<N;j++){
						if(recommend_count[v[j].second] == recommend_count[v[index].second]){
							if(v[j].first < v[index].first){
								index = j;
							}
						}
						else if (recommend_count[v[j].second] < recommend_count[v[index].second]){
							index = j;
						}
						
					}
					recommend_count[v[index].second] = 0;
						v[index].first = i;
						v[index].second = st_num;
					
				}
				}
				
		}
			
			vector<int> picture;
			for(int i=0; i<N;i++){
				picture.push_back(v[i].second);
			}
			sort(picture.begin(), picture.end());
			
			for( int i =0; i<N; i++){
				cout << picture[i] << " ";
			}
			cout <<"\n";
		
		}
		
	}
	return 0;
}



