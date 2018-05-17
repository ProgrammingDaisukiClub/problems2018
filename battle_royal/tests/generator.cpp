#include <fstream>
#include <string>
#include <algorithm>
#include <random>
#include "testlib.h"
#include "constraints.h"
using namespace std;

vector<int> random_case(int kill_sum, int killers) {
  int remain = kill_sum - killers;
  vector<int> K(PLAYERS);
  for(int i = 0; i < killers; i++) K[i] = 1;
  for(int i = 0; i < remain; i++) {
    K[rnd.next(killers)]++;
  }
  shuffle(K.begin(), K.end());
  return K;
}

vector<int> no_kill_case() {
  vector<int> K(PLAYERS);
  return K;
}

void write_data_set(const string &name, vector< vector<int> > &data_set) {
  int T = data_set.size();
  ofstream ofs(name);
  ofs << T << "\n";
  for(int t = 0; t < T; t++) {
    for(int i = 0; i < PLAYERS; i++) {
      ofs << data_set[t][i] << (i + 1 != PLAYERS ? " " : "\n");
    }
  }
}

void generate_small() {
  vector< vector<int> > data_set;
  data_set.push_back(random_case(32, 15));
  data_set.push_back(random_case(54, 3));
  data_set.push_back(random_case(82, 10));
  data_set.push_back(random_case(98, 87));
  data_set.push_back(random_case(77, 2));
  data_set.push_back(no_kill_case());
  write_data_set("small.in", data_set);
}

void generate_large() {
  vector< vector<int> > data_set;
  for(int t = 0; t < 90; t++) {
    int kill_sum = rnd.next(PLAYERS - 2) + 1;
    int killers = rnd.next(kill_sum) + 1;
    data_set.push_back(random_case(kill_sum, killers));
  }
  data_set.push_back(random_case(32, 15));
  data_set.push_back(random_case(54, 3));
  data_set.push_back(random_case(82, 10));
  data_set.push_back(random_case(98, 87));
  data_set.push_back(random_case(77, 2));
  data_set.push_back(random_case(99, 99));
  data_set.push_back(random_case(99, 1));
  data_set.push_back(random_case(5, 4));
  data_set.push_back(random_case(42, 7));
  data_set.push_back(no_kill_case());
  shuffle(data_set.begin(), data_set.end());
  write_data_set("large.in", data_set);
}

void generate(const string &name, int T) {
  vector< vector<int> > data_set;
  for(int t = 0; t < T; t++) {
    int kill_sum = rnd.next(PLAYERS - 2) + 1;
    int killers = rnd.next(kill_sum) + 1;
    data_set.push_back(random_case(kill_sum, killers));
  }
  shuffle(data_set.begin(), data_set.end());
  write_data_set(name, data_set);
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  generate_small();
  generate_large();

  for(int i = 0; i < 10; i++) {
    generate("random_test" + to_string(i) + ".in", MAX_T);
  }

  return 0;
}
