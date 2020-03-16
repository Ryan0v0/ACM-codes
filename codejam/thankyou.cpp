class Solution {
private:
    int dx[30] = {-2, -1, 0, 1, 2, -2, -1, 0, 1, 2, -2, -1, 1, 2, -2, -1, 0, 1, 2, -2, -1, 0, 1, 2};
    int dy[30] = {-2, -2, -2, -2, -2, -1, -1, -1, -1, -1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2};
    bool vis[5][5];

    bool check(int x, int y) {
        return (x >= 0) && (x < 3) && (y >= 0) && (y < 3);
    }

    void dfs(int x, int y, int step, int tot, int &ans) {
        if (step == tot) {
            ans++;
            return;
        }
        for (int i = 0; i < 24; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (!check(nx, ny)) {
                continue;
            }
            if (vis[nx][ny]) {
                continue;
            }
            if ((nx + x) % 2 == 0 && (ny + y) % 2 == 0 && (!vis[(nx + x) / 2][(ny + y) / 2])) {
                continue;
            }
            vis[nx][ny] = true;
            dfs(nx, ny, step + 1, tot, ans);
            vis[nx][ny] = false;
        }
    }

public:
    int numberOfPatterns(int m, int n) {
        int ans = 0;
        for (int i = m; i <= n; i++) { // 最多9
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    // memset(vis, false, sizeof(vis));
                    for (int x = 0; x < 3; x++) {
                        for (int y = 0; y < 3; y++) {
                            vis[x][y] = false;
                        }
                    }
                    vis[x][y] = true;
                    dfs(x, y, 1, i, ans);
                }
            }
        }
        return ans;
    }
};