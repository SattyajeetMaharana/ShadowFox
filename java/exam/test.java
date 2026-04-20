#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<ctype.h>

int UserIdIdx = 10000;

struct Node{
    int id;
    char name[30];
    int score;
    int ScoreStack[10];
    int top;
    struct Node *next;
};

struct Question {
    char question[200];
    char optionA[100];
    char optionB[100];
    char optionC[100];
    char optionD[100];
    char correct;
};

struct Question qbank[] = {
    {"What is the capital of India?", "New Delhi", "Mumbai", "Kolkata", "Chennai", 'A'},
    {"Which data structure uses FIFO?", "Stack", "Queue", "Tree", "Graph", 'B'},
    {"Who invented C programming?", "Dennis Ritchie", "James Gosling", "Bjarne Stroustrup", "Ken Thompson", 'A'},
    {"Which planet is known as Red Planet?", "Earth", "Venus", "Mars", "Jupiter", 'C'},
    {"2 + 2 * 2 = ?", "6", "8", "4", "12", 'A'},
    {"Which is fastest?", "RAM", "Hard Disk", "SSD", "CPU Cache", 'D'},
    {"Water formula is?", "H2O", "CO2", "NaCl", "O2", 'A'},
    {"Which keyword creates a loop?", "if", "switch", "for", "break", 'C'},
    {"Binary of 5?", "101", "110", "111", "100", 'A'},
    {"Who is known as Father of Computers?", "Newton", "Einstein", "Charles Babbage", "Elon Musk", 'C'},
    {"Which is OS?", "Chrome", "Windows", "Google", "Facebook", 'B'},
    {"Size of int in most systems?", "8 bytes", "2 bytes", "4 bytes", "1 byte", 'C'},
    {"HTML stands for?", "HighText Machine Language", "HyperText Markup Language", "Hyper Tool Multi Language", "None", 'B'},
    {"Earth is?", "Star", "Planet", "Comet", "Asteroid", 'B'},
    {"Which is pointer operator?", "*", "+", "-", "/", 'A'}
};

int totalQuestions = sizeof(qbank) / sizeof(qbank[0]);
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

    while(tempSize > 0){
        sorted[k++] = extractMin(heap, &tempSize);
    }

    printf("\n----- TOP 10 PLAYERS -----\n");

    for(int i = k-1; i >= 0; i--){
        printf("UserID: %d  Score: %d  Name: %s\n",
            sorted[i]->id, sorted[i]->score, sorted[i]->name);
    }
}

void startQuiz(struct Node *currPlayer) {
    int asked[10];
    int count = 0;
    int scoreChange = 0;

    srand(time(NULL));

    while(count < 10) {
        int q = rand() % totalQuestions;

        // check duplicate
        int repeat = 0;
        for(int i=0; i<count; i++)
            if(asked[i] == q) repeat = 1;

        if(repeat) continue;

        asked[count++] = q;
        struct Question qs = qbank[q];

        printf("\nQ%d: %s\n", count, qs.question);
        printf("A) %s\n", qs.optionA);
        printf("B) %s\n", qs.optionB);
        printf("C) %s\n", qs.optionC);
        printf("D) %s\n", qs.optionD);

        printf("Enter answer (A/B/C/D) or X to skip: ");
        char ans;
        scanf(" %c", &ans);

        ans = toupper(ans);

        if(ans == 'X')
            scoreChange -= 1;
        else if(ans == qs.correct)
            scoreChange += 10;
        else
            scoreChange -= 4;
    }

    printf("\nQuiz Finished! Score gained: %d\n", scoreChange);

    // Update stack
    if(currPlayer->top < 9){
        currPlayer->top++;
        currPlayer->ScoreStack[currPlayer->top] = currPlayer->score + scoreChange;
        currPlayer->score = currPlayer->ScoreStack[currPlayer->top];
    }
    else printf("Score stack full!\n");
}

void userMenu(struct Node* head, struct Node* currNode){
    int operation;

    do{
        printf("\nWelcome %s!\n", currNode->name);
        printf("1 -> Take Quiz (10 Questions)\n");
        printf("2 -> Undo Score\n");
        printf("3 -> Search Player\n");
        printf("4 -> View Leaderboard\n");
        printf("5 -> View History\n");
        printf("0 -> Logout\n");
        printf("Enter operation: ");
        scanf("%d", &operation);

        switch(operation){
            case 1: startQuiz(currNode); break;
            case 2: undoUpdate(currNode); break;
            case 3: Search(head); break;
            case 4: {
                struct Node* heap[10];
                int size = buildTop10Heap(head, heap);
                printTop10(heap, size);
            } break;
            case 5: History(currNode); break;
            case 0: printf("Logging out...\n"); break;
            default: printf("Invalid choice!\n");
        }

    } while(operation != 0);
}

int main(){
    struct Node* head = NULL;

    // Default players
    insert(&head, "Rohit");
    insert(&head, "Surya");
    insert(&head, "Virat");
    insert(&head, "Hardik");
    insert(&head, "Bumrah");

    while(1){
        char choice;
        printf("\n-------- MAIN MENU --------\n");
        printf("E -> Existing User\n");
        printf("N -> New User\n");
        printf("X -> Exit Program\n");
        printf("Enter choice: ");
        scanf(" %c", &choice);

        // Exit
        if(choice == 'X' || choice == 'x'){
            printf("Exiting... Goodbye!\n");
            break;
        }

        // New User
        else if(choice == 'N' || choice == 'n'){
            char name[30];
            printf("Enter Name: ");

            int c;
            while((c = getchar()) != '\n' && c != EOF);

            fgets(name, sizeof(name), stdin);
            name[strcspn(name, "\n")] = 0;

            struct Node* newUser = insert(&head, name);
            printf("Registration Successful!\nYour UserID = %d\n", newUser->id);

            userMenu(head, newUser);
        }

        // Existing User Login
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

        else printf("Invalid option!\n");
    }

    return 0;
}
