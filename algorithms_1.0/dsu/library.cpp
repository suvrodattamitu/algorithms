class DSU
{
    public int[] dsu;

    public DSU(int N)
    {
        dsu = new int[N+1];
        for(int i=0; i <= N; i++)
        {
            dsu[i] = i;
        }
    }
    //with path compression, no find by rank
    public int find(int x)
    {
        return dsu[x] == x ? x : (dsu[x] = find(dsu[x]));
    }
    public void merge(int x, int y)
    {
        int fx = find(x);
        int fy = find(y);
        if(fx == fy)
            return;
        dsu[fx] = fy;
    }
}

struct dsu {
    int n;
    vector <int> root, sz;
    int comp;
  
    dsu(int n) {
      root.resize(n);
      sz.resize(n, 1);
      for (int i = 1; i <= n; ++i) root[i] = i;
      comp = n;
    }
    
    int get_root(int u) {
      return (u == root[u]? u: (root[u] = get_root(root[u])));
    }
    
    bool connected(int u, int v) {
      if (get_root(u) == get_root(v))
        return true;
      return false;
    }
    
    void merge(int u, int v) {
      if (connected(u, v))
        return ;
      u = get_root(u);
      v = get_root(v);
      comp--;
      if (sz[v] > sz[u])
        swap(u, v);
      root[v] = u;
      sz[u] += sz[v];
    }
    
    int get_size(int i) {
        return sz[get_root(i)];
    }
    
    int count() {
      return comp;
    }
};