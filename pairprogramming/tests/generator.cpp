#include <fstream>
#include "constraints.h"
#include "testlib.h"

using namespace std;

void generate(const string& file_name, int num_case, int max_n, int max_a) {
  ofstream ofs(file_name);
  ofs << num_case << endl;

  for (int i = 0; i < num_case; i++) {
    int n;
    if (i == 0) {
      n = max_n;
    } else if (i == 1) {
      n = 1;
    } else {
      n = rnd.next(1, max_n);
    }

    ofs << n << endl;

    for (int i = 0; i < n; i++) {
      ofs << (i ? " " : "") << rnd.next(0, max_a);
    }
    ofs << endl;
  }
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  generate("small.in", MAX_T, 10, 10);
  generate("large.in", MAX_T, MAX_N, MAX_A);
  for (int i = 0; i < 10; i++) {
    generate("random_test" + to_string(i) + ".in", MAX_T, MAX_N, MAX_A);
  }

  return 0;
}
