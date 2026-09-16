/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {
    if (head == NULL || head->next == NULL || k == 0)
        return head;

    int n = 1;
    struct ListNode* temp = head;

    while (temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    k = k % n;

    if (k == 0)
        return head;

    temp->next = head;

    int steps = n - k;
    struct ListNode* newTail = temp;

    while (steps--) {
        newTail = newTail->next;
    }

    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}