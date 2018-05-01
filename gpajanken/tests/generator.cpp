#include <fstream>
#include <string>
#include "testlib.h"
#include "constraints.h"

using namespace std;

void generate(const string &file_name, int num_case) {
  ofstream ofs(file_name);
  ofs << num_case <<endl;

  for (int i=0; i<num_case; i++) {
    ofs << rnd.next(MIN_AB, MAX_AB) << " ";
    ofs << rnd.next(MIN_AB, MAX_AB) << endl;
  }
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  generate("small.in", 10);
  generate("large.in", MAX_T);
  for (int i=0; i<10; i++) {
    generate("random_test" + to_string(i) + ".in", MAX_T);
  }

  return 0;
}
