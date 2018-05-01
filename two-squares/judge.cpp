#include "testlib.h"
#include <cstdio>
using namespace std;
typedef pair<int,int> P;

int main(int argc,char *argv[]){
	registerTestlibCmd(argc,argv);
	int test=inf.readInt();
	for(int i=0;i<test;i++){
		int x[8],y[8];
		for(int j=0;j<8;j++){
			x[j]=inf.readInt();
			y[j]=inf.readInt();
		}
		P judge,out;
		judge.first=ans.readInt();
		judge.second=ans.readInt();
		out.first=ouf.readInt();
		out.second=ouf.readInt();
		if(out!=judge){
			quitf(_wa,"Wrong Answer on %d test, expected:(%d,%d), found:(%d,%d)",i+1,judge.first,judge.second,out.first,out.second);
			return 0;
		}
	}
	quitf(_ac,"OK all number correct");
	return 0;
}