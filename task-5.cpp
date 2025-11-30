#include <stdio.h>
#include <string.h>

#define MAX_PLAYER 100

struct player {
    char name[50];
    int age;
    char position[100];
};

struct team {
    char name[50];
    char sports[100];
    struct player players[MAX_PLAYER];
    int plycount;
};

struct team myteam;  




void addplayer() {

    if (myteam.plycount >= MAX_PLAYER) {
        printf("Team is full!\n");
        return;
    }

    getchar();  

    printf("Enter player name: ");
    fgets(myteam.players[myteam.plycount].name,
          sizeof(myteam.players[myteam.plycount].name),
          stdin);

    myteam.players[myteam.plycount].name[
        strcspn(myteam.players[myteam.plycount].name, "\n")
    ] = '\0';


    printf("Enter player position: ");
    fgets(myteam.players[myteam.plycount].position,
          sizeof(myteam.players[myteam.plycount].position),
          stdin);

    myteam.players[myteam.plycount].position[
        strcspn(myteam.players[myteam.plycount].position, "\n")
    ] = '\0';


    printf("Enter player age: ");
    scanf("%d", &myteam.players[myteam.plycount].age);

    myteam.plycount++;

    printf("Player added successfully!\n");
}




void searchbypos(char searchpos[]) {

    int found = 0;

    printf("\nPlayers in position '%s':\n", searchpos);

    for (int i = 0; i < myteam.plycount; i++) {
        if (strcmp(myteam.players[i].position, searchpos) == 0) {
            printf("Name: %s | Position: %s | Age: %d\n",
                   myteam.players[i].name,
                   myteam.players[i].position,
                   myteam.players[i].age);
            found = 1;
        }
    }

    if (!found) {
        printf("No players found in this position.\n");
    }
}


void displayplayer() {

    printf("\nTeam Name: %s\n", myteam.name);
    printf("Sport: %s\n", myteam.sports);
    printf("Total Players: %d\n", myteam.plycount);

    for (int i = 0; i < myteam.plycount; i++) {
        printf("%d. %s | Age: %d | Position: %s\n",
               i + 1,
               myteam.players[i].name,
               myteam.players[i].age,
               myteam.players[i].position);
    }
}




int main() {

    myteam.plycount = 0;

    printf("Enter team name: ");
    fgets(myteam.name, sizeof(myteam.name), stdin);
    myteam.name[strcspn(myteam.name, "\n")] = '\0';

    printf("Enter sport: ");
    fgets(myteam.sports, sizeof(myteam.sports), stdin);
    myteam.sports[strcspn(myteam.sports, "\n")] = '\0';

    int choice;
    char searchpos[20];

    do {

        printf("\n------ Team Management System -------\n");
        printf("1. Add Player\n");
        printf("2. Search Player by Position\n");
        printf("3. Display Team\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar();

        switch (choice) {

        case 1:
            addplayer();
            break;

        case 2:
            printf("Enter position to search: ");
            fgets(searchpos, sizeof(searchpos), stdin);
            searchpos[strcspn(searchpos, "\n")] = '\0';
            searchbypos(searchpos);
            break;

        case 3:
            displayplayer();
            break;

        case 4:
            printf("Exiting program...\n");
            break;

        default:
            printf("Invalid choice!\n");

        }

    } while (choice != 4);

    return 0;
}

