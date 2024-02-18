#include <bits/stdc++.h>

using namespace std;

int T, W, ans = 0;
vector<int> plum;
int DP[31][1001] = {{0,},};


void input(){
    int p;
    cin >> T >> W;

    plum.push_back(-1);

    for(int i=1; i<=T; i++){
        cin >> p;
        plum.push_back(p);
    }
}

void buildDP(){
    for(int w = 0; w<=W; w++){
        for(int t=1; t<=T; t++){
            int nowPlum = plum.at(t);

            if(w == 0){
                DP[w][t] = DP[w][t-1];

                if(nowPlum == 1) DP[w][t]++;
            }

            if(w > 0){
                DP[w][t] = max(DP[w][t-1], DP[w-1][t]);

                if(w%2 == 1 && nowPlum == 2)
                    DP[w][t] += 1;
                if(w%2 == 0 && nowPlum == 1)
                    DP[w][t] += 1;
            }

            if(t == T){
                ans = max(ans, DP[w][t]);
            }
        }
    }
}

void printAns(){
    cout << ans << endl;
}

void printDP(){
    for(int i=0; i<=W; i++){
        for(int j=0; j<=T; j++){
            cout << DP[i][j] << ' ';
        }

        cout << endl;
    }
}

void run(){
    input();
    buildDP();
    printAns();
    //printDP();
}

int main(){
    run();
    return 0;
}

