#include <bits/stdc++.h>

using namespace std;

class Trie{

private:
    bool end;
    vector<Trie*> children;
public:
    Trie(){
        end = false;
        for(int i=0; i<26; i++){
            children.push_back(nullptr);
        }
    }

    ~Trie(){
        for(int i=0; i<26; i++){
            if(children.at(i) != nullptr)
                delete children.at(i);
        }
    }

    void insert(const char* c){

        if(!*c){
            this->end = true;
            return;
        } // c == null일 때 return (문자열의 끝)

        int now  = *c - 'A';

        if(children.at(now) == nullptr){
            children.at(now) = new Trie();
        }

        children.at(now)->insert(c+1); // 다음 문자로 이동
    }

    bool search(const char* c){
        if(!*c){
            if(end) return true;
            return false;
        }

        int now = *c - 'A';
        if(!children.at(now)) return false;
        return children.at(now)->search(c+1);
    }
};


class Boggle{
private:
    int dlen;
    int blen;
    int score;
    int cnt;
    string longest;

    Trie* dic;

    vector<int> directionX = {0, 1, 1, 1, 0, -1, -1, -1};
    vector<int> directionY = {-1, -1, 0, 1, 1, 1, 0, -1};
    vector<vector<bool  >> visit;
    vector<vector<string>> vboard;

public:
    Boggle(){
        score = 0;
        makeTrie();
        makeBoard();
    }

    void makeBoard(){
        int bcnt;

        blen = 4;
        cin >> bcnt;

        for(int i=0; i<bcnt; i++){
            vector<string> board;

            for(int j=0; j<blen; j++){
                string str;
                cin >> str;

                board.push_back(str);
            }
            vboard.push_back(board);
        }

        for(int i=0; i<blen; i++){
            vector<bool> vrow;
            for(int j=0; j<blen; j++){
                vrow.push_back(false);
            }

            visit.push_back(vrow);
        }

    }

    void makeTrie(){

        string word;

        dic = new Trie();

        cin >> dlen;

        for(int i=0; i < dlen; i++){
            cin >> word;
            dic->insert(word.c_str());
        }
    }

    bool inRange(int x, int y){
        return (x >= 0) && (x < blen) && (y >= 0) && (y < blen);
    }


    bool findWord(int y, int x, int bidx, string& word){

        word += vboard.at(bidx).at(y).at(x);
        visit.at(y).at(x) = true;


        if(dic->search(word.c_str())){
            updateScore(word);
            return true;
        }

        for(int i=0; i<8; i++){
            int nextX = x + directionX.at(i);
            int nextY = y + directionY.at(i);

            if(inRange(nextX, nextY) && visit.at(nextY).at(nextX)){
                findWord(nextY, nextX, bidx, word);
            }
        }

        visit.at(y).at(x) = false;
        word.pop_back();

        return false;
    }

    bool overall(int bidx, string& word){

        bool gotIt = false;

        for(int i=0; i<blen; i++){
            for(int j=0; j<blen; j++){

                gotIt = findWord(i, j, bidx, word);

                if(gotIt) return true;
            }
        }

        return false;
    }


    void updateScore(string word){

        int wlen = word.length();

        switch(wlen){
            case 3:
            case 4:
                score += 1;
                break;
            case 5:
                score += 2;
                break;
            case 6:
                score += 3;
                break;
            case 7:
                score += 5;
                break;
            case 8:
                score += 11;
                break;
        }

        cnt++;


        if(longest.empty()){
            longest = word;
            return ;
        }

        if(longest < word){
            longest = word;
        }

        return ;
    }


    void play(int bidx){
        string start = "";

        if(overall(bidx, start)){
            updateScore(start);
        }
    }

    void printResult(){
        cout << score << " " << longest << " " << cnt <<endl;

    }

    void run(){
        for(int i=0; i<vboard.size(); i++){
            play(i);
            printResult();
        }
    }



};



int main()
{

    Boggle* bp = new Boggle();

    bp->run();

    return 0;
}
