#include <bits/stdc++.h>

using namespace std;

int sz, houseSize;

vector<vector<bool>> vst;
vector<vector<int>> squareMap;
vector<vector<int>> moveTo =
{
    { 0, 1}, {0, -1},
    { 1, 0}, {-1, 0}
};

vector<int> houseComplex;

bool rangeCheck(int y, int x){
    return ((0 <= y) && (y < sz)) && ((0 <= x) && (x < sz)) ;
}

void input(){
    cin >> sz;

    for(int i=0; i<sz; i++){
        vector<int>  srow;
        vector<bool> vrow;
        string dataStr;
        cin >> dataStr;

        for(int j=0; j<sz; j++){
            srow.push_back(dataStr.at(j)-'0');
            vrow.push_back(false);
        }
        squareMap.push_back(srow);
        vst.push_back(vrow);
    }
}

void DFS(int y, int x){

    if(!rangeCheck(y, x)) return;
    if(vst.at(y).at(x)) return;

    int now = squareMap.at(y).at(x);

    if(now){
        vst.at(y).at(x) = true;
        houseSize++;
        for(int i=0; i<moveTo.size(); i++){
            int nextY = y + moveTo.at(i).at(0);
            int nextX = x + moveTo.at(i).at(1);

            DFS(nextY, nextX);
        }
    }

    return ;
}

void searchMap(){
    for(int i=0; i<sz; i++){
        for(int j=0; j<sz; j++){
            DFS(i,j);
            if(houseSize > 0){
                houseComplex.push_back(houseSize);
                houseSize = 0;
            }
        }
    }
}

void output(){
    int hsz = houseComplex.size();

    cout<< hsz << endl;

    sort(houseComplex.begin(), houseComplex.end());
    for(int i=0; i<hsz; i++){
        cout << houseComplex.at(i) << endl;
    }
}

void run(){
    input();
    searchMap();
    output();
}

int main(){
    run();

    return 0;
}

