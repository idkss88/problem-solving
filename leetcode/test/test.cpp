#include<string>
#include<iostream>
#include<unordered_map>

using namespace std;


int main(void) {

    string test = "abcdefghdabcdefhgk";
    string str[] = {"abc","def","hgk"};
    unordered_map<string,int> m;
   



    for (auto& i : str) {
        cout << i <<endl;
         m.insert(make_pair(i,1));
    }

    unordered_map<string,int> remaining = m;

    cout << "size : " << str->size() << endl;

    int length = str->size() * str[0].size();

    int offset = 0;
    int count = length;
    while ( offset < test.size()) {
        cout << "find : " << test.substr(offset,3) << endl;
        if (remaining.find(test.substr(offset,3)) != remaining.end()) {
             cout << "exsits! : " << test.substr(offset,3) << " remained "<< remaining[test.substr(offset,3)] << endl;
            if (remaining[test.substr(offset,3)] > 0) {
                remaining[test.substr(offset,3)]--;
                cout << "remove it, cur cout " <<  remaining[test.substr(offset,length)] << endl;
                count -= 3;
            } else {
                remaining = m;
                count = length;
            }
        } else {
                remaining = m;
                count = length;
        } 
        if (count == 0) {
            cout << "hit!!" << endl;
        }
        offset+= 3;
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
        cout << m["abc"] << endl;
    }



}