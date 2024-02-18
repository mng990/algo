#include <bits/stdc++.h>

using namespace std;
const int inf = 0x3f3f3f3f;
int DP[16][1<<16], weight[16][16], N;

void input(){
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            int w;
            cin >> w;

            weight[i][j] = w;
        }
    }
}

int TSP(int vertex, int mask){
    if(DP[vertex][mask]){
        return DP[vertex][mask];
    }

    if(mask == (1<<N) - 1){
        return DP[vertex][mask] = (weight[vertex][0] ? weight[vertex][0] : inf);
    }

    DP[vertex][mask] = inf;

    for(int i=0; i<N; i++){
        if((mask & (1<<i)) || !weight[vertex][i]){
            continue;
        }

        DP[vertex][mask] = min(DP[vertex][mask], TSP(i, mask | (1<<i))+weight[vertex][i]);
    }

    return DP[vertex][mask];
}


int main(){
    input();
    cout << TSP(0, 1);

    return 0;
}

