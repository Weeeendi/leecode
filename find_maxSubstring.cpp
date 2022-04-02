#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
#include <algorithm>
using namespace std;

#define vi vector<int>
#define vc vector<char>
#define rep(i, a, b) for (int i = a; i < (b); i++)

class Solution {
public:
    string s1;

    int lengthOfLongestSubstring(string s) {
        unsigned int slowidx = 0;
        unsigned int fastidx = 0;    
        int mx = 0;    
        unordered_set<char> Tchar;
        //fast move first
        while(fastidx<s.size()){
            if(Tchar.count(s[fastidx]) == 1){
                //move slow index
                do{
                Tchar.erase(s[slowidx]);
                //slowidx++;
                }while(s[slowidx++]!=s[fastidx]);
            }
            Tchar.insert(s[fastidx]);
            mx = max(mx,(int)(fastidx-slowidx+1));
            fastidx++;
        }  
        return mx;
    }
};

int main(void){
    int mx_substrlen;
    Solution MyString;
    MyString.s1 = "uqinntq";
    mx_substrlen = MyString.lengthOfLongestSubstring(MyString.s1);
    cout<<mx_substrlen<<endl;
    return 0;
}