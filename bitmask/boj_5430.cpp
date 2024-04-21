#include<bits/stdc++.h>

using namespace std;

int T;

deque<string> split(string str, string delimeter){
	
	deque<string> result;
	int start = 0;
	int end = str.find(delimeter);
	
	while(end != string::npos){
		result.push_back(str.substr(start, end-start));
		start = end+delimeter.size();
		end = str.find(delimeter, start);
	}
	
	result.push_back(str.substr(start));
	
	return result;
}

void run(){
	cin >> T;
	
	for(int t=0; t<T; t++){
		int N, mask;
		bool R = false;
		bool error = false;
		
		string func, arr;
		cin >> func >> N >> arr;
		
		deque<string> realArr = split(arr.substr(1, arr.size()-2), ",");
		if(N == 0) realArr.pop_back();
		//cout << realArr.front() << "\n";
		
		for(int i=0; i<func.size(); i++){
			char nowFunc = func[i];
			
			if(nowFunc == 'R'){
				R = !R;
			}
			else{
				if(realArr.size() == 0){
					cout << "error\n";
					error = true;
					break;
				} 
				
				if(R){
					realArr.pop_back();
				}
				else{
					realArr.pop_front();
				}
			}
		}
		
		if(error) continue;
		
		if(realArr.size() == 0){
			cout << "[]\n";
			continue;
		}
		
		if(!R){
			
			int cnt = 0;
			cout << "[";
			
			
			for(int i=0; i<realArr.size(); i++){
				if(cnt != 0) cout << ",";
				cout << realArr[i];
				cnt++;
			}
			
			
			cout << "]\n"; 
			
			}
		else{
			int cnt = 0;

			cout << "[";
			for(int i=realArr.size()-1; i>=0; i--){
				if(cnt != 0) cout << ","; 
				cout << realArr[i];
				cnt++;
			}
				cout << "]\n"; 
		}
			
			
	}
}



int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	run();
	return 0;
}
