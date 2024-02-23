#include <bits/stdc++.h>

using namespace std;


vector<int> vLego;
vector<int> subArr;
int hole, len, lego;
pair<string, vector<int>> ans;
ifstream fin;
ofstream fout;


void pushSubArr(int idx){
    if(idx < 2) subArr.push_back(0);
    else        subArr.push_back(1);
}

void init(){
    vLego.clear();
    subArr.clear();
    ans.first  = "danger";
    ans.second.clear();
}




void chooseLego(){

    if(len < 2) return;

    do{
        int blockHole = 0;
        vector<int> twoPieces;


        for(int i=0; i< len; i++){
            if(subArr.at(i) == 0){
                twoPieces.push_back(vLego.at(i));
                blockHole+=vLego.at(i);
            }
        }

        if(hole == blockHole){
            if(ans.second.empty()){
                ans.first = "yes";
                ans.second = twoPieces;
            }
            else{
                int prevDiff = ans.second.at(1) - ans.second.at(0);
                int nowDiff  = twoPieces .at(1) - twoPieces .at(0);

                if(nowDiff > prevDiff){
                    ans.second = twoPieces;
                }
            }
        }
    }while(next_permutation(subArr.begin(), subArr.end()));
}

bool input(){
    if(cin >> hole) {
        cin >> len;

        for(int i=0; i<len; i++){
            cin >> lego;
            vLego.push_back(lego);

            pushSubArr(i);
        }

        hole *= pow(10, 7);
        sort(vLego.begin(), vLego.end());

        return true;
    }

    return false;
}

void output(){
    cout << ans.first;
    if(!ans.second.empty()) cout << " " << ans.second.at(0) << " "<< ans.second.at(1);
    cout << endl;
}

bool fileInput(){
    if(fin >> hole) {
        fin >> len;

        for(int i=0; i<len; i++){
            fin >> lego;
            vLego.push_back(lego);

            pushSubArr(i);
        }

        hole *= pow(10, 7);
        sort(vLego.begin(), vLego.end());

        return true;
    }

    return false;
}

void fileOutput(){
    fout << ans.first;
    if(!ans.second.empty()) fout << " " << ans.second.at(0) << " "<< ans.second.at(1);
}

void fileOpen(){
    fin.open("joint-venture.in");
    fout.open("joint-venture_my.out");
}

void fileClose(){
    fin.close();
    fout.close();
}

void run(){
    int i = 0;
    bool cont;
    while(1){
        init();
        cont = input();
        if(cont){
            chooseLego();
            output();
        }
        else break;
    }

}

int main(){

    run();

    return 0;
}

