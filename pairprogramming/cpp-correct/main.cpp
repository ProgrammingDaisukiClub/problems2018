#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  int m = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    int m = (m + a) % 2;
    cout << m << endl;
  }
}
