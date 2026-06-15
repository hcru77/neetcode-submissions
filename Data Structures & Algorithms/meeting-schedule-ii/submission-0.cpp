/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        vector<int> start, end;

        for (const auto& i : intervals) {
            start.push_back(i.start);
            end.push_back(i.end);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        

        int count(0), res(0);
        int s(0), e(0);// We need to keep track of current start s, current end e
        while (s < intervals.size()){
            if (start[s] < end[e]) {
                count++;
                s++;
            } 
            else{
                count--;
                e++;
            }
            res = max(count, res);
        }
        return res;


    }
};
