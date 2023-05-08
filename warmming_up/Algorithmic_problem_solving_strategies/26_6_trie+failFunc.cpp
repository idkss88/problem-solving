//
//  main.cpp
//  tries
//
//  Created by idkss88 on 2023/05/03.
//

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <queue>

using namespace std;


const int ALPABETS = 256;
#define ALPABET (256)

int toInt(const char* ch) {
    return *ch - 'A';
}

class Tries {
public:
    int first = -1;
    Tries(): children(), isEnd(-1) {
        //std::memset(children,0,sizeof(Tries)*256);
    }
    ~Tries() {
        for (int i = 0 ; i < ALPABETS ; i++) {
            if (children[i]) {
                delete children[i];
            }
        }
    }
    
    void insert(const char* ch, int i) {
        if (first == -1) first = i;
        if (*ch == 0) {
            isEnd = i;
        } else {
            if (children[toInt(ch)] == nullptr) {
                children[toInt(ch)] = new Tries();
            }
            children[toInt(ch)]->insert(ch+1,i);
        }
    }
    
    Tries* find(const char* ch) {
        
        if (*ch == 0) return this;
        
        if (children[toInt(ch)]) {
            return children[toInt(ch)]->find(ch+1);
        }
        return nullptr;
    }
    
    int type(const char* key, int id) {
        if (*key == 0) return 0;
        if (first == id) return 1;
        // if (children[toInt(key)] == nullptr) return strlen(key);
        return 1+children[toInt(key)]->type(key+1,id);
    }
    
    int countKeys(Tries* trie, const char* word) {
        Tries* node = trie->find(word);
        
        if (node == nullptr || node->isEnd == -1) return strlen(word);
        
        return trie->type(word, node->isEnd);
    }
    
    //현 위치에서 끝나는 문자열의 번호
    int terminal;
    
    Tries* fail;
    
    vector<int> output;
    
    void computeFailFunc(Tries* root) {
        queue<Tries*> q;
        
        root->fail = root;
        
        q.push(root);
        
        while(!q.empty()) {
            Tries* here = q.front();
            q.pop();
            
            for(int edge = 0; edge < ALPABETS ; edge++) {
                Tries* child = here->children[edge];
                if (!child) continue;
                
                if (here == root) {
                    child->fail = root;
                } else {
                    Tries* t = here->fail;
                    while(t != root && t->children[edge] == nullptr) t = t->fail;
                    
                    if(t->children[edge]) t = t->children[edge];
                    child->fail = t;
                }
                
                //출력 문자열 목록: 실패 연결을 따라간 노드에서 복사해온 뒤,
                //이 위치에서 끝나는 비늘 문자열이 있으면 추가한다.
                
                child->output = child->fail->output;
                if(child->terminal != -1) child->output.push_back(child->terminal);
                q.push(child);
            }
        }
    }
    
    
    
private:
    Tries* children[ALPABET];
    int isEnd;
};

Tries* readInput(int words) {
    std::vector<std::pair<int,std::string>> input;
    
    for (int i = 0 ; i < words; i++) {
        char buf[11];
        int freq;
        scanf("%s %d",buf,&freq);
        
        input.push_back(std::pair<int,std::string>(-freq,std::string(buf)));
    }
    
    std::sort(input.begin(),input.end());
    
    Tries* trie = new Tries();
    for(int i = 0 ; i < input.size(); i++) {
        trie->insert(input[i].second.c_str(),i);
    }
    
    return trie;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

