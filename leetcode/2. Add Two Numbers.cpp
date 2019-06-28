struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
            int carry = 0;
            ListNode *result = nullptr;
            ListNode *p_l1 = l1, *p_l2 = l2, *p_result = result;
            while (p_l1 or p_l2) {
                    int sum = 0;
                    if (p_l1) {
                            sum += p_l1->val;
                            p_l1 = p_l1->next;
                    }
                    if (p_l2) {
                            sum += p_l2->val;
                            p_l2 = p_l2->next;
                    }
                    sum += carry;
                    carry = sum / 10;
                    if (result == nullptr) {
                            result = new ListNode(sum % 10);
                            p_result = result;
                    } else {
                            p_result->next = new ListNode(sum % 10);
                            p_result = p_result->next;
                    }
            }
            if (carry == 1) {
                    p_result->next = new ListNode(carry);
                    p_result = p_result->next;
            }
            return result;
    }
};