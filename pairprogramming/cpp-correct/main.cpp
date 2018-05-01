#include <iostream>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int m = 0;
    for (int j = 0; j < n; j++) {
      int a;
      cin >> a;
      int m = (m + a) % 2;
      cout << m << endl;
    }
  }
}
