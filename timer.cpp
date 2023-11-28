#include <iostream>
#include <string>
#include <chrono>

using namespace std;
using namespace std::chrono;

class SimpleTimer {
public:
    // Constructor: Initializes a stopped timer with zero elapsed time
    SimpleTimer() : m_bRunning(false), m_ElapsedTime(milliseconds::zero()) {}

    // Starts the timer if it is not already running
    void start() {
        if (!m_bRunning) {
            m_StartTime = steady_clock::now() - m_ElapsedTime;
            m_bRunning = true;
        }
    }

    // Stops the timer if it is currently running and calculates elapsed time
    void stop() {
        if (m_bRunning) {
            m_EndTime = steady_clock::now();
            m_ElapsedTime = m_EndTime - m_StartTime;
            m_bRunning = false;
        }
    }

    // Resets the timer to a stopped state with zero elapsed time
    void reset() {
        m_bRunning = false;
        m_ElapsedTime = milliseconds::zero();
    }

    // Returns the elapsed time in milliseconds
    double elapsedMilliseconds() {
        if (m_bRunning) {
            return duration_cast<milliseconds>(steady_clock::now() - m_StartTime).count();
        } else {
            return duration_cast<milliseconds>(m_ElapsedTime).count();
        }
    }

    // Converts and returns the elapsed time as a formatted string
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
    // Time points and duration for managing the timer
    steady_clock::time_point m_StartTime, m_EndTime;
    steady_clock::duration m_ElapsedTime;
    bool m_bRunning; // Indicates whether the timer is currently running
};

// Global timer object
SimpleTimer timer;

// Starts or stops the timer based on the input argument
void Timer(bool start) {
    if (start) {
        timer.start();
    } else {
        timer.stop();
    }
}

// Resets the global timer
void ResetTimer() {
    timer.reset();
}

// Returns the elapsed time as a string from the global timer
string GetTime() {
    return timer.elapsedString();
}
