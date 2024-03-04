#include <bits/stdc++.h>

using namespace std;

int N, minute, second;
vector<vector<int>> record;
vector<vector<int>> result(2, vector<int>(2));
vector<int> score(2);

vector<string> split(const string& input, string delimiter){
	vector<string> result;
	auto start = 0;
	auto end = input.find(delimiter);
	
	while(end != string::npos){
		result.push_back(input.substr(start, end - start));
		start = end + delimiter.size();
		end = input.find(delimiter, start);
	}
	result.push_back(input.substr(start));
	return result;
}

void input(){
	
	cin >> N;
	for(int i=0; i<N; i++){
		int team;
		string time;
		vector<int> r(3);
		
		cin >> r.at(0) >> time;
		r.at(1) = stoi(split(time, ":").at(0));
		r.at(2) = stoi(split(time, ":").at(1));
		r.at(0)--;
		
		record.push_back(r);
	}
	
	record.push_back({2, 48, 0});
}

void scoreBoard(){
	int prevMin = 0, prevSec = 0 , prevTeam = -1;
	vector<int> score(2);
	
	for(int i=0; i<record.size(); i++){
		int team = record.at(i).at(0);
		int min = record.at(i).at(1);
		int sec = record.at(i).at(2);
		int wMin, wSec;
			
		if(prevTeam != -1){
			wMin = min - prevMin;
			wSec = sec - prevSec;
			
			if(wSec < 0){
				wMin--;
				wSec+=60;
			}
			
			if(wSec >= 60){
				wMin++;
				wSec -= 60;
			}
			
			result.at(prevTeam).at(0) += wMin;
			result.at(prevTeam).at(1) += wSec;
			
			if(result.at(prevTeam).at(1) > 60){
				result.at(prevTeam).at(1) %= 60;
				result.at(prevTeam).at(0)++;
			}
		}
		
		if(team == 2) break;
		score.at(team)++;

		
		if(score.at(team) > score.at(1-team)){
			prevTeam = team;
		}
		if(score.at(team) == score.at(1-team)){
			prevTeam = -1;
		}
		
		prevMin = min;
		prevSec = sec;
	}
}


void printRecord(){
	for(int i=0; i<record.size();i++){
		cout << record.at(i).at(0) << " " << record.at(i).at(1) << " " << record.at(i).at(2) << endl;
	}
}

void output(){
	for(int i=0; i<result.size(); i++){
		cout << setfill('0') <<setw(2)<< result.at(i).at(0);
		cout << ":";
		cout << setfill('0') <<setw(2) << result.at(i).at(1) << '\n';
	}	
}

void run(){
	input();
	scoreBoard();
	output();
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    run();
	return 0;
} 
