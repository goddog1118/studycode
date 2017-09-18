// stackorder.cpp: 定义控制台应用程序的入口点。
//判断是否是栈输出

#include "stdafx.h"
#include<iostream>
#include<stack>
#include<vector>
using namespace std;


int main()
{
	int n;
	cin >> n;
	int i, j=1,k=0;
	vector<int> number(n);
	for (i = 0; i < n; i++){
		cin >> number[i];
		if (number[i]<=0 || number[i]>n) {
			cout<< "NO" <<endl;
			return 0;
		}
	}
	for (i = 0; i < n; i++) {
		int tmp = n;
		for (k = i + 1; k < n; k++) {
			if (number[i]>number[k])
			{
				if (tmp > number[k])
					tmp = number[k];
				else {
					cout << "NO" <<endl; 
					return 0;
				}
			}
		}
	}
	stack<int> mystack;
	for (i = 0; i < n; i++) {
		while (mystack.empty()||mystack.top() < number[i]) {
			mystack.push(j);
			cout << "PUSH " << j++ << endl;
		}
		if (mystack.top() == number[i]) {
			cout << "POP " << mystack.top() << endl;
			mystack.pop();
		}
	}
    return 0;
}

