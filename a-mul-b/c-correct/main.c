#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        int a, b;
        scanf("%d %d ", &a, &b);
        int answer = a * b;
        printf("%d\n", answer);
    }
    return 0;
}
