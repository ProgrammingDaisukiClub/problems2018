#include <fstream>
#include <string>
#include "testlib.h"
#include "constraints.h"

using namespace std;

void generate(const string &file_name, int num_case, int n, int m) {
  ofstream ofs(file_name);
  ofs << num_case << endl;

  for (int i=0; i<num_case; i++) {
    ofs << n << endl;

    set<string> know;
    vector<string> a;
    for(int j=0; j<n; j++) {
      while(1){
        string animal = pattern("[a-z]{1,20}").next(rnd);
        if(know.count(animal)) continue;

        ofs << animal << endl;
        know.insert(animal);
        a.push_back(animal);
        break;
      }
    }
    ofs << m << endl;
    for(int j=0; j<m; j++) {
      int s = rnd.next(0,1);
      if(s==0) {
        // knowに存在する名前を生成
        int idx = rnd.next(0,n-1);
        ofs << a[idx] << endl;
      }
      else {
        while(1){
          string animal = pattern("[a-z]{1,20}").next(rnd);
          if(know.count(animal)) continue;
          ofs << animal << endl;
          break;
        }
      }
    }
  }
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  generate("small.in", 10, 5, 20);
  generate("large.in", MAX_T, MAX_N, MAX_M);
  for (int i=0; i<10; i++) {
    generate("random_test" + to_string(i) + ".in", MAX_T, MAX_N, MAX_M);
  }

  return 0;
}
