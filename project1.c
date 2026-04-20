#include <stdio.h>
#include <string.h>

#define MAX 10   

char bugs[MAX][50];   
int front = 0, rear = -1;

void addBug(char bug[]) {
    if (rear == MAX - 1) {
        printf("Bug list full!\n");
        return;
    }
    rear++;
    strcpy(bugs[rear], bug);
    printf("Bug added: %s\n", bug);
}

void resolveBug() {
    if (front > rear) {
        printf("No bugs to resolve!\n");
        return;
    }

    printf("Bug resolved: %s\n", bugs[front]);
    front++;

    // Reset queue when empty
    if (front > rear) {
        front = 0;
        rear = -1;
    }
}

void showBugs() {
    if (front > rear) {
        printf("No bugs in queue.\n");
        return;
    }

    printf("Current bugs:\n");
    for (int i = front; i <= rear; i++) {
        printf("- %s\n", bugs[i]);
    }
}

int main() {
    addBug("Login button not working");
    addBug("Crash on file upload");
    addBug("UI misalignment on dashboard");

    showBugs();

    resolveBug();
    resolveBug();

    showBugs();

    addBug("Payment page bug");
    addBug("Profile picture not updating");

    showBugs();

    return 0;
}