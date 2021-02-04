#include<bits/stdc++.h>

using namespace std;

char arr[5][5];
bool visited[5][5]={false};
string word;
vector<char> v;
int s=0;

int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,1,-1,1,-1,-1,1};

void hasWord(int x, int y, char start){
	v.push_back(word[start]);
	visited[x][y]=true;
	int xcur = x;
	int ycur = y;
	for(int i=0; i<8; i++){
		int xnxt=xcur+dx[i];
		int ynxt=ycur+dy[i];
		if(xnxt<0||xnxt>4||ynxt<0||ynxt>4) continue;
		if(!visited[xnxt][ynxt] && arr[xnxt][ynxt]==word[start]) hasWord(xnxt,ynxt,++start);
	}
	
}


int main(){
	for(int i=0;i<5;i++){
			scanf("%s",&arr[i]);
	}

	char temp[100];
	scanf("%s",&temp);
	word = temp;
	
	for(int i=0;i<5;i++){
		for(int j=0; j<5; j++){
			if(arr[i][j]==word[0]){
				if(!visited[i][j]){
					hasWord(i,j,0);
				}
			}
		}
	}
	for(int i=0; i<word.length();i++){
		printf("%c",v[i]);
	}
	for(int i=0; i<word.length();i++){
		if(word[i]!=v[i]){
			printf("No");
			break;
			
		}else{
			printf("Find");
		}
	}
	
}
