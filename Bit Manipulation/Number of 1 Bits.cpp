class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        while(n != 0){
            
            //Drops the lowest set bit
            n &= n-1;
            ++ res;
        }
        return res;
        
        /*int count = 0;
        while(n != 0){
            
            //Checking last bit
            if(n & 1){
                count++;
            }
            n = n >> 1;
        }
        return count;*/
        
        /*int count = 0;
        while(n != 0){
            int d = n % 2;
            if(d == 1) count++;
            n = n / 2;
        }
        return count;*/
    }
};
