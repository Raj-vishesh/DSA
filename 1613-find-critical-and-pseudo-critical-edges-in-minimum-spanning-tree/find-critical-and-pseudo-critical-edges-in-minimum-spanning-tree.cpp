class DSU{
    vector<int> parent;
    public:
    DSU(int n){
        parent.resize(n+1);
        for(int i = 0 ; i < n ; i++){
            parent[i] = i;
        }
    }

    int findParent(int node){
        if(parent[node] == node){
            return node;
        }

        return parent[node] = findParent(parent[node]);
    }

    bool unionByRank(int u , int v){
        int ult_u  = findParent(u);
        int ult_v = findParent(v);

        if(ult_u != ult_v) {
            parent[ult_u] = ult_v;
            return true;
        }
        return false; 
    }
};

class Solution {
public:

    int getMST( int n, vector<vector<int>>& edges , int skipidx =-1,int forceidx =-1){

        DSU dsu(n);
        int weight = 0;
        int cnt = 0;
        if(forceidx != -1){
            weight += edges[forceidx][0];
            dsu.unionByRank(edges[forceidx][1] , edges[forceidx][2]);
            cnt++;
        }

        for(int i = 0 ; i < edges.size() ; i++){
            if(i == skipidx) continue;

            if(dsu.unionByRank(edges[i][1] , edges[i][2])){
                weight+= edges[i][0];
                cnt++;
            }
        }

        if(cnt == n-1) return weight;
        else return 1e9;

    }




    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        int E = edges.size();
        //Format: {weight, u, v, original_index}

        for(int i = 0 ; i < E ; i++ ){
            int u = edges[i][0], v = edges[i][1], w = edges[i][2];
            edges[i] = {w, u, v, i}; 

        }

        sort(edges.begin() , edges.end());

        int minwt = getMST(n , edges);

        vector<int> critical , pseudo;

        for(int i = 0 ; i < E; i++){
            if(getMST(n , edges , i , -1) > minwt){
                critical.push_back(edges[i][3]);

            }
            else if(getMST(n , edges , -1 , i) == minwt){
                pseudo.push_back(edges[i][3]);
            }
        }


        return {critical , pseudo};


        
    }
};