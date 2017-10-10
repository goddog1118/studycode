class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		map<char, int> mymap;
		int maxlen = 0, start = -1;
		for (int i = 0; i != s.length(); i++) {
			if (mymap.find(s[i]) != mymap.end()) {
				start = max(start, mymap[s[i]]);
			}
			mymap[s[i]] = i;
			maxlen = max(maxlen, i - start);
		}
		return maxlen;
	}
};