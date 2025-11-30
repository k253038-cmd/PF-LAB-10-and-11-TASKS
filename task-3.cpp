#include <stdio.h>
#include <string.h>


struct Flight {
    int flightNumber;
    char departure[50];
    char destination[50];
    char date[20]; 
    int availableSeats;
};


void displayFlight(struct Flight f) {
    printf("\nFlight Number: %d\n", f.flightNumber);
    printf("Departure: %s\n", f.departure);
    printf("Destination: %s\n", f.destination);
    printf("Date: %s\n", f.date);
    printf("Available Seats: %d\n", f.availableSeats);
}

void bookSeat(struct Flight *f) {
    if (f->availableSeats > 0) {
        f->availableSeats--;
        printf("Booking successful! Seats remaining: %d\n", f->availableSeats);
    } else {
        printf("Sorry, no seats available on this flight.\n");
    }
}

int main() {
    struct Flight flights[5]; 
    int n, choice, flightIndex;

    printf("Enter number of flights to manage: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter details for flight %d:\n", i + 1);
        printf("Flight Number: ");
        scanf("%d", &flights[i].flightNumber);
        printf("Departure City: ");
        scanf(" %[^\n]", flights[i].departure);
        printf("Destination City: ");
        scanf(" %[^\n]", flights[i].destination);
        printf("Date (DD/MM/YYYY): ");
        scanf(" %[^\n]", flights[i].date);
        printf("Available Seats: ");
        scanf("%d", &flights[i].availableSeats);
    }

    // Menu-driven system
    do {
        printf("\n--- Flight Management Menu ---\n");
        printf("1. Display all flights\n");
        printf("2. Book a seat\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                for (int i = 0; i < n; i++) {
                    displayFlight(flights[i]);
                }
                break;
            case 2:
                printf("Enter flight index to book (1 to %d): ", n);
                scanf("%d", &flightIndex);
                if (flightIndex >= 1 && flightIndex <= n) {
                    bookSeat(&flights[flightIndex - 1]);
                } else {
                    printf("Invalid flight index!\n");
                }
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);

    return 0;
}


	

