/*
Description

There are so many different religions in the world today that it is difficult to keep track of them all. 
You are interested in finding out how many different religions students in your university believe in. 

You know that there are n students in your university (0 < n <= 50000). It is infeasible for you to ask
every student their religious beliefs. Furthermore, many students are not comfortable expressing their beliefs. 
One way to avoid these problems is to ask m (0 <= m <= n(n-1)/2) pairs of students and ask them whether they believe
in the same religion (e.g. they may know if they both attend the same church). From this data, you may not 
know what each person believes in, but you can get an idea of the upper bound of how many different religions
can be possibly represented on campus. You may assume that each student subscribes to at most one religion.
Input

The input consists of a number of cases. Each case starts with a line specifying the integers n and m. 
The next m lines each consists of two integers i and j, specifying that students i and j believe in 
the same religion. The students are numbered 1 to n. The end of input is specified by a line in which n = m = 0.
Output

For each test case, print on a single line the case number (starting with 1) followed by the maximum 
number of different religions that the students in the university believe in.
Sample Input

10 9
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
10 4
2 3
4 5
4 8
5 8
0 0
Sample Output

Case 1: 1
Case 2: 7
*/
/*
分析：一开始最大数量count应该是学生人数，每输入一个i,j,如果i和j不是同一个集合，那么合并到同一个集合中，count--
*/
#include <iostream>
#include <cstdio>
using namespace std;

int par[50001];
int rank[50001];

void init(int n) {
	for (int i = 1; i <= n; i++) {
		par[i] = i;
		rank[i] = 0;
	}
}

int find(int x) {
	if (x == par[x]) {
		return x;
	} else {
		par[x] = find(par[x]);
	}
	return par[x];
}

void merge(int x, int y) {
	if (rank[x] < rank[y]) {
		par[x] = y;
	} else {
		par[y] = x;
		if (rank[x] == rank[y])
			rank[x]++;
	}
}

int main() {
	int n, m;
	int test = 0;
	while (scanf("%d %d", &n, &m) != EOF) {
		if (n == 0 && m == 0)
			break;
		init(n);
		int count = n;
		int x, y;
		for (int i = 0; i < m; i++) {
			scanf("%d %d", &x, &y);
			int rootx = find(x);
			int rooty = find(y);
			if (rootx != rooty) {
				merge(rootx, rooty);
				count--;
			}
		}
		++test;
		printf("Case %d: %d\n", test, count);
	}
	return 0;
}