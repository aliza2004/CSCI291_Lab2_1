#include <stdio.h>
#include <string.h>

#define NUM_TEAMS 10
#define SQUAD_SIZE 25

// Structure to represent a player's age
typedef struct {
    int day;
    int month;
    int year;
} birthDate_t;

// Structure to represent a player
typedef struct {
    char name[26]; // Full name (max 25 characters)
    int kitNumber; // Kit number (1-99)
    birthDate_t birthDate; // Player's birth date
    char position[20]; // Position within the team
} player_t;

// Structure to represent a team
typedef struct {
    char teamName[21]; // Team name (max 20 characters)
    player_t players[SQUAD_SIZE]; // Array of players
    int activeSize; // Number of players currently enrolled
} team_t;

// Function prototypes
void display_menu();
void enroll_club(team_t teams[], int *numTeams);
void add_player(team_t teams[], int numTeams);
void search_update(team_t teams[], int numTeams);
void display_club_statistics(const team_t teams[], int numTeams);

// Main function
int main() {
    team_t teams[NUM_TEAMS] = {0};
    int numTeams = 0;
    int choice;

    do {
        display_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                enroll_club(teams, &numTeams);
                break;
            case 2:
                add_player(teams, numTeams);
                break;
            case 3:
                search_update(teams, numTeams);
                break;
            case 4:
                display_club_statistics(teams, numTeams);
                break;
            case 5:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}

// Function to display the menu
void display_menu() {
    printf("\n--- League Team Management Menu ---\n");
    printf("1. Enroll a club\n");
    printf("2. Add a player\n");
    printf("3. Search and update player\n");
    printf("4. Display club statistics\n");
    printf("5. Exit\n");
}

// Function to enroll a new club
void enroll_club(team_t teams[], int *numTeams) {
    if (*numTeams >= NUM_TEAMS) {
        printf("Maximum number of teams reached.\n");
        return;
    }

    printf("Enter the name of the club (max 20 characters): ");
    scanf(" %[^\n]s", teams[*numTeams].teamName);  // Fixed input for club name
    teams[*numTeams].activeSize = 0;
    (*numTeams)++;

    printf("Club enrolled successfully.\n");
}

// Function to add a player to a team
void add_player(team_t teams[], int numTeams) {
    if (numTeams == 0) {
        printf("No clubs available.\n");
        return;
    }

    printf("Select a club (1-%d):\n", numTeams);
    for (int i = 0; i < numTeams; i++) {
        printf("%d. %s\n", i + 1, teams[i].teamName);
    }

    int clubIndex;
    printf("Enter club number: ");
    scanf("%d", &clubIndex);
    clubIndex--;

    if (clubIndex < 0 || clubIndex >= numTeams) {
        printf("Invalid club selection.\n");
        return;
    }

    if (teams[clubIndex].activeSize >= SQUAD_SIZE) {
        printf("Squad size limit reached.\n");
        return;
    }

    player_t newPlayer;
    printf("Enter player name: ");
    scanf(" %[^\n]s", newPlayer.name);  // Fixed input for player name
    printf("Enter kit number: ");
    scanf("%d", &newPlayer.kitNumber);
    printf("Enter birth date (DD MM YYYY): ");
    scanf("%d %d %d", &newPlayer.birthDate.day, &newPlayer.birthDate.month, &newPlayer.birthDate.year);
    printf("Enter position: ");
    scanf(" %[^\n]s", newPlayer.position);  // Fixed input for position

    teams[clubIndex].players[teams[clubIndex].activeSize++] = newPlayer;
    printf("Player added successfully.\n");
}

// Function to search and update a player
void search_update(team_t teams[], int numTeams) {
    char searchName[26];
    printf("Enter the name of the player to search: ");
    scanf(" %[^\n]s", searchName);  // Fixed input for search name

    for (int i = 0; i < numTeams; i++) {
        for (int j = 0; j < teams[i].activeSize; j++) {
            if (strcasecmp(teams[i].players[j].name, searchName) == 0) {
                printf("Player found in club: %s\n", teams[i].teamName);
                printf("Kit Number: %d\n", teams[i].players[j].kitNumber);
                printf("Position: %s\n", teams[i].players[j].position);

                printf("Enter new position: ");
                scanf(" %[^\n]s", teams[i].players[j].position);  // Fixed input for new position
                printf("Player updated.\n");
                return;
            }
        }
    }

    printf("Player not found.\n");
}

// Function to display statistics for all clubs
void display_club_statistics(const team_t teams[], int numTeams) {
    for (int i = 0; i < numTeams; i++) {
        printf("\nClub: %s\n", teams[i].teamName);
        printf("Number of players: %d\n", teams[i].activeSize);

        for (int j = 0; j < teams[i].activeSize; j++) {
            printf("Name: %s, Kit: %d, Position: %s\n",
                   teams[i].players[j].name, teams[i].players[j].kitNumber, teams[i].players[j].position);
        }
    }
}
