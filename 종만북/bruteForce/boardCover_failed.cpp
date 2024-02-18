#include <bits/stdc++.h>

using namespace std;

class BoardCover{
private:
    int C;
    vector<vector<vector<int>>> vboard;
    vector<vector<vector<int >>> tet;
public:
    BoardCover(){
        tet = {
            {{0, 0}, {1, 0}, {0, 1}},
            {{0, 0}, {0, 1}, {1, 1}},
            {{0, 0}, {1, 0}, {1, 1}},
            {{0, 0}, {1, 0}, {1, -1}}
            };

        cin >> C;

        for(int i=0; i<C; i++){
            vector<vector<int>> board;
            int H, W;
            cin >> H >> W;
            string str;
            for(int j=0; j < H; j++){
                cin >> str;
                vector<int> row;
                for(auto c: str){
                    row.push_back(convert(c));
                }
                board.push_back(row);
            }
            vboard.push_back(board);
        }
    }

    bool convert(char c){
        if(c == '#')
            return 1;
        else
            return 0;
    }

    bool setTet(int bidx, int y, int x, int tetIdx, int delta){
        bool ok = true;

        for(int i=0; i<3; i++){
            const int ny = y + tet.at(tetIdx).at(i).at(0);
            const int nx = x + tet.at(tetIdx).at(i).at(1);

            if(ny < 0 || ny >= vboard.at(bidx).size() || nx < 0 || nx >= vboard.at(bidx).at(0).size())
                ok = false;
            else{
                vboard.at(bidx).at(ny).at(nx) += delta;

                if(vboard.at(bidx).at(ny).at(nx) > 1) ok = false;
            }
        }

        return ok;
    }

    int coverTet(int bidx){
        vector<vector<int>> board = vboard.at(bidx);

        int colSize = board.size();
        int rowSize = board.at(0).size();

        int y = -1, x = -1;

        for(int i=0; i<colSize; i++){
            for(int j=0; j<rowSize; j++){
                if(board.at(i).at(j) == 0){
                    y = i;
                    x = j;
                    break;
                }
            }

            if(y != -1) break;
        }

        if(y != -1) return 1;

        int ret = 0, tetSize = tet.size();

        for(int tetIdx = 0; tetIdx < tetSize; tetIdx++){
            if(setTet(bidx, y, x, tetIdx, 1))
                ret += coverTet(bidx);
            setTet(bidx, y, x, tetIdx, -1);
        }

        return ret;
    }

    void printBoard(){
        for(auto board: vboard){
            int bsize = board.size();
            for(int i=0; i<bsize; i++){
                vector<int> row = board.at(i);
                int rowSize = row.size();

                for(int j=0; j<rowSize; j++){
                    cout << board.at(i).at(j) << " ";
                }
                cout << endl;
            }
        }
    }

    void run(){
        int vbSize = vboard.size();

        for(int bidx=0; bidx<vbSize; bidx++){
            cout << coverTet(bidx) <<endl;
        }
    }
};



int main()
{
    BoardCover* bcp = new BoardCover();

    bcp -> printBoard();

    bcp -> run();


    return 0;
}
