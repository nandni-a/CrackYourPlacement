class Solution {
  public:
  
      string findOrder(vector<string> &words) {
        // code here
        vector<vector<int>> graph(26);
        vector<int> present(26,0);
        vector<int> ind(26,0);
        
        for(int i = 0 ; i < words.size() ; i++){
            string temp = words[i];
            for(int j = 0 ; j < temp.size() ; j++){
                present[temp[j]-'a'] = 1;
            }
        }
        
        int n = words.size();
        for(int i = 1 ; i < n ; i++){
            string first = words[i-1];
            string second = words[i];
            
            int len = min(first.size(),second.size());
            int j = 0;
            while(j < len && first[j]==second[j]){
                j++;
            }
            if(j < len){
                
                graph[first[j] - 'a'].push_back(second[j] - 'a');
                ind[second[j] - 'a']++;
            }
            else if(first.size() > second.size()){ 
                return "";
            }
        }
        
        queue<int> q;
        for(int i = 0 ; i < 26 ; i++){
            if(ind[i] == 0 && present[i] == 1){
                q.push(i);
            }
        }
        
        string result;
        while (!q.empty()) {
        int u = q.front(); q.pop();
        result += (char)(u + 'a');

        for (int v : graph[u]) {
            ind[v]--;
            if (ind[v] == 0) {
                q.push(v);
            }
        }
    }

        for(int i = 0 ; i < 26 ; i++){
            if(present[i] == 1 && ind[i]!=0){
                return "";
            }
        }
        return result;
    }
};