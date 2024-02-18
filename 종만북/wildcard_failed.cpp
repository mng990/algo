#include <bits/stdc++.h>

using namespace std;

int C, n;
string W, S;

int cache[101][101];

bool matchMemoized(int w, int s){

    int& ret = cache[w][s];

    if(ret != -1) return ret;

    if(w < W.size() && s < S.size() && (W.at(w) == '?' || W.at(w) == S.at(s))){
        return ret = matchMemoized(w+1, s+1);
    }

    if(w == W.size() && (s == S.size())) return ret = true;



    if(W.at(w) == '*'){
        if(matchMemoized(w+1, s) || (s < S.size() && matchMemoized(w, s+1))){
            return ret = 1;

        }
    }

    return ret = false;
}

void run(){

    cin >> C;

    for(int i=0; i<C; i++){
        cin >> W >> n;

        vector<string> ans;

        for(int j=0; j < n; j++){
            cin >> S;

            memset(cache, -1, sizeof(cache));

            if(matchMemoized(0, 0)){
                ans.push_back(S);
            }
        }

        for(int i=0; i < ans.size(); i++){
            cout << ans.at(i) << endl;
        }
    }
}

int main(){

    run();

    return 0;
}

