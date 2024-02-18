#include <bits/stdc++.h>

using namespace std;


class picnic{
private:
    int n;
    vector<vector<bool>> areFriends;
    vector<bool> taken;
public:
    picnic(){
        for(int i=0; i<10; i++){
            vector<bool> friends;

            for(int j=0; j<10; j++){
                friends.push_back(false);
            }
            areFriends.push_back(friends);

        }

        taken.resize(10, false);
    }

    int countPairings(){
        int firstFree = -1;
        for(int i=0; i < n; i++){
            if(!taken.at(i)){
                firstFree = i;
                break;
            }
        }


        int ret = 0;

        for(int p = firstFree+1; p < n; p++){
            if(!taken.at(p) && areFriends.at(firstFree).at(p)){
                taken.at(firstFree) = true;
                taken.at(p) = true;
                ret += countPairings(taken);
                taken.at(firstFree) = false;
                taken.at(p) = false;
            }
        }

        return ret;
    }


};



int main()
{

    picnic* pp = new picnic();

    pp->countPairings();


    return 0;
}
