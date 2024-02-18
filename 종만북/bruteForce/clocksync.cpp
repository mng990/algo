#include <bits/stdc++.h>

using namespace std;
const int INF = 9999;


class clocksync{
private:
    int C;
    vector<int> needforvswitch;
    vector<vector<int >> vclocks;
    vector<vector<int>> vswitch;
public:
    clocksync(){
        cin >> C;
        for(int i=0; i<C; i++){
            vector<int> clocks;
            for(int j=0; j<16; j++){
                int    clock;
                cin >> clock;
                clocks.push_back(clock);
            }
            vclocks.push_back(clocks);
        }

        vswitch.push_back({0,1,2});
        vswitch.push_back({3,7,9,11});
        vswitch.push_back({4,10,14,15});
        vswitch.push_back({0,4,5,6,7});
        vswitch.push_back({6,7,8,10,12});
        vswitch.push_back({0,2,14,15});
        vswitch.push_back({3,14,15});
        vswitch.push_back({4,5,7,14,15});
        vswitch.push_back({1,2,3,4,5});
        vswitch.push_back({3,4,5,9,13});
    }

    bool checkClocks(vector<int> clocks){
        for(int i=0; i<clocks.size(); i++)
            if(clocks.at(i) != 12) return false;

        return true;
    }

    void push(int sidx, vector<int>& clocks){
        int slen = vswitch.at(sidx).size();
        for(int sw_cidx = 0; sw_cidx < slen; sw_cidx++){
            int cidx = vswitch.at(sidx).at(sw_cidx);
            clocks.at(cidx) += 3;
            if(clocks.at(cidx) > 12)
                clocks.at(cidx) = 3;
        }
        return;
    } // switch를 누르면 해당하는 시계가 3시간 씩 up


    int solve(int sidx, vector<int>& clocks){
        if(sidx == 10){
            if(checkClocks(clocks))
                return 0;

            return INF; // false일 경우 반영 안됨
        }

        int ret = INF;

        for(int cnt=0; cnt<4; cnt++){
            ret = min(ret, cnt+solve(sidx+1, clocks));
            push(sidx, clocks);
        }

        return ret;
    }

    void run(){
        int ret;
        int start = 0;
        for(int vcidx=0; vcidx<C; vcidx++){
            ret = solve(start, vclocks.at(vcidx));
            if(ret == INF) cout << -1 << endl;
            else           cout << ret << endl;
        }
    }

};

int main()
{
    clocksync* csp = new clocksync();

    csp -> run();

    return 0;
}
