class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int, int> mymap;
		vector<int> result;
		for (int i = 0; i<nums.size(); i++) {
			int temp = target - nums[i];
			if (mymap.find(temp) != mymap.end()) {
				result.push_back(mymap[temp]);
				result.push_back(i);
			}
			else {
				mymap[nums[i]] = i;
			}
		}
		return result;
	}
};