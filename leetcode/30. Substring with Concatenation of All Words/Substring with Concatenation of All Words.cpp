#include<string>
#include<iostream>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
vector findSubstring(string s, vector& words) {
unordered_map<string, int> counts;
for (string word : words)
counts[word]++;
int n = s.length(), num = words.size(), len = words[0].length();
vector indexes;
for (int i = 0; i < n - num * len + 1; i++) {
unordered_map<string, int> seen;
int j = 0;
for (; j < num; j++) {
string word = s.substr(i + j * len, len);
if (counts.find(word) != counts.end()) {
seen[word]++;
if (seen[word] > counts[word])
break;
}
else break;
}
if (j == num) indexes.push_back(i);
}
return indexes;
}
};

int main(void) {

//"barfoofoobarthefoobarman"
//["bar","foo","the"]

    string s = "lingmindraboofooowingdingbarrwingmonkeypoundcake";
    string words[] = {"word","good","best","good"};
    unordered_map<string,int> m;
   
   vector<int> ans;

    for (auto& i : words) {
        if (m.find(i) != m.end()) {
            m[i]++;
        } else {
            m.insert(make_pair(i,1));
        }
    }

    unordered_map<string,int> remaining = m;

    cout << "size : " << words->size() << endl;

    int length = words->size() * words[0].size();
    int start = 0, end = start+length-words[0].size();
    int prev = start;
    int count = length;
    int offset = start;

    while(offset < s.size()) {

        //1. find subStr
        string subStr = s.substr(offset,words[0].size());
        cout << "find : " <<subStr<< endl;
        
        //1.1 if find
        if(remaining.find(subStr) != remaining.end()) {
            cout << "exsits! : " << subStr << " remained "<< remaining[subStr] << endl;
            if (remaining[subStr] > 0) {
                remaining[subStr]--;
                count -=words[0].size();
            } else {
                // escape case
                remaining[subStr]--;
                count -=words[0].size();
                //if prev exist in map
                if (remaining.find(s.substr(start,words[0].size())) != remaining.end()) {
                   

                     remaining[s.substr(start,words[0].size())]++;
                     cout << "restore1 : " << s.substr(start,words[0].size()) << " remained "<< remaining[s.substr(start,words[0].size())] << endl;
                     count+=words[0].size();;
                }

                start +=words[0].size();
                end = start+length-words[0].size();
                //offset = start;

            }

        } else {
                //if prev exist in map
                if (remaining.find(s.substr(start,words[0].size())) != remaining.end()) {
                     remaining[s.substr(start,words[0].size())]++;
                           cout << "restore2 : " << s.substr(start,3) << " remained "<< remaining[s.substr(start,words[0].size())] << endl;
                     count+=3;
                }

                start +=words[0].size();
                end = start+length-words[0].size();
                //offset = start;
        }

          cout << "count!! at " << count<< endl;
        if (count == 0) {
            
             int offset2 = start;
            bool flag = false;
            while (offset2 < end+words[0].size()) {
                if (remaining[s.substr(offset2,words[0].size())] != 0) {
                    flag = true;
                }
                offset2 += words[0].size();
            }
            
            if ( flag  != true) {
            
            cout << "hit!! at " << start<< endl;
            ans.push_back(start);
                            //if prev exist in map
                if (remaining.find(s.substr(start,words[0].size())) != remaining.end()) {
                     remaining[s.substr(start,words[0].size())]++;
                           cout << "restore3 : " << s.substr(start,words[0].size()) << " remained "<< remaining[s.substr(start,words[0].size())] << endl;
                     count+=words[0].size();
                }

                start +=words[0].size();
                end = start+length-words[0].size();
                //offset = start;
            }
                
        }

        if ( offset == end ) {
                        cout << "shift!!" << endl;
                            //if prev exist in map
                if (remaining.find(s.substr(start,words[0].size())) != remaining.end()) {
                     remaining[s.substr(start,words[0].size())]++;
                           cout << "restore4 : " << s.substr(start,words[0].size()) << " remained "<< remaining[s.substr(start,words[0].size())] << endl;
                     count+=words[0].size();
                }

                start +=words[0].size();
                end = start+length-words[0].size();
        }
        offset += words[0].size();
    }

        
}





    /*
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

*/