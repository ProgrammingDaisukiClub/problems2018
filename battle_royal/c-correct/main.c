#include <stdio.h>

int main(void) {
  const int N = 100;
  int T;
  int K[N];

  scanf("%d", &T);
  for(int t = 0; t < T; t++) {
    for(int i = 0; i < N; i++) {
      scanf("%d", &K[i]);
    }

    int sum = 0;
    for(int i = 0; i < N; i++) {
      sum += K[i];
    }
    printf("%d\n", N - sum);
  }

  return 0;
}
