#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
using namespace std;
int main(){
    vector<int> nums;
    string line;
    cout<<"shuzu:"<<endl;
    if(getline(cin, line)){
        stringstream ss(line);
        int a;
        while(ss>>a){
            nums.push_back(a);
        }
    }
    int tar;
    cout<<"mubiao:";
    cin>>tar;
    
    unordered_map<int, int> mp;
    int sum=0, count=0;
    mp[0]=1;
    for(int num : nums){
        sum = sum+num;
        if(mp.count(sum-tar)){
            count += mp[sum-tar];
        }
        mp[sum]++;
    }

    cout<<endl<<count<<endl;
}
