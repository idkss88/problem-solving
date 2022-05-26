#include<string>
#include<iostream>
#include<unordered_map>

using namespace std;


int main(void) {

    string str[] = {"abc","def","hgk"};
     unordered_map<string,int> m;
    for (auto& i : str) {
        cout << i <<endl;
         m.insert(make_pair(i,1));
    }

    for (auto& i : m) {
        cout << i.first << " "<< i.second << endl;
    }

    unordered_map<string,int>::iterator itr;

    for (itr = m.begin() ; itr != m.end() ; itr++) {
        cout << itr->first  << " "<< itr->second << endl;
    }

   if (m.find("abc") != m.end()) {
       m["abc"]++;
       cout << m["abc"] <<endl;
   }

}