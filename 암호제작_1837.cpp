#include<bits/stdc++.h>


using namespace std;

vector<int> v;
vector<int> v1;
vector<int> vm; 


int main(){
	
	ios_base::sync_with_stdio(false); 
	cout.tie(NULL); 
	cin.tie(NULL);
	
	int x =2;
	int K;
	int p=0;
	int j=0;
	string P;
	
	cin >> P >> K; 
	v.assign(K,0);
	vm.assign(K,0);
	
	for(int i=0; i<K-1; i++){
		v[i]=x;
		x++;
	}

	for(int i=0;i<K-1;i++){
		p=v[i];
		if(v[i]!=0){
			for(int j=i+1; j<K-1;j++){
			if(v[j]%p==0){
				v[j]=0;
			}
		}
		}else{
			continue;
		}	
	}
	
	for(int i=0; i<K-1;i++){
		if(v[i]!=0){
			v1.push_back(v[i]);	
		}else{
			continue;
		}
		
	}
	//p ����Ʈ  ���� ��.
	int r=0;
	// str���� �ε��� �ڸ���.	
//	} // 143 10 => 143�� 2 3 5 7 11�� ������ ����
	for(int i=0; i<v1.size();i++){
		int mod = 0;
		for(int j=0; j<P.length();j++){
			mod = (mod*10 + P[j]-'0')%v1[i];
			
		}
		cout << "v : "<<v1[i] << " d : " << mod << "\n";
	
	}
	 //mod ==0 �̸� BAD����ϰ� ���� ���� ����. 
	
	 
	
}

