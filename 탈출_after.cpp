// 1. ť���� ������
// 2. �������� ���� �Ͽ��°�?
// 3. ����� ���� ��ȸ
// 4. �� �� �ִ°�?
// 5. üũ��&ť�� ����


#include<bits/stdc++.h>

char forest[][]; 
queue<int> q;


int mx[] = {-1,1,0,0};
int my[] = {0,0,1,-1};

void BFS(){
	
}




int main(){
	
	// input
	
	int R,C;   //R�� C�� 
	char c;
	int Sx,Sy,Dx,Dy,Wx,Wy,Xx,Xy;
	
	scanf("%d %d",&R,&C);
	
	//���� �Է�
	for(int i=0;i<R;i++){
		for(int j=0; j<C;j++){
			scanf("%c",&c);
			if(c=="S"){					//�� 
				Sx=i;
				Sy=j;
			} else if(c=="D"){        //��� 
				Dx=i;
				Dy=j
			}else if(c=="*"){        //�� 
				Wx=i;
				Wy=j;
			}else if(c=="X"){
				Xx=i;
				Xy=j;          			//���� 
		}
	} 
	
	// S�� ��ġ�� D�� ��ġ *�� ��ġ?
	 
	
	
} 
