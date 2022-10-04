#include <bits/stdc++.h>
using namespace std;

int main() {

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// start code from here
	//cout << "Hello";
	int n;
	cin >> n;
	int temp = n;
	int sum = 0;
	while (n > 0) {
		int r = n % 10;
		sum = sum + (r * r * r);
		n = n / 10;
	}
	if (sum == temp) {
		cout << temp << " Number is Armstrong Number";
	}
	else {
		cout << "not a armstrong number ";
	}


	return 0;
}
