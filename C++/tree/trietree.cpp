class trietree{
public:
    static const int SIGMA = 256;
    vector<array<int, SIGMA>> nxt;
    vector<bool> is_end;
    vector<int> cnt;

    trietree(){
        nxt.emplace_back();
        nxt[0].fill(-1);
        is_end.push_back(false);
        cnt.push_back(0);
    }

    void insert(const string& s){
        int v = 0;
        for (unsigned char c : s){
            if (nxt[v][c] == -1){
                nxt[v][c] = nxt.size();
                nxt.emplace_back();
                nxt.back().fill(-1);
                is_end.push_back(false);
                cnt.push_back(0);
            }
            v = nxt[v][c];
            cnt[v]++;
        }
        is_end[v] = true;
    }

    bool search(const string& s) const{
        int v = 0;
        for (unsigned char c : s){
            if (nxt[v][c] == -1) return false;
            v = nxt[v][c];
        }
        return is_end[v];
    }

    bool starts_with(const string& s) const{
        int v = 0;
        for (unsigned char c : s){
            if (nxt[v][c] == -1) return false;
            v = nxt[v][c];
        }
        return true;
    }

    int max_lcp(const string& s) const{
        int v = 0;
        int depth = 0;
        int ans = 0;
        for (unsigned char c : s){
            v = nxt[v][c];
            depth++;
            if (cnt[v] >= 2) ans = depth;
        }
        return ans;
    }
};