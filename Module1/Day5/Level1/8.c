// Program compute total number of seconds.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int computeTotalSeconds(const char* timeString) {
    int hours, minutes, seconds;
    char* token;

    token = strtok((char*)timeString, ":");
    hours = atoi(token);

    token = strtok(NULL, ":");
    minutes = atoi(token);

    token = strtok(NULL, ":");
    seconds = atoi(token);

    int totalSeconds = hours * 3600 + minutes * 60 + seconds;
    return totalSeconds;
}

int main() {
    char timeString[] = "10:12:50";
    printf("Time: %s\n", timeString);
    
    int totalSeconds = computeTotalSeconds(timeString);
    printf("Total seconds: %d\n", totalSeconds);

    return 0;
}