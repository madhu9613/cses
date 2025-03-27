#include <stdio.h>
#include <stdlib.h>

// Function to compare integers for qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Binary search to find the largest ticket <= max_price
int find_ticket(int *tickets, int size, int max_price) {
    int left = 0, right = size - 1, result = -1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (tickets[mid] <= max_price) {
            result = mid;  // Update result and move right
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return result;  // Returns the index of the ticket, or -1 if none found
}

// Function to remove the ticket at the given index
void remove_ticket(int *tickets, int *size, int index) {
    for (int i = index; i < *size - 1; i++) {
        tickets[i] = tickets[i + 1];
    }
    (*size)--;  // Reduce the size of the array
}

int main() {
    int n, m;

    // Read number of tickets and customers
    scanf("%d %d", &n, &m);

    int *tickets = (int *)malloc(n * sizeof(int));
    int *max_prices = (int *)malloc(m * sizeof(int));

    // Read ticket prices
    for (int i = 0; i < n; i++) {
        scanf("%d", &tickets[i]);
    }

    // Sort tickets
    qsort(tickets, n, sizeof(int), compare);

    // Read maximum prices customers are willing to pay
    for (int i = 0; i < m; i++) {
        scanf("%d", &max_prices[i]);
    }

    // Process each customer
    for (int i = 0; i < m; i++) {
        int max_price = max_prices[i];

        // Find the largest ticket <= max_price
        int index = find_ticket(tickets, n, max_price);
        if (index == -1) {
            printf("-1\n");  // No valid ticket
        } else {
            printf("%d\n", tickets[index]);  // Print the ticket price
            remove_ticket(tickets, &n, index);  // Remove the ticket
        }
    }

    // Free allocated memory
    free(tickets);
    free(max_prices);

    return 0;
}
