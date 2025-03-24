#include <bits/stdc++.h>
using namespace std;

vector<int> adj[100000+5];

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    for(int i = 0; i < M; i++){
        int u, v;
        cin >> u >> v;
        --u; 
        --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> visited(N, 0);
    long long sumUsed = 0;
    vector<int> oddPathSizes;

    auto bfs_component = [&](int start){
        queue<int>q;
        q.push(start);
        visited[start] = 1;

        vector<int> nodesInComp;
        long long edgesCount = 0; 

        while(!q.empty()){
            int u = q.front(); 
            q.pop();
            nodesInComp.push_back(u);
            for(int w : adj[u]){
                edgesCount++; 
                if(visited[w] == 0){
                    visited[w] = 1;
                    q.push(w);
                }
            }
        }

        edgesCount /= 2;
        long long vCount = (long long)nodesInComp.size();

        if(edgesCount == vCount){
            if(vCount % 2 == 0){
                sumUsed += vCount;
            }
        }
        else if(edgesCount == vCount - 1){
            if(vCount % 2 == 0){
                sumUsed += vCount;
            } else {
                oddPathSizes.push_back((int)vCount);
                sumUsed += vCount;
            }
        }
    };

    for(int i=0; i<N; i++){
        if(visited[i] == 0){
            bfs_component(i);
        }
    }

    int countOdd = (int)oddPathSizes.size();
    if(countOdd % 2 == 1 && !oddPathSizes.empty()){
        sort(oddPathSizes.begin(), oddPathSizes.end());
        int smallest = oddPathSizes[0];
        sumUsed -= smallest;
    }

    long long finalUsed = sumUsed;
    long long answer = finalUsed / 2;

    cout << answer << "\n";

    return 0;
}
