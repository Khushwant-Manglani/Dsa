class Solution {
public:
    string toHex(int num) {
        string Hex;
        if(num == 0) return "0";
        unsigned int nums=num;
        while(nums != 0){
            int d = nums % 16;
            
            if(d > 9) Hex += ('a'+(d%10));
            else Hex += to_string(d);
            
            nums /= 16;
        }
        reverse(Hex.begin(),Hex.end());
        return Hex;  
        
        
        /*string result;
        
        if(num == 0) return "0";
        int res = 0,j = 0;
        for(int i=0 ; i <= 32 ; i++){ 
            //After first four bit complete we check if(j % 4 == 0) is true then go to if condn push this res into string then go to next four bits and so on 
            
            if(j % 4 == 0 && j != 0){
                if(res > 9) result += ('a' + (res%10));
                else result += to_string(res); //move first added four bit to result then go to next 4 bits
                
                res = 0; //complete first four bits by (8 4 2 1) rule then go to second four bits by initialize res to 0 
                j=0; // initialize power to 0
                
                if(res == 0 && num == 0) break; //If num and res is 0 then number is ended so the result is our final result  
            }
            //(1 << j) -> it is pow(2,j) where j is the power
            res += (1 << j) * (num & 1); //Adding the bits one by one according to (8 4 2 1) rule in binary
            
            num >>= 1; //remove last bit on num 
            j++;
        }
        reverse(result.begin(),result.end()); //At last we reverse the string 
        return result; //Final result*/
    }
};
