/* 
Time Limit:1000ms
Case Time Limit:1000ms
Memory Limit:256MB
Description
Calculate A + B.

Input
Input contains multiple test cases。
Each test case contains two integers: A(1 ≤ A ≤ 100) and B(1 ≤ B ≤ 100).

Output
For each test case output the sum A + B.

Sample Input
1 2
3 4
Sample Output
3
7
*/
#include <iostream>
using namespace std;

int main() {
    int a, b;
    while(cin >> a >> b) {
        cout << a + b << endl;
    }
    return 0;
}
