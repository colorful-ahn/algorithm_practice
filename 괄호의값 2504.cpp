#include <iostream>
#include <stack>

using namespace std;

stack<char> s;

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); 

	int count=1; // count result
	long long result = 0;
	bool isInvalid=false;
	// ���ÿ�  ���ڿ��� ���´�.
	string input;
	cin >> input;
	
	for(int i=0; i<input.length();i++){
		// �ϴ� �ְ� ī��Ʈ�� ������ 
		if(input[i]=='('){
			count *=2;
			s.push('(');
		}
		else if(input[i]=='['){
			count *=3;
			s.push('[');		
		}
		// ��ġ x 
		else if(input[i]==')'&&(s.empty()||s.top() !='(')){
			isInvalid = true;
			break;
		}
		else if(input[i]==']'&&(s.empty()||s.top()!='[')){
			isInvalid = true;
			break;
		}
		// ¦�� ������ �������ְ� ī��Ʈ �������. 
		else if(input[i]==')'){
			if(input[i-1] == '('){
				result +=count;
			}
			s.pop();
			count /=2;
		}
		else if(input[i]==']'){
			if(input[i-1]=='['){
				result +=count;
			}
			s.pop();
			count /=3;
		}
			
			
		
	}
	if(isInvalid || !s.empty()){
		cout << 0;
	}
	else {
		cout << result;
	}
	return 0;
}
