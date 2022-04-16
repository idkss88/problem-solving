#include<iostream>
#include<vector>
#include<string>
#include<algorithm> 

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))


using namespace std;

vector<int> getPartialMatchNative(const string& N) {
    int m = N.size();
    vector<int> pi(m,0);

    for (int begin = 1; begin < m ; ++begin) {
        for (int i = 0; i+begin < m; i++ ) {
            if(N[begin+i] != N[i]) {
                break;
            }
            pi[begin+i] = max(pi[begin+i],i+1);

        }
    }

    return pi;
}


vector<int> nativeSearch(const string& H, const string& N ) {
    vector<int> ret;

    for (int begin = 0 ; begin + N.size() <= H.size(); begin++ )  {
        bool matched = true;
        for (int i = 0; i < N.size() ; i++) {
            if (H[begin+i] != N[i]) {
                matched = false;
                break;
            }            

        }

        if (matched)  { 
            ret.push_back(begin); 
        }
    }   

    return ret;
}
vector<int> kpmSearch(const string& H, const string& N ) { 

    int n = H.size(); int m = N.size();

    vector<int> ret;

    vector<int> pi = getPartialMatchNative(N);

    // pi 는 접두사도 되고 접미사도 되면 최대 길이
    // next = matched - pi;

    for (int begin = 0; begin + N.size() <= H.size() ;) {
        int matched = 0;
        if ( matched < m && H[begin+matched] == N[matched]) {
            matched++;

            if (matched == m) ( ret.push_back(begin));
        } else {

        }
        for (int i = 0 ; i < N.size(); i++) {
            if (H[begin+i] != N[i]) {
                break;
            } else {
                matched++;
            }
        }
        if (matched != 0) {
            begin += matched - pi[matched-1];
            matched = pi[matched-1];
        } else {
            begin++;
        }
    }
    return ret;
}


vector<int> getPatialMatch(const string& N) {
    int m = N.size();

    vector<int> pi(m,0);

    int begin = 1, matched = 0;

    while(begin + matched < m) {
        if(N[begin+matched] == N[matched]) {
            ++matched;
            pi[begin+matched-1] = matched;
        }
        else {
            if (matched == 0) {
                begin++;
            } else {
                begin += matched - pi[matched-1];
                matched = pi[matched-1];
            }
        }
    }

    return pi;
}

int main(void) {
    return 0;
}