#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <time.h> 
 
#define MAX 100 
 
char history[10][MAX]; 
int msg_count = 0; 
 
// Function to simulate delay 
void delay() { 
    for(long int i = 0; i < 100000000; i++); 
} 
 
// TCP Simulation 

 
void tcp_chat(char sender[], char receiver[], char message[]) { 
    printf("\n--- TCP Communication ---\n"); 
    printf("%s is sending message...\n", sender); 
     
    delay(); 
     
    printf("Message delivered to %s\n", receiver); 
    printf("ACK received from %s\n", receiver); 
     
    strcpy(history[msg_count++], message); 
} 
 
// UDP Simulation 
void udp_chat(char sender[], char receiver[], char message[]) { 
    printf("\n--- UDP Communication ---\n"); 
    printf("%s is sending message...\n", sender); 
 
    delay(); 
 
    int loss = rand() % 3; // Higher chance of loss 
 
    if(loss == 0) { 
        printf("Message lost!\n"); 
    } else { 
        printf("Message received by %s\n", receiver); 
        strcpy(history[msg_count++], message); 
    } 
} 
 
// Display Chat History 
void show_history() { 
    printf("\n--- Chat History ---\n"); 

    if(msg_count == 0) { 
        printf("No messages yet.\n"); 
        return; 
    } 
 
    for(int i = 0; i < msg_count; i++) { 
        printf("%d: %s\n", i+1, history[i]); 
    } 
} 
 
int main() { 
    int choice; 
    char sender[50], receiver[50]; 
    char message[MAX]; 
 
    srand(time(0)); 
 
    printf("Enter Sender Name: "); 
    scanf("%s", sender); 
 
    printf("Enter Receiver Name: "); 
    scanf("%s", receiver); 
 
    while(1) { 
        printf("\n===== CHAT MENU =====\n"); 
        printf("1. Send via TCP\n"); 
        printf("2. Send via UDP\n"); 
        printf("3. Show Chat History\n"); 
        printf("4. Exit\n"); 
        printf("Enter choice: "); 
        scanf("%d", &choice); 
 
 
 
        getchar(); // clear buffer 
 
        if(choice == 4) break; 
 
        switch(choice) { 
            case 1: 
                printf("Enter message: "); 
                fgets(message, sizeof(message), stdin); 
                tcp_chat(sender, receiver, message); 
                break; 
 
            case 2: 
                printf("Enter message: "); 
                fgets(message, sizeof(message), stdin); 
                udp_chat(sender, receiver, message); 
                break; 
 
            case 3: 
                show_history(); 
                break; 
 
            default: 
                printf("Invalid choice!\n"); 
        } 
    } 
 
    printf("\nChat Ended.\n"); 
    return 0; 
}