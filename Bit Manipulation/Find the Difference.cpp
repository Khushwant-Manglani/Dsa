class Solution {
public:
    char findTheDifference(string s, string t) {
        for(int i=0; i < s.size() ;i++){
            t[i+1] += t[i] - s[i]; //we'll put the diff of t[i] and s[i] in t[i+1]
        }
        return t[t.size() - 1]; // So at last diff will com in last element it is ans
        
        
        /*int res = t[0];
        for(int i=0 ; i < s.length() ; i++){
            res ^= s[i] ^ t[i+1];
        }
        return res;*/
        
        
        /*unordered_map<int,int> freq;
        for(auto x : s) freq[x]++; 
        for(auto a : t){ 
            if(freq[a] > 0){
                freq[a]--; 
            }    
            else return a;        
        }        
        return '0';*/
    }
};
