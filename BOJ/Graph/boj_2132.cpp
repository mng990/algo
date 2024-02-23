#include <bits/stdc++.h>

using namespace std;

int N, maxEat = INT_MIN;
vector<int> tree;
vector<int> starts;
vector<int> results;
vector<vector<int>> edge;


void input(){
    cin >> N;

    tree.push_back(-1);

    for(int i=1; i<=N; i++){
        int fruit;
        cin >> fruit;

        tree.push_back(fruit);
    }

    edge.resize(N+1);

    for(int i=0; i<N-1; i++){
        int to, from;

        cin >> to >> from;
        edge.at(to).push_back(from);
        edge.at(from).push_back(to);
    }
}

void buildStarts(int now, int prev, int eat){

    eat += tree.at(now);

    if(maxEat <= eat){
        if(maxEat < eat) starts.clear();

        maxEat = eat;
        starts.push_back(now);
    }

    vector<int> adj = edge.at(now);

    for(int i=0; i < adj.size(); i++){
        int next = adj.at(i);

        if(next != prev){
            buildStarts(next, now, eat);
        }
    }

    return ;
}


void buildEnds(int startVtx, int now, int prev, int eat){
    eat += tree.at(now);

    if(maxEat <= eat){
        if(maxEat < eat) results.clear();

        maxEat = eat;
        results.push_back(min(startVtx, now));
    }

    vector<int> adj = edge.at(now);

    for(int i=0; i < adj.size(); i++){
        int next = adj.at(i);

        if(next != prev){
            buildEnds(startVtx, next, now, eat);
        }
    }

    return;
}

void outputStarts(){
    for(int i=0; i<starts.size(); i++){
        cout << starts.at(i) << " ";
    }
    cout << endl;
}

void output(){
    cout << maxEat << " " << results.at(0) <<endl;
}

void forEnds(){
    for(auto& startVtx : starts){
        buildEnds(startVtx, startVtx, 0, 0);
    }

    sort(results.begin(), results.end());
}

void run(){
    input();
    buildStarts(1, 0, 0);
    forEnds();
    output();
}

int main(){
    run();
    return 0;
}



