#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> cache(30, vector<int>(30, -1));

int bino(int n, int r, int depth){
    cout << "depth: " << depth << " / n: " << n << " / r: "<< r << endl;
    if(r == 0 || n == r) return 1;
    return bino(n-1, r-1, depth+1) + bino(n-1, r, depth+1);
}

int bino2(int n, int r, int depth){
    cout << "depth: " << depth << " / n: " << n << " / r: "<< r << endl;

    if(r == 0 || n == r) return 1;
    if(cache.at(n).at(r) != -1){
        return cache.at(n).at(r);
    }

    return cache.at(n).at(r) = bino2(n-1, r-1, depth+1) + bino2(n-1, r, depth+1);
} // 메모이제이션

int main(){

    cout << "bino 1" << endl;
    bino (4, 2, 0);


    cout << endl << "bino 2" << endl;
    bino2(4, 2, 0);

    return 0;
}

