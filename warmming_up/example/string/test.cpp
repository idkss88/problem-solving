// 사전순으로 부분문자열
//abcdef 
//1. k개를 뽑아 사전 순으로 가장 뒤에 나오는 문자열 만들기
// -  중복문자 당연 허용

// 영문자 사전 순이 되기 위해서는
// 뽑은 단어가 가장 큰  값부터 나열되면 된다.
//
// 부분 문자열에서 문자 변형해서 사전 순으로 가장 뒤에 나오는 문자열 만들기
// 가장 늦은 문자가 오면 사전 순서 가장 뒤임.

// 1. 정렬 + index
// 2. ZZZZYYYYYYYYYYYYYXXXXXXXXWWWWWWWWWVVVVVV
//    0315678
//가장 첫번째에 가장 큰 값이 와야 한다.  가장 큰 값이 중복이면 가장 뒤에 있는 값 = index가 가장 큰 값. pair sort.
//두번 째도 첫번째와 같거나 그보다 작은 값이 와야 한다. index가 두번째로 큰 값.
//....
//...
// PAIR sort를 하면 될 듯 (nlogn)
// 그렇게 되면, 
// 끝인가??
// 2번 만 변경 했을 때 첫번째가 가장 큰 수라면?` 

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {

    string s = "zzyytestf";
    
    //int k = 2;
    //ttsef
    //testf
    //ttsfe
    int k = 4;
    
    string::iterator itr;
    vector<pair<char,int>> origin;
    vector<pair<char,int>> chareactor;
    int size = strlen(s.c_str());
    int i = 0;
    for (auto& elem : s) {
        origin.push_back({elem,i});
        chareactor.push_back({elem,i});
        i++;
    }


    stable_sort(chareactor.begin(),chareactor.end());

    for (auto& elem : chareactor) {
        cout << elem.first <<elem.second<<endl;
    }
    int cnt = 0;
    i = 0;
     while(cnt < k) {
         //할 필요가 없다면 skip 해야 한다.
         int j = 0;
         while(j < chareactor[(size-1)-i].second) {
             if (chareactor[(size-1)-i].first == origin[j].first) {
                 // skip 케이스
                 if (j == chareactor[(size-1)-i].second - 1) {
                     i++;
                     break;
                 }
                 j++;
                 continue;
             } else if (chareactor[(size-1)-i].first > origin[j].first ) {
                char temp = origin[j].first;
                origin[j].first = chareactor[(size-1)-i].first;
                origin[chareactor[(size-1)-i].second].first = temp;
                cnt++;
                i++;
                break;
             } 
             j++;
         }
         i++;
         if (i == size) {
             break;
         }

     }
    string newStr;
     for (auto& elem : origin) {  
        newStr.push_back(elem.first);
    }
    cout  << newStr<<endl;
}

