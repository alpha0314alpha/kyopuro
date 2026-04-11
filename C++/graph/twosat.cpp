class twosat{
private:
public:
	int N;
	vector<vector<int>> G, rG;
	vector<int> comp, order, used;
	vector<bool> answer;

	twosat(int n) : N(n){
		G.resize(2*n);
	}

	int var(int i, bool f){
		return 2*i+(f? 1: 0);
	}

	void add_implication(int u, int v){
		G[u].push_back(v);
	}

	void add_or(int i, bool f, int j, bool g){
		add_implication(var(i, !f), var(j, g));
		add_implication(var(j, !g), var(i, f));
	}

	void add_if(int i, bool f, int j, bool g){
		add_implication(var(i, f), var(j, g));
	}

	void set_true(int i, bool f){
		add_implication(var(i, !f), var(i, f));
	}

	void dfs1(int n){
		used[n] = 1;
		for (auto i : G[n]) if (!used[i]) dfs1(i);
		order.push_back(n);
	}

	void dfs2(int n, int c){
		comp[n] = c;
		for (int i : rG[n]) if (comp[i] == -1) dfs2(i, c);
	}

	bool satisfiable(){
		int n = 2*N;
		used.assign(n, 0);
		order.clear();
		for (int i = 0; i < n; i++) if (!used[i]) dfs1(i);
		rG.assign(n, {});
		for (int i = 0; i < n; i++) for (int j : G[i]) rG[j].push_back(i);
		comp.assign(n, -1);
		int k = 0;
		for (int i = n-1; i >= 0; i--) if (comp[order[i]] == -1) dfs2(order[i], k++);
		answer.assign(N, false);
		for (int i = 0; i < N; i++){
			if (comp[2*i] == comp[2*i+1]) return false;
			answer[i] = (comp[2*i] < comp[2*i+1]);
		}
		return true;
	}

	vector<bool> get_answer(){
		return answer;
	}
};
