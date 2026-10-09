class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector <int> visited(n,0);

        for (int i = 0 ; i < n; i++){
            if(visited[i] != 0)
            continue;
            queue<int> q;
            q.push(i);
            visited[i] = 1;

            while(!q.empty()){
                int node = q.front();
                q.pop();

                for(int neighbor : graph[node]){
                    if(visited[neighbor] == 0){
                        visited[neighbor] = -visited[node];
                        q.push(neighbor);
                    }
                    else if (visited[neighbor] == visited[node]){
                        return false;
                    }
                }
            }
        }
        return true;
    }
};