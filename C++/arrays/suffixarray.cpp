template <class T> class suffixarray{
public:
    vector<T> s;
    vector<int> sa, lcp;

    suffixarray(const vector<T>& str){
        s = str;
        build_sa();
        build_lcp();
    }

private:
    void build_sa(){
        int n = s.size();
        sa.resize(n);
        vector<int> rnk(n), tmp(n);
        vector<T> xs = s;
        sort(xs.begin(), xs.end());
        xs.erase(unique(xs.begin(), xs.end()), xs.end());
        for (int i = 0; i < n; i++){
            sa[i] = i;
            rnk[i] = lower_bound(xs.begin(), xs.end(), s[i]) - xs.begin();
        }
        for (int k = 1; k < n; k <<= 1){
            auto cmp = [&](int i, int j){
                if (rnk[i] != rnk[j]) return rnk[i] < rnk[j];
                int ri = (i+k < n? rnk[i+k]: -1);
                int rj = (j+k < n? rnk[j+k]: -1);
                return ri < rj;
            };
            sort(sa.begin(), sa.end(), cmp);
            tmp[sa[0]] = 0;
            for (int i = 1; i < n; i++){
                tmp[sa[i]] = tmp[sa[i-1]] + cmp(sa[i-1], sa[i]);
            }
            for (int i = 0; i < n; i++) rnk[i] = tmp[i];
            if (rnk[sa[n-1]] == n-1) break;
        }
    }

    void build_lcp(){
        int n = s.size();
        if (n > 1) lcp.resize(n - 1);
        vector<int> rnk(n);
        for (int i = 0; i < n; i++) rnk[sa[i]] = i;
        int h = 0;
        for (int i = 0; i < n; i++){
            if (rnk[i] == 0) continue;
            int j = sa[rnk[i]-1];
            if (h > 0) h--;
            while (i+h < n && j+h < n && s[i+h] == s[j+h]) h++;
            lcp[rnk[i]-1] = h;
        }
    }

public:
    int cmp_substr(int pos, const vector<T>& t){
        int n = s.size(), m = t.size();
        for (int i = 0; i < m; i++){
            if (pos+i >= n) return -1;
            if (s[pos+i] != t[i]) return (s[pos+i] < t[i])? -1: 1;
        }
        return 0;
    }

    bool contains(const vector<T>& t){
        return count(t) > 0;
    }

    int lower_bound(const vector<T>& t){
        int left = 0, right = s.size();
        while (left < right){
            int mid = (left+right)/2;
            if (cmp_substr(sa[mid], t) < 0) left = mid+1;
            else right = mid;
        }
        return left;
    }

    int upper_bound(const vector<T>& t){
        int left = 0, right = s.size();
        while (left < right){
            int mid = (left+right)/2;
            if (cmp_substr(sa[mid], t) <= 0) left = mid+1;
            else right = mid;
        }
        return left;
    }

    int count(const vector<T>& t){
        return upper_bound(t)-lower_bound(t);
    }
};
