#include <iostream>
#include <cstdio>
using namespace std;

int main() {
  int num = 0, n;
  scanf("%d", &n);
  while (n != 1) {
    if (n & 1) {
      n = 3 * n + 1;
    } 
    n /= 2;
    num++;
  }
  printf("%d\n", num);
  return 0;
}