#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <unordered_set>
using namespace std;
int main(){
    string s;
    cout<<"shuru："<<endl;
    cin>>s;

    int left=0, right=0;
    int res;
    unordered_set<char> window;
    while(right<s.size()){
        char c = s[right];
        while(window.count(c)){
            window.erase(s[left]);
            left++;
        }
        window.insert(s[right]);
        res = max(res, right-left+1);
        right++;
    }
    string ress;
    ress=s.substr(left, res);
    cout<<"zichuan:"<<ress<<endl;
    cout<<res<<endl;
    return 0;


}