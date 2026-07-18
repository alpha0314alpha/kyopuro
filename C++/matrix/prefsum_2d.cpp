template<class T> struct prefsum_2d{
    int H, W;
    vector<vector<T>> S;

    prefsum_2d(const vector<vector<T>>& A) : H((int)A.size()), W((int)A[0].size()){
        for (const auto& a : A) assert((int)A[0].size() == W);
        S.assign(H+1, vector<T>(W+1));
        for (int i = 1; i <= H; i++) for (int j = 1; j <= W; j++){
            S[i][j] = A[i-1][j-1]+S[i][j-1]+S[i-1][j]-S[i-1][j-1];
        }
    }

    T sum(int h1, int w1, int h2, int w2) const{
        return S[h2][w2]-S[h1][w2]-S[h2][w1]+S[h1][w1];
    }
};
