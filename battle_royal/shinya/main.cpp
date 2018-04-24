#include <iostream>
using namespace std;

int main(void) {
  const int N = 100;
  int K[N];

  for(int i = 0; i < N; i++) {
    cin >> K[i];
  }

  int sum = 0;
  for(int i = 0; i < N; i++) {
    sum += K[i];
  }
  cout << N - sum << endl;

  return 0;
}
