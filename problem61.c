struct ListNode* rotateRight(struct ListNode* head, int k) {

    if (head == NULL || head->next == NULL || k == 0)
        return head;

    // Find length and tail
    int length = 1;
    struct ListNode* tail = head;

    while (tail->next != NULL) {
        tail = tail->next;
        length++;
    }

    // Reduce unnecessary rotations
    k = k % length;

    if (k == 0)
        return head;

    // Make circular linked list
    tail->next = head;

    // Find new tail position
    int steps = length - k;

    struct ListNode* newTail = tail;

    while (steps--) {
        newTail = newTail->next;
    }

    // Break the circle
    struct ListNode* newHead = newTail->next;
    newTail->next = NULL;

    return newHead;
}
