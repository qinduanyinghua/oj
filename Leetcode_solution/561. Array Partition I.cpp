/* Given an array of 2n integers, your task is 
 to group these integers into n pairs of integer, 
 say (a1, b1), (a2, b2), ..., (an, bn) which makes 
 sum of min(ai, bi) for all i from 1 to n as large as possible. */

/* Example 1:
Input: [1,4,3,2]

Output: 4
Explanation: n is 2, and the maximum sum of pairs is 4 = min(1, 2) + min(3, 4).
Note:
n is a positive integer, which is in the range of [1, 10000].
All the integers in the array will be in the range of [-10000, 10000].*/

/* algorithm analysis:

input: an array of 2n inyegers
output: max sum(min(ai, bi))

let us suppose that for every pair (ai, bi): bi >= ai
then, our object is Sm = a1 + a2 + ... + an
when we input an array, the sum of array Sa = a1 + b1 + ... + an + bn is a constant
we suppose di = |ai - bi|, then di = bi - ai, bi = ai + di

Sd = d1 + d2 + ... + dn

Sa = a1 + (a1 + d1) + ... + an + (an + dn)
==> Sa = 2 * Sm + Sd
==> Sm = (Sa - Sd) / 2
to maximize Sm, we need minimize Sd, so we should make di close as far as possible.
As a result, we sort the array. */

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int arrayPairSum(vector<int>& nums) {
		int len = nums.size();
		int sum = 0;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < len; i += 2) {
			sum += nums[i];
		}
		return sum;
	}
};

int main() {
	Solution a;
	int tmp[] = {1, 4, 3, 2};
	int len = sizeof(tmp) / sizeof(tmp[0]);
	vector<int> nums(tmp, tmp + len);
	cout << a.arrayPairSum(nums) << endl;
	return 0;
}
