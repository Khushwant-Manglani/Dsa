class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        //using hashset
        int mask = 0, max = 0;
        set<int> se;
        for(int i=31 ; i>=0 ; i--){
            mask |= (1 << i);
            for(int i=0 ; i < nums.size() ; ++i){
                se.insert(nums[i] & mask);    
            }
            int MAXI = max | (1 << i);
            for(int prefix : se){
                //a^b = c then c ^ a = b 
                //prefix^b = MAXI -> MAXI^prefix = b
                if(se.count(MAXI ^ prefix)){
                    max = MAXI;
                    break;
                }
            }
            se.clear();
        }
        return max;
        
        
        //Trie method pending
        
        
        
        
        
        //Naive solution - TLE
        /*int maxor = 0,res = 0;
        for(int i=0 ; i < nums.size() ; i++){
            for(int j=i+1 ; j < nums.size() ; j++){
                maxor = nums[i] ^ nums[j];
                res = max(maxor,res);
            }
        }   
        return res;*/
    }
};
