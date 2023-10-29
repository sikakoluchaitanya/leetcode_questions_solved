class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T = (minutesToTest/minutesToDie) + 1;
        int poorpigs = 0;

        while(pow(T, poorpigs) < buckets) {
            poorpigs++;
        }

        return poorpigs; 
    }
};