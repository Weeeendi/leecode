#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define vi vector<int>
#define rep(i, a, b) for (int i = a; i < (b); i++)

int main(void)
{
    vi n;
    int list[] = {1, 2, 4, 62, 3, 5, 56, 23, 4, 56, 4};
    rep(i,0,sizeof(list)/sizeof(int)){
        n.push_back(list[i]);
    }

    for(auto &v :  n)
    {
    	cout<<v<<" ";
    }
    cout<<endl;    
    return 0;
}