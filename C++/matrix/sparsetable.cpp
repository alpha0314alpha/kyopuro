  template<typename T> class sparsetable{
  private:
      vector<vector<T>> st;
      vector<int> log;
      function<T(T, T)> op;
      int n;
  public:
      sparsetable(const vector<T>& a, function<T(T, T)> op) : op(op){
          n = a.size();
          log.resize(n+1);
          log[1] = 0;
          for (int i = 2; i <= n; i++) log[i] = log[i/2]+1;
          int K = log[n]+1;
          st.assign(n, vector<T>(K));
          for (int i = 0; i < n; i++) st[i][0] = a[i];
          for (int j = 1; j < K; j++){
              for (int i = 0; i+(1<<j) <= n; i++){
                  st[i][j] = op(st[i][j-1], st[i+(1<<(j-1))][j-1]);
              }
          }
      }

      T prod(int l, int r){
          int j = log[r-l+1];
          return op(st[l][j], st[r-(1<<j)+1][j]);
      }
  };
