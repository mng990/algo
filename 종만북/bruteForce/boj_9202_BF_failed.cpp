#include <bits/stdc++.h>

using namespace std;



class boggle{

private:
    int blen;

    int score;
    int cnt;
    string longest;

    vector<int> directionX = {0, 1, 1, 1, 0, -1, -1, -1};
    vector<int> directionY = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<string> vword;
    vector<string> board;
    vector<vector<string>> vboard;

public:
    boggle(){
        int w, b;
        string word, bline;

        score = 0;
        blen = 4;
        cnt = 0;

        cin >> w;


        for(int i=0; i<w; i++){
            cin >> word;
            vword.push_back(word);
        }

        cin >> b;

        for(int i=0; i<b; i++){
            for(int j=0; j<blen; j++){
                cin >> bline;

                board.push_back(bline);
            }

            vboard.push_back(board);
            board.clear();
        }
    }

    bool inRange(int y, int x){
        return (y < blen) && (y >= 0) && (x >= 0) && (x < blen);
    }

    bool hasWord(int y, int x, string word){
        if(!inRange(y, x)){
            return false;
        }

        if(board.at(y).at(x) != word.at(0)){
            return false;
        }


        if(word.length() == 1){
            return true;
        }


        for(int dir = 0; dir < 8; dir++){
            int nextY = y + directionY.at(dir);
            int nextX = x + directionX.at(dir);

            if(hasWord(nextY, nextX, word.substr(1))){
                return true;
            }
        }

        return false;
    }

    bool isWord(string word){
        for(int i=0; i<blen; i++){
            for(int j=0; j<blen; j++){

                if(hasWord(j, i, word) == true)
                    return true;
            }
        }

        return false;
    }


    void update(string word){

        if(isWord(word) == true){

            int wlen = word.length();
            int llen = longest.length();


            if(wlen >=3 && wlen <= 4) score += 1;

            if(wlen == 5) score += 2;

            if(wlen == 6) score += 3;

            if(wlen == 7) score += 5;

            if(wlen == 8) score += 11;

            if(longest.empty())
                longest = word;

            else{
                if(llen < wlen){
                    longest = word;
                }

                if(llen == wlen){
                    longest = min(longest, word);
                }
            }

            cnt++;
        }

        return ;
    }

    void printResult(){
        cout << score << " " << longest << " " << cnt << endl;
    }

    void reset(){
        score = 0;
        longest = "";
        cnt = 0;
    }

    void play(){

        string word;

        for(int i=0; i<vword.size(); i++){
            word = vword.at(i);
            update(word);
        }

        printResult();
        reset();
    }

    void setBoard(vector<string> newBoard){
        board.clear();
        board = newBoard;
    }

    void run(){
        for(int i=0; i<vboard.size(); i++){
            setBoard(vboard.at(i));
            play();
        }
    }

};


int main()
{

    boggle* bp = new boggle();

    bp->run();

    return 0;
}
