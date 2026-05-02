#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
int main(){
    vector<int> nums;
    string line;
    if(getline(cin,line)){
        stringstream ss(line);
        int a;
        while(ss>>a){
            nums.push_back(a);
        }
    }
    int left=0,right = nums.size()-1, hi=1;
    int sum=0, res=0;
    while (left<right){
        while(left<=right && nums[left]<hi) left++;
        while(left<=right && nums[right]<hi) right--;
        sum += right-left+1;
        hi++;
    }
    res=sum;
    for(auto a:nums){
        res -= a;
    }
    cout<<"sum:"<<res<<endl;
    return 0;
}
