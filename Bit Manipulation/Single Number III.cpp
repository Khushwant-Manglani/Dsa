class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        
        unsigned int single=0; 
	    //If we take int variable then runtime error occur becoz of negation of -2147483648 cannot be int so therefore we take variable as unsigned int 
	
	    int res1=0,res2=0;  //Taking two variable to take the result of both half after xor the elements of both half
	
	    for(int x : nums) single ^= x; //Taking XOR of all the elements of nums
	
	    single &= ~(single - 1);  //or we can use single &= -single; also 
	    //this statement is to find first set bit from right most side 
	
        for(int x : nums){
            if(x & single) res1 ^= x; //This is for the first half of elements with not set bit 
            else res2 ^= x; //This is for the second half of elements with set bit
        }

        return {res1,res2}; //This is our final result
        
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
