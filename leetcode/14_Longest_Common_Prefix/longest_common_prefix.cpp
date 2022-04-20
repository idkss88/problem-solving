#include <vector>
#include <string>

using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {

        if (strs.size() == 1)
        {
            return strs[0];
        }
        string result = "";
        string compareString = strs[0];
        int compareIndex = 0;
        int compareStringSize = compareString.size();
        int hit = 0;
        while (compareIndex < compareStringSize)
        {
            for (int i = 0; i < strs.size(); i++)
            {
                hit = 0;
                if (strs[i][compareIndex] != compareString[compareIndex])
                {
                    hit = 0;
                    break;
                }
                else
                {
                    hit = 1;
                }
            }

            if (hit == 0)
            {
                break;
            }
            else
            {
                result += compareString[compareIndex];
            }
            compareIndex++;
        }

        return result;
    }

    string longestCommonPrefix2(vector<string> &strs)
    {

        string ans = strs[0];

        if (strs.size() == 1)
        {
            return strs[0];
        }

        for (int i = 0; i < strs.size(); i++)
        {
            int j;
            for (int j = 0; j < strs[i].size(); j++)
            {

                if (strs[i][j] != ans[j])
                {
                    break;
                }
            }
            ans = ans.substr(0, j);

            // ans is empty
            if (ans == "")
            {
                return ans;
            }
        }

        return ans;
    }

    /*
    vector<string> rVector;
    string result = "";
    string result2 = "";
    string temp = strs[0];
    int tempSize = temp.size();
    int tempIndex = 0;
    int maxSize = 0;
    int hit = 0;

    if ( strs.size() == 1) {
        return strs[0];
    }

    while(tempIndex < tempSize) {
        cout << "Find : " << temp[tempIndex]<<endl;
        for (int i = 1;  i< strs.size() ; i++) {
            int j = 0;
            hit = 0;
            while(j < strs[i].size()) {
                if (temp[tempIndex] == strs[i][j]) {

                    hit = 1;
                    break;
                }
                j++;
            }

            if ( hit == 0) {
                cout << "hit zero : " <<endl;
                break;
            }
        }

        if (hit == 1) {
            result += temp[tempIndex];
        } else {
            int size = result.size();

            if (size > maxSize) {
                 cout << "save  : " << size <<" : "<<maxSize<<" : "<<result<< endl;
                result2 = result;
            }
            result = "";
        }

        tempIndex++;
    }

    return result2;
} */
};