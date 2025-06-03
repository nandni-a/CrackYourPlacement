// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector< pair< int , int > > adj[n] ;
       
       for( auto it : roads )
       {
           adj[it[0]].push_back({ it[1] , it[2] } ) ;
           adj[it[1]].push_back( { it[0] , it[2] } ) ;
       }
       
       
       vector< long long > dist( n , 1e18 ) ;             
       vector < int > ways( n , 0 ) ;
       dist[0] = 0 ;
       ways[0] = 1 ;
       
       priority_queue<  pair< long long , int > , 
       vector< pair< long long , int >> , 
       greater< pair< long long ,int >>> pq ;
       int mod = (int)(1e9 + 7) ;
       pq.push({0 , 0 }); // { dist , node } 
       
       while( !pq.empty() )
       {
           long long distance = pq.top().first ;
           int node = pq.top().second ;
           pq.pop() ;
           
           for( auto it : adj[node] )
           {
               int adjnode = it.first ;
               long long edjwt = it.second ;
               if( edjwt + distance < dist[adjnode] )
               {
                   dist[adjnode] = edjwt + distance ;
                   pq.push({ edjwt + distance , adjnode } ) ;
                   ways[adjnode] = ways[node] ;
               }
               
               else if( edjwt + distance == dist[adjnode] )
               {
                   ways[adjnode] = ( ways[node] + ways[adjnode] )%mod ;
               }
               
           }
           
           
       }
       
       return ways[n-1]%mod ;
        
    }
};