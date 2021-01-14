#include<iostream>
#include<vector>

using namespace std;

vector<int> v;
int N =5;


void insert(int d,int len){
//	int len;
//	len = v.size()-N+1;
	if(len<=1){
		v[1]=d;
	} else{
	v[len]=d;
	int child = v.size();  //
	int parent = child/2;
	
	while(child >=1 && v[parent]<v[child]){  //10 100
		int temp;
		temp = v[child];
		v[parent] = v[child];
		v[parent] = temp;
		child = parent;
		parent /=2;
	}
	}
	cout << v[3];
}

void delete_(){
	int child = v.size();
	int root = 1;
	int parent = child/2;	
	int left = root*2;
	int right = root*2+1;
	
	v[root] = v[child];
	v.pop_back();
	
	while(true){
		if(v[left]!=0 || v[right]!=0){
			if(v[left]>v[root]){
				int temp;
				temp = v[root];
				v[left] = v[root];
				v[root] = temp;
				root*=2;
			}else if(v[right]>v[root]){
				int temp;
				temp = v[root];
				v[right] = v[root];
				v[root] = temp;
				root*=2;
				root+=1;
			}
			else{
				break;
			}
		}
	}
}



int main(){

	int x;
	int i=0;
	v.assign(N,0);
	for(int i=5; i>N;i--){
		insert(i,i);
	}
	
	
	//heap
	//cout << v[2];
	
	
}
