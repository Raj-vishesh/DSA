class Solution {
public:

    vector<int> parent;

    int findParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findParent(parent[node]);
    }
        

    
    int makeConnected(int n, vector<vector<int>>& connections) {

       if(connections.size() < n-1) return -1; 
       parent.resize(n);
       int components = n;

       for(int i = 0 ; i < n ; i++){
            parent[i] = i;
       }


       

       for(auto it: connections){
            int u = findParent(it[0]);
            int v = findParent(it[1]);

            if(u != v){
                parent[u] = v;
                components--;
            }

       }

       return components -1;

    }
};