struct Dsu{
    parent: Vec<usize>,
    sz: Vec<usize>,
}

impl Dsu{
    fn new(n: usize) -> Self{
        let mut parent = Vec::with_capacity(n);
        for i in 0..n{
            parent.push(i);
        }
        let sz = vec![1; n];
        Dsu { parent, sz }
    }

    fn root(&mut self, x: usize) -> usize{
        if self.parent[x] == x{
            x
        }
        else{
            let r = self.root(self.parent[x]);
            self.parent[x] = r;
            r
        }
    }

    fn merge(&mut self, x: usize, y: usize){
        let mut x = self.root(x);
        let mut y = self.root(y);
        if x == y{
            return;
        }
        if self.sz[x] < self.sz[y]{
            std::mem::swap(&mut x, &mut y);
        }
        self.parent[y] = x;
        self.sz[x] += self.sz[y];
    }

    fn same(&mut self, x: usize, y: usize) -> bool{
        self.root(x) == self.root(y)
    }

    fn size(&mut self, x: usize) -> usize{
        let r = self.root(x);
        self.sz[r]
    }
}