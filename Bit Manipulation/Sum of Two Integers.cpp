class Solution {
public:
    int getSum(int a, int b) {
        while(b != 0){
            int tmp = (unsigned int)(a & b) << 1;
            a = a ^ b;
            b = tmp;
        }
        return a;
        
        //return b == 0 ? a : getSum(a ^ b , (unsigned int)(a & b) << 1);  
    }
};
