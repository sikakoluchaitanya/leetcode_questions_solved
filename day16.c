/*
Given n orders, each order consist in pickup and delivery services. 

Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i). 

Since the answer may be too large, return it modulo 10^9 + 7.

 

Example 1:

Input: n = 1
Output: 1
Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.
Example 2:

Input: n = 2
Output: 6
Explanation: All possible orders: 
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
Example 3:

Input: n = 3
Output: 90*/

#define MOD 1000000007

int countOrders(int n) {
    long long int result = 1;
    
    for (int i = 2; i <= n; i++) {
        // Calculate the number of ways to insert a new pickup and delivery into the existing sequence.
        // There are 2 * i - 1 positions to insert (2 for pickup and delivery at each step).
        // So, there are (2 * i - 1) * (2 * i) / 2 = i * (2 * i - 1) ways to insert.
        result = (result * i * (2 * i - 1)) % MOD;
    }
    
    return (int)result;
}
