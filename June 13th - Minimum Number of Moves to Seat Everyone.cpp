// brute force 

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        int sum = 0;
        for(int i = 0; i < seats.size(); i++) {
            sum += abs(students[i] - seats[i]);
        }
        return sum;
    }
};

//optimal - counting sort

class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        vector<int> seatcnt(101);
        vector<int> studcnt(101);
        
        for(auto it : seats) seatcnt[it]++;
        for(auto it : students) studcnt[it]++;

        int seatidx = 0, studidx = 0, moves = 0;

        while(seatidx <= 100, studidx <= 100) {
            while(seatidx <= 100 && seatcnt[seatidx] == 0) seatidx++;
            while(studidx <= 100 && studcnt[studidx] == 0) studidx++;

            if(seatidx <= 100 && studidx<=100) {
                int cnt = min(studcnt[studidx], seatcnt[seatidx]);
                moves += cnt * abs(seatidx - studidx);
                seatcnt[seatidx] -= cnt;
                studcnt[studidx] -= cnt;
            }
        }
        return moves;
    }
};
