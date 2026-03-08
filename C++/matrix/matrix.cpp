template<typename T> class matrix{
private:
    using mat = vector<vector<T>>;
public:
    int sz;
    mat A;
    explicit matrix(int sz, T val = T()) : sz(sz), A(sz, vector<T>(sz, val)) {}

    vector<T>& operator [] (int i){
        return A[i];
    }

    const vector<T>& operator[] (int i) const{
        return A[i];
    }

    int size() const{
        return sz;
    }

    static matrix identity(int n){
        matrix I(n);
        for (int i = 0; i < n; i++) I[i][i] = T(1);
        return I;
    }

    friend istream& operator >> (istream& is, matrix& M){
        for(int i = 0; i < M.size(); i++){
            for(int j = 0; j < M.size(); j++){
                is >> M[i][j];
            }
        }
        return is;
    }

    matrix operator + (const matrix& B) const{
        assert(sz == B.sz);
        matrix C(sz);
        for (int i = 0; i < sz; i++){
            for (int j = 0; j < sz; j++){
                C[i][j] = A[i][j]+B[i][j];
            }
        }
        return C;
    }

    matrix& operator += (const matrix& B){
        assert(sz == B.sz);
        for (int i = 0; i < sz; i++){
            for (int j = 0; j < sz; j++){
                A[i][j] += B[i][j];
            }
        }
        return *this;
    }

    matrix operator - (const matrix& B) const{
        assert(sz == B.sz);
        matrix C(sz);
        for (int i = 0; i < sz; i++){
            for (int j = 0; j < sz; j++){
                C[i][j] = A[i][j]-B[i][j];
            }
        }
        return C;
    }

    matrix& operator -= (const matrix& B){
        assert(sz == B.sz);
        for (int i = 0; i < sz; i++){
            for (int j = 0; j < sz; j++){
                A[i][j] -= B[i][j];
            }
        }
        return *this;
    }

    matrix operator * (const matrix& B) const{
        assert(sz == B.sz);
        matrix C(sz, T());
        for (int i = 0; i < sz; i++){
            for (int k = 0; k < sz; k++){
                if (A[i][k] == T()) continue;
                for (int j = 0; j < sz; j++){
                    C[i][j] += A[i][k]*B[k][j];
                }
            }
        }
        return C;
    }

    matrix& operator *= (const matrix& B){
        assert(sz == B.sz);
        *this = (*this) *B;
        return *this;
    }

    matrix pow(long long n) const{
        matrix base = *this;
        matrix R = identity(sz);
        while (n > 0){
            if (n&1) R *= base;
            base *= base;
            n >>= 1;
        }
        return R;
    }
};