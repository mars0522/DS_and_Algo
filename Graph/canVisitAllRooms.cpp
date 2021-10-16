class Solution {
public:

    void dfs(vector<vector<int>>& graph, int source, vector<int>& visited)
    {
        visited[source] = 1;

        for (auto v : graph[source])
        {
            if (visited[v] == 0)
                dfs(graph, v, visited);
        }
    }
    void add_edge(vector<vector<int>>& graph, int i, int j)
    {
        graph[i].push_back(j);
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int n = rooms.size();
        vector<vector<int>>graph(n);

        for (int i = 0; i < rooms.size(); i++)
        {
            for (auto n : rooms[i])
                add_edge(graph, i, n);

        }
        int count = 0;
        vector<int>visited(n);

        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0)
            {
                count++;
                dfs(graph, i, visited);
            }
        }

        if (count > 1)
            return false;
        else
            return true;



    }
};