#include <stdio.h>

int main() {
  int t;
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int n;
    scanf("%d", &n);
    int m = 0;
    for (int j = 0; j < n; j++) {
      int a;
      scanf("%d", &a);
      m = (m + a) % 2;
      printf("%d\n", m);
    }
  }
  return 0;
}
