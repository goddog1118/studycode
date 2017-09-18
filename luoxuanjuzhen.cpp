// ConsoleApplication2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;


int main()
{
	int a, b;
	int n,m;
	cin >> n >> m;
	int t = n;
	int sum = 0;
	int k = 0;
	int** c = new int*[n];
	int x, y;
	for ( a = 0; a<n; a++){
		c[a] = new int[n];
	}
	for (a = 0; a < n; a++) {
		for (b = 0; b < n; b++) {
			c[a][b] = 0;
		}
	}
	while (t > 0) {
		for (a = b = k; b < n - k; b++) {
			sum++;
			c[a][b] = sum;
		}
		for (a = k+1, b = n - 1 - k; a < n - k; a++) {
			sum++;
			c[a][b] = sum;
		}
		for (a = n - 1 - k, b = n - 2 - k; b >= k; b--) {
			sum++;
			c[a][b] = sum;
		}
		for (a = n - 2 - k, b = k; a >= k+1; a--) {
			sum++;
			c[a][b] = sum;
		}
		t = t - 2;
		k = k + 1;
	}
	for (a = 0; a < n; a++) {
		for (b = 0; b < n; b++) {
			if (m == c[a][b]) {
				x = a+1;
				y = b+1;
			}
		}
	}
	cout << x << " " << y;
	return 0;
}
