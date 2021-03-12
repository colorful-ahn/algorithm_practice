#include<iostream>

#define MAX 100001
typedef long long ll;

using namespace std;

int n;
ll oil[MAX];
bool visited[MAX]={false,};
ll dis[MAX];
ll sum=0; 

int main(){
    scanf("%d",&n);
    for(int i=0; i<n-1;i++){
        ll x;
        scanf("%lld",&x);
        dis[i]=x;
    }
    for(int i=0; i<n; i++){
        ll x;
        scanf("%lld",&x);
        oil[i]=x;
    }
    for(int i=0; i<n; i++){
            if(!visited[i]){
                visited[i]=true;
                for(int j=i; j<n; j++){
                    if(oil[j]>=oil[i]){
                        sum += oil[i]*dis[j];
                        visited[j]=true;
                    }else{
                        break;
                    }
                }
            
        }
        
    }
    printf("%lld",sum);
}