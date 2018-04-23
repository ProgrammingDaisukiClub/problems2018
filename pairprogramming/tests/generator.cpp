#include <fstream>
#include "constraints.h"
#include "testlib.h"

using namespace std;

void generate(const string& file_name, int n, int max_a) {
  ofstream ofs(file_name);
  ofs << n << endl;

  for (int i = 0; i < n; i++) {
    ofs << (i ? " " : "") << rnd.next(0, max_a);
  }
  ofs << endl;
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  generate("small.in", 10, 1000);
  generate("large.in", MAX_N, MAX_A);
  for (int i = 0; i < 10; i++) {
    generate("random_test" + to_string(i) + ".in", MAX_N, MAX_A);
  }

  return 0;
}
