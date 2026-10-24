
class Solution {
public:
    int toDay(string date) {
        int daysBeforeMonth[] = {
            0, 31, 59, 90, 120, 151,
            181, 212, 243, 273, 304, 334
        };

        int month = stoi(date.substr(0, 2));
        int day = stoi(date.substr(3, 2));

        return daysBeforeMonth[month - 1] + day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int startA = toDay(arriveAlice);
        int endA = toDay(leaveAlice);

        int startB = toDay(arriveBob);
        int endB = toDay(leaveBob);

        int start = max(startA, startB);
        int end = min(endA, endB);

        return max(0, end - start + 1);
    }
};
