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
    static bool comp(const Interval& a,const Interval& b){
        if(a.start < b.start) return true;
        if(a.start == b.start) return a.end < b.end;
        return false;
        //can be written as return a.start<b.start as well (tiebreaker not needed here)
    }
    bool canAttendMeetings(vector<Interval>& intervals) {
        if(intervals.size()<=1) return true; //imp else DEADLYSIGNAL error
        sort(intervals.begin(),intervals.end(),comp);
        for(int i=0;i<intervals.size()-1;i++){
            if((intervals[i+1]).start < (intervals[i]).end)
                return false;
        }
        return true;
    }
};
