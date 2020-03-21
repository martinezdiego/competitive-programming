/*
Estructura de datos para modelar una colección de conjuntos disyuntos.
Permite determinar de manera eficiente a que conjunto pertenece un elemento, si dos elementos se encuentran en un mismo conjunto y unir dos conjuntos en un uno.
*/

struct DSU
{
    vector<int> parent;
    vector<int> size;
    int N;

    DSU(int n) : N(n), parent(vector<int>(n)), size(vector<int>(n, 1)) 
    {
        for (int i = 0; i < N; i++)
            parent[i] = i;
    }

    int find(int u)
    {
        if (parent[u] == u)
            return u;
        
        return find(parent[u]);
    }

    bool same(int u, int v)
    {
        return find(u) == find(v);
    }

    void unite(int u, int v)
    {   
        u = find(u);
        v = find(v);

        if (u == v)
            return;

       if (size[u] > size[v])
            swap(u, v);
        
        parent[u] = v;
        size[v] += size[u];
        N--;
    }

    int count(int u)
    {
        return size[find(u)];
    }
};

