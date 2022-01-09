
struct Node {
  Node * next;
  int data;
};

/*recursive solution*/
int Length(Node *head)
{
  if(head == nullptr) return 0;
  return 1 + Length(head->next); //1 + the rest
}

int Count(Node *head, int data)
{
  if(head == nullptr) return 0;
  return (head->data == data) + Count(head->next, data);
}

/* Iterative solution
int Length(Node *head)
{
  int length = 0;
  while(head != nullptr)
  {
    length++;
    head = head->next;
  }
  return length;
}

int Count(Node *head, int data)
{
  int count = 0;
  while(head != nullptr)
  {
    if(head->data == data) count++;
    head = head->next;
  }
  return count;
}
*/