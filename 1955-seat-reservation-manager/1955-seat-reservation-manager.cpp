class SeatManager {
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int seat_marker;
    SeatManager(int n) {
        seat_marker = 1;
    }
    
    int reserve() {
        if(!pq.empty()) {
            int seat = pq.top();
            pq.pop(); //log(n)
            return seat;
        }
        
        int seat = seat_marker;
        seat_marker++;
        return seat;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
};