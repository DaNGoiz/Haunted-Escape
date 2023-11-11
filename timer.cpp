#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

class SimpleTimer {
public:
    void start() {
        m_StartTime = steady_clock::now();
        m_bRunning = true;
    }

    void stop() {
        m_EndTime = steady_clock::now();
        m_bRunning = false;
    }

    double elapsedMilliseconds() {
        steady_clock::time_point endTime;

        if (m_bRunning) {
            endTime = steady_clock::now();
        } else {
            endTime = m_EndTime;
        }

        return duration_cast<milliseconds>(endTime - m_StartTime).count();
    }

    string elapsedString() {
        auto ms = elapsedMilliseconds();
        int hours = ms / 3600000;
        ms -= hours * 3600000;
        int minutes = ms / 60000;
        ms -= minutes * 60000;
        int seconds = ms / 1000;

        string timeStr;
        if (hours > 0) {
            timeStr += to_string(hours) + " hour ";
        }
        if (minutes > 0 || hours > 0) { // include minutes if hours are present
            timeStr += to_string(minutes) + " min ";
        }
        timeStr += to_string(seconds) + " sec";

        return timeStr;
    }

private:
    steady_clock::time_point m_StartTime;
    steady_clock::time_point m_EndTime;
    bool m_bRunning = false;
};

SimpleTimer timer;

void Timer(bool start) {
    if (start) {
        timer.start();
    } else {
        timer.stop();
    }
}

void ResetTimer() {
    timer = SimpleTimer();
}

string GetTime() {
    return timer.elapsedString();
}
