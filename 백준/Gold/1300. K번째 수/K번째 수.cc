#include<bits/stdc++.h>

using namespace std;
using ll = long long;


ll getIndex(ll target, ll N)
{
	ll ret = 0;
	
	for(ll i=1; i<=N; i++)
	{
		ret += min(target / i, N);	
	}
	
	return ret;	
}


ll binarySearch(ll N, ll k)
{
	ll start = 1;
	ll end = N * N;
	ll mid;
	ll ret;
	
	while(start <= end)
	{	
		mid = (start + end)/2;
		
		if(start == end)
		{
			ret = mid;
			break;
		}
		
		ll targetIdx = getIndex(mid, N);

		
		if(targetIdx >= k)
		{
			end = mid;
			ret = mid;
		}
		else
		{
			start = mid+1;
		}
	}
	
	return ret;
}



int main(){
	ll N, K;
	cin >> N >> K;
	cout << binarySearch(N, K);
	
	return 0;
}