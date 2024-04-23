#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* detectCycle(Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL;

    Node* slow = head;
    Node* fast = head;

    slow = slow->next;
    fast = fast->next->next;


    while (fast != NULL && fast->next != NULL) {
        if (slow == fast) {
            break;
        }
        slow = slow->next;
        fast = fast->next->next;
    }


    if (fast == NULL || fast->next == NULL) {
        return NULL;
    }


    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }


    return slow;
}

int main() {

    Node* head1 = (Node*)malloc(sizeof(Node));
    head1->val = 3;
    head1->next = (Node*)malloc(sizeof(Node));
    head1->next->val = 2;
    head1->next->next = (Node*)malloc(sizeof(Node));
    head1->next->next->val = 0;
    head1->next->next->next = (Node*)malloc(sizeof(Node));
    head1->next->next->next->val = 4;
    head1->next->next->next->next = head1->next; // Create cycle
    Node* cycle_start1 = detectCycle(head1);
    printf("Example 1: Cycle starts at node with value %d\n", cycle_start1 ? cycle_start1->val : -1);


    Node* head2 = (Node*)malloc(sizeof(Node));
    head2->val = 1;
    head2->next = (Node*)malloc(sizeof(Node));
    head2->next->val = 2;
    head2->next->next = head2; // Create cycle
    Node* cycle_start2 = detectCycle(head2);
    printf("Example 2: Cycle starts at node with value %d\n", cycle_start2 ? cycle_start2->val : -1);


    Node* head3 = (Node*)malloc(sizeof(Node));
    head3->val = 1;
    head3->next = NULL;
    Node* cycle_start3 = detectCycle(head3);
    printf("Example 3: Cycle starts at node with value %d\n", cycle_start3 ? cycle_start3->val : -1);

    return 0;
}
//YES,THE CODE USES CONSTANT MEMORY
