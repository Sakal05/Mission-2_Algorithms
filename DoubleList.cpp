/*
Mission#2
Section: 2
Team Name:
- Sakal Samnang
- Hongsreng Pheng
- Samrin Nuon
*/

#include <iostream>
using namespace std;

#include "DoubleNode.h" //Import double_node class

template <class T> // Generic template for the Double_node class
class Double_list
{
private:
  Double_node<T> *list_head; // Node pointer pointing to the first node (or NULL if list is empty)
  Double_node<T> *list_tail; // Node pointer pointing to the last node (or NULL if list is empty)
  int list_size;             // Number of items(nodes) contain within the list
public:
  Double_list()
  {
    list_head = nullptr;
    list_tail = nullptr;
    list_size = 0;
  } // Default constuctor

  Double_list(const Double_list &dl) : Double_list()
  {
    for (Double_node<T> *trav = dl.head(); trav != NULL; trav = trav->getNext())
    {
      this->push_back(trav->getData());
    }
  } // Copy constructor

  int size() const
  {
    return list_size;
  } // Return list_size

  bool empty() const
  {
    return size() == 0 ? true : false;
  } // Return true if list_size equal to 0, else return false

  T front() const
  {
    return list_head->getData();
  } // Return the item stored inside the node the list_head pointer's pointing to

  T back() const
  {
    return list_tail->getData();
  } // Return the item stored inside the node the list_tail pointer's pointing to

  Double_node<T> *head() const
  {
    return this->list_head;
  } // Return list_head

  Double_node<T> *tail() const
  {
    return this->list_tail;
  } // Return list_Tail

  int count(T data) const
  {
    int counter = 0;
    for (Double_node<T> *trav = list_head; trav != NULL; trav = trav->getNext())
    {
      if (trav->getData() == data)
        counter++;
    }
    return counter;
  } // Return the number of nodes storing a value equal to the argument

  Double_list &operator=(const Double_list &data)
  {
    for (Double_node<T> *trav = data.head(); trav != NULL; trav = trav->getNext())
    {
      this->push_back(trav->getData());
    }
    return *this;
  }

  // Swap the contents of this list with the argument list
  void swap(Double_list<T> &list)
  {
    Double_node<T> *temp = list_head;
    list_head = list.head();
    list.set_head(temp);

    temp = list_tail;
    list_tail = list.tail();
    list.set_tail(temp);
  }

  void push_front(T obj)
  {
    Double_node<T> *newNode = new Double_node<T>(obj);
    newNode->setData(obj);
    newNode->setNext(nullptr);
    newNode->setPrev(nullptr);
    if (list_head == nullptr && list_tail == nullptr)
    {
      list_head = list_tail = newNode;
    }
    else
    {
      list_head->setPrev(newNode);
      newNode->setNext(list_head);
      list_head = newNode;
    }
    list_size++;
  } // Add a node storing the argument to the front of the list
  void push_back(T obj)
  {
    Double_node<T> *newNode = new Double_node<T>(obj);
    newNode->setData(obj);
    newNode->setNext(nullptr);
    newNode->setPrev(nullptr);
    if (list_head == nullptr && list_tail == nullptr)
    {
      list_head = list_tail = newNode;
    } // condition for the first node
    else
    {
      list_tail->setNext(newNode);
      newNode->setPrev(list_tail);
      list_tail = newNode; // new node will become the last node
    }
    list_size++;
  }; // Add a node storing the argument to the back of the list
  T pop_front()
  {
    if (this->empty())
    {
      throw "underflow";
    }

    else if (list_head == list_tail)
    {
      delete list_head;
      return list_head->getData();
    }
    else
    {
      Double_node<T> *trav = list_head;
      list_head = list_head->getNext();
      list_head->setPrev(nullptr);
      T temp = trav->getData();
      delete trav;
      list_size--;
      return temp;
    }

  } // Remove a node from the front of the list and return the data it stores

  T pop_back()
  {
    if (this->empty())
    {
      throw "underflow";
    }

    if (list_head == list_tail)
    {
      delete list_head;
      return list_head->getData();
    }
    else
    {
      Double_node<T> *trav = list_tail;
      list_tail = list_tail->getPrev();
      list_tail->setNext(nullptr);
      T temp = trav->getData();
      delete trav;
      list_size--;
      return temp;
    }

  } // Remove a node from the back of the list and return the data it stores

