/*
“答案正确”是自动判题系统给出的最令人欢喜的回复。本题属于PAT的“答案正确”大派送 —— 
只要读入的字符串满足下列条件，系统就输出“答案正确”，否则输出“答案错误”。

得到“答案正确”的条件是：

1. 字符串中必须仅有P, A, T这三种字符，不可以包含其它字符；
2. 任意形如 xPATx 的字符串都可以获得“答案正确”，其中 x 或者是空字符串，或者是仅由字母 A 组成的字符串；
3. 如果 aPbTc 是正确的，那么 aPbATca 也是正确的，其中 a, b, c 均或者是空字符串，或者是仅由字母 A 组成的字符串。

现在就请你为PAT写一个自动裁判程序，判定哪些字符串是可以获得“答案正确”的。
输入格式： 每个测试输入包含1个测试用例。第1行给出一个自然数n (<10)，是需要检测的字符串个数。接下来每个字符串占一行，
字符串长度不超过100，且不包含空格。

输出格式：每个字符串的检测结果占一行，如果该字符串可以获得“答案正确”，则输出YES，否则输出NO。

输入样例：
8
PAT
PAAT
AAPATAA
AAPAATAAAA
xPATx
PT
Whatever
APAAATAA
输出样例：
YES
YES
YES
YES
NO
NO
NO
NO
*/
#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

bool judge(string s) {
	int flag = 0;
	int pindex = -1, tindex = -1;
	int pcount = 0, tcount = 0;
	int len = s.length();

	for (int i = 0; i < len; i++) {
		if (!(s[i] == 'P' || s[i] == 'A' || s[i] == 'T')) {
			flag = 1;
			break;
		}
		if ((s[i] == 'P' && pcount == 1) || s[i] == 'T' && tcount == 1) {
			flag = 1;
			break;
		}
		if (s[i] == 'P') {
			pindex = i;
			pcount++;
		}
		if (s[i] == 'T') {
			tindex = i;
			tcount++;
		}
	}
	if (flag == 0 && (pindex != tindex - 1) && (pindex * (tindex - pindex - 1) == (len - tindex - 1))) {
		return true;
	} else {
		return false;
	}
}

int main() {
	int n;
	string s;
	scanf("%d", &n);
	while (n--) {
		cin >> s;
		if (judge(s)) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
/*
#include <iostream>
#include <map>
using namespace std;

int main() {
	int n, p = 0, t = 0;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		map<char, int> m;
		for (int j = 0; j < s.length(); j++) {
			m[s[j]]++;
			if (s[j] == 'P') p = j;
			if (s[j] == 'T') t = j;
		}
		if (m['P'] == 1 && m['T'] == 1 && (p != t - 1) && m.size() == 3
			&& p * (t - p - 1) == s.length() - t - 1) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
*/