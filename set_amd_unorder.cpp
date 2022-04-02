#include <iostream>
#include <vector>
#include<unordered_set>
#include<set>
#include <string>
using namespace std;

int main()
{
    int test[] = {1,3,5,21,5,2451,314,41,421,42,3};
    set<int> order;
    unordered_set<int> unorder;
    for(auto &t:test){
        order.insert(t);
        unorder.insert(t);
    }
    for(auto a:order)
    {
        cout<<a<<" ";
    }cout<<endl;
    for(auto b:unorder)
    {
        cout<<b<<" ";
    }cout<<endl;
}