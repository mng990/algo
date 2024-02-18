#include <bits/stdc++.h>

using namespace std;


// C++ implementation of the above approach.
#include <iostream>
#include <math.h>
using namespace std;

// Function to return the
// sign of a number
int sign(double x)
{
	if (x < 0)
		return -1;
	if (x > 0)
		return 1;
	return 0;
}

// Function to swap
// two numbers in an array.
void swap(vector<int>& arr, int i, int j)
{
	int temp = arr.at(i);
	arr.at(i) = arr.at(j);
	arr.at(j) = temp;
}

int select(vector<int>& arr, int left,
		int right, int k)
{
	while (right > left) {
		if (right - left > 600) {
			// Choosing a small subarray
			// S based on sampling.
			// 600, 0.5 and 0.5
			// are arbitrary constants
			int n = right - left + 1;
			int i = k - left + 1;
			double z = log(n);
			double s = 0.5 * exp(2 * z / 3);
			double sd = 0.5 * sqrt(z * s
								* (n - s) / n)
						* sign(i - n / 2);

			int newLeft = max(left,
							(int)(k - i * s / n + sd));

			int newRight = min(right,
							(int)(k + (n - i) * s / n
									+ sd));

			select(arr, newLeft, newRight, k);
		}

		// Partition the subarray S[left..right]
		// with arr[k] as pivot
		int t = arr.at(k);
		int i = left;
		int j = right;
		swap(arr, left, k);
		if (arr.at(right) > t) {
			swap(arr, left, right);
		}

		while (i < j) {
			swap(arr, i, j);
			i++;
			j--;

			while (arr.at(i) < t)
				i++;
			while (arr.at(j) > t)
				j--;
		}

		if (arr.at(left) == t)
			swap(arr, left, j);
		else {
			j++;
			swap(arr, right, j);
		}

		// Adjust the left and right pointers
		// to select the subarray having k
		if (j <= k)
			left = j + 1;
		if (k <= j)
			right = j - 1;
	}
	return arr.at(k);
}

int kth(vector<int> &a, int k) {
    int n = a.size();
	return select(a, 0, n-1, k-1);
}

/*
// Driver code
int main()
{
	vector<int> arr = { 7, 3, 4, 0, 1, 6 };
	int n = arr.size();

	// k-th smallest element.
	// In this we get the 2nd smallest element
	int k = 2;
	int res = select(arr, 0, n - 1, k - 1);
	cout << "The " << k << "-th smallest element is "
		<< res << endl;
	return 0;
}
*/
