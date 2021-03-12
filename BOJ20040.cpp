#include<stdio.h>
#include<vector>

using namespace std;
#define MAX 500001

int arr[MAX]={-1,};
int n,m;
vector<int> v;



int findf(int a){
    if(a==arr[a]) return a;
    arr[a]=findf(arr[a]);
    return arr[a];

}

int check(int a,int b){
    if(findf(a)==findf(b)) return 1;    //사이클 생성
    return 0;
}

void unionf(int a, int b){
    a = findf(a);
    b = findf(b);
    if(a>b){
        arr[b]=a;
    }else{
        arr[a]=b;
    }
}

int main(){
    int flag=0;
    scanf("%d%d",&n,&m);
    for(int i=0; i<n; i++){
        arr[i]=i;
    }
    for(int i=0; i<m; i++){
        int x,y;
        scanf("%d%d",&x,&y);
        flag = check(x,y);
        if(flag==1){
            v.push_back(i+1);
        }
        unionf(x,y);
    }
    if(v.size()==0) printf("0\n");
    else printf("%d",v[0]);
}