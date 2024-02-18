#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> inVtx (1000000);
vector<vector<int>> outVtx(1000000);
int maxVtx = 0, cntDonut = 0, cntBar = 0, cntEight = 0, constVtx=0;

void classifyGraph(int from, int start){
    if(outVtx.at(from).empty()
       || inVtx.at(from).empty()){
        cntBar++;
        return;
    }

    if(inVtx.at(from).size() > 1
       && outVtx.at(from).size() > 1){
        cntEight++;
        return;
    }

    int to = outVtx.at(from).at(0);

    if(to == start){
        cntDonut++;
        return;
    }

    return classifyGraph(to, start);
}

void buildGraph(vector<vector<int>> edges){
    int esize = edges.size();

    for(int i=0; i < edges.size(); i++){
        int from = edges.at(i).at(0);
        int to   = edges.at(i).at(1);

        maxVtx = max(max(maxVtx, from), to);

        inVtx .at(to).push_back(from);
        outVtx.at(from).push_back(to);
    }

    inVtx .resize(maxVtx+1);
    outVtx.resize(maxVtx+1);

    return;
}

int findConstructor(){
    for(int vtx=1; vtx <= maxVtx; vtx++){
        if(inVtx.at(vtx).empty() && outVtx.at(vtx).size()>=2)
            return vtx;
    }
}

void printGraph(){
    cout << "inVtx" << endl;
    for(int i=1; i<inVtx.size(); i++){
        cout << i << ": ";
        for(auto vtx: inVtx.at(i))
            cout << vtx << " ";
        cout << endl;
    }


    cout << "outVtx" << endl;
    for(int i=1; i<outVtx.size(); i++){
        cout << i << ": ";
        for(auto vtx: outVtx.at(i))
            cout << vtx << " ";
        cout << endl;
    }
    return;
}

vector<int> solution(vector<vector<int>> edges) {
    vector<int> answer;

    buildGraph(edges);
    constVtx = findConstructor();

    for(int i=0; i < outVtx.at(constVtx).size(); i++){
        int startVtx = outVtx.at(constVtx).at(i);

        classifyGraph(startVtx, startVtx);
    }

    answer = {constVtx, cntDonut, cntBar, cntEight};

    return answer;
}
