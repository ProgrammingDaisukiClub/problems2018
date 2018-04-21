#include <fstream>
#include <string>
#include "testlib.h"
#include "constraints.h"

using namespace std;

void generate(const string &file_name, int num_case, int max_num) {
  ofstream ofs(file_name);
  ofs << num_case <<endl;
  
  for (int i=0; i<num_case; i++) {
    ofs << 2 * rnd.next(1, max_num / 2) << endl;
  }
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  generate("small.in", 5, 32);
  generate("medium.in", MAX_T, 500);
  generate("large.in", MAX_T, MAX_E);
  for (int i=0; i<10; i++) {
    generate("random_test" + to_string(i) + ".in", MAX_T, MAX_E);
  }

  return 0;
}
