#include <bits/stdc++.h>

using namespace std;

class vectorSort{
private:
    vector<int> vint;
public:
    vectorSort(int len){
        for(int i=0; i<len; i++){
            int input;
            cin >> input;
            vint.push_back(input);
        }
    }

    void selectionSort(){
        int minIdx;

        for(int i=0; i<vint.size(); i++){
            minIdx = i;
            for(int j=i+1; j<vint.size(); j++){
                if(vint.at(j) < vint.at(minIdx)){
                    minIdx = j;
                }
            }

            swap(vint.at(i), vint.at(minIdx));
        }
    }

    void printVector(){
        for(auto i : vint){
            cout << i << " ";
        }
        cout <<endl;
    }

    void insertionSort(){

        int len = vint.size();

        for(int i=0; i<len; i++){
            int j=i;
            while(j>0 && vint[j-1] > vint[j]){
                swap(vint[j-1], vint[j]);
                cout << "key: " << j << " / ";
                printVector();
                --j;
            }
        }
    }



};

int main()
{
    int len;
    cin >> len;
    vectorSort* vs = new vectorSort(len);

    vs->printVector();
    vs->insertionSort();
    vs->printVector();

    return 0;
}
