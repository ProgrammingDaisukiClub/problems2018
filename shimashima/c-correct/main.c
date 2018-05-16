#include <stdio.h>
#include <stdlib.h>

int main(){
  int T;
  scanf("%d", &T);
  for(int i = 0; i < T; i++){
    int A, B;
    scanf("%d %d", &A, &B);
    if(abs(A - B) <= 1){
      printf("YES\n");
    }else{
      printf("NO\n");
    }
  }
  return 0;
}
