/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    // First we will need to find length of both LLs
    // Move pointer of longer LL by difference of lengths
    // This will make sure that we start from parallel nodes at both LLs
    // Then increment both until we reach NULL or find intersection node

    struct ListNode* tempA = headA;
    struct ListNode* tempB = headB;
    int countA = 0;
    int countB = 0;
    int diff = 0;

    while(tempA != NULL){
        countA++;
        tempA = tempA->next;
    }
    tempA = headA;

    while(tempB != NULL){
        countB++;
        tempB = tempB->next;
    }
    tempB = headB;

    if(countA > countB){
        diff = countA - countB;
        while(diff){
            diff--;
            tempA = tempA->next;
        }
    } else if (countB > countA){
        diff = countB - countA;
        while(diff){
            diff--;
            tempB = tempB->next;
        }
    }

    while(tempA || tempB){
        if(tempA == tempB){
            return tempA;
        }
        tempA = tempA->next;
        tempB = tempB->next;
    }

    return NULL;
}