class Solution {
public:
    char findTheDifference(string s, string t) {
        for(int i=0; i < s.size() ;i++){
            t[i+1] += t[i] - s[i]; //we'll put the diff of t[i] and s[i] in t[i+1]
        }
        return t[t.size() - 1]; // So at last diff will com in last element it is ans
        
        
        
        /*int n = s.length();
        int m = t.length();
        int res = 0;
        for(int i=0,j=0 ; i<n || j<m ; i++,j++){
            if(i < n) res ^= s[i];
            if(j < m) res ^= t[i];
        }
        return res;*/
    }
};
