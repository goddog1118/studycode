class Solution {
public:
	string longestPalindrome(string s) {
		if (s.empty()) return "";
		if (s.size() == 1) return s;
		int start = 0, maxlen = 1;
		for (int i = 0; i<s.size();) {
			if (s.size() - i <= maxlen / 2) break;
			int pre = i, next = i;
			while (next<s.size() - 1 && s[next + 1] == s[next]) {
				next++;
			}
			i = next + 1;
			while (next<s.size() - 1 && pre>0 && s[next + 1] == s[pre - 1]) {
				next++;
				pre--;
			}
			int len = next - pre + 1;
			if (len>maxlen) {
				start = pre;
				maxlen = len;
			}
		}
		return s.substr(start, maxlen);
	}
};