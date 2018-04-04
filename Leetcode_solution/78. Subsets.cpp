/* 
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

For example,
If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


// Backtracking
class Solution {
public:
	vector<vector<int> > subsets(vector<int>& nums) {
		vector<vector<int> > result;
		vector<int> path;
		sort(nums.begin(), nums.end());
		int startIndex = 0;
		dfs(startIndex, nums, path, result);
		return result;
	}

	void dfs(int startIndex, 
			vector<int>& nums, 
			vector<int>& path, 
			vector<vector<int> >& res) {

		res.push_back(path);

		if (startIndex == nums.size())
			return;
		
		for (int i = startIndex; i < nums.size(); i++) {
			path.push_back(nums[i]);
			dfs(i + 1, nums, path, res);
			path.pop_back();
		}
	}
};

// bit manipulation
class Solution1 {
public:
	vector<vector<int> > subsets(vector<int>& nums) {
		vector<vector<int> > result;
		vector<int> tmp;
		sort(nums.begin(), nums.end());

		int len = nums.size();
		for (int i = 0; i < (1 << len); i++) {
			tmp.clear();
			for (int j = 0; j < len; j++) {
				if ((i >> j) & 1) {
					tmp.push_back(nums[j]);
				}
			}
			result.push_back(tmp);
		}
		return result;
	}
};
// iterative
/*
This problem can also be solved iteratively. Take [1, 2, 3] 
in the problem statement as an example. The process of generating all the subsets 
is like:

Initially: [[]]
Adding the first number to all the existed subsets: [[], [1]];
Adding the second number to all the existed subsets: [[], [1], [2], [1, 2]];
Adding the third number to all the existed subsets: [[], [1], [2], [1, 2], 
													[3], [1, 3], [2, 3], [1, 2, 3]].
*/
class Solution2 {
public:
	vector<vector<int> > subsets(vector<int>& nums) {
		vector<vector<int> > result;
		vector<int> tmp;
		sort(nums.begin(), nums.end());
		result.push_back(tmp);
		for (int i = 0; i < nums.size(); i++) {
			int len = result.size();
			for (int j = 0; j < len; j++) {
				tmp = result[j];
				tmp.push_back(nums[i]);
				result.push_back(tmp);
			}
		}
		return result;
	}
};

int main() {
	Solution2 a;
	int tmp[] = {1, 2, 3};
	int len = sizeof(tmp) / sizeof(tmp[0]);
	vector<int> nums(tmp, tmp + len);
	
	vector<vector<int> > res;
	res = a.subsets(nums);
	for (int i = 0; i < res.size(); i++) {
		for (int j = 0; j < res[i].size(); j++) {
			cout << res[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}