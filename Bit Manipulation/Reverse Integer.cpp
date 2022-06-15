class Solution {
public:
    int reverse(int x) {
        int res = 0;
        while(x != 0){
            int d = x % 10;
            if(res > INT_MAX/10 || res < INT_MIN/10) return 0;
            res = (res*10) + d;
            x /= 10;
        }
        return res;
        
        /*if(x<-pow(2,31) || x>pow(2,31)-1) return 0;
        bool isNegetive = false;
        if(x < 0)  isNegetive = true;
        x = abs(x);
        long int res = 0;
        while(x > 0){
            int d = x % 10;
            res = res*10 + d;
            if(res < -pow(2,31) || res > pow(2,31) - 1) return 0;
            x = x / 10;
        }
        if(isNegetive){
            res = -res;
            return (int)res;
        }
        return (int)res;*/
        
        
        
        /*if(x<-pow(2,31) || x>pow(2,31)-1) return 0; 
            return 0;
        long int rev=0;
        if(x>0)
        {
            while(x>0)
            {
                rev=rev*10+(x%10);
                if(rev<-pow(2,31) || rev>pow(2,31)-1) return 0;
                x=x/10;
            }
        }
        else if(x<0)
        {
            x = (-1)*x; 
            while(x>0)
            {
                rev=rev*10+(x%10);
                if(rev<-pow(2,31) || rev>pow(2,31)-1) return 0;
                x=x/10;
            }
            rev = (-1)*rev;
        }
        return (int)rev;*/
    }
};
