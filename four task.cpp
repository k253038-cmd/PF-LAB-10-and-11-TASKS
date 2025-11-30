#include <stdio.h>
#include <string.h>

struct Movie {
    char title[50];
    char genre[30];
    char director[50];
    int year;
    float rating;
};

int addMovie(struct Movie movies[], int count) {
    printf("\nEnter Movie Title: ");
    getchar();
    fgets(movies[count].title, 50, stdin);
    movies[count].title[strcspn(movies[count].title, "\n")] = '\0';

    printf("Enter Genre: ");
    fgets(movies[count].genre, 30, stdin);
    movies[count].genre[strcspn(movies[count].genre, "\n")] = '\0';

    printf("Enter Director: ");
    fgets(movies[count].director, 50, stdin);
    movies[count].director[strcspn(movies[count].director, "\n")] = '\0';

    printf("Enter Release Year: ");
    scanf("%d", &movies[count].year);

    printf("Enter Rating: ");
    scanf("%f", &movies[count].rating);

    printf("Movie Added Successfully!\n");
    return count + 1;     
    

}


void searchByGenre(struct Movie movies[], int count) {
    char searchGenre[30];
    int found = 0;

    printf("\nEnter Genre to Search: ");
    getchar();
    fgets(searchGenre, 30, stdin);
    searchGenre[strcspn(searchGenre, "\n")] = '\0';

    for (int i = 0; i < count; i++) {
        if (strcmp(movies[i].genre, searchGenre) == 0) {
            printf("\nTitle: %s\n", movies[i].title);
            printf("Director: %s\n", movies[i].director);
            printf("Year: %d\n", movies[i].year);
            printf("Rating: %.1f\n", movies[i].rating);
            found = 1;
        }
    }

    if (!found) {
        printf("No movies found in this genre.\n");
    }
}


void displayAll(struct Movie movies[], int count) {
    if (count == 0) {
        printf("\nNo movies available.\n");
        return;
    }

    printf("\n--- All Movies ---\n");
    for (int i = 0; i < count; i++) {
        printf("\nTitle: %s\n", movies[i].title);
        printf("Genre: %s\n", movies[i].genre);
        printf("Director: %s\n", movies[i].director);
        printf("Year: %d\n", movies[i].year);
        printf("Rating: %.1f\n", movies[i].rating);
    }
}

int main() {
    struct Movie movies[100];  
    int count = 0;              
    int choice;

    do {
        printf("\n--- Movie Menu ---\n");
        printf("1. Add Movie\n");
        printf("2. Search by Genre\n");
        printf("3. Display All Movies\n");
        printf("4. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                count = addMovie(movies, count);
                break;

            case 2:
                searchByGenre(movies, count);
                break;

            case 3:
                displayAll(movies, count);
                break;

            case 4:
                printf("Exiting program...\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }

    } while (choice != 4);

    return 0;
}


