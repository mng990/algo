#include <bits/stdc++.h>

using namespace std;


class Node{
public:
    Node(int k){
        key = k+1;
        check = false;
    }

    int           getKey     ()         {return key  ;         }
    bool          getCheck   ()         {return check;         }
    Node*         moveToChild(int cidx) {return child.at(cidx);}
    void          visit      ()         {check = true;         }
    void          reset      ()         {check = false;        }
    void          pushChild  (Node* np) {child.push_back(np);  }
    vector<Node*> getChild   ()         {return child;         }

    void buildEdge(Node* np){
        child.push_back(np);
        np->pushChild(this);
    }

    bool operator <(Node* other){
        return this->getKey() < other->getKey();
    }

    void CSort(){
        sort(child.begin(), child.end());
    }

private:
    int key;
    bool check;
    vector<Node*> child;
};


int N, M, root;
queue <Node*> NQueue;
vector<Node*> Graph;



void resetGraph(){
    for(int i=0; i < Graph.size(); i++){
        Graph.at(i)->reset();
    }
}

void DFS(Node* now){
    cout << now->getKey() << " ";
    now->visit();

    vector<Node*> vNext = now->getChild();

    for(int i=0; i<vNext.size(); i++)
    {
        Node* next = vNext.at(i);
        if(!next->getCheck()) DFS(next);
    }
}

void BFS(Node* now){
    now->visit();

    vector<Node*> vNext = now->getChild();

    for(int i=0; i<vNext.size(); i++){
        NQueue.push(vNext.at(i));
        vNext.at(i)->visit();
    }

    cout << now->getKey() << " ";

    while(!NQueue.empty()){
        Node* next = NQueue.front();

        NQueue.pop();

        vector<Node*> nChild = next->getChild();

        for(int i=0; i < nChild.size(); i++){
            Node* nptr = nChild.at(i);
            if(!nptr->getCheck()){
                NQueue.push(nptr);
                nptr->visit();
            }
        }

        cout << next->getKey() << " ";
    }
}

void input(){
    cin >> N >> M >> root;

    for(int i=0; i<N; i++){
        Graph.push_back(new Node(i));
    }

    for(int i=0; i < M; i++){
        int first, second;
        cin >> first >> second;
        Graph.at(first-1)->buildEdge(Graph.at(second-1));
    }


    for(int i=0; i<N; i++){
        Graph.at(i)->CSort();
        cout << "node " << Graph.at(i)->getKey() << ": ";
        for(int j=0; j < Graph.at(i)->getChild().size();j++){
            cout << Graph.at(i)->getChild().at(j)->getKey() << " ";
        }
        cout <<endl;
    }
}

void run(int root){
    DFS(Graph.at(root-1));
    cout << endl;
    resetGraph();
    BFS(Graph.at(root-1));
}


int main(){

    input();
    run(root);

    return 0;
}
