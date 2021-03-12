#include <iostream>
#include <stack>

using namespace std;


int main(){
    stack<int> s;
    s.push(10);
    s.push(5);
    s.push(4);
    s.pop();
    s.push(1);
    while(!s.empty()){
        printf("%d ",s.top());
        s.pop();
    }
}