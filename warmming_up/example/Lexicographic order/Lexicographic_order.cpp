#include<string>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
    public:
        void test(string& str,int count) {
            
            string temp = str;
            sort(temp.begin(),temp.end(),greater<char>());
            
            cout<<"sort before :"<<temp<<endl;
            int cur = 0;
            int start = 0;
            while (count--) {
                int e = str.size() - 1;
                int s = cur;
              //  while(s<e) {
                     cout<<"[start] curIdx "<< cur <<" char "<<str[cur]<<endl;

                    if (temp[cur] == str[cur]) {
                        while(cur < e && str[cur] == str[cur+1]) cur++;
                    } else {
                        for (int j = e; j > s ; j--) {
                            if ( str[j] == temp[cur]) {
                                cout<<"j "<< j <<" char "<<str[j]<<endl;
                                cout<<"cur "<< cur <<" char "<<str[cur]<<endl;
                                char temp = str[j];
                                str[j] = str[cur];
                                str[cur] = temp;
                                break;
                            }
                        }
                    }
                    cur = cur+1;
                    s = cur;
              //  }

            }
            cout<<"sort after :"<<str<<endl;

            
        }
};


int main(void) {

    string str = "KWZZDOYW";
    Solution s;

    s.test(str,3);

    return 0;
}