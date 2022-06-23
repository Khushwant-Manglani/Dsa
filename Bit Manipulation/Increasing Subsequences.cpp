class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> res;
        //vector<int> result;
        int n = nums.size();
        int pow = (1 << n);
        for(int i=0 ; i < pow ; ++i){
            vector<int> result;
            for(int j=0 ; j < n ; ++j){
                if(i >> j & 1){
                    if(result.size() == 0)
                        result.push_back(nums[j]);
                    else {
                        if(result.back() <= nums[j]) 
                            result.push_back(nums[j]);
                        else result.pop_back();
                    }
                }
            }
            if(result.size() >= 2) 
                res.insert(result);
            //if(find(Subseq.begin(),Subseq.end(),result) == Subseq.end())
        }
        vector<vector<int>> Subseq(res.begin(),res.end());
        return Subseq;
        
        //Others method pending like reccursion and backtracking
    }
};