  int erase(T obj)
  {
    for (Double_node<T> *trav = list_head; trav != NULL; trav = trav->getNext())
    {
      //
      if (trav->getData() != obj)
      {
        continue;
      }

      list_size--;

      if (this->size() == 1)
      {
        delete trav;
        this->list_head = nullptr;
        this->list_tail = nullptr;
        return 1;
      }

      if (trav == list_head)
      {
        pop_front();
        return 1;
      }
      if (trav == list_tail)
      {
        pop_back();
        return 1;
      }

      // condition for obj at the middle
      trav->getPrev()->setNext(trav->getNext());
      trav->getNext()->setPrev(trav->getPrev());
      delete trav;
      return 1;
    }
    return 0;

  } // Delete the first node (from the front) storing a value equal to the argument and return 1 if an object is found and deleted, else return 0

  void diplayList() const
  {
    for (Double_node<T> *trav = list_head; trav != NULL; trav = trav->getNext())
    {
      cout << trav->getData() << (trav->getNext() == NULL ? "\n" : "->");
    }
  }

  void displayReverse() const
  {
    for (Double_node<T> *trav = list_tail; trav != NULL; trav = trav->getPrev())
    {
      cout << trav->getData() << (trav->getPrev() == NULL ? "\n" : "->");
    }
  }

  void set_head(Double_node<T> *list_head)
  {
    this->list_head = list_head;
  } // Set list_head to the input list_head

  void set_tail(Double_node<T> *list_tail)
  {
    this->list_tail = list_tail;
  } // Set list_tail to the input list_tail

  void set_size(int list_size)
  {
    this->list_size = list_size;
  } // Set list_size to the input list_size

  ~Double_list()
  {
    Double_node<T> *trav = list_head;
    while (list_head != nullptr)
    {
      trav = list_head;
      list_head = list_head->getNext();
      delete trav;
    }
  } // Destructor
};

/* Test Case */
int main()
{
  cout << "====== Test Case Result =======" << endl;
  Double_list<int> L1; // declare/create object of the class

  // Add Elements into L1 using push_back and push_front functions
  L1.push_front(20);
  L1.push_back(30);
  L1.push_back(30);
  L1.push_back(40);  // last node
  L1.push_front(10); // first node
  // Result: 10 20 30 40
  cout << "\nList of nodes: ";
  L1.diplayList(); // print list of L1
  cout << "Size of list L1 before Implementation: " << L1.size() << endl;
  // impl pop front function
  cout << "Data that's being pop front is: " << L1.pop_front() << "\n" << endl;
  //Test case for exception popping empty list
  /*
  try
  {
    L1.pop_front();
  }
  catch (char const *error)
  {
    cerr << "Error: " << error << endl;
    return 404;
  }
  */
  // Perform pop back function
  cout << "Data that's being pop back is: " << L1.pop_back() << "\n"
       << endl;
  // Result after pop back
  cout << "=== Result of list L1 after perform pop back and pop front is: ";
  L1.diplayList();
  cout << endl;
  // impl print list function
  cout << "=== Final Result of the list after perform pop function is: ";
  L1.diplayList();
  cout << endl;
  cout << "Empty Status of L1: " << L1.empty() << endl;
  cout << "Value Front of L1: " << L1.front() << endl;
  cout << "Value Back of L1: " << L1.back() << endl;
  cout << "Address of Head: " << L1.head() << endl;
  cout << "Address of Tail: " << L1.tail() << endl;
  cout << "Count the node that stores the value of 30: " << L1.count(30) << endl;
  cout << "Status of Erase the value of 30: " << L1.erase(30) << endl;
  cout << "\n=== Result of list after erase the value of 30: ";
  L1.diplayList();
  cout << "Size of list L1 after Implementation: " << L1.size() << endl;

  // Add element into L2 using push_back
  Double_list<int> L2;
  L2.push_back(1);
  L2.push_back(2);
  L2.push_back(3);
  L2.push_back(4);
  // perfrom swap function from L2 to L1
  L1.swap(L2);
  cout << "\nList of L2 after swap with L1: ";
  L2.diplayList();

  // create new List L4
  Double_list<int> *L4 = new Double_list<int>(L1); // Implement using "=" operator to L4
  cout << "\nList of L4: ";
  L4->diplayList();
  cout << "Size of list L4: " << L4->size() << endl;
  // Perform push back to L1 to see any changes on L4. (Result should be made no change to L4)
  L1.push_back(90);
  cout << "\nList of L4 after pushing 90 to L1 (Must remained unchange): ";
  L4->diplayList();
  cout << endl;
  cout << "The List of L1 in Reverse (after pushing 90): ";
  L1.displayReverse();

  return 0;
}