#include <bits/stdc++.h>
using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int arr[10];
		for (int i = 0; i < 10; i++) cin >> arr[i];
		*max_element(arr, arr + 10) = 0;
		*max_element(arr, arr + 10) = 0;
		cout << *max_element(arr, arr + 10) << '\n';
	}
}