template<typename T> struct dst{
    int N, K;
    vector<T> A;
    vector<vector<T>> table;
    vector<int> log_table;
    function<T(T, T)> op;
    T e;

    dst(const vector<T>& v, T e, function<T(T, T)> op) : A(v), op(op), e(e){
        N = A.size(), K = 0;
        while ((1<<K) < N) K++;
        table.assign(K, vector<T>(N));
        for (int k = 0; k < K; k++){
            table[k] = A;
            int w = 1<<k;
            for (int a = 0; a < N; a += 2*w){
                int mid = min(a+w, N);
                int b = min(a+2*w, N);
                if (mid-1 >= a){
                    table[k][mid-1] = A[mid-1];
                    for (int i = mid-2; i >= a; i--) table[k][i] = op(A[i], table[k][i+1]);
                }
                if (mid < b){
                    table[k][mid] = A[mid];
                    for (int i = mid+1; i < b; i++) table[k][i] = op(table[k][i-1], A[i]);
                }
            }
        }
        log_table.resize(1<<K);
        for (int k = 0; k < K; k++){
            for (int i = (1<<k); i < (1<<(k+1)); i++) log_table[i] = k;
        }
    }

    T prod(int l, int r){
        if (l >= r) return e;
        if (l+1 == r) return A[l];
        int k = log_table[l^(r-1)];
        return op(table[k][l], table[k][r-1]);
    }
};

