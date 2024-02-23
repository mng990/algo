#include <bits/stdc++.h>

using namespace std;

int N, K, MOD = pow(10, 9)+3;
int DP[1001][1001];

void input(){
    cin >> N >> K;

    for(int i=1; i<N; i++){
        DP[i][0] = 1;
        DP[i][1] = i;
    }
}

void buildDP(){
    for(int i=2; i<N; i++){
        for(int j=2; j<=K; j++){
            DP[i][j] = (DP[i-1][j] + DP[i-2][j-1])%MOD;
        }
    }

    DP[N][K] = (DP[N-1][K] + DP[N-3][K-1])%MOD;
}

void printDP(){
    for(int i=1; i<=N; i++){
        for(int j=1; j<=K; j++){
            cout << DP[i][j] << " ";
        }
        cout << endl;
    }

}

void output(){
    cout << DP[N][K] << endl;
}

void run(){
    input();
    buildDP();
    //printDP();
    output();
}

int main(){
    run();
    return 0;
}
