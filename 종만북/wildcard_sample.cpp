using namespace std;


string w_str;
string str[51];
int dp[102][102]; // w_str[i]와 str[j]가 대응 되는가 1, 안되는가 0
int n;
int w_len, str_len;
bool recv(int i, int j, int idx) {
	if (i == w_len) { // 와일드 문자열이 끝까지 비교된 경우
		if (j == str_len) { // 비교 문자열도 끝까지 비교되면 대응 가능
			return true;
		}
		return false;
	}

	int& ret = dp[i][j];
	if (~ret) return ret;
	ret = 0;

	if (w_str[i] == str[idx][j]) { // 규칙 1 . 같은 경우
		ret = recv(i + 1, j + 1, idx);
	}
	else {
		if (w_str[i] == '*') { // 규칙 2-1
			ret |= recv(i + 1, j, idx); // i+=1, j 고정
			if (!ret) {
				while (j <= str_len) {
					ret |= recv(i, j, idx); // i고정, j+=1
					j += 1;
				}
			}
		}
		else if (w_str[i] == '?') { // 규칙 2-2
			ret = recv(i + 1, j + 1, idx);
		}
	}
	// 규칙 1. 다른 경우 그대로 false return
	return ret;
}
void solve() {
	vector<string> ans;
	cin >> w_str;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}
	w_len = w_str.length();

	for (int i = 0; i < n; i++) {
		memset(dp, -1, sizeof(dp));
		str_len = str[i].length();
		if (recv(0, 0, i)) {
			ans.push_back(str[i]);
		}
	}
	sort(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << "\n";
	}
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	for (; t--;) {
		solve();
	}
}
