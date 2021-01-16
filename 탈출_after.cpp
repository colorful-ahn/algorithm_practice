// 1. 큐에서 꺼내옴
// 2. 목적지에 도달 하였는가?
// 3. 연결된 곳을 순회
// 4. 갈 수 있는가?
// 5. 체크인&큐에 넣음


#include<bits/stdc++.h>

char forest[][]; 
queue<int> q;


int mx[] = {-1,1,0,0};
int my[] = {0,0,1,-1};

void BFS(){
	
}




int main(){
	
	// input
	
	int R,C;   //R행 C열 
	char c;
	int Sx,Sy,Dx,Dy,Wx,Wy,Xx,Xy;
	
	scanf("%d %d",&R,&C);
	
	//지도 입력
	for(int i=0;i<R;i++){
		for(int j=0; j<C;j++){
			scanf("%c",&c);
			if(c=="S"){					//고슴 
				Sx=i;
				Sy=j;
			} else if(c=="D"){        //비버 
				Dx=i;
				Dy=j
			}else if(c=="*"){        //물 
				Wx=i;
				Wy=j;
			}else if(c=="X"){
				Xx=i;
				Xy=j;          			//바위 
		}
	} 
	
	// S의 위치와 D의 위치 *의 위치?
	 
	
	
} 
