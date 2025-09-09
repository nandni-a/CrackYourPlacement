class Solution {
  public:
    int wordLadderLength(string startWord, string targetWord,
                         vector<string>& wordList) {
        // Code here
        unordered_set<string>dict(wordList.begin(),wordList.end());
        if(dict.find(targetWord)==dict.end()) return 0;
        queue<pair<string,int>>q;
        q.push({startWord,1});
        while(!q.empty()){
            auto [word,step]=q.front();
            q.pop();
            if(word==targetWord) return step;
            for(int i=0;i<word.length();i++){
                string temp=word;
                for(char ch='a';ch<='z';ch++){
                    temp[i]=ch;
                    if(dict.find(temp)!=dict.end()){
                        q.push({temp,step+1});
                        dict.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};