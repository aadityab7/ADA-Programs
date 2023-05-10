#include <stdio.h>
#include <stdlib.h>

/* Definition for singly-linked list. */
struct ListNode {
    int val;
    struct ListNode *next;
};

/* Function to merge two sorted linked lists. */
struct ListNode* merge(struct ListNode* l1, struct ListNode* l2) {
    if (l1 == NULL) {
        return l2;
    }
    if (l2 == NULL) {
        return l1;
    }
    if (l1->val <= l2->val) {
        l1->next = merge(l1->next, l2);
        return l1;
    } else {
        l2->next = merge(l1, l2->next);
        return l2;
    }
}

/* Function to find the middle node of a linked list. */
struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode *slow = head, *fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/* Function to perform merge sort on a linked list. */
struct ListNode* sortList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct ListNode* mid = findMiddle(head);
    struct ListNode* left = head;
    struct ListNode* right = mid->next;
    mid->next = NULL;
    left = sortList(left);
    right = sortList(right);
    return merge(left, right);
}

/* Function to print a linked list. */
void printList(struct ListNode* head) {
    while (head != NULL) {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

/* Main function for testing. */
int main() {
    struct ListNode* head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node1 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node2 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node3 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node4 = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* node5 = (struct ListNode*)malloc(sizeof(struct ListNode));
    head->val = 5;
    head->next = node1;
    node1->val = 4;
    node1->next = node2;
    node2->val = 3;
    node2->next = node3;
    node3->val = 2;
    node3->next = node4;
    node4->val = 1;
    node4->next = node5;
    node5->val = 0;
    node5->next = NULL;
    printf("Before sorting: ");
    printList(head);
    head = sortList(head);
    printf("After sorting: ");
    printList(head);
    return 0;
}
