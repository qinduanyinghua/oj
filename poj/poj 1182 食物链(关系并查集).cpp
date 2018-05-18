/*
Description
动物王国中有三类动物A,B,C，这三类动物的食物链构成了有趣的环形。A吃B， B吃C，C吃A。 
现有N个动物，以1－N编号。每个动物都是A,B,C中的一种，但是我们并不知道它到底是哪一种。 
有人用两种说法对这N个动物所构成的食物链关系进行描述： 
第一种说法是"1 X Y"，表示X和Y是同类。 
第二种说法是"2 X Y"，表示X吃Y。 
此人对N个动物，用上述两种说法，一句接一句地说出K句话，这K句话有的是真的，有的是假的。当一句话满足下列三条之一时，这句话就是假话，否则就是真话。 
1）	当前的话与前面的某些真的话冲突，就是假话； 
2）	当前的话中X或Y比N大，就是假话； 
3）	当前的话表示X吃X，就是假话。 
你的任务是根据给定的N（1 <= N <= 50,000）和K句话（0 <= K <= 100,000），输出假话的总数。 
Input

第一行是两个整数N和K，以一个空格分隔。 
以下K行每行是三个正整数 D，X，Y，两数之间用一个空格隔开，其中D表示说法的种类。 
若D=1，则表示X和Y是同类。 
若D=2，则表示X吃Y。
Output

只有一个整数，表示假话的数目。

Sample Input

100 7
1 101 1 
2 1 2
2 2 3 
2 3 3 
1 1 3 
2 3 1 
1 5 5
Sample Output

3
*/

#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

#define N 50010

struct node {
	int par;
	int relation;
};

node p[N];

void init(int n) {
	for (int i = 1; i <= n; i++) {
		p[i].par = i;
		p[i].relation = 0;
	}
}

int find(int x) {
	if (x == p[x].par) {
		return x;
	}
	int temp = p[x].par;
	p[x].par = find(temp);
	p[x].relation = (p[temp].relation + p[x].relation) % 3;
	return p[x].par;
}

int main() {
	int n, k;
	int d, x, y;
	int sum = 0;
	int rootx, rooty;
	scanf("%d %d", &n, &k);

	// initialize
	init(n);

	for (int i = 0; i < k; i++) {
		scanf("%d %d %d", &d, &x, &y);

		if (x > n || y > n) {
			sum++;
			continue;
		}
		if (d == 2 && x == y) {
			sum++;
			continue;
		}

		rootx = find(x);
		rooty = find(y);
		if (rootx != rooty) {
			p[rooty].par = rootx;
			p[rooty].relation = (p[x].relation + (d - 1) + (3 - p[y].relation)) % 3;
		} else {
			if ((d == 1 && (p[x].relation != p[y].relation))
				|| ((d == 2) &&  (d - 1 != (3 - p[x].relation + p[y].relation) % 3))){
				sum++;
			}
		}
	}

	printf("%d\n", sum);
	return 0;
}

