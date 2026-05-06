#include <stdio.h>
#include <string.h>

#define MAXN 200005

char s[MAXN];
int preA[MAXN];      // preA[i] = 前 i 个字符中 'A' 的数量（i 从 1 开始）
int eq[MAXN];        // 每个 '=' 的位置（1-indexed）
int suffixMax[MAXN]; // suffixMax[i] = max_{r>=i} (r + 1 + A_after[eq[r]])

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int n;
        scanf("%d", &n);
        scanf("%s", s);

        // 前缀和：preA[i] = s[0..i-1] 中 'A' 的数量
        preA[0] = 0;
        int m = 0; // '=' 的数量
        for (int i = 0; i < n; i++) {
            preA[i + 1] = preA[i] + (s[i] == 'A');
            if (s[i] == '=')
                eq[m++] = i + 1; // 1-indexed 位置
        }
        int totalA = preA[n];

        // 没有 = 或只有 1 个 =：答案为 0
        if (m <= 1) {
            printf("0\n");
            continue;
        }

        // 后缀最大值：对每个 r，value = r+1 + (totalA - preA[eq[r]])
        // 其中 r 是 eq 数组中的索引（0-indexed）
        suffixMax[m - 1] = m + (totalA - preA[eq[m - 1]]);
        // 化简：eq 中下标 r，value = r+1 + totalA - preA[eq[r]]
        for (int r = m - 2; r >= 0; r--) {
            int val = r + 1 + totalA - preA[eq[r]];
            suffixMax[r] = val > suffixMax[r + 1] ? val : suffixMax[r + 1];
        }

        int maxKept = totalA; // 保留 0 个 = 的情况（保留所有 A）
        for (int l = 0; l < m; l++) {
            // 保留 eq[l]..eq[r] 之间的 =，r >= l 且使 suffixMax[r] 最大
            int kept = preA[eq[l] - 1] - l + suffixMax[l];
            if (kept > maxKept) maxKept = kept;
        }

        printf("%d\n", n - maxKept);
    }
    return 0;
}
