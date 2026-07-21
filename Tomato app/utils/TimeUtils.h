#ifndef TIME_UTILS_H
#define TIME_UTILS_H

#include<iostream>
#include <ctime>
#include<bits/stdc++.h>

using namespace std;

class TimeUtils {
public:
    static string getCurrentTime()
    {
        time_t now = time(0);
        char* dt = ctime(&now);
        string currentTime(dt);
        if(!currentTime.empty() && currentTime.back() == '\n') {
            currentTime.pop_back(); // Remove the trailing newline character
        }
        return currentTime;
    }
};

#endif //TIME_UTILS_H