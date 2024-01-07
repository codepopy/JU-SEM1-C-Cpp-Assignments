#include <iostream>
using namespace std;

class Time {
private:
    int hours, minutes, seconds;

public:
    Time() : hours(0), minutes(0), seconds(0) {}

    friend istream& operator>>(istream& input, Time& t);
    friend Time operator+(const Time& t1, const Time& t2);
    friend ostream& operator<<(ostream& output, const Time& t);
    friend bool operator==(const Time& t1, const Time& t2);
};

istream& operator>>(istream& input, Time& t) {
    cout << "Enter time (hours minutes seconds): ";
    input >> t.hours >> t.minutes >> t.seconds;
    return input;
}

Time operator+(const Time& t1, const Time& t2) {
    Time result;
    int totalSeconds = (t1.hours + t2.hours) * 3600 + (t1.minutes + t2.minutes) * 60 + t1.seconds + t2.seconds;
    result.hours = totalSeconds / 3600;
    totalSeconds %= 3600;
    result.minutes = totalSeconds / 60;
    result.seconds = totalSeconds % 60;
    return result;
}

ostream& operator<<(ostream& output, const Time& t) {
    output << t.hours << " hours " << t.minutes << " minutes " << t.seconds << " seconds";
    return output;
}

bool operator==(const Time& t1, const Time& t2) {
    return (t1.hours == t2.hours && t1.minutes == t2.minutes && t1.seconds == t2.seconds);
}

int main() {
    Time time1, time2, sum;

    cout << "Enter the first time:" << endl;
    cin >> time1;

    cout << "Enter the second time:" << endl;
    cin >> time2;

    sum = time1 + time2;

    cout << "\nSum of the times:" << endl;
    cout << sum << endl;

    if (time1 == time2) {
        cout << "The two times are equal." << endl;
    } else {
        cout << "The two times are not equal." << endl;
    }

    return 0;
}

