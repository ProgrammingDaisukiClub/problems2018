#include <stdio.h>
#include <string.h>

char know[100][100], saw[100][100];
char query[100];

void solve(){
	int n, m;
	int i, j;
	int sawcount = 0;
	scanf("%d", &n);
	for(i = 0; i < n; i++){
		scanf("%s", know[i]);
	}
	scanf("%d", &m);
	for(i = 0; i < m; i++){
		int known = 0, done = 0;
		scanf("%s", query);
		for(j = 0; j < n; j++){
			if(strcmp(know[j], query) == 0){
				known = 1; break;
			}
		}
		if(!known){
			printf("siranai\n");
			continue;
		}

		for(j = 0; j < sawcount; j++){
			if(strcmp(saw[j], query) == 0){
				printf("moumita\n");
				done = 1; break;
			}
		}
		if(done)continue;

		printf("kawaii\n");
		strcpy(saw[sawcount++], query);
	}
}

int main(void){
	int t;
	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		solve();
	}	
	return 0;
}
