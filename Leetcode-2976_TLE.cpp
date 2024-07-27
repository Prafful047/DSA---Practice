class Solution {
public:

    long long dikstra(unordered_map<char, vector<pair<char,int>> >& adj , char source , char target ){

        priority_queue<pair<int,char>, vector<pair<int,char>> , greater<pair<int,char>> >pq;
        vector<long long>result(26 , INT_MAX);

        result[source-'a'] = 0;

        pq.push({0,source});

        while(!pq.empty()){
            int cost = pq.top().first;
            char node = pq.top().second;
            pq.pop();

            for(auto &vec : adj[node]){
                char adjNode = vec.first;
                int wt = vec.second;

                if(cost+wt < result[adjNode - 'a']){
                    result[adjNode - 'a'] = cost + wt;
                    pq.push({cost+wt , adjNode});
                }
            }
        }

        return result[target-'a'];
    }

    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        unordered_map<char, vector<pair<char,int>> > adj;

        int n = original.size();

        for(int i=0 ; i<n ; i++){
            adj[original[i]].push_back(make_pair(changed[i],cost[i]));
        }

        int V = adj.size();

        long long minCost = 0;

        for(int i=0 ; i<source.length() ; i++){
            if(source[i] != target[i]){
                long long subMinCost = dikstra( adj , source[i] , target[i]);
                if(subMinCost != INT_MAX){
                    minCost += subMinCost;
                }else{
                    return -1;
                }
            }
        }

        return minCost;
    }
};