
//c++ 문법에 맞게 바꾸기 Boggle 9202 문제 
#include <bits/stdc++.h> 


using namespace std; 
  
const int ALPHABET_SIZE = 26; 
vector<string> v;
vector<char> sb;

 
int mx[]={-1,1,0,0,-1,1,-1,1};
int my[]={0,0,-1,1,-1,-1,1,1};
int score[]={0,0,0,1,1,2,3,5,11}; 
	
char map[4][4]={};
string answer;
int sum;
int count;
	
bool visited[4][4];
 
  
// trie node 
struct TrieNode 
{ 
    struct TrieNode *children[ALPHABET_SIZE]; 
  
    bool isEndOfWord; 
}; 
  
// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
    struct TrieNode *pNode =  new TrieNode; 
  
    pNode->isEndOfWord = false; 
  
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        pNode->children[i] = NULL; 
  
    return pNode; 
} 
  
// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
void insert(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root; 
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            pCrawl->children[index] = getNode(); 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    // mark last node as leaf 
    pCrawl->isEndOfWord = true; 
} 
  
// Returns true if key presents in trie, else 
// false 
void search(struct TrieNode *root, int x, int y) 
{ 
    
	struct TrieNode *pCrawl = root;
	// 1.체크인
	visited[y][x] = true;
	sb.push_back(map[y][x]);
	//2. 목적지에 도달하였는가?
	if(pCrawl.isEndOfWord && pCrawl.isHit == false){
		// 점수계산 
		pCrawl.isHit = true;
		sum += score[length];
		count++;
		string foundWord = sb.toString();
		if(compare(answer, foundWord)>0){
			answer = foundWord;
		}
	}
	// 3. 연결된 곳을 순회
	for(int i=0; i< 8; i++){
		int ty = y + my[i];
		int tx = x +mx[i];
		//4. 가능한가?
		//5. 간다
		if(0<=ty && ty <4 && 0<=tx && tx <4){
			if(visited[ty][tx]==false && pCrawl.hasChild(map[ty][tx])){
				search(ty,tx,length+1,getChild(map[ty][tx]));
			}
		}
	}
	
	// 6. 체크아 웃 
	visited[y][x] = false;
	sb.clear();
} 

int compare(string arg0, string arg1){
	int result = compare(arg1.length(), arg0.length()); // long txt
	if(result == 0){
		return arg0.compareTo(arg1);
	}else{
		return result;
	}
}
  
// Driver 
int main() 
{ 
    // Input keys (use only 'a' through 'z' 
    // and lower case) 
    	
	 
    int N,W;
	cin>>N; 
  	string str;
    struct TrieNode *root = getNode(); 
  	
  	v.assign(N,"");
    // Construct trie 
    
	for (int i = 0; i < N; i++){
    	cin >> str;
		v[i]=str;
    	insert(root, v[i]);
	} 
	
	cin >> W;
	
	for (int i=0; i<W; i++){
		
	}
	
	for(int y=0; y<4;y++){
		for(int x=0; x<4; x++){
			if(root.hasChild(map[y][x])){
				search(y,x,1,root.getChild(map[y][x]));
			}
		}
	}
         
    return 0; 
} 
