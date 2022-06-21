class Solution {
public:
    bool isPowerOfTwo(int n) {
        /*if(n <= 0) return false;
        int res = log2(n);
        if(pow(2,res) == n)
            return true;
        return false;*/
        
        return (n > 0 && (n & n-1) == 0);
        
        //naive soln
        /*int ans = 1;
        for(int i=0; i<=30 ; i++){
            if(ans == n){
                return true;
            }
            if(ans < INT_MAX/2)
            ans *= 2;
            
        }
        return false;*/
        
        /*while(n > 0 && n % 2 == 0) n /= 2;
        if(n == 1) return true;
        return false;*/
    }
};
