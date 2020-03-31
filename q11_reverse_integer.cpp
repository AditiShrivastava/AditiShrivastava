class Solution {
public:
    
    bool would_reversed_integer_overflow_if_proceeded_further(int reversed_integer, int x){
        if((reversed_integer > (INT_MAX / 10)) ||
          ((reversed_integer == (INT_MAX / 10)) && (reversed_integer % 10 >= INT_MAX % 10)) ||
          (reversed_integer < (INT_MIN / 10)) || 
          ((reversed_integer == (INT_MIN / 10)) && (reversed_integer % 10 <= INT_MIN % 10)))
                return 1;
        return 0;
    }
    int reverse(int x) {
        int reversed_integer = 0;
        while(x != 0){
            if(would_reversed_integer_overflow_if_proceeded_further(reversed_integer, x))
                return 0;
            reversed_integer = reversed_integer * 10 + x % 10;
            x /= 10;
        }
        return reversed_integer;
    }
};
