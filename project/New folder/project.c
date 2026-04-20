#include<stdio.h>
#include<stdlib.h>
#include<string.h>
// PART 1
int UserIdIdx = 10000;

struct Node{
    int id;
    char name[30];
    int score;
    int ScoreStack[10];
    int top;
    struct Node *next;
};


struct Node* insert(struct Node** head, char name[30]) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->id = UserIdIdx++;
    newNode->score = 0;
    strcpy(newNode->name, name);

    newNode->next = *head;
    *head = newNode;

    newNode->top = 0;
    newNode->ScoreStack[0] = 0;

    return newNode;
}

// PART 2
void updateScore(struct Node *currPlayer){
    int score;
    printf("Enter the New Score : ");
    scanf("%d", &score);

    if(currPlayer->top < 9) {
        currPlayer->top++;
        currPlayer->ScoreStack[currPlayer->top] = score;
        currPlayer->score = score;
    } else {
        printf("Stack FULL! Cannot update more scores.\n");
    }
}


void undoUpdate(struct Node* currNode){
    if(currNode->top == 0){
        printf("Cannot undo. Initial score reached.\n");
        return;
    }
    currNode->top--;
    currNode->score = currNode->ScoreStack[currNode->top];
}


void Search(struct Node* head){
    int plrId;
    printf("Enter UserId of the Player : ");
    scanf("%d", &plrId);

    struct Node *ptr = head;
    while(ptr != NULL){
        if(ptr->id == plrId){
            printf("Player : %s\n", ptr->name);
            printf("Score  : %d\n", ptr->score);
            return;
        }
        ptr = ptr->next;
    }
    printf("Player Not Found !\n");
}


void History(struct Node* currNode){
    printf("Your Score History : ");
    for(int i=0;i<=currNode->top;i++){
        printf("%d ", currNode->ScoreStack[i]);
    }
    printf("\n");
}
// PART 3
/* ===============================
          MIN HEAP CODE
   =============================== */
void minHeapify(struct Node* heap[], int n, int i){
    int smallest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(left < n && heap[left]->score < heap[smallest]->score)
        smallest = left;

    if(right < n && heap[right]->score < heap[smallest]->score)
        smallest = right;

    if(smallest != i){
        struct Node* temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(heap, n, smallest);
    }
}

int insertMinHeap(struct Node* heap[], int size, struct Node* player){
    if(size < 10){
        heap[size] = player;

        int i = size;
        while(i != 0 && heap[(i-1)/2]->score > heap[i]->score){
            struct Node* temp = heap[i];
            heap[i] = heap[(i-1)/2];
            heap[(i-1)/2] = temp;
            i = (i-1)/2;
        }
        return size + 1;
    }

    if(player->score > heap[0]->score){
        heap[0] = player;
        minHeapify(heap, 10, 0);
    }

    return size;
}

int buildTop10Heap(struct Node* head, struct Node* heap[]){
    int size = 0;
    struct Node* temp = head;

    while(temp != NULL){
        size = insertMinHeap(heap, size, temp);
        temp = temp->next;
    }

    return size;
}

struct Node* extractMin(struct Node* heap[], int *size){
    if(*size == 0) return NULL;

    struct Node* min = heap[0];
    heap[0] = heap[*size - 1];
    (*size)--;

    minHeapify(heap, *size, 0);
    return min;
}
void printTop10(struct Node* heap[], int size){
    struct Node* sorted[10];
    int tempSize = size;

    int k = 0;

    // Extract min one by one → gives ascending order
    while(tempSize > 0){
        sorted[k++] = extractMin(heap, &tempSize);
    }

    printf("\n----- TOP 10 PLAYERS -----\n");

    // Print in reverse → highest score first
    for(int i = k-1; i >= 0; i--){
        printf("UserID: %d  Score: %d  Name: %s\n",
            sorted[i]->id, sorted[i]->score, sorted[i]->name);
    }
}


// MAIN MENU PART 4
void userMenu(struct Node* head, struct Node* currNode){
    int operation;

    do{
        printf("\nWelcome %s!\n", currNode->name);
        printf("1 -> Update Score\n");
        printf("2 -> Undo Update\n");
        printf("3 -> Search Player\n");
        printf("4 -> View Leaderboard\n");
        printf("5 -> View History\n");
        printf("0 -> Logout\n");
        printf("Enter operation: ");
        scanf("%d", &operation);

        switch(operation){
            case 1: updateScore(currNode); break;
            case 2: undoUpdate(currNode); break;
            case 3: Search(head); break;
            case 4: {
                struct Node* heap[10];
                int size = buildTop10Heap(head, heap);
                printTop10(heap, size);
            }
            break;
            case 5: History(currNode); break;
            case 0: printf("Logging out...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while(operation != 0);
}


// PART 5
int main(){
    struct Node* head = NULL;

    // default players
    insert(&head, "Rohit");
    insert(&head, "Surya");
    insert(&head, "Virat");
    insert(&head, "Hardik");
    insert(&head, "Bumrah");

    while(1){
        char choice;
        printf("--------MAIN MENU ---------\n");
        printf("E -> Existing User\n");
        printf("N -> New User\n");
        printf("X -> Exit Program\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        if(choice == 'X' || choice == 'x'){
            printf("Exiting... Goodbye!\n");
            break;
        }

        /* NEW USER REGISTRATION */
      else if(choice == 'N' || choice == 'n'){
    char name[30];
    printf("Enter Name: ");

    // clear leftover input (consume until newline or EOF)
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { }

    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;  

    struct Node* newUser = insert(&head, name);
    printf("Registration Successful!\nYour UserID = %d\n", newUser->id);

    userMenu(head, newUser);  // NOW GO TO EXISTING USER PAGE
}


        /* EXISTING USER LOGIN */
        else if(choice == 'E' || choice == 'e'){
            int id;
            printf("Enter your UserID: ");
            scanf("%d", &id);

            struct Node* temp = head;
            while(temp != NULL && temp->id != id)
                temp = temp->next;

            if(temp == NULL){
                printf("Invalid User ID!\n");
            } else {
                userMenu(head, temp);
            }
        }

        else {
            printf("Invalid option!\n");
        }
    }

    return 0;
}