# MONMED

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### Monotone Median

*This is the easy version of the problem. Here, $N$ is odd and you must construct a valid sequence of subarrays for $K = \frac{N+1}{2}$.
The setup of both problems is otherwise the same.*

You are given a permutation $P$ of length $N$, where $N$ is  **odd**.
A permutation of length $N$ is an array of length $N$ that contains every integer from $1$ to $N$ exactly once each.

Let $K = \frac{N+1}{2}$.
Find a sequence of $K$ subarrays $[L_1,R_1], [L_2,R_2], \ldots, [L_K,R_K]$ such that all the following conditions hold:

- For each $1 \le i \le K$, the length of $[L_i,R_i]$ is exactly $2i-1$. That is, $R_i-L_i+1=2i-1$.
- For each $2 \le i \le K$, the subarray $[L_i,R_i]$ contains $[L_{i-1},R_{i-1}]$. That is, $L_i \le L_{i-1}$ and $R_{i-1} \le R_i$.
- The medians of these $K$ subarrays are strictly increasing.

The median of an array of odd length is its middle element after sorting it. For example, the median of $[4,1,3]$ is $3$.

If many such sequences exist, you may find any of them.
If no such sequence exists, print $-1$.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input. The first line of each test case contains a single integer $N$ — the length of the permutation. The second line of each test case contains $N$ space-separated integers $P_1, \ldots, P_N$.
### Output Format

For each test case:

- If no valid sequence exists, print $-1$ on a new line.
- Otherwise, print $K=\frac{N+1}{2}$ lines. On the $i$-th line, print two space-separated integers $L_i$ and $R_i$, denoting the endpoints of the $i$-th subarray.

If there are multiple valid sequences, you may print any of them.

### Constraints
- $1 \le T \le 10^5$
- $1 \le N \lt 2\cdot 10^5$
- $N$ is odd.
- $P$ is a permutation of $[1,N]$.
- The sum of $N$ over all test cases does not exceed $2\cdot 10^5$.
### Sample 1:
Input
Output

```
5
1
1
3
2 3 1
5
1 3 4 2 5
7
4 7 2 6 1 5 3
7
1 2 4 5 6 3 7

```

```
1 1
3 3
1 3
-1
5 5
3 5
3 7
1 7
-1

```

### Explanation:

 **Test case $1$:**  There's only a single subarray, and it satisfies the condition.

 **Test case $2$:**  We have $P = [2, 3, 1]$. Consider the sequence of subarrays $[1], [2, 3, 1]$. They satisfy the conditions, because:

- Their lengths are $1$ and $3$.
- The first subarray is contained in the second.
- Their medians are $1$ and $2$ in order, which is strictly increasing.

So, this is a valid sequence of subarrays.
We print the endpoints of the subarrays, which is $[3, 3]$ for $[1]$ and $[1, 3]$ for $[2, 3, 1]$.

 **Test case $3$:**  It can be verified that no valid sequence of subarrays satisfying the conditions exists.

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-09T16:18:30.278Z  

```c_cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> p(n + 1);
    vector<int> pos(n + 1);
    
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        pos[p[i]] = i;
    }
    
    int k = (n + 1) / 2;
    vector<int> min_p(k + 1);
    vector<int> max_p(k + 1);
    
    // Track the absolute required boundary for each step i
    min_p[1] = pos[1];
    max_p[1] = pos[1];
    for (int i = 2; i <= k; i++) {
        min_p[i] = min(min_p[i - 1], pos[i]);
        max_p[i] = max(max_p[i - 1], pos[i]);
    }
    
    // Step 1: Check if a valid sequence is possible globally
    for (int i = 1; i <= k; i++) {
        if (max_p[i] - min_p[i] + 1 > 2 * i - 1) {
            cout << -1 << "\n";
            return;
        }
    }
    
    // Step 2: Construct backwards to avoid sub-optimal padding
    vector<pair<int, int>> ans(k + 1);
    ans[k] = {1, n};
    
    int L = 1, R = n;
    
    for (int i = k; i >= 2; i--) {
        // We need to form the (i-1)-th subarray of length 2i - 3
        int target_len = 2 * i - 3; 
        
        // Safely shrink the current boundaries by 2 without violating requirements
        while (R - L + 1 > target_len) {
            if (L < min_p[i - 1]) {
                L++;
            } else if (R > max_p[i - 1]) {
                R--;
            }
        }
        ans[i - 1] = {L, R};
    }
    
    // Step 3: Print in the correct forward order
    for (int i = 1; i <= k; i++) {
        cout << ans[i].first << " " << ans[i].second << "\n";
    }
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    
    return 0;
}
```

---

[View on CodeChef](https://www.codechef.com/problems/MONMED)