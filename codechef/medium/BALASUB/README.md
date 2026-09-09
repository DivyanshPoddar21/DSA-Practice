# BALASUB

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

### SuBalance

An array $B$ is called  *balanced*  if it has an equal number of prefix maximums and suffix maximums.
Here,

- Element $B_i$ is a prefix maximum if $B_i \ge B_j$ for all $1 \le j \lt i$
- Element $B_i$ is a suffix maximum if $B_i \ge B_j$ for all $i \lt j \le |B|$, where $|B|$ denotes the length of $B$.

You are given an array $A$ of length $N$.

Find  *any*  contiguous subarray of $A$ with  **length at least $2$**  that's balanced, i.e. find any pair $(L, R)$ such that $1 \le L \lt R \le N$ and $[A_L, \ldots, A_R]$ is balanced.

If there are multiple balanced subarrays of $A$ of length $\ge 2$, you may find any of them.
If there are no balanced subarrays in $A$ of length $\ge 2$, print $-1$.

### Input Format
- The first line of input will contain a single integer $T$, denoting the number of test cases.
- Each test case consists of two lines of input. The first line of each test case contains a single integers $N$ — the length of the array. The second line contains $N$ space-separated integers $A_1, \ldots, A_N$.
### Output Format

For each test case, on a new line:

- If no balanced subarray of length $\ge 2$ exists, print the single integer $-1$.
- Otherwise, print two space-separated integers $L$ and $R$ ($1 \le L \lt R \le N$), denoting that the subarray $[A_L, \ldots, A_R]$ is balanced.

If there are multiple balanced subarrays of length $\ge 2$, you may find any one of them.

### Constraints
- $1 \leq T \leq 10^5$
- $2 \leq N \leq 2\cdot 10^5$
- $1 \le A_i \le N$
- The sum of $N$ over all test cases won't exceed $2\cdot 10^5$.
### Sample 1:
Input
Output

```
5
2
1 2
3
1 3 2
4
3 1 1 3
5
5 3 1 2 4
5
5 1 5 3 4

```

```
-1
1 3
1 4
-1
2 5
```

### Explanation:

 **Test case $1$:**  The only subarray of length $\ge 2$ is $[1, 2]$, which is not balanced because it has two prefix maximums but only one suffix maximum.
So, we output $-1$.

 **Test case $2$:**  The subarray $[1, 3, 2]$ is balanced, having two prefix maximums ($1$ and $3$) as well as two suffix maximums ($2$ and $3$).

## Solution

**Language:** c_cpp  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-09T16:26:33.941Z  

```c_cpp
#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Pattern 1: Adjacent equals
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i+1]) {
            cout << (i + 1) << " " << (i + 2) << "\n";
            return;
        }
    }

    // Pattern 2: Strict peak
    for (int i = 1; i < n - 1; i++) {
        if (a[i-1] < a[i] && a[i] > a[i+1]) {
            cout << i << " " << (i + 2) << "\n";
            return;
        }
    }

    // Pattern 3: Valley duplicates
    // Using a vector instead of a map guarantees O(N) time without high constant factors
    vector<int> seen(n + 1, -1);
    for (int i = 0; i < n; i++) {
        if (seen[a[i]] != -1) {
            cout << (seen[a[i]] + 1) << " " << (i + 1) << "\n";
            return;
        }
        seen[a[i]] = i;
    }

    // If no patterns are found
    cout << -1 << "\n";
}

int main() {
    // Optimize standard I/O operations for performance
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

[View on CodeChef](https://www.codechef.com/problems/BALASUB)