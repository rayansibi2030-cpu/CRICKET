
/* Cricket Player Stats Tracker - Phase 1 (Fixed)
   1. Add player: name, runs scored, balls faced
   2. View all players with strike rate = (runs x 100) / balls
   3. Search player by name (Case-insensitive)
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 50

/* Helper function for case-insensitive string comparison */
int compare_case_insensitive(const char *s1, const char *s2) {
    while (*s1 && *s2) {
        if (tolower((unsigned char)*s1) != tolower((unsigned char)*s2)) {
            return 0;
        }
        s1++;
        s2++;
    }
    return *s1 == *s2;
}

int main()
{
    char name[MAX][30];     /* player names */
    int runs[MAX];          /* runs scored */
    int balls[MAX];         /* balls faced */
    int count = 0;          /* number of players added; S.No. = i + 1 */
    int choice = 0, i, found;
    char key[30];
    float sr;

    do {
        printf("\n===== CRICKET PLAYER STATS TRACKER =====\n");
        printf("1. Add Player\n");
        printf("2. View All Players\n");
        printf("3. Search Player by Name\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        if (scanf("%d", &choice) != 1) {
            /* Clear invalid input if user types letters */
            while (getchar() != '\n');
            printf("Invalid input! Please enter a number.\n");
            continue;
        }

        switch (choice) {
        case 1:
            if (count == MAX) {
                printf("Cannot add: storage full (%d players).\n", MAX);
                break;
            }

            printf("Enter player name: ");
            scanf(" %29[^\n]", name[count]);

            /* Validate non-negative runs */
            do {
                printf("Enter runs scored (>= 0): ");
                if (scanf("%d", &runs[count]) != 1 || runs[count] < 0) {
                    printf("Invalid input! Runs cannot be negative.\n");
                    while (getchar() != '\n'); /* clear buffer */
                    runs[count] = -1;
                }
            } while (runs[count] < 0);

            /* Validate non-negative balls */
            do {
                printf("Enter balls faced (>= 0): ");
                if (scanf("%d", &balls[count]) != 1 || balls[count] < 0) {
                    printf("Invalid input! Balls faced cannot be negative.\n");
                    while (getchar() != '\n'); /* clear buffer */
                    balls[count] = -1;
                }
            } while (balls[count] < 0);

            count++;
            printf("Player added successfully with S.No. %d!\n", count);
            break;

        case 2:
            if (count == 0) {
                printf("No players added yet.\n");
                break;
            }
            printf("\n%-6s %-25s %6s %6s %12s\n", "S.No.", "Name", "Runs", "Balls", "Strike Rate");
            printf("----------------------------------------------------------\n");
            for (i = 0; i < count; i++) {
                if (balls[i] > 0)
                    sr = (runs[i] * 100.0f) / balls[i];
                else
                    sr = 0.0f;
                printf("%-6d %-25s %6d %6d %12.2f\n", i + 1, name[i], runs[i], balls[i], sr);
            }
            break;

        case 3:
            if (count == 0) {
                printf("No players added yet.\n");
                break;
            }
            printf("Enter player name to search: ");
            scanf(" %29[^\n]", key);
            found = 0;

            for (i = 0; i < count; i++) {
                if (compare_case_insensitive(name[i], key)) {
                    if (balls[i] > 0)
                        sr = (runs[i] * 100.0f) / balls[i];
                    else
                        sr = 0.0f;

                    printf("\n--- Match Found ---\n");
                    printf("S.No.: %d\n", i + 1);
                    printf("Name: %s\n", name[i]);
                    printf("Runs: %d\n", runs[i]);
                    printf("Balls: %d\n", balls[i]);
                    printf("Strike Rate: %.2f\n", sr);
                    found = 1;
                }
            }
            if (!found)
                printf("No player found with name '%s'\n", key);
            break;

        case 4:
            printf("Exiting. Goodbye!\n");
            break;

        default:
            printf("Invalid choice. Enter 1 to 4.\n");
        }
    } while (choice != 4);

    return 0;
}
