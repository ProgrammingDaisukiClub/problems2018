#include <stdio.h>

int N;
int A[101];
int B[101];

void read_input(){
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&B[i]);
	}
}

void solve_greedy(){
	int ans=0;
	int rb=N;
	for(int i=N-1;i>=0;i--){
		while(rb>0){
			rb--;
			if(A[i]>B[rb]){
				ans++;
				break;
			}
		}
	}
	printf("%d\n",ans);
}

int main(void){
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++){
		read_input();
		solve_greedy();
	}
	return 0;
}