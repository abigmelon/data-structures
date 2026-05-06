#include <stdio.h>
#include <stdlib.h>

int a[200005];
long long pre[200005];

int cmp(const void *p, const void *q) {
    int x = *(int *)p, y = *(int *)q;
    return (x < y) - (x > y);
}

int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        qsort(a, n, sizeof(int), cmp);
        pre[0] = 0;
        for (int i = 0; i < n; i++){
            pre[i + 1] = pre[i] + a[i];
        }
        for (int t = 1; t <= n; t++) {
            int d = t / k;
            long long ans = pre[t] + pre[d];
            printf("%lld ", ans);
        }
        printf("\n");
    }
    return 0;
}
