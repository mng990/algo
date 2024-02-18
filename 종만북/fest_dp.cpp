#include <bits/stdc++.h>

using namespace std;

class festival{
private:
    int N;
    int L;
    int day;
    double avg;
    vector<int> cost;
    vector<int> DP;
public:
    festival(){
        cin >> N >> L;
        avg = DBL_MAX;
        day = L;
        inputCost();
    }

    void inputCost(){
        int cst;
        int sum = 0;
        for(int i=0; i<N; i++){
            cin >> cst;
            cost.push_back(cst);
            sum += cst;

            DP.push_back(sum);
        }
    }

    void pickUp(){

        if(day > N) return;

        int minDP = INT_MAX;

        for(int i=day-1; i<DP.size(); i++){
            int prev  = i - day;
            int dpSum = DP.at(i);

            if(prev >= 0){
                dpSum -= DP.at(prev);
            }

            if(minDP > dpSum){
                minDP = dpSum;
            }
        }

        avg = min((double)minDP/day, avg);
        day++;

        return pickUp();
    }

    void printDP(){
        cout << "DP: ";
        for(auto d: DP){
            cout << d << " ";
        }

        cout <<endl;
    }

    void printCost(){
        cout << "Cost: ";
        for(auto c: cost){
            cout << c << " ";
        }

        cout <<endl;
    }

    void test(){
        pickUp();
        printCost();
        printDP();
        cout << "avg: " << avg << endl;
    }

};

int main()
{
    vector<int> vint;
    vector<int> DP;

    //int C, N, L;

    //cin >> C;

    festival* fp = new festival();

    fp->test();

    return 0;
}
