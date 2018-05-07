#include <fstream>
#include <string>
#include <algorithm>
#include <random>
#include "testlib.h"
#include "constraints.h"
using namespace std;

double normal(double mu, double sigma) {
  const double PI = acos(-1);
  double z = sqrt(-2.0*log(rnd.next(1.0))) * sin(2.0 * PI * rnd.next(1.0));
  return mu + z * sigma;
}

void generate(const string &name, int T) {
  ofstream ofs(name);

  ofs << T << endl;
  for(int t = 0; t < T; t++) {
    int K[PLAYERS];
    int remain = PLAYERS - 1;
    double mu = rnd.next(1.0, 5.0);
    double sigma = rnd.next(0.0, 5.0);
    for(int i = 0; i < PLAYERS; i++) {
      K[i] = min(max((int) normal(mu, sigma), 0), remain);
      remain -= K[i];
    }

    random_device seed_gen;
    mt19937 engine(seed_gen());
    shuffle(K, K + PLAYERS, engine);

    for(int i = 0; i < PLAYERS; i++) {
      ofs << K[i] << (i + 1 != PLAYERS ? " " : "\n");
    }
  }
}

int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  generate("small.in", 10);
  generate("large.in", MAX_T);

  for(int i = 0; i < 10; i++) {
    generate("random_test" + to_string(i) + ".in", MAX_T);
  }

  return 0;
}
