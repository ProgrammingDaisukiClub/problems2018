#include <fstream>
#include <string>
#include <cassert>
#include <cmath>
#include "testlib.h"
#include "constraints.h"

using namespace std;

using P = pair<long,long>;

vector<vector<P>> handmade_med = {
  {{-3000,-3000}, {3000,-3000}, {-3000,3000}, {3000,3000}, {-2999,-2999}, {2999,-2999}, {-2999,2999}, {2999,2999}},
  {{-2999,-2999}, {3000,-2999}, {-2999,3000}, {3000,3000}, {-3000,-3000}, {2999,-3000}, {-3000,2999}, {2999,2999}},
  {{-3000,-3000}, {3000,-3000}, {-3000,3000}, {3000,3000}, {-3000,-3000}, {2999,-3000}, {-3000,2999}, {2999,2999}},
  {{-3000,3000}, {0,3000}, {-3000,0}, {0,0}, {0,0}, {0,3000}, {3000,0}, {3000,3000}},
  {{-3000,-3000}, {-3000,-2999}, {-2999,-3000}, {-2999,-2999}, {-3000,3000}, {-3000,2999}, {-2999,3000}, {-2999,2999}},
  {{-3000,-3000}, {-3000, -3000}, {3000,-3000}, {3000, -3000}, {-3000,3000}, {-3000,3000}, {3000,3000}, {3000,3000}},
  {{0,0}, {1,0}, {0,1}, {1,1}, {2,0}, {3,0}, {2,1}, {3,1}}
};

vector<vector<P>> handmade_large = {
  {{-3000,-3000}, {3000,-3000}, {-3000,3000}, {3000,3000}, {-2999,3000}, {3000,2999}, {2999,-3000}, {-3000,-2999}},
  {{-3000,2999}, {2999,3000}, {3000,-2999}, {-2999,-3000}, {-2999,3000}, {3000,2999}, {2999,-3000}, {-3000,-2999}},
  {{0,-3000}, {0,3000}, {-3000,0}, {3000,0}, {-3000,-3000}, {-3000,0}, {0,-3000}, {0,0}},
};


void shuffle_and_output(ostream &os, vector<vector<P>> &vec) {
  shuffle(begin(vec), end(vec));
  for(auto &v : vec) {
    for(int i=0; i<8; i++) os << v[i].first << " " << v[i].second << (i==7 ? "\n" : " ");
  }
}

void shuffle_vector(vector<P> &v) {
  assert(v.size() == 8);
  shuffle(begin(v), end(v));
}

bool validate(const vector<P> &v) {
  if(v.size() != 8) return false;

  for(int i=0; i<8; i++){
    if(MAX_ABS < abs(v[i].first) || MAX_ABS < abs(v[i].second)) return false;
  }

  auto check_square = [](const vector<P> &ps){
    auto dist = [](const P &lhs, const P &rhs){
      long dx = lhs.first - rhs.first;
      long dy = lhs.second - rhs.second;
      return dx*dx + dy*dy;
    };

    map<long,long> dists;
    for(int i=0; i<4; i++){
      for(int j=i+1; j<4; j++) dists[dist(ps[i], ps[j])]++;
    }

    vector<P> conv(begin(dists), end(dists));
    if(conv.size() != 2 || conv[0].first*2 != conv[1].first || conv[0].second != 4 || conv[1].second != 2) return 0L;
    return conv[0].first;
  };


  map<P,int> ans;
  for(int mask=0; mask < (1<<8); mask++) if(__builtin_popcount(mask)==4){
    vector<P> v1,v2;
    for(int i=0; i<8; i++){
      if((mask>>i)%2) v1.push_back(v[i]);
      else v2.push_back(v[i]);
    }

    long l1 = check_square(v1);
    long l2 = check_square(v2);
    if(l1>0 && l2>0) ans[{min(l1,l2), max(l1,l2)}]++;
  }

  return ans.size() == 1;
}


void generate(const string &file_name, int num_case, int max_abs, vector<vector<P>> hand_cases, bool is_parallel = false) {
  ofstream in_ofs(file_name + ".in");
  in_ofs << num_case << endl;

  auto gen_square = [max_abs, is_parallel](){
    P p1 = {rnd.next(-max_abs/2, max_abs/2), rnd.next(-max_abs/2, max_abs)/2};
    int dx,dy;
    do {
      dx = rnd.next(-max_abs/2, max_abs/2);
      dy = rnd.next(-max_abs/2, max_abs/2);
      if(is_parallel){
        if(rnd.next(0,1) == 0) dx = 0;
        else dy = 0;
      }
    } while(dx==0 && dy==0);

    P p2 = {p1.first + dx, p1.second + dy};
    P p3 = {p1.first - dy, p1.second + dx};
    P p4 = {p1.first + dx - dy, p1.second + dx + dy};
    return vector<P>({p1, p2, p3, p4});
  };

  vector<vector<P>> cases;

  for (int i=0; i + hand_cases.size()<num_case; i++) {
    vector<P> v;
    do {
      v = gen_square();
      auto tmp = gen_square();
      v.insert(v.end(), tmp.begin(), tmp.end());
    } while(!validate(v));
    shuffle_vector(v);
    cases.push_back(v);
  }

  for (auto &v : hand_cases) {
    assert(validate(v));
    shuffle_vector(v);
    cases.push_back(v);
  }

  shuffle_and_output(in_ofs, cases);
}


int main(int argc, char* argv[]) {
  registerGen(argc, argv, 1);

  generate("small", 5, 100, {}, true);
  generate("medium", MAX_T, MAX_ABS, handmade_med, true);
  handmade_large.insert(handmade_large.end(), handmade_med.begin(), handmade_med.end());
  generate("large", MAX_T, MAX_ABS, handmade_large);
  for (int i=0; i<10; i++) {
    generate("random_test" + to_string(i), MAX_T, MAX_ABS, {});
  }

  return 0;
}
