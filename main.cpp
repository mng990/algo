#include<bits/stdc++.h>

using namespace std;

int N, C, M, nowC, ans = 0;


class deliveryData{
public:
    deliveryData(int _from, int _to, int _box)
    {
        from = _from;
        to = _to;
        box = _box;
    }

    int getFrom(){return from;}
    int getTo()  {return to;  }
    int getBox() {return box; }

    bool operator < (deliveryData dd) const {
        int dto = dd.getTo();
        int dfrom = dd.getFrom();
        int dbox = dd.getBox();


        if(to != dto)
            return to > dto;
        if(from != dfrom)
            return from > dfrom;
        else
            return box < dbox;
    }



    friend ostream& operator<<(ostream& os, deliveryData DD){
        os << DD.getFrom() << " / " << DD.getTo() << " / " << DD.getBox();
        return os;
    }

private:
    int from;
    int to;
    int box;
};

vector<int> truck;
vector<int> drop;
vector<int> capacity;
priority_queue<deliveryData> optimize_path;
int cap[2001];
// bill = {{from, to, #ofboxes}..}



void input(){
    cin >> N >> C >> M;

    for(int i=0; i < M; i++){
        int from, to, box;

        cin >> from >> to >> box;

        deliveryData* ptrDD = new deliveryData(from, to, box);

        optimize_path.push(*ptrDD);
    }

    truck.resize(N+1);
    drop.resize(N+1);

    for(int i=1; i<=N; i++) cap[i] = C;
}



void printTruck(){
    for(int from=1; from < truck.size(); from++){
        cout << truck.at(from) << " ";
    }
    cout << endl;
}

void delivery(){
    while(!optimize_path.empty()){
        deliveryData dd = optimize_path.top();
        int from = dd.getFrom(), to = dd.getTo(), box = dd.getBox();
        int maxTruck = 0;

        for(int i=from; i<to; i++)
            maxTruck = max(maxTruck, truck[i]);

        if(maxTruck + box > C)
            box = C-maxTruck;

        for(int i=from;i<to;i++)
            truck.at(i) += box;

        ans += box;

        optimize_path.pop();
    }
}

void output(){
    cout << ans <<endl;
}

void run(){
    input();
    delivery();
    output();
}

void test(){
    input();
    delivery();
    //printTruck();
}


int main(){
    //sortTest();
    run();
    return 0;
}
