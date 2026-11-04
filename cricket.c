/* Cricket Player Stats Tracker - Phase 1
   1. Add player: name, runs scored, balls faced
   2. View all players with strike rate = (runs x 100) / balls
   3. Search player by name
*/
#include <stdio.h>
#include <string.h>

#define MAX 50

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
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (count == MAX) {
                printf("Cannot add: storage full (%d players).\n", MAX);
                break;
            }
            printf("Enter player name: ");
            scanf(" %29[^\n]", name[count]);   /* reads name with spaces */
            printf("Enter runs scored: ");
            scanf("%d", &runs[count]);
            printf("Enter balls faced: ");
            scanf("%d", &balls[count]);
            count++;
            printf("Player added with S.No. %d\n", count);
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
                    sr = (runs[i] * 100.0) / balls[i];
                else
                    sr = 0;
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
                if (strcmp(name[i], key) == 0) {
                    if (balls[i] > 0)
                        sr = (runs[i] * 100.0) / balls[i];
                    else
                        sr = 0;
                    printf("S.No.: %d\n", i + 1);
                    printf("Name: %s\n", name[i]);
                    printf("Runs: %d\n", runs[i]);
                    printf("Balls: %d\n", balls[i]);
                    printf("Strike Rate: %.2f\n", sr);
                    found = 1;
                }
            }
            if (found == 0)
                printf("No player found with name %s\n", key);
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
