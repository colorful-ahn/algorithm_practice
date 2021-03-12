#include<iostream>
#include<queue>

using namespace std;

int main(){
    queue<int> q;
    q.push(10);
    q.push(5);
    q.push(4);
    q.pop();
    q.push(1);
    while(!q.empty()){
        printf("%d ",q.front());
        q.pop();
    }
}