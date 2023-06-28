class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<pair<int ,double>>adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1],succProb[i]});
            adj[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        
        priority_queue<pair<double,int>> pq;
        
        pq.push({1.0,start});
        
        vector<double> dis(n,INT_MIN);
        
        dis[start]=1;
        
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            double d = it.first;
            int node = it.second;
            
            for(auto it : adj[node]){
                double wt = it.second;
                int x = it.first;
                
                if(dis[x] < d*wt){
                    dis[x]=d*wt;
                    pq.push({dis[x],x});
                }
            }
        }
        if(dis[end]==INT_MIN)return 0.00000;
         return dis[end];
    }
};

