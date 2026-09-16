/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if (listsSize == 0)
        return NULL;

    struct ListNode** heap = malloc(listsSize * sizeof(struct ListNode*));
    int size = 0;

    for (int i = 0; i < listsSize; i++) {
        if (lists[i] != NULL) {
            heap[size] = lists[i];
            size++;
        }
    }

    for (int i = size / 2 - 1; i >= 0; i--) {
        int j = i;

        while (1) {
            int smallest = j;
            int left = 2 * j + 1;
            int right = 2 * j + 2;

            if (left < size && heap[left]->val < heap[smallest]->val)
                smallest = left;

            if (right < size && heap[right]->val < heap[smallest]->val)
                smallest = right;

            if (smallest == j)
                break;

            struct ListNode* temp = heap[j];
            heap[j] = heap[smallest];
            heap[smallest] = temp;

            j = smallest;
        }
    }

    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (size > 0) {
        struct ListNode* node = heap[0];

        tail->next = node;
        tail = tail->next;

        if (node->next != NULL) {
            heap[0] = node->next;
        } else {
            heap[0] = heap[size - 1];
            size--;
        }

        int j = 0;

        while (1) {
            int smallest = j;
            int left = 2 * j + 1;
            int right = 2 * j + 2;

            if (left < size && heap[left]->val < heap[smallest]->val)
                smallest = left;

            if (right < size && heap[right]->val < heap[smallest]->val)
                smallest = right;

            if (smallest == j)
                break;

            struct ListNode* temp = heap[j];
            heap[j] = heap[smallest];
            heap[smallest] = temp;

            j = smallest;
        }
    }

    tail->next = NULL;

    free(heap);

    return dummy.next;
}