class Solution {
public:
    double angleClock(int hour, int minutes) {
        float hA=(30*hour)+(0.5*minutes);
        if(hA==360)
            hA=0;
        
        float mA=6*minutes;
        if(mA==360)
            mA=0;
        
        float res = abs(hA-mA);
        
        
        if(res>180)
            res = 360 - res;
        
        return(res);
    }
};