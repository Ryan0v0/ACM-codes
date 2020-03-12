class Trie {
private:
    static const int N = 100000;
    int cnt, t[N][30];
    bool end[N];
public:
    /** Initialize your data structure here. */
    Trie() {
        cnt = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < 30; j++) {
                t[i][j] = 0;
            }
        }
        memset(end, false, sizeof(end));
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        int cur = 0;
        for (char ch : word) {
            if (!t[cur][ch - 'a']) {
                t[cur][ch - 'a'] = ++cnt;
            }
            cur = t[cur][ch - 'a'];
        }
        end[cur] = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int cur = 0;
        for (char ch : word) {
            if (!t[cur][ch - 'a']) {
                return false;
            }
            cur = t[cur][ch - 'a'];
        }
        return end[cur];
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int cur = 0;
        for (char ch : prefix) {
            if (!t[cur][ch - 'a']) {
                return false;
            }
            cur = t[cur][ch - 'a'];
        }
        return true;
    }
};
