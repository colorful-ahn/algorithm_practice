#include <iostream>
#include <set>
#include <string>

using namespace std;


int main(){
    set<string> s;

    s.insert("abc");
    s.insert("hello");
    s.insert("let");
    s.insert("get");
    s.insert("123");
    s.insert("123");

    s.erase("let");

    if(!s.empty()) cout << "size : " <<s.size()<<'\n';

    cout << *s.find("abc") <<'\n';
    cout << *s.find("hello") << '\n';

    cout << "let count : "<<s.count("get")<<'\n';

    for(auto i=s.begin();i!=s.end();i++){
        cout << "value : "<<*i<<'\n';
    }
}