#include<iostream>
#include<vector>
#include <string>
#include <sstream>
using namespace std;
int main(){
    vector<int> sum;
    string line;
    if(getline(cin,line)){
        stringstream ss(line);
        int a;
        while(ss>>a){
            sum.push_back(a);
        }
    }
    int left = 0, right = sum.size()-1;
    int maxsize=0, size=0;
    while (left<=right){
        size = min(sum[left],sum[right]) * (right-left);
        maxsize = max(size, maxsize);
        if(sum[left]<sum[right]){
            left++;
        }
        else{
            right--;
        }
    }
    cout<<maxsize<<endl;
}