template<typename T> class minplus_matrix{
private:
    using mat = vector<vector<T>>;
public:
    T inf = numeric_limits<T>::max()/2;
    int sz;
    mat A;
    explicit minplus_matrix(int sz, T val = numeric_limits<T>::max()/2) : sz(sz), A(sz, vector<T>(sz, val)) {}

    vector<T>& operator[] (int i){
        return A[i];
    }

    const vector<T>& operator[] (int i) const{
        return A[i];
    }

    int size() const{
        return sz;
    }

    static minplus_matrix identity(int n){
        minplus_matrix I(n);
        for (int i = 0; i < n; i++) I[i][i] = 0;
        return I;
    }

    friend istream& operator >> (istream& is, minplus_matrix& M){
        for(int i = 0; i < M.size(); i++){
            for(int j = 0; j < M.size(); j++){
                is >> M[i][j];
            }
        }
        return is;
    }

    minplus_matrix operator * (const minplus_matrix& B) const{
        assert(sz == B.sz);
        minplus_matrix C(sz);
        for (int i = 0; i < sz; i++){
            for (int k = 0; k < sz; k++){
                for (int j = 0; j < sz; j++){
                    if (A[i][k] == inf || B[k][j] == inf) continue;
                    C[i][j] = min(C[i][j], A[i][k]+B[k][j]);
                }
            }
        }
        return C;
    }

    minplus_matrix& operator *= (const minplus_matrix& B){
        assert(sz == B.sz);
        *this = (*this) *B;
        return *this;
    }

    minplus_matrix pow(long long n) const{
        minplus_matrix base = *this;
        minplus_matrix R = identity(sz);
        while (n > 0){
            if (n&1) R = R * base;
            base = base * base;
            n >>= 1;
        }
        return R;
    }
};
