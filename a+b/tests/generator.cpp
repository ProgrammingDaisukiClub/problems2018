#include <fstream>
#include <string>
#include "testlib.h"
#include "constraints.h"

using namespace std;

void generate(const string &file_name, int num_case, int max_num) {
  ofstream ofs(file_name);
  ofs << num_case <<endl;

  for (int i=0; i<num_case; i++) {
    ofs << rnd.next(-max_num, max_num) << " ";
    ofs << rnd.next(-max_num, max_num) << endl;
  }
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  generate("small.in", 10, 500);
  generate("large.in", MAX_T, MAX_AB);
  for (int i=0; i<10; i++) {
    generate("random_test" + to_string(i) + ".in", MAX_T, MAX_AB);
  }

  return 0;
}
