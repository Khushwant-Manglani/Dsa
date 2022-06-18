class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unsigned int single=0;
        int res1=0,res2=0;
        for(int x : nums) single ^= x;
        single &= ~(single - 1);  //or we can use single &= -single;
        for(int x : nums){
            if(x & single) res1 ^= x;
            else res2 ^= x;
        }
        return {res1,res2};
        
        /*int res = 0,res1=0,res2=0;
        for(auto x : nums) res ^= x;
        int i=0;
        while((res & (1 << i)) != (1 << i)) i++;
        for(auto x : nums){
            if((x & (1 << i)) != 0) res1 ^= x;
            else res2 ^= x;
        }
        return {res1,res2};*/
    }
};
