#include<iostream>
#include<vector>
#include <string>
#include <algorithm>
#include <sstream>
using namespace std;
int main(){
    vector<int> nums;
    string line;
    if(getline(cin, line)){
        stringstream ss(line);
        int a;
        while(ss>>a){
            nums.push_back(a);
        }
    }
    int target;
    cout<<"target:";
    cin>>target;
    vector<vector<int>> res;
    sort(nums.begin(), nums.end());
    int n=nums.size();
    for(int i=0;i<n;i++){
        int left=i+1;
        int right = n-1;
        if(i>0&&nums[i]==nums[i-1]) continue;
        while(left<right){
            int sum = nums[i]+ nums[left]+nums[right];
            if(sum==target){
                res.push_back({nums[i], nums[left], nums[right]});
                left++;right--;
                while(left<right && nums[left]==nums[left-1]) left++;
                while(left<right && nums[right]==nums[right+1]) right--;
            }else if(sum<target){
                left++;
            }else{
                right--;
            }
        }
    }

    cout<<'[';
    for(int i=0;i<res.size();i++){
        cout<<'[';
        for(int j=0;j<res[i].size();j++){
            cout<<res[i][j];
            if(j==res[i].size()-1) break;
            cout<<',';
        }
        cout<<']';
        if(i==res.size()-1) break;
        cout<<',';
    }
    cout<<']'<<endl;

    return 0;

}