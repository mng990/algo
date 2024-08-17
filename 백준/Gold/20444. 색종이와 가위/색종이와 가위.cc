#include<bits/stdc++.h>

using namespace std;
using ll = long long;

ll N, K;


// (x + 1) * ((N-x) + 1) = K
// (x+1) * (N - x + 1) -K= 0 
// Nx - x^2 + x +N -x +1 -K =
// Nx - x^2 +1 -K+N = 0
// x^2 -Nx + K -N -1 = 0
// N^2 + 4(1+N-K) = 제곱수면 OK
// (N^2+4N+4) - 4K = (N+2)^2 - 4K  
void cal() {
	ll num = (N+2) * (N+2) - 4*K;
	ll check = static_cast<ll>(sqrt(num));
	if(check*check == num) cout << "YES";
	else				   cout << "NO";
}

int main(){
	cin >> N >> K;
	cal();
	return 0;
}