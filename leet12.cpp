#include <iostream> //53 最大子数组和
#include <sstream>
#include <vector>
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

    int sum=0, maxsum = INT_MIN;
    for(int i=0; i<nums.size(); i++){
        if(nums[i] < nums[i]+sum){
            sum += nums[i];
        }else{
            sum = nums[i];
        }
        maxsum = max(sum, maxsum);
    }
    cout<<maxsum<<endl;
}