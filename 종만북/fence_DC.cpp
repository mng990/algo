#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> vheight;
vector<int> ans;

int C, N;

int solve(int left, int right, vector<int>& h){
    if(left == right) return h.at(left);

    int mid = (left+right)/2;
    int ret = max(solve(left, mid, h), solve(mid+1, right, h));
    int low = mid, high = mid+1;
    int height = min(h.at(low), h.at(high));
    ret = max(ret, height*2);

    while(left < low || high < right){
        if( high < right && (low == left || h.at(low-1) < h.at(high+1))){
            ++high;
            height = min(height, h.at(high));
        }
        else{
            low--;
            height = min(height, h.at(low));
        }
        ret = max(ret, height * (high - low+1));
    }

    return ret;
}

void input(){
    int h;
    cin >> C;

    for(int i=0; i<C; i++){
        vector<int> height;
        cin >> N;
        for(int j=0; j<N; j++){
            cin >> h;
            height.push_back(h);
        }
        vheight.push_back(height);
    }
}

void output(){
    for(int i=0; i < C; i++){
        cout << ans.at(i) << endl;
    }
}

void run(){

    input();

    for(int i=0; i < C; i++){
        vector<int> h = vheight.at(i);
        ans.push_back(solve(0, h.size()-1, h));
    }

    output();
}


int main(){

    run();

    return 0;
}



