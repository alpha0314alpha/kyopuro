	template<typename T> class fenwicktree{
	private:
		int n;
		vector<T> bit, a;

	public:
		fenwicktree(int n) : n(n), bit(n, T()), a(n, T()) {}

		void add(int i, T x){
			while(i < n){
				bit[i] += x;
				i |= i + 1;
			}
		}

		void set(int i, T x){
			add(i, x - a[i]);
			a[i] = x;
		}

        T get(int i) const{
            return a[i];
        }

		T _sum(int i) const{
			T res = T();
			while(i >= 0){
				res += bit[i];
				i = (i&(i+1))-1;
			}
			return res;
		}

		T sum(int l, int r) const{
            r--;
			if (l > r) return T();
			return _sum(r)-(l? _sum(l-1): T());
		}

        int lower_bound(T x){
            int i = 0, k = 1;
            while(k<<1 <= n) k <<= 1;
            for(; k > 0; k >>= 1){
                if(i+k <= n && bit[i+k] < x){
                    x -= bit[i+k];
                    i += k;
                }
            }
            return i;
        }
	};
