// ConsoleApplication1.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

template <class T>
class arrList {
private:
	T * aList;
	int msize;
	int length;
public:
	arrList(const int size) {
		this->msize = size;
		aList = new T[msize];
		length = 0;
	}
	~arrList() {
		delete[] aList;
	}
	void clear()
	{
		delete[] aList;
		length = 0;
		aList = new T[msize];
	}
	int getlength() {
		return this->length;
	}
	bool append(const T value) {
		if (length >= msize) {
			cout << "out of range" << endl;
			return false;
		}
		aList[length] = value;
		length++;
		return true;
	}
	bool getpos(int & p, const T& value) {
		int i;
		for (i = 0; i < length; i++) {
			if (aList[i] == value) {
				p = i;
				return true;
			}
		}
		cout << "CANNOT FIND" << endl;
		return false;
	}
	bool insert(const int p, const T& value) {
		int i;
		if (length >= msize) {
			cout << "out of range" << endl;
			return false;
		}
		if (p<0 || p>length) {
			cout << "not legal" << endl;
			return false;
		}
		for (i = length; i > p; i--) {
			aList[i] = aList[i - 1];
		}
		aList[p] = value;
		length++;
		cout << "insert done" << endl;
		return true;
	}
};

int main()
{
	int leng;
	int p;
	arrList<int> a(5);
	if (a.append(1))
		cout << "successful" << endl;
	a.append(2);
	a.append(3);
	a.append(4);
	a.insert(1, 5);
	a.getpos(p, 5);
	cout << p << endl;
	leng = a.getlength();
	cout << leng << endl;
	a.clear();
	leng = a.getlength();
	cout << leng << endl;
	return 0;
}
