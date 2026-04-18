class zobristrange{
private:
    int N;
    vector<ull> w1, w2;
    vector<ull> HA1, HA2, HB1, HB2;
    vector<ull> SA, SB;

public:
    zobristrange(int n) : N(n), w1(n+1), w2(n+1), HA1(n+1), HA2(n+1), HB1(n+1), HB2(n+1), SA(n+1), SB(n+1) {
        for (int i = 1; i <= N; i++){
            w1[i] = rng();
            w2[i] = rng();
        }
    }

    void build(const vector<int>& A, const vector<int>& B){
        for(int i = 1; i <= N; i++){
            HA1[i] = HA1[i-1]^w1[A[i]];
            HA2[i] = HA2[i-1]^w2[A[i]];
            HB1[i] = HB1[i-1]^w1[B[i]];
            HB2[i] = HB2[i-1]^w2[B[i]];
            SA[i] = SA[i-1]+w1[A[i]];
            SB[i] = SB[i-1]+w1[B[i]];
        }
    }

    bool same(int l, int r, int L, int R){
        ull a1 = HA1[r]^HA1[l-1];
        ull a2 = HA2[r]^HA2[l-1];
        ull b1 = HB1[R]^HB1[L-1];
        ull b2 = HB2[R]^HB2[L-1];
        ull sa = SA[r]-SA[l-1];
        ull sb = SB[R]-SB[L-1];
        return (a1 == b1 && a2 == b2 && sa == sb);
    }
};
