#include <iostream> //239，滑动窗口最大值
#include <sstream>
#include <vector>
#include <string>
#include <deque>
using namespace std;
int main(){
    vector<int> nums;
    string line;
    cout<<"shuru"<<endl;
    if(getline(cin,line)){
        stringstream ss(line);
        int a;
        while(ss>>a){
            nums.push_back(a);
        }
    }
    int k;
    cout<<"shuru k: ";
    cin>>k;

    deque<int> dq;
    vector<int> res;
    for(int i=0; i<nums.size(); i++){
        if(!dq.empty() && dq.front() <= i-k){
            dq.pop_front();
        }
        while(!dq.empty() && nums[dq.back()] < nums[i]){
            dq.pop_back();
        }
        dq.push_back(i);
        if(i>= k-1){
            res.push_back(nums[dq.front()]);
        }
    }
    cout<<"jieguo"<<endl;
    for(int x:res){
        cout<<x<<",";
    }

}
