#include<bits/stdc++.h>
using namespace std;

int and_op(vector<int> x){
    int ans = 1;
    for(auto i:x){
        ans &= i;
    }
    return ans;
}
int or_op(vector<int> x){
    int ans = 0;
    for(auto i: x){
        ans |= i;
    }
    return ans;
}
int not_op(int x){
    int ans = ~x;
    return ans;
}
void dfs(int node, vector<int> &v, vector<vector<int>> &adj, vector<bool> &visited, vector<char> &funcs){
    if(funcs[node] == 'i')
        return;
    if(visited[node])
        return;
    visited[node] = true;
    vector<int> inputs;
    for(auto i: adj[node]){
        dfs(i, v, adj, visited, funcs);
        inputs.push_back(v[i]);
    }
    switch(funcs[node]){
    case 'o':
        v[node] = or_op(inputs);
        break;
    case 'a':
        v[node] = and_op(inputs);
        break;
    case 'n':
        v[node] = not_op(inputs[0]);
        break;
    default:
        cout<<"Incorrect character entered"<<endl;
    }
    return;
}

int main()
{
    int n, m;
    cin>>n>>m;
    vector<int> v(n+m);
    vector<char> funcs(n+m);
    for(int i=0; i<m; i++){
        cin>>v[i];
        if((v[i] > 1) || (v[i]<0)){
            cout<<"Gaand maraiye Viru ji";
            return 0;
        }
        funcs[i] = 'i';
    }
    vector<vector<int>> adj(n+m,vector<int>());
    for(int i=0; i<m; i++){
        char ch;
        cin>>ch;
        int temp_n;
        cin>>temp_n;
        int temp;
        cin>>temp;
        for(int j=0; j<temp_n; j++){
            int x;
            cin>>x;
            adj[temp].push_back(x);
        }
        funcs[temp] = ch;
    }
    vector<bool> visited(m+n, false);
    for(int i=n+m-1; i>=0; i--){
        if(!visited[i])
            dfs(i, v, adj, visited, funcs);
    }
    int num_out;
    cin>>num_out;
    vector<int> outputs(num_out);
    for(int i=0; i<num_out; i++){
        cin>>outputs[i];
    }
    for(int i=0; i<num_out; i++){
        cout<<outputs[i];
    }
    return 0;
}