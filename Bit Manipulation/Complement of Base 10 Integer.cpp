class Solution {
public:
    int bitwiseComplement(int n){
        int X = 1;
        // n + bitwiseComplement(n) == X -> bitwiseComplement(n) = X - n;
        while(n > X) X = (X * 2) + 1;
        return X - n;
        
        
        /*int X = 1;
        // n + bitwiseComplement(n) == X -> bitwiseComplement(n) = X - n;
        while(n > X) X = (X << 1) + 1;
        return X ^ n;*/
    
        
        //edge case
        /*if(n == 0) return 1;
        int m = n,mask = 0;
        while(m != 0){
            m = m >> 1;
            mask = (mask << 1) | 1;
        }
        return (~n) & mask;*/
            
        
        /*if(n == 0) return 1;
        int i = 0,res = 0;
        while(n != 0){
            int d = n % 2;
            if(d == 1) d = 0;
            else if(d == 0) d = 1;
            res += pow(2,i)*d;
            i++;
            n /= 2;
        }
        return res;*/
    }
};
