#include<iostream>
#include<vector>

using namespace std;

int arr[51];
vector<int> v;


int main(){
    string str;
    cin >> str;
    int temp=0;
    int msum=0;
    int result=0;

    for(int i=0; i<str.size();i++){
        if(str[i]!='-' && str[i]!='+'){
            temp*=10;
            temp+=(str[i]-'0');
        }
        if(str[i]=='-'){
            msum+=temp;
            v.push_back(msum);
            temp=0;
            msum=0;
        }
        if(str[i]=='+'){
            msum+=temp;
            temp=0;
        }
    }
    msum+=temp;
    v.push_back(msum);
    result=v[0];

    for(int i=1; i<v.size(); i++){
        result -= v[i];
    }

    printf("%d",result);

}