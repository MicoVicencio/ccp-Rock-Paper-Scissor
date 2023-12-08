#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h> //for random number generator
// typedef node para Node lagi tawagin
typedef struct Node {
    char playerName[100];
    int playerScore;
    struct Node *next;
} Node;

Node *head = NULL;

enum Choices { ROCK = 1, PAPER = 2, SCISSORS = 3 }; //ENUM DATA

int gnum = 1;
char playername[5][100];  //GLOBAL VARIABLES
int playern = 0;
int trials = 0;

void addToLinkedList(char playerName[], int playerScore) { //PANG DAGDAG NG PLAYER SA LARO USING LINKED LIST
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->playerName, playerName);
    newNode->playerScore = playerScore;
    newNode->next = head;
    head = newNode;
}

void displayLinkedList() { //PANG DISPLAY NG SCORE BOARD FUNCTION USING LINKED LIST
    Node *current = head;
    printf("\t\t\t\t\t\tScore of Players:\n");
    printf("\t\t\t\t\t\tName:");
    while (current != NULL) {
        printf("\t%s", current->playerName);
        current = current->next;
    }
    printf("\n");
    printf("\t\t\t\t\t\tScores:");
    current = head;
    while (current != NULL) {
        printf("\t%d", current->playerScore);
        current = current->next;
    }
    printf("\n");
}

void scoreboard() { //SCOREBOARD FUNCTION
    displayLinkedList();
    exit(0);
}

void menu() { //MENU FUNCTION PANG DISPLAY NGG ART
    printf("\t\t\t           _____          ______               _____ \n");
    printf("\t\t\t       ---'   __)     ---'    __)_____     ---'   __)____\n");
    printf("\t\t\t             (___)                ____)               ____)\n");
    printf("\t\t\t             (___)               _____)            ________)\n");
    printf("\t\t\t             (__)              _____)             (__)\n");
    printf("\t\t\t       ---.__(_)     ---.__________)         ---.__(_)\n");
    printf("\t\t\t\t\t\t\n\t\t\t\t\t\tHello %s\n", playername[playern]);
    printf("\t\t\t\t\t\tEnter your option\n");
    printf("\t\t\t\t\t\t[1] Rock\n");
    printf("\t\t\t\t\t\t[2] Paper\n");
    printf("\t\t\t\t\t\t[3] Scissors\n");
    printf("\t\t\t\t\t\tCurrent Score: %d\n", head->playerScore);
}

int main() { /MAIN FUNCTION
    printf("\t\t\t\t\t\tEnter Player Name:");
    scanf("%s", playername[playern]);
    addToLinkedList(playername[playern], 0);  //STARTING PLAYER

    for (int life = 1; life > 0;) { 
        srand(time(NULL)); 
        int user = 0;
        int cpu = 0;
        printf("\t\t\t\t\t==================================\n");
        printf("\t\t\t\t\t   ROCK PAPER SCISSORS GAME # %d\n", gnum);
        printf("\t\t\t\t\t==================================\n");
        menu();
        printf("\t\t\t\t\t\tRemaining Life: %d\n", life);
        printf("\t\t\t\t\t\tDecision: ");
        scanf("%d", &user);

        cpu = rand() % 3 + 1; // RANDOM NUMBER GENERATOR FOR THE CHOICE OF CPU

        printf("\t\t\t\t\t\t-CPU chooses ");
        switch (cpu) { //SWITCH CASE FOR CHOICES
            case ROCK:
                printf("Rock-\n");
                break;
            case PAPER:
                printf("Paper-\n");
                break;
            case SCISSORS:
                printf("Scissors-\n");
                break;
        }

        if (user == cpu) {
            printf("\t\t\t\t\t\tLadies and Gentlemen!\n");
            printf("\t\t\t\t\t\tWe have a tie!\n");
            gnum++;
        } else if (user == ROCK) {
            if (cpu == PAPER) {
                printf("\t\t\t\t\t\tYou Lose!\n");
                printf("\t\t\t\t\t\tPaper covers Rock!\n");
                life--;
                gnum++;
            } else if (cpu == SCISSORS) {
                printf("\t\t\t\t\t\tYou Win!\n");
                printf("\t\t\t\t\t\tRock smashes Scissors!\n");
                gnum++;
                head->playerScore++;  // Update the player's score in the linked list
            }
        } else if (user == PAPER) {
            if (cpu == ROCK) {
                printf("\t\t\t\t\t\tYou Win!\n");
                printf("\t\t\t\t\t\tPaper covers Rock!\n");
                gnum++;
                head->playerScore++;  // Update the player's score in the linked list
            } else if (cpu == SCISSORS) {
                printf("\t\t\t\t\t\tYou Lose!\n");
                printf("\t\t\t\t\t\tScissors cuts Paper!\n");
                life--;
                gnum++;
            }
        } else if (user == SCISSORS) {
            if (cpu == ROCK) {
                printf("\t\t\t\t\t\tYou Lose!\n");
                printf("\t\t\t\t\t\tRock smashes Scissors!\n");
                life--;
                gnum++;
            } else if (cpu == PAPER) {
                printf("\t\t\t\t\t\tYou Win!\n");
                printf("\t\t\t\t\t\tScissors cuts Paper!\n");
                gnum++;
                head->playerScore++;  // Update the player's score in the linked list
            }
        }
    }

    char selection;
    printf("\n\t\t\t\t\t\tYou lost your life.\n");
    printf("\t\t\t\t\t\tDo you want to try again? [Y] = yes [N] = no:");
    scanf(" %c", &selection);
    printf("\n");
    if (selection == 'y' || selection == 'Y') { //SELECTION IF STILL WANT TO CONTINUE
        trials++;
        if (trials < 5) {
            gnum = 1;
            playern++;
            main();
        } else {
            printf("\t\t\t\t\t\tMaximum Player Reached! The program will now exit.\n");
            scoreboard();
        }
    } else {
        scoreboard();
    }

    return 0;
}
