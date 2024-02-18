#include <bits/stdc++.h>
#define CLEN 4


using namespace std;

class quadTree{
private:
    char key;
    vector<quadTree*> child;
public:
    quadTree(){
        char c;
        cin >> c;

        key = c;
        if(c == 'x'){
            pushChild();
        }
    }

    void pushChild(){
        for(int i=0; i<CLEN; i++){
            quadTree* qdp = new quadTree();
            child.push_back(qdp);
        }
    }

    void flip(){
        if(child.empty()) return;

        swap(child.at(0), child.at(2));
        swap(child.at(1), child.at(3));

        for(int i=0; i<CLEN; i++){
            child.at(i) -> flip();
        }
    }

    char getKey(){
        return key;
    }

     void preOrder(){

        char key  = getKey();
        cout << key;

        if(child.empty()) return ;

        for(int i=0; i<CLEN; i++){
            child.at(i) -> preOrder();
        }
    }

};


int main(){

    int C;

    cin >> C;

    for(int i=0; i<C; i++){
        quadTree* qdp = new quadTree();
        qdp->flip();
        qdp->preOrder();
        cout << endl;
    }

    return 0;
}



