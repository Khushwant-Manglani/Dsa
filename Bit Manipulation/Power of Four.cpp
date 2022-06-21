class Solution {
public:
    bool isPowerOfFour(int n) {    
        //(n & 0x55555555) gives the 1 is located at odd posn in n
        return (n > 0 && (n & n-1) == 0 && (n & 0x55555555) == n);
        
        /*int fac = 0b01010101010101010101010101010101;
        if(n > 0 && (n & n-1) == 0 && (fac & n) > 0)
            return true;
        return false;*/
        
        /*for(int i=0 ; i<=30 ; i+=2){
            if((1 << i) == n) return true;
        }
        return false;*/
        
        
        /*while(n > 0 && n % 4 == 0) n /= 4;
        return n == 1;*/
        
        /*int ans = 1;
        for(int i=0 ; i<16 ; i++){
            if(ans == n) return true;
            if(ans < INT_MAX/4)
            ans *= 4;
        }
        return false;*/
        
        //return (n > 0 && (n & n-1) == 0 && (n - 1) % 3 == 0);
    }
};
