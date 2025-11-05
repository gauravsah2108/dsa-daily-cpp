#include <bits/stdc++.h>
using namespace std;

int binarysearch(const vector<int>& arr, int target){
    int left=0;
    int right = arr.size()-1;
    while(left<=right){
        int mid= left+(right-left)/2;
        if(arr[mid]==target)return mid;
        else if (arr[mid]<target) left=mid+1;
        else right=mid-1;
    }
    return -1;

}

int main(){

    cout<<"Binary Search";
    cout<<"Enter Array element(comma or space separated) : ";
    string input;
    getline(cin,input);

    stringstream ss(input);
    vector<int> nums;
    string temp;
    for(char& c: input){
        if(c==',') c=' ';
    }
    ss.str(input);

    int num;
    while(ss >> num){
        nums.push_back(num);
    }

    if(nums.empty()){
        cout<<"no number entered "<< endl;
        return 0;
    }

    sort(nums.begin(),nums.end());
    cout<<"sorted array:";
    for(int n: nums)cout<<n<<" ";
    cout<<endl;

    int target;
    cout<<"Enter the number to search:";
    cin>>target;

    int index = binarysearch(nums,target);
    cout<<index;
    return 0;
}