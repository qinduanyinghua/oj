#include <iostream>
#include <string>

using namespace std;

int main() {
	string str[10] = {"ling", "yi", "er", "san", "wu", "liu", "qi", "ba", "jiu"};
	string s;
	int sum = 0;
	cin >> s;
	for (int i = 0; s[i] != '\0'; i++) {
		sum += (s[i] - '0');
	}
	string res = to_string(sum);
	cout << str[res[0] - '0'];
	for (int i = 1; i < res.length(); i++) {
		cout << " " << str[res[i] - '0'];
	}
	return 0;
}