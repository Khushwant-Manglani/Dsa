class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        unsigned long int mask = 0;
        for(int i=0; i<=31 ;i++){
            if((n & 1) == 1){
                mask |= 1;
                mask <<= 1;
            }
            else{
                mask <<= 1;
            }
            n >>= 1;
        }
        return mask >> 1;
        
        /*if(n == 0) return 0;
        int result = 0;
        for(int i=0; i<32 ;i++){
            result <<= 1;
            if((n & 1) == 1) result++;
            n >>= 1;
        }
        return result;*/
    }
};
