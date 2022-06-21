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
        
        /*int Co = 0;
        for(int i=0 ; i<32 ; ++i){
            if(((1 << i) & n) != 0)
                Co++;
        }
        return Co;*/
        
        
        /*int mask = 0,Co = 0;
        for(int i=0 ; i<32 ; i++){
            mask |= 1;
            mask &= n;
            if(mask == 1) Co++;
            n >>= 1;
        }
        return Co;*/
    }
};
