#include <bits/stdc++.h> 


using namespace std; 
  
const int ALPHABET_SIZE = 26; 
vector<string> v;
bool visited[26];

 
 
 
  
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
bool search(struct TrieNode *root, string key) 
{ 
    struct TrieNode *pCrawl = root;
    bool key_value[26]={0};
    for(int i=0; i<key.length();i++){
    	int index = key[i]-'a';
    	key_value[index] = true;
	}
	
	// 1.체크인
	for(int i=0; i< key.length(); i++){
		int index = key[i] -'a';
		if(pCrawl->children[index]){
			visited[index]=true;
			pCrawl = pCrawl->children[index];
			
		}else{
			// 단어가 없음. 
			return false;
		}
		// visited and key compare
		
		
		
	}
	 pCrawl->isEndOfWord = true; 
	
	//2. 목적지에 도달하였는가?
	// 3. 연결된 곳을 순회
	//4. 가능한가?
	//5. 간다
	// 6. 체크아 웃 
	visited[index] =false;
  
    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 
  
        pCrawl = pCrawl->children[index]; 
    } 
  
    return (pCrawl != NULL && pCrawl->isEndOfWord); 
} 
  
// Driver 
int main() 
{ 
    // Input keys (use only 'a' through 'z' 
    // and lower case) 
    
	
	
	int mx[]={-1,1,0,0,-1,1,-1,1};
	int my[]={0,0,-1,1,-1,-1,1,1};
	int score={0,0,0,1,1,2,3,5,11}; 
	
	
	
	
	
	 
    int N,M;
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
         
  
    // Search for different keys 
    search(root, "ICP")? cout << "Yes\n" : 
                         cout << "No\n"; 
//    search(root, "these")? cout << "Yes\n" : 
//                           cout << "No\n"; 
    return 0; 
} 
