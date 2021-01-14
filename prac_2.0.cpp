#include<iostream>
#include<string>
#include <algorithm>
#include <cstring>

using namespace std;

int N,K;
bool visited[26];
string words[50];
int selectedcount = 5;
int result = 0;
void DFS(int index);
int count();


 int main(){
 	
 	
 	visited['a'-'a'] = true;
 	visited['c'-'a'] = true;
 	visited['i'-'a'] = true;
 	visited['n'-'a'] = true;
 	visited['t'-'a'] = true;
	
	cin >> N >> K;
 	
	 
 	for(int i=0;i<N;i++){
		 
 		cin >> words[i];
	}
	
	
	
	for(int i=0; i<26; i++){
		if(visited[i] == false){
			DFS(i);
		}
	}
	if(N>50 || N<=0 || K>26 ){
	cout << "error";
	}
	else if(K < 5){
		cout << "0";
	}
	else if(K == 5){
		result = count();
		cout << result;
	}
	else if(K == 26){
 		cout << N;
	 }	
	 else{
	 
	cout << result;
	}
	return 0;
	 	
 }
 
 
 void DFS(int index){
 	
 	visited[index] = true;
 	selectedcount +=1;
 	
 	if(selectedcount == K){
 		result = max(count(),result);
	 }
	 else{
	 	for(int i= index+1; i<26; i++){
	
		if(visited[i] == false){
		DFS(i);
	}
	 }
	
	}
	visited[index] =false;
	selectedcount --;
	

 }
 
 int count() {
 	int num = 0;
 	
 	for (int i=0; i<N; i++){
 		bool isPossible = true;
 		string word = words[i];
 		for (int j=0; j< word.size(); j++){
 			if(visited[word.at(j)-'a']==false){				
 				isPossible = false;
 				break;
			 }
		 }
		 if (isPossible == true) {
		 	num++;
		 }
	 }
	 return num;
 }

