#include <string>

class Node
{
  public:
    int data;
    Node* next;
  
  Node(int data, Node* next = nullptr)
  {
    this->data = data;
    this->next = next;
  }
};


std::string stringify(Node* list)
{
  if(list == nullptr) return "nullptr";
  return std::to_string(list->data) + " -> " + stringify(list->next);
}

/*
std::string stringify(Node* list)
{
  std::string result;
  while(list != nullptr)
  {
    result += std::to_string(list->data) + " -> ";
    list = list->next;
  }
  return result + "nullptr";
}
*/