#include <bits/stdc++.h>

using namespace std;

string intToBi(int num, int n){
    string ret = "";
    
    while(num > 0){
        char block = (num%2) ? '#' : ' ';
        ret = block + ret;
        num /= 2;
    }
    
    while(ret.length() < n) ret = ' ' + ret;
    
    return ret;
}

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
    vector<string> answer;
    
    for(int i=0; i<n; i++){
        answer.push_back(intToBi(arr1[i] | arr2[i], n));
    }
    return answer;
}