#include <bits/stdc++.h>

using namespace std;

map<string, int> giftScore;
map<string, int> result;
map<string, map<string, int>> accountBook;

vector<string> split(string input, char dlim){
    vector<string> rst;
    stringstream ss;
    string stringBuffer;

    ss.str(input);

    while(getline(ss, stringBuffer, dlim))
        rst.push_back(stringBuffer);


    return rst;
}

void record(vector<string> friends, vector<string> gifts){
    for(auto gift: gifts){
        vector<string> trade = split(gift, ' ');
        string From  = trade.at(0);
        string To = trade.at(1);

        giftScore[From]++;
        giftScore[To]--;
        accountBook[From][To]++;
        accountBook[To][From]--;
    }

    return ;
}


int makeResult(vector<string> friends){
    int answer = 0;

    for(int i=0; i < friends.size(); i++){
        string From = friends.at(i);

        for(int j=0; j<friends.size(); j++){
            if(i == j) continue;

            string To = friends.at(j);

            int gnum = accountBook[From][To];

            if((gnum > 0) || ((gnum == 0) && (giftScore.at(From) > giftScore.at(To))))
                result[From]++;
        }

        answer = max(answer, result[From]);
    }

    return answer;
}

int solution(vector<string> friends, vector<string> gifts) {
    record(friends, gifts);
    int answer = makeResult(friends);

    return answer;
}


int main(){
    vector<string> friends = {"muzi", "ryan", "frodo", "neo"};
    vector<string> gifts = {"muzi frodo", "muzi frodo", "ryan muzi", "ryan muzi", "ryan muzi", "frodo muzi", "frodo ryan", "neo muzi"};

    cout << solution(friends, gifts) << endl;

    return 0;
}
