// FUNCTION TO MERGE TWO SORTED LINKED LISTS

/* Link list Node
struct Node {
  int data;
  struct Node *next;

  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

Node *sortedMerge(Node *head1, Node *head2)
{
    // new node tail set as null
    Node *tail = NULL;
    // checking base cases

    // if first list is empty then directly return second list
    if (head1 == NULL)
    {
        return head2;
    }
    // else if second list is empty directly return first list
    if (head2 == NULL)
    {
        return head1;
    }

    // we iterate from the start of both lists and check which list has smaller element

    // we assign that value to tail and then recursively call the sorted merge function for remaining elements
    if (head1->data <= head2->data)
    {
        tail = head1;
        tail->next = sortedMerge(head1->next, head2);
        // head1->next because head1 was smaller so we already took that in our ans list
        // and moved forward
    }
    else
    {
        tail = head2;
        tail->next = sortedMerge(head1, head2->next);

        // as explained above we do the similar method on the second list elements
    }
    // as one list reaches null i.e it is completely iterated over then we can directly add the remaining elements of other list as they are all
    // bigger than the elements already in ans list

    // linked list is ready
    return tail;
};