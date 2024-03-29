## Codeforces Round #589 (Div. 2)

#### E

$dp[i][j]$ 前i行恰好覆盖j列的方案数

$dp[i-1][k]—>dp[i][j]$

按行考虑：

$i \geq 2:$

​	新增覆盖的列：$\tbinom{n-k}{j-k}$

​	重复覆盖的列：$K^k$ (注意$K$与$k$不同)

​	未被覆盖的列：$(K-1)^{(n-j)}$

​	乘法原理得：$dp[i][j]=dp[i-1][k]*\tbinom{n-k}{j-k}*K^k*(K-1)^{(n-j)}$

 * 特殊情况：当$k==j$（即当前行没有新增覆盖的列）时,为了保证该行被覆盖，则重复覆盖的列中必须有1

   $dp[i][j]=dp[i-1][j]*(K^j-(K-1)^j)*(K-1)^{(n-j)}$

$i=1$：

​	$dp[1][i]=\tbinom{n}{i}*(K-1)^{(n-i)}$	