#include <bits/stdc++.h>
#define llng long long

using namespace std;


class vertex{
private:
    int cost;
    int left;
    int right;

public:
    vertex(int c){
        cost  = c;
        left  = -1;
        right = -1;
    }

    int getCost(){
        return cost;
    }

    int getLeft(){
        return left;
    }

    int getRight(){
        return right;
    }

    void setLeft(int _left){
        left = _left;
    }

    void setRight(int _right){
        right = _right;
    }
};

class festival{
private:
    vector<vertex*> schedule;
    int N;
    int L;
public:
    festival(){
        int cost;

        cin >> N >> L;

        for(int i=0; i<N; i++){
            cin >> cost;
            vertex* vp = new vertex(cost);
            schedule.push_back(vp);

            if(i != 0){
                direction(0, i);
            }
        }
    }

    void direction(int prev, int vidx){

        vertex* prevp = schedule.at(prev);
        vertex* vp    = schedule.at(vidx);
        int left  = prevp->getLeft ();
        int right = prevp->getRight();

        if(prevp->getCost() > vp->getCost()){
            if(prevp->getLeft() != -1)
                direction(left, vidx);
            else{
                prevp->setLeft(vidx);
            }
        }

        else{
            if(prevp->getRight() != -1)
                direction(right, vidx);
            else{
                prevp->setRight(vidx);
            }
        }
    }


    void inorder(int vidx){

        vertex* now = schedule.at(vidx);

        int cost  = now->getCost();
        int left  = now->getLeft();
        int right = now->getRight();

        if(left != -1){
            inorder(left);
        }

        cout << cost << " ";

        if(right != -1){
            inorder(right);
        }
    }


    vertex* minVP(){

    }



};

int main()
{
    festival* fp = new festival();

    fp->inorder(0);

    return 0;
}
