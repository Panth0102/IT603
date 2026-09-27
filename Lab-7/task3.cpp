#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cctype>
using namespace std;

class Interval {
public:
    int start, end;

    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}

    bool operator<(const Interval& other) const {
        return this->start < other.start;
    }

    bool operator==(const Interval& other) const {
        return this->start == other.start && this->end == other.end;
    }

    Interval& operator=(const Interval& other) {
        if (this != &other) {
            this->start = other.start;
            this->end = other.end;
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Interval& iv) {
        os << "[" << iv.start << "," << iv.end << "]";
        return os;
    }
};

vector<Interval> mergeIntervals(vector<Interval>& intervals) {
    vector<Interval> result;
    if (intervals.empty()) return result;

    sort(intervals.begin(), intervals.end());

    Interval current = intervals[0];

    for (size_t i = 1; i < intervals.size(); i++) {
        if (intervals[i].start <= current.end) {
            current.end = max(current.end, intervals[i].end);
        } else {
            result.push_back(current);
            current = intervals[i];
        }
    }
    result.push_back(current);

    return result;
}

int main() {
    stringstream buffer;
    buffer << cin.rdbuf();
    string text = buffer.str();

    vector<int> nums;
    int i = 0, len = text.size();
    while (i < len) {
        if (isdigit((unsigned char)text[i]) || (text[i] == '-' && i + 1 < len && isdigit((unsigned char)text[i+1]))) {
            int j = i;
            bool neg = false;
            if (text[j] == '-') { neg = true; j++; }
            int val = 0;
            while (j < len && isdigit((unsigned char)text[j])) {
                val = val * 10 + (text[j] - '0');
                j++;
            }
            nums.push_back(neg ? -val : val);
            i = j;
        } else {
            i++;
        }
    }

    vector<Interval> intervals;
    for (size_t k = 0; k + 1 < nums.size(); k += 2) {
        intervals.push_back(Interval(nums[k], nums[k + 1]));
    }

    vector<Interval> merged = mergeIntervals(intervals);

    cout << "[";
    for (size_t k = 0; k < merged.size(); k++) {
        cout << merged[k];
        if (k != merged.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    return 0;
}