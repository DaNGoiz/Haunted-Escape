#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

class SimpleTimer {
public:
    SimpleTimer() : m_bRunning(false), m_ElapsedTime(milliseconds::zero()) {}

    void start() {
        if (!m_bRunning) {
            m_StartTime = steady_clock::now() - m_ElapsedTime;
            m_bRunning = true;
        }
    }

    void stop() {
        if (m_bRunning) {
            m_EndTime = steady_clock::now();
            m_ElapsedTime = m_EndTime - m_StartTime;
            m_bRunning = false;
        }
    }

    void reset() {
        m_bRunning = false;
        m_ElapsedTime = milliseconds::zero();
    }

    double elapsedMilliseconds() {
        if (m_bRunning) {
            return duration_cast<milliseconds>(steady_clock::now() - m_StartTime).count();
        } else {
            return duration_cast<milliseconds>(m_ElapsedTime).count();
        }
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
        if (minutes > 0 || hours > 0) {
            timeStr += to_string(minutes) + " min ";
        }
        timeStr += to_string(seconds) + " sec";

        return timeStr;
    }

private:
    steady_clock::time_point m_StartTime, m_EndTime;
    steady_clock::duration m_ElapsedTime;
    bool m_bRunning;
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
    timer.reset();
}

string GetTime() {
    return timer.elapsedString();
}
