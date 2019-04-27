#include <iostream>
#include <list>

using namespace std;

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 

class MergeTwoLists
{
    public:
    MergeTwoLists();
    ~MergeTwoLists();
    MergeTwoLists(MergeTwoLists& obj);
    MergeTwoLists& operator=(MergeTwoLists& obj);

    //main function
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2);
};

MergeTwoLists::MergeTwoLists()
{

}

MergeTwoLists::~MergeTwoLists()
{

}

MergeTwoLists::MergeTwoLists(MergeTwoLists& obj)
{

}

MergeTwoLists& MergeTwoLists::operator=(MergeTwoLists& obj)
{
    return *this;
}

ListNode* MergeTwoLists::mergeTwoLists(ListNode* l1, ListNode* l2)
{
    ListNode* MergedList;
    list<int>
    return MergedList;
}