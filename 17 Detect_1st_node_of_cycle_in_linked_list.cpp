// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.


// LOGIC:

// m -->  Dist of 1st node from cycle head
// n -->  Length of cycle
// k -->  dist of (node where slow and fast meet) FROM (the 1st cycle node)
// x -->  Number of complete cyclic rounds made by fast pointer before they meet first time
// y -->  Number of complete cyclic rounds made by slow pointer before they meet first time


// Distance traveled by fast pointer = 2 * (Distance traveled by slow pointer)
// (m + n*x + k) = 2*(m + n*y + k)
// reduces to => n*(x-2*y) = m+k
// can we written as => n*Z = m+k (where Z is an integer >= 0)
// thus, **n*Z = m+k** => eqn 1

// Once both slow and fast coincide, we move fast to the first node
// then both move at same speed

// we need to prove that now they'll coincide at the cycle starting node

// fast reaches cycle start in m steps
// slow is already k steps ahead of cycle start node
// if we want both to coincide at cycle start node:
// for slow pointer it might take these many steps: 
//    n-k (0 extra cycles)
//    2*n-k (1 extra cycle)
//    3*n-k (2 extra cycles)
//    so on....
// this satisfies our eqn 1

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL)
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        slow = slow->next;
        fast = fast->next->next;

        while(slow != fast){
            if(fast==NULL || fast->next==NULL)
                return NULL;
            
            slow = slow->next;
            fast = fast->next->next;
        }

        slow = head;             //imp-1

        while(slow != fast){
            slow = slow->next;
            fast = fast->next;   //imp-2  //MOVE @ SAME SPD.
        }

        return slow;
    }
};
