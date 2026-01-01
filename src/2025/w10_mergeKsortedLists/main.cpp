/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    bool AllListsStillHaveValues( vector<ListNode*>& lists  ){

        for(auto & list : lists){
            if ( list != nullptr ){
                return true;
            }
        }
        return false;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* res = new ListNode(-1);
        ListNode* head = res;

        while ( AllListsStillHaveValues(lists)  ){
            int min_value = INT_MAX;
            int index = -1;
            for ( int i = 0; i < lists.size(); i++ ){
                if ( lists[i] &&  lists[i]->val < min_value ){
                    min_value = lists[i]->val;
                    index = i;
                }
            }
            auto temp = lists[index];
            lists[index] = lists[index]->next; 
            temp->next = nullptr;
            res->next = temp;
            res = res->next;
        } 

        return head->next;
    }
};


//-------------------------------------

// beats 100% of  submissions : using priority_queue


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        ListNode* res = new ListNode(-1);
        ListNode* head = res;

        auto cmp = [](ListNode* a, ListNode* b) { return a->val > b->val; };
        priority_queue<ListNode*, vector<ListNode*>, decltype(cmp)> pq(cmp);

        for (auto& list : lists){
            if (list){
                pq.push( list );
            }
        }

        while (  !pq.empty()  ){
            auto min_node = pq.top();
            pq.pop();
            res->next = min_node;
            res = res->next;

            if (min_node->next){
                pq.push( min_node->next );
            }
        }
        return head->next;
    }
};
