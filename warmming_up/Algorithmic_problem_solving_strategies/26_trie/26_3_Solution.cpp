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
