// stringcode.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_set>
using namespace std;

class scode {
private:
	vector<string> existcode;
	unordered_set<string> myset;
public:
	scode(vector<string> existcode) {
		this->existcode = existcode;
	}
	bool judge(string& testcode) {
		string aftertest;
		solution(testcode, aftertest);
		if (myset.find(aftertest) == myset.end()) {
			cout << "no" << endl;
			return false;
		}
		cout << "yes" << endl;
		return true;
	}
	bool encode() {
		int i;
		for (i = 0; i < existcode.size(); i++) {
			string aftercode;
			solution(existcode[i], aftercode);
			myset.insert(aftercode);
		}
		return true;
	}
	bool solution(const string& code, string& aftercode) {
		int i, j=0;
		map<char, char> mapchar;
		for (i = 0; i < code.length(); i++) {
			if (mapchar.find(code[i])== mapchar.end()) {
				mapchar.insert(map<char, char>::value_type(code[i], char(1+j)));
				aftercode += char(1 + j);
				j++;
			}
			else {
				aftercode += mapchar[code[i]];
			}
		}
		return true;
	}

};

int main() {
	vector<string> vec = { "aad","abc"};
	string teststring = "ddd";
	scode test(vec);
	test.encode();
	test.judge(teststring);
	return 0;
}


