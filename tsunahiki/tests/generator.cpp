#include <fstream>
#include <string>
#include "testlib.h"
#include "constraints.h"

using namespace std;

void generate(const string &file_name, int num_case, int max_num) {
  ofstream ofs(file_name);
  ofs << num_case <<endl;

  for (int i=0; i<num_case; i++) {
    int N=rnd.next(MIN_AB,max_num);
    ofs << N << endl;
    for(int k=0;k<2;k++){
      int ele=1;
      for(int j=0;j<N;j++){
        if(j!=0)ofs << " ";
        ele=rnd.next(ele,max_num);
      }
      ofs << endl;
    }
  }
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  generate("small.in", 10, 10);
  generate("large.in", MAX_T, MAX_AB);
  for (int i=0; i<10; i++) {
    generate("random_test" + to_string(i) + ".in", MAX_T, MAX_AB);
  }

  return 0;
}
