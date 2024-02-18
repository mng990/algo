#include <bits/stdc++.h>

using namespace std;

int N, M, V;
vector<bool> DP;
vector<vector<int>> Graph;
queue<int> vtxQueue;


void input(){

    cin >> N >> M >> V;

    Graph.resize(N+1);
    DP.assign(N+1, false);

    for(int i=0; i<M; i++){
        int first, second;
        cin >> first >> second;
        Graph.at(first).push_back(second);
        Graph.at(second).push_back(first);
    }

    for(int i=1; i<=N; i++){
        sort(Graph.at(i).begin(), Graph.at(i).end());
    }
}

void DFS(int vtx){
    cout << vtx << " ";
    DP.at(vtx) = true;

    vector<int> adjacent = Graph.at(vtx);

    for(int i=0; i<adjacent.size(); i++){
        int nextVtx = adjacent.at(i);
        if(!DP.at(nextVtx))
            DFS(nextVtx);
    }

    return ;
}

void resetDP(){
    for(auto d: DP) d = false;
}

void BFS(int root){

    vtxQueue.push(root);
    DP.at(root) = true;
    cout << root << " ";
    vtxQueue.pop();


    vector<int> adjacent = Graph.at(root);

    for(int idx = 0; idx<adjacent.size(); idx++){
        int nowVtx = adjacent.at(idx);

        if(!DP.at(nowVtx)){
            vtxQueue.push(nowVtx);
            DP.at(nowVtx) = true;
        }
    }

    while(!vtxQueue.empty()){
        int nextVtx = vtxQueue.front();
        cout << nextVtx << " ";
        vtxQueue.pop();

        adjacent = Graph.at(nextVtx);

        for(int i=0; i < adjacent.size(); i++){
            int waitVtx = adjacent.at(i);

            if(!DP.at(waitVtx)){
                vtxQueue.push(waitVtx);
                DP.at(waitVtx) = true;
            }
        }
    }

    cout << endl;
}

void run(){
    input();
    DFS(V);
    resetDP();
    cout << endl;
    BFS(V);
}

int main(){
    run();
    return 0;
}
