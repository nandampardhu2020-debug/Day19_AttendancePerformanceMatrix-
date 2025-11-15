int main() {
#include <stdio.h>

    int attendance[5][5], marks[5][5];
    char names[5][20];
    int totalPresent[5], totalMarks[5];
    float avg[5];
    char grade[5];
    int i, j, choice;

    // INPUT NAMES
    printf("Enter names of 5 students:\n");
    for(i = 0; i < 5; i++) scanf("%s", names[i]);

    // INPUT ATTENDANCE
    printf("\nEnter Attendance (1=Present, 0=Absent):\n");
    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            scanf("%d", &attendance[i][j]);

    // INPUT MARKS
    printf("\nEnter Marks (0-100):\n");
    for(i = 0; i < 5; i++)
        for(j = 0; j < 5; j++)
            scanf("%d", &marks[i][j]);

    // PROCESS ATTENDANCE + MARKS + GRADES
    int highAtt = 0, lowAtt = 0, top = 0, low = 0;

    for(i = 0; i < 5; i++) {

        totalPresent[i] = 0;
        totalMarks[i] = 0;

        for(j = 0; j < 5; j++) {
            totalPresent[i] += attendance[i][j];
            totalMarks[i] += marks[i][j];
        }

        avg[i] = totalMarks[i] / 5.0;

        // Grade
        if(avg[i] >= 90) grade[i] = 'A';
        else if(avg[i] >= 80) grade[i] = 'B';
        else if(avg[i] >= 70) grade[i] = 'C';
        else if(avg[i] >= 60) grade[i] = 'D';
        else if(avg[i] >= 50) grade[i] = 'E';
        else grade[i] = 'F';

        if(totalPresent[i] > totalPresent[highAtt]) highAtt = i;
        if(totalPresent[i] < totalPresent[lowAtt]) lowAtt = i;
        if(totalMarks[i] > totalMarks[top]) top = i;
        if(totalMarks[i] < totalMarks[low]) low = i;
    }

    // MENU SYSTEM
    do {
        printf("\n========= MENU =========\n");
        printf("1. Attendance Matrix\n");
        printf("2. Marks Matrix\n");
        printf("3. Attendance Report\n");
        printf("4. Performance Report\n");
        printf("5. Grade Report\n");
        printf("6. Exit\n");
        printf("========================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("\nAttendance Matrix:\n");
                for(i = 0; i < 5; i++) {
                    printf("%s: ", names[i]);
                    for(j = 0; j < 5; j++)
                        printf("%d ", attendance[i][j]);
                    printf("\n");
                }
                break;

            case 2:
                printf("\nMarks Matrix:\n");
                for(i = 0; i < 5; i++) {
                    printf("%s: ", names[i]);
                    for(j = 0; j < 5; j++)
                        printf("%d ", marks[i][j]);
                    printf("\n");
                }
                break;

            case 3:
                printf("\nAttendance Report:\n");
                for(i = 0; i < 5; i++)
                    printf("%s - Present: %d  Absent: %d\n",
                           names[i], totalPresent[i], 5 - totalPresent[i]);

                printf("\nHighest Attendance: %s\n", names[highAtt]);
                printf("Lowest Attendance : %s\n", names[lowAtt]);
                break;

            case 4:
                printf("\nPerformance Report:\n");
                for(i = 0; i < 5; i++)
                    printf("%s - Total: %d  Avg: %.2f\n",
                           names[i], totalMarks[i], avg[i]);

                printf("\nTopper: %s\n", names[top]);
                printf("Lowest Performer: %s\n", names[low]);
                break;

            case 5:
                printf("\nGrade Report:\n");
                for(i = 0; i < 5; i++)
                    printf("%s - Grade: %c\n", names[i], grade[i]);
                break;

            case 6:
                printf("Exiting program...\n");
        }

    } while(choice != 6);

    return 0;
}
