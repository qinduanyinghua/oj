/*
Description

An army of ants walk on a horizontal pole of length l cm, each with a constant speed of 1 cm/s. 
When a walking ant reaches an end of the pole, it immediatelly falls off it. When two ants meet 
they turn back and start walking in opposite directions. We know the original positions of ants 
on the pole, unfortunately, we do not know the directions in which the ants are walking. Your 
task is to compute the earliest and the latest possible times needed for all ants to fall off the pole.

Input

The first line of input contains one integer giving the number of cases that follow. The data 
for each case start with two integer numbers: the length of the pole (in cm) and n, the number 
of ants residing on the pole. These two numbers are followed by n integers giving the position 
of each ant on the pole as the distance measured from the left end of the pole, in no particular 
order. All input integers are not bigger than 1000000 and they are separated by whitespace.

Output

For each case of input, output two numbers separated by a single space. The first number is the 
earliest possible time when all ants fall off the pole (if the directions of their walks are chosen 
appropriately) and the second number is the latest possible such time. 

Sample Input

2
10 3
2 6 7
214 7
11 12 7 13 176 23 191
Sample Output

4 8
38 207
*/

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int tmp[1000005];

vector<int> solved(int l, int n) {
	vector<int> res(2, 0);

	for (int i = 0; i < n; i++) {
		res[0] = max(res[0], min(tmp[i], l - tmp[i]));
		res[1] = max(res[1], max(tmp[i], l - tmp[i]));
	}

	return res;
}

int main() {
	int test, l, n;
	scanf("%d", &test);

	while(test--) {
		scanf("%d %d", &l, &n);
		int temp;
		for (int i = 0; i < n; i++) {
			scanf("%d", &temp);
			tmp[i] = temp;
		}
		vector<int> res;
		res = solved(l, n);

		printf("%d %d\n", res[0], res[1]);
		// cout << res[0] << " " << res[1] << endl;
		
	}
}