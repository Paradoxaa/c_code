#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
int main(){
    string s,t;
    getline(cin,s);
    getline(cin,t);

    if(s.size()<t.size()){
        cout<<""<<endl;
        return 0;
    }
    unordered_map<char, int> need,window;
    for(char c:t){
        need[c]++;
    }
    int left =0, right =0;
    int count =0;
    int start = 0, maxlen = INT_MAX;
    while(right<s.size()){
        char c=s[right];
        right++;
        if(need.count(c)){
            window[c]++;
            if(window[c]==need[c]){
                count++;
            }
        }
        while(count == need.size()){
            if(right-left<maxlen){
                start = left;
                maxlen = right - left;
            }
            char d=s[left];
            left++;
            if(need.count(d)){
                if(window[d] == need[d]){
                    count--;
                }
                window[d]--;
            }
        }
    }
    if(maxlen == INT_MAX){
        cout<<""<<endl;return 0;
    }else{
        cout<<s.substr(start, maxlen)<<endl;
    }



    return 0;
}