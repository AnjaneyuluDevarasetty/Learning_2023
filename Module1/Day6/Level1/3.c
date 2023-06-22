#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

struct Time calculateDifference(struct Time t1, struct Time t2) {
    struct Time diff;

    // Convert everything to seconds
    int time1Seconds = t1.hours * 3600 + t1.minutes * 60 + t1.seconds;
    int time2Seconds = t2.hours * 3600 + t2.minutes * 60 + t2.seconds;

    // Calculate the absolute difference in seconds
    int differenceSeconds = time2Seconds - time1Seconds;
    if (differenceSeconds < 0) {
        differenceSeconds = -differenceSeconds;
    }

    // Convert back to hours, minutes, and seconds
    diff.hours = differenceSeconds / 3600;
    diff.minutes = (differenceSeconds % 3600) / 60;
    diff.seconds = (differenceSeconds % 3600) % 60;

    return diff;
}

int main() {
    struct Time time1, time2, difference;

    printf("Enter the first time (hours minutes seconds): ");
    scanf("%d %d %d", &time1.hours, &time1.minutes, &time1.seconds);

    printf("Enter the second time (hours minutes seconds): ");
    scanf("%d %d %d", &time2.hours, &time2.minutes, &time2.seconds);

    difference = calculateDifference(time1, time2);

    printf("Difference: %d hours %d minutes %d seconds\n", difference.hours, difference.minutes, difference.seconds);

    return 0;
}
