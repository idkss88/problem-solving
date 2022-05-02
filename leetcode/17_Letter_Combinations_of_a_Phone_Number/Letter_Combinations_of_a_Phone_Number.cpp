#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<stack>
#include<utility>

using namespace std;

class Solution {
public:




    string convertToString(int digit) {
        switch (digit) {
            case 2:
                return "abc";
            case 3:
                return "def";
            case 4:
                return "ghi";
            case 5:
                return "jkl";
            case 6:
                return "mno";
            case 7:
                return "pqrs";
            case 8:
                return "tuv";
            case 9:
                return "wxyz";
                
            default:
                return "";
                
        }
        
        return "";
    } 
    
    vector<string> appendString(string str,int index) {
        
        vector<string> ans;
        if (index >= str.size()) return ans;
        
        char c = str[index];
        printf("test");
        string letter = convertToString(c-'0');
        vector<string> result = appendString(str,++index);
        
        if (!result.empty()) {        
        for (int i = 0 ; i < letter.size(); i++) {
            for (int j = 0 ; j <result.size(); j++ ) {
                ans.push_back(letter[i]+result[j]);
            }
        }
        } else {
            std::string s;
            for (int i = 0 ; i < letter.size(); i++) {
                ans.push_back(s+letter[i]);
            }
        }
         
         
        return ans;
       
        }
    


    vector<string> letterCombinations(string digits) {
        
        return appendString(digits,0);
    
    }

    vector<string> combine(vector<string> set1, vector<string> set2) {
        vector<string> res; 
        for (string a:set1) 
            for(string b:set2)
                res.push_back(a+b);
        return res;
    }

    vector<string> letterCombinations2(string digits) {
        if(digits == "") 
            return {};


        unordered_map<char,vector<string>> letters {
            {'2',{"a","b","c"}},
            {'3',{"d","e","f"}},
            {'4',{"g","h","i"}},
            {'5',{"j","k","l"}},
            {'6',{"m","n","o"}},
            {'7',{"p","q","r","s"}},
            {'8',{"t","u","v"}},
            {'9',{"w","x","y","z"}},
        };

        vector<string> combination = letters[digits[0]];

        for (int i = 1; i< digits.size(); i++) {
            combination = combine(combination,letters[digits[i]]);
        }

        return combination;

  
    }

    vector<string>  letterCombinations3(string digits) {

        if (digits.size() == 0) {
            return {};
        }

        vector<string> ans;
        
        unordered_map<char,string> letters {
            {'2',{"abc"}},
            {'3',{"def"}},
            {'4',{"ghi"}},
            {'5',{"jkl"}},
            {'6',{"mno"}},
            {'7',{"pqrs"}},
            {'8',{"tuv"}},
            {'9',{"wxyz"}},
        };

        stack<pair<int,string>> combination({make_pair(0,"")});
        while(!combination.empty()) {
            pair<int,string> temp = combination.top();
            combination.pop();

            for (auto& el : letters[digits[temp.first]-'0']) {

                string str = temp.second + el; 

                if (temp.first == digits.size() - 1 ) {
                    ans.push_back(str);
                } else {
                    combination.push(make_pair((temp.first+1),str));
                }
            }

        }

        return ans;

    }
};

/*
    std::vector<std::string> letterCombinations(std::string digits) {
        // 1. DFS with stack
        // Time complexity:     O(L * 4^L)
        // Space complexity:    O(L)
        std::vector<std::string> res;
        if (digits.size() == 0) return res;
        std::vector<std::string> v{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        std::stack<std::pair<int, std::string>> s;
        s.push(std::make_pair(0, std::string{}));
        while (!s.empty()) {
            auto t = s.top();
            s.pop();
            auto& candidate = v[digits[t.first] - '2'];
            for (auto c : candidate) {
                std::string str = t.second + c;
                if (t.first == digits.size() - 1) {
                    res.push_back(str);
                }
                else {
                    s.push(std::make_pair(t.first + 1, str));
                }
            }
        }
        return res;
*/

int main (void) {

    vector<string> a = {};

    cout << a.size() << endl;


    return 0;
}