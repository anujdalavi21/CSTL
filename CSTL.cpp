#include <iostream>
using namespace std;

template <typename T>
struct node
{
    T data;
    struct node<T> *next;
};

template <typename T>
struct node1
{
    T data;
    struct node1<T> *next;
    struct node1<T> *prev;
};

////////////////////////////////////////////
// Singly Linear Linked List
///////////////////////////////////////////
template <class T>
class SinglyLL
{
private:
    node<T> *Head;

public:
    SinglyLL();
    void InsertFirst(T);
    void InsertAtPos(T, int);
    void InsertLast(T);
    void DeleteFirst();
    void DeleteAtPos(int);
    void DeleteLast();
    void Display();
    int Count();
};

// Constructor
template <class T>
SinglyLL<T>::SinglyLL()
{
    Head = NULL;
}

// Insert First

template <class T>
void SinglyLL<T>::InsertFirst(T no)
{
    node<T> *newn = new node<T>; // newn=(struct node *)malloc(sizeof(NODE))

    newn->data = no;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }

    else
    {
        newn->next = Head;
        Head = newn;
    }
}

// Insert Last
template <class T>
void SinglyLL<T>::InsertLast(T no)
{
    node<T> *newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }

    else
    {
        node<T> *temp = NULL;
        temp = Head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

// Insert At Position
template <class T>
void SinglyLL<T>::InsertAtPos(T no, int iPos)
{
    int Size = 0;
    int iCnt = 0;
    Size = Count();

    if ((iPos < 1) || (iPos > Size + 1))
    {
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == Size + 1)
    {
        InsertLast(no);
    }
    else
    {
        node<T> *newn = NULL;
        newn = new node<T>;

        newn->data = no;
        newn->next = NULL;

        node<T> *temp = NULL;
        temp = Head;

        for (iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

// Delete First
template <class T>
void SinglyLL<T>::DeleteFirst()
{
    node<T> *temp = NULL;

    if (Head == NULL)
    {
        return;
    }
    else
    {
        temp = Head;
        Head = temp->next;

        delete temp;
    }
}
// Delete Last
template <class T>
void SinglyLL<T>::DeleteLast()
{
    if (Head == NULL)
    {
        return;
    }
    else if (Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {
        node<T> *temp = NULL;
        temp = Head;

        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
}

// Delete At Position

template <class T>
void SinglyLL<T>::DeleteAtPos(int iPos)
{
    int iSize = 0;
    iSize = Count();

    if ((iPos < 1) || (iPos > iSize + 1))
    {
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iSize + 1)
    {
        DeleteLast();
    }
    else
    {
        node<T> *temp1 = NULL;
        temp1 = Head;
        node<T> *temp2 = NULL;

        int iCnt = 0;
        for (iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp1->next->next;
        delete temp2;
    }
}

// Display

template <class T>
void SinglyLL<T>::Display()
{
    node<T> *temp = NULL;
    temp = Head;

    while (temp != NULL)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Count
template <class T>
int SinglyLL<T>::Count()
{
    node<T> *temp = NULL;
    temp = Head;
    int iCnt = 0;

    while (temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

//////////////////////////////////////////////////////////////
/////Singly Circular Linked List
//////////////////////////////////////////////////////////////
template <class T>
class SinglyCLL
{
private:
    node<T> *Head;
    node<T> *Tail;

public:
    SinglyCLL();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
    void Display();
    int Count();
};

// Constructor

template <class T>
SinglyCLL<T>::SinglyCLL()
{
    Head = NULL;
    Tail = NULL;
}

// Insert First
template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if ((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
    Tail->next = Head;
}

// Insert Last
template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if ((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        Tail = newn;
    }
    Tail->next = Head;
}

// Insert At Position

template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int iPos)
{
    int Size = Count();

    if ((iPos < 1) || (iPos > Size + 1))
    {
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == Size + 1)
    {
        InsertLast(no);
    }
    else
    {
        node<T> *newn = NULL;
        newn = new node<T>;

        newn->data = no;
        newn->next = NULL;

        node<T> *temp = Head;
        int iCnt = 0;
        for (iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next = newn;
    }
}

// Delete First
template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if (Head == NULL && Tail == NULL)
    {
        return;
    }
    else if (Head == Tail)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Tail->next;
        Tail->next = Head;
    }
}

// Delete Last
template <class T>
void SinglyCLL<T>::DeleteLast()
{
    if (Head == NULL && Tail == NULL)
    {
        return;
    }
    else if (Head == Tail)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        node<T> *temp = Head;

        while (temp->next != Tail)
        {
            temp = temp->next;
        }
        delete Tail;
        Tail = temp;
        Tail->next = Head;
    }
}

// Delete at position
template <class T>
void SinglyCLL<T>::DeleteAtPos(int iPos)
{
    int Size = Count();

    if ((iPos < 1) || (iPos > Size))
    {
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == Size)
    {
        DeleteLast();
    }
    else
    {
        node<T> *temp1 = Head;
        node<T> *temp2 = NULL;

        int iCnt = 0;

        for (iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp1 = temp1->next;
        }
        temp2 = temp1->next;
        temp1->next = temp1->next->next;
        delete temp2;
    }
}

// Display
template <class T>
void SinglyCLL<T>::Display()
{
    node<T> *temp = NULL;
    temp = Head;
    if (Head == NULL && Tail == NULL)
    {
        return;
    }

    do
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;

    } while (temp != Head);

    cout << "|NULL|" << endl;
}

// Count
template <class T>
int SinglyCLL<T>::Count()
{
    int iCnt = 0;
    node<T> *temp = NULL;
    temp = Head;
    if (Head == NULL && Tail == NULL)
    {
        return 0;
    }

    do
    {
        iCnt++;
        temp = temp->next;

    } while (temp != Head);
    return iCnt;
}
////////////////////////////////////////////////////////////
// Doubly Linear Linked List
///////////////////////////////////////////////////////////
template <class T>
class DoublyLL
{
private:
    node1<T> *Head;
    node1<T> *Tail;

public:
    DoublyLL();

    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);

    int Count();
    void Display();
};

// Constructor
template <class T>
DoublyLL<T>::DoublyLL()
{
    Head = NULL;
    Tail = NULL;
}

// Insert First
template <class T>
void DoublyLL<T>::InsertFirst(T no)
{
    node1<T> *newn = NULL;

    newn = new node1<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        Head->prev = newn;
        newn->next = Head;
        Head = newn;
    }
}

// Insert Last
template <class T>
void DoublyLL<T>::InsertLast(T no)
{
    node1<T> *newn = NULL;
    newn = new node1<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }

    else
    {
        node1<T> *temp = Head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
}
// Insert At Position
template <class T>
void DoublyLL<T>::InsertAtPos(T no, int iPos)
{
    int iSize = 0;
    iSize = Count();

    if ((iPos < 1) || (iPos > iSize + 1))
    {
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(no);
    }
    else if (iPos == iSize + 1)
    {
        InsertLast(no);
    }
    else
    {
        int iCnt = 0;
        node1<T> *temp = Head;
        node1<T> *newn = new node1<T>;

        // newn=new node1<T>;

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
    }
}

// Delete First
template <class T>
void DoublyLL<T>::DeleteFirst()
{
    if (Head == NULL)
    {
        return;
    }

    if (Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }

    else
    {
        Head = Head->next;

        delete Head->prev;

        Head->prev = NULL;
    }
}

// Delete Last
template <class T>
void DoublyLL<T>::DeleteLast()
{
    node1<T> *temp = NULL;
    temp = Head;

    if (Head == NULL)
    {
        return;
    }

    if (Head->next == NULL)
    {
        delete Head;
        Head = NULL;
    }
    else
    {

        delete temp->next;
        temp->next = NULL;
    }
}

// Delete At Position

template <class T>
void DoublyLL<T>::DeleteAtPos(int iPos)
{
    int iSize = 0;
    iSize = Count();

    if ((iPos < 1) || (iPos > iSize))
    {
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == iSize)
    {
        DeleteLast();
    }
    else
    {
        int iCnt = 0;
        node1<T> *temp = Head;

        for (iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;

        delete (temp->next->prev);

        temp->next->prev = temp;
    }
}

// Display
template <class T>
void DoublyLL<T>::Display()
{
    node1<T> *temp = Head;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Count
template <class T>
int DoublyLL<T>::Count()
{
    node1<T> *temp = Head;
    int iCnt = 0;

    while (temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

////////////////////////////////////////////////////////////
//////Doubly Circular Linked List
////////////////////////////////////////////////////////////
template <class T>
class DoublyCLL
{
private:
    int no;
    node1<T> *Head;
    node1<T> *Tail;
    int Countnode;

public:
    DoublyCLL();
    void InsertFirst(T no);
    void InsertLast(T no);
    void InsertAtPos(T no, int iPos);

    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int iPos);
    int Count();
    void Display();
};

// constructor
template <class T>
DoublyCLL<T>::DoublyCLL()
{
    Head = NULL;
    Tail = NULL;
    Countnode = 0;
}

// Insert First
template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    node1<T> *newn = NULL;
    newn = new node1<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }

    else
    {
        newn->next = Head;
        Head->prev = newn;
        Head = newn;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Countnode++;
}

// InsertLast
template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    node1<T> *newn = NULL;
    newn = new node1<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if ((Head == NULL) && (Tail == NULL))
    {
        Head = newn;
        Tail = newn;
    }
    else
    {
        Tail->next = newn;
        newn->prev = Tail;
        Tail = newn;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Countnode++;
}

// Insert At Position
template <class T>
void DoublyCLL<T>::InsertAtPos(T iNo, int iPos)
{
    if ((iPos < 1) || (iPos > Countnode + 1))
    {
        cout << "Invalid position\n";
        return;
    }

    if (iPos == 1)
    {
        InsertFirst(iNo);
    }
    else if (iPos == Countnode + 1)
    {
        InsertLast(iNo);
    }
    else
    {
        node1<T> *newn = NULL;
        newn = new node1<T>;

        newn->data = iNo;
        newn->next = NULL;
        newn->prev = NULL;

        node1<T> *temp = Head;

        for (int i = 1; i < iPos - 1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;

        Countnode++;
    }
}

// Delete First
template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if (Countnode == 0)
    {
        return;
    }

    if (Countnode == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Head = Head->next;
        delete Tail->next;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Countnode--;
}

// Delete Last

template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if (Countnode == 0)
    {
        return;
    }

    if (Countnode == 1)
    {
        delete Head;
        Head = NULL;
        Tail = NULL;
    }
    else
    {
        Tail = Tail->prev;
        delete Head->prev;
    }
    Head->prev = Tail;
    Tail->next = Head;

    Countnode--;
}

// Delete At Position
template <class T>
void DoublyCLL<T>::DeleteAtPos(int iPos)
{

    if ((iPos < 1) || (iPos > Countnode + 1))
    {
        return;
    }

    if (iPos == 1)
    {
        DeleteFirst();
    }
    else if (iPos == Countnode)
    {
        DeleteLast();
    }

    else
    {
        node1<T> *temp = Head;
        for (int iCnt = 1; iCnt < iPos - 1; iCnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        Countnode--;
    }
}

// Display
template <class T>

void DoublyCLL<T>::Display()
{
    node1<T> *temp = Head;
    int iCnt = 0;
    for (iCnt = 1; iCnt <= Countnode; iCnt++)
    {
        cout << "|" << temp->data << "|->";
        temp = temp->next;
    }
    cout << "NULL\n";
}

// Count
template <class T>
int DoublyCLL<T>::Count()
{
    return Countnode;
}

//////////////////////////////////////////////
/// Queue
//////////////////////////////////////////////

template <class T>
class Queue
{
private:
    node<T> *Head;

public:
    Queue();
    void Enqueue(T no);
    void Dequeue();
    void Display();
    int Count();
};

// Constructor
template <class T>
Queue<T>::Queue()
{
    Head = NULL;
}

// Enqueue
template <class T>
void Queue<T>::Enqueue(T no) // InsertLast SinglyLinkedlist
{
    node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }

    else
    {
        node<T> *temp = Head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
}

// Dequeue
template <class T>

void Queue<T>::Dequeue()
{
    node<T> *temp = NULL;

    if (Head == NULL)
    {
        return;
    }

    temp = Head;
    Head = Head->next;
    delete temp;
}

// Display
template <class T>
void Queue<T>::Display()
{
    node<T> *temp = Head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Count
template <class T>
int Queue<T>::Count()
{
    node<T> *temp = Head;
    int iCnt = 0;
    while (temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

///////////////////////////////////////////////////////
// Stack
//////////////////////////////////////////////////////
template <class T>
class Stack
{
private:
    node<T> *Head;

public:
    Stack();
    void Push(T no);
    void Pop();
    void Display();
    int Count();
};

// Constructor
template <class T>
Stack<T>::Stack()
{
    Head = NULL;
}

// Push
template <class T>
void Stack<T>::Push(T no)
{
    node<T> *newn = NULL;
    newn = new node<T>;

    newn->data = no;
    newn->next = NULL;

    if (Head == NULL)
    {
        Head = newn;
    }
    else
    {
        newn->next = Head;
        Head = newn;
    }
}

// Pop
template <class T>
void Stack<T>::Pop()
{
    node<T> *temp = NULL;

    if (Head == NULL)
    {
        return;
    }
    temp = Head;
    Head = Head->next;
    delete temp;
}

// Display
template <class T>
void Stack<T>::Display()
{
    node<T> *temp = NULL;
    temp = Head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
// Count
template <class T>

int Stack<T>::Count()
{
    node<T> *temp = NULL;
    temp = Head;
    int iCnt = 0;

    while (temp != NULL)
    {
        iCnt++;
        temp = temp->next;
    }
    return iCnt;
}

///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
/////Main Function
/////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////

int main()
{
    int iChoice = 1;
    int iChoice1 = 1;
    int iChoice2 = 1;

    int iPos = 0;
    int iRet = 0;
    float fRet = 0.0f;
    char cRet = '\0';
    double dRet = 0.0f;

    int iValue = 0;
    float iValue2 = 0.0f;
    char iValue3 = '\0';
    double iValue4 = 0.0f;

    //_________________
    while (iChoice1 != 0)
    {

        cout << "**************************************************************\n";
        cout << "Enter your Generic Data structure Choice \n";
        cout << "1: Singly Linear LinkedList\n";
        cout << "2: Doubly Linear LinkedList\n";
        cout << "3: Singly Circular Linear LinkedList\n";
        cout << "4: Doubly Circular LinkedList\n";
        cout << "5: QUEUE\n";
        cout << "6: STACK\n";
        cout << "0: Terminate the Program \n";
        cout << "**************************************************************\n";
        cin >> iChoice1;

        //-------------
        switch (iChoice1)
        {

        case 1:
        {

            while (iChoice2 != 0)
            {

                cout << "Enter the Data type for your Singly LinkedList\n";
                cout << "1: INTEGER \n";

                cout << "2: FLOAT \n";

                cout << "3: CHARACTER \n";

                cout << "4: DOUBLE \n";

                cout << "0: TERMINATE\n";
                cout << "----------------------------------------------------------\n";

                cin >> iChoice2;

                switch (iChoice2)
                {

                case 1:
                {
                    SinglyLL<int> SLobj1;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Insert your data At First \n";
                        cout << "2 : Insert your data At Last \n";
                        cout << "3 : Insert your data At Given Position \n";
                        cout << "4 : Delete your data At First \n";
                        cout << "5 : Delete your data At Last \n";
                        cout << "6 : Delete your data At Given Position \n";
                        cout << "7 : Display the data from your LinkedList \n";
                        cout << "8 : Count the elements from your LinkedList \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue;
                            SLobj1.InsertFirst(iValue);
                            break;

                        case 2:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue;
                            SLobj1.InsertLast(iValue);
                            break;

                        case 3:
                            cout << "Enter your data for Insertion\n";
                            cin >> iValue;
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            SLobj1.InsertAtPos(iValue, iPos);
                            break;

                        case 4:
                            SLobj1.DeleteFirst();
                            break;

                        case 5:
                            SLobj1.DeleteLast();
                            break;

                        case 6:
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            SLobj1.DeleteAtPos(iPos);
                            break;

                        case 7:
                            cout << "Elements from  your LinkedList is :\n";
                            SLobj1.Display();
                            break;

                        case 8:
                            iRet = SLobj1.Count();
                            cout << "Count of your elements from LinkedList is " << iRet << "\n";
                            break;

                        case 0:
                            cout << "Thankyou for using Generic Singly Linear LinkedList\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;

                case 2:
                {
                    SinglyLL<float> SLobj2;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Insert your data At First \n";
                        cout << "2 : Insert your data At Last \n";
                        cout << "3 : Insert your data At Given Position \n";
                        cout << "4 : Delete your data At First \n";
                        cout << "5 : Delete your data At Last \n";
                        cout << "6 : Delete your data At Given Position \n";
                        cout << "7 : Display the data from your LinkedList \n";
                        cout << "8 : Count the elements from your LinkedList \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue2;
                            SLobj2.InsertFirst(iValue2);
                            break;

                        case 2:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue2;
                            SLobj2.InsertLast(iValue2);
                            break;

                        case 3:
                            cout << "Enter your data for Insertion\n";
                            cin >> iValue2;
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            SLobj2.InsertAtPos(iValue2, iPos);
                            break;

                        case 4:
                            SLobj2.DeleteFirst();
                            break;

                        case 5:
                            SLobj2.DeleteLast();
                            break;

                        case 6:
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            SLobj2.DeleteAtPos(iPos);
                            break;

                        case 7:
                            cout << "Elements from  your LinkedList is :\n";
                            SLobj2.Display();
                            break;

                        case 8:
                            fRet = SLobj2.Count();
                            cout << "Count of your elements from LinkedList is" << fRet << "\n";
                            break;

                        case 0:
                            cout << "Thankyou for using Generic Singly Linear LinkedList\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;
                case 3:
                {
                    SinglyLL<char> SLobj3;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Insert your data At First \n";
                        cout << "2 : Insert your data At Last \n";
                        cout << "3 : Insert your data At Given Position \n";
                        cout << "4 : Delete your data At First \n";
                        cout << "5 : Delete your data At Last \n";
                        cout << "6 : Delete your data At Given Position \n";
                        cout << "7 : Display the data from your LinkedList \n";
                        cout << "8 : Count the elements from your LinkedList \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue3;
                            SLobj3.InsertFirst(iValue3);
                            break;

                        case 2:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue3;
                            SLobj3.InsertLast(iValue3);
                            break;

                        case 3:
                            cout << "Enter your data for Insertion\n";
                            cin >> iValue3;
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            SLobj3.InsertAtPos(iValue3, iPos);
                            break;

                        case 4:
                            SLobj3.DeleteFirst();
                            break;

                        case 5:
                            SLobj3.DeleteLast();
                            break;

                        case 6:
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            SLobj3.DeleteAtPos(iPos);
                            break;

                        case 7:
                            cout << "Elements from  your LinkedList is :\n";
                            SLobj3.Display();
                            break;

                        case 8:
                            cRet = SLobj3.Count();
                            cout << "Count of your elements from LinkedList is" << cRet << "\n";
                            break;

                        case 0:
                            cout << "Thankyou for using Generic Singly Linear LinkedList\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;
                case 4:
                {
                    SinglyLL<double> SLobj4;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Insert your data At First \n";
                        cout << "2 : Insert your data At Last \n";
                        cout << "3 : Insert your data At Given Position \n";
                        cout << "4 : Delete your data At First \n";
                        cout << "5 : Delete your data At Last \n";
                        cout << "6 : Delete your data At Given Position \n";
                        cout << "7 : Display the data from your LinkedList \n";
                        cout << "8 : Count the elements from your LinkedList \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue4;
                            SLobj4.InsertFirst(iValue4);
                            break;

                        case 2:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue4;
                            SLobj4.InsertLast(iValue4);
                            break;

                        case 3:
                            cout << "Enter your data for Insertion\n";
                            cin >> iValue4;
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            SLobj4.InsertAtPos(iValue4, iPos);
                            break;

                        case 4:
                            SLobj4.DeleteFirst();
                            break;

                        case 5:
                            SLobj4.DeleteLast();
                            break;

                        case 6:
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            SLobj4.DeleteAtPos(iPos);
                            break;

                        case 7:
                            cout << "Elements from  your LinkedList is :\n";
                            SLobj4.Display();
                            break;

                        case 8:
                            dRet = SLobj4.Count();
                            cout << "Count of your elements from LinkedList is " << dRet << "\n";
                            break;

                        case 0:
                            cout << "Thankyou for using Generic Singly Linear LinkedList\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }

                break;
                }
            }
        }
        break;

        case 2:
        {

            while (iChoice2 != 0)
            {
                cout << "Enter the Data type for your Doubly LinkedList\n";
                cout << "1: INTEGER \n";

                cout << "2: FLOAT \n";

                cout << "3: CHARACTER \n";

                cout << "4: DOUBLE \n";

                cout << "0: TERMINATE\n";

                cout << "----------------------------------------------------------\n";

                cin >> iChoice2;

                switch (iChoice2)
                {

                case 1:
                {
                    DoublyLL<int> DLobj1;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Insert your data At First \n";
                        cout << "2 : Insert your data At Last \n";
                        cout << "3 : Insert your data At Given Position \n";
                        cout << "4 : Delete your data At First \n";
                        cout << "5 : Delete your data At Last \n";
                        cout << "6 : Delete your data At Given Position \n";
                        cout << "7 : Display the data from your LinkedList \n";
                        cout << "8 : Count the elements from your LinkedList \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue;
                            DLobj1.InsertFirst(iValue);
                            break;

                        case 2:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue;
                            DLobj1.InsertLast(iValue);
                            break;

                        case 3:
                            cout << "Enter your data for Insertion\n";
                            cin >> iValue;
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            DLobj1.InsertAtPos(iValue, iPos);
                            break;

                        case 4:
                            DLobj1.DeleteFirst();
                            break;

                        case 5:
                            DLobj1.DeleteLast();
                            break;

                        case 6:
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            DLobj1.DeleteAtPos(iPos);
                            break;

                        case 7:
                            cout << "Elements from  your LinkedList is :\n";
                            DLobj1.Display();
                            break;

                        case 8:
                            iRet = DLobj1.Count();
                            cout << "Count of your elements from LinkedList is " << iRet << "\n";
                            break;

                        case 0:
                            cout << "Thankyou for using Generic Doubly Linear LinkedList\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;

                case 2:
                {
                    DoublyLL<float> DLobj2;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Insert your data At First \n";
                        cout << "2 : Insert your data At Last \n";
                        cout << "3 : Insert your data At Given Position \n";
                        cout << "4 : Delete your data At First \n";
                        cout << "5 : Delete your data At Last \n";
                        cout << "6 : Delete your data At Given Position \n";
                        cout << "7 : Display the data from your LinkedList \n";
                        cout << "8 : Count the elements from your LinkedList \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue2;
                            DLobj2.InsertFirst(iValue2);
                            break;

                        case 2:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue2;
                            DLobj2.InsertLast(iValue2);
                            break;

                        case 3:
                            cout << "Enter your data for Insertion\n";
                            cin >> iValue2;
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            DLobj2.InsertAtPos(iValue2, iPos);
                            break;

                        case 4:
                            DLobj2.DeleteFirst();
                            break;

                        case 5:
                            DLobj2.DeleteLast();
                            break;

                        case 6:
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            DLobj2.DeleteAtPos(iPos);
                            break;

                        case 7:
                            cout << "Elements from  your LinkedList is :\n";
                            DLobj2.Display();
                            break;

                        case 8:
                            fRet = DLobj2.Count();
                            cout << "Count of your elements from LinkedList is " << fRet << "\n";
                            break;

                        case 0:
                            cout << "Thankyou for using Generic Doubly Linear LinkedList\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;
                case 3:
                {
                    DoublyLL<char> DLobj3;

                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Insert your data At First \n";
                        cout << "2 : Insert your data At Last \n";
                        cout << "3 : Insert your data At Given Position \n";
                        cout << "4 : Delete your data At First \n";
                        cout << "5 : Delete your data At Last \n";
                        cout << "6 : Delete your data At Given Position \n";
                        cout << "7 : Display the data from your LinkedList \n";
                        cout << "8 : Count the elements from your LinkedList \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue3;
                            DLobj3.InsertFirst(iValue3);
                            break;

                        case 2:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue3;
                            DLobj3.InsertLast(iValue3);
                            break;

                        case 3:
                            cout << "Enter your data for Insertion\n";
                            cin >> iValue3;
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            DLobj3.InsertAtPos(iValue3, iPos);
                            break;

                        case 4:
                            DLobj3.DeleteFirst();
                            break;

                        case 5:
                            DLobj3.DeleteLast();
                            break;

                        case 6:
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            DLobj3.DeleteAtPos(iPos);
                            break;

                        case 7:
                            cout << "Elements from  your LinkedList is :\n";
                            DLobj3.Display();
                            break;

                        case 8:
                            cRet = DLobj3.Count();
                            cout << "Count of your elements from LinkedList is " << cRet << "\n";
                            break;

                        case 0:
                            cout << "Thankyou for using Generic Doubly Linear LinkedList\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;
                case 4:
                {
                    DoublyLL<double> DLobj4;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Insert your data At First \n";
                        cout << "2 : Insert your data At Last \n";
                        cout << "3 : Insert your data At Given Position \n";
                        cout << "4 : Delete your data At First \n";
                        cout << "5 : Delete your data At Last \n";
                        cout << "6 : Delete your data At Given Position \n";
                        cout << "7 : Display the data from your LinkedList \n";
                        cout << "8 : Count the elements from your LinkedList \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue4;
                            DLobj4.InsertFirst(iValue4);
                            break;

                        case 2:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue4;
                            DLobj4.InsertLast(iValue4);
                            break;

                        case 3:
                            cout << "Enter your data for Insertion\n";
                            cin >> iValue4;
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            DLobj4.InsertAtPos(iValue4, iPos);
                            break;

                        case 4:
                            DLobj4.DeleteFirst();
                            break;

                        case 5:
                            DLobj4.DeleteLast();
                            break;

                        case 6:
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            DLobj4.DeleteAtPos(iPos);
                            break;

                        case 7:
                            cout << "Elements from  your LinkedList is :\n";
                            DLobj4.Display();
                            break;

                        case 8:
                            dRet = DLobj4.Count();
                            cout << "Count of your elements from LinkedList is " << dRet << "\n";
                            break;

                        case 0:
                            cout << "Thankyou for using Generic Doubly Linear LinkedList\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;
                }
            }
        }
        break;

        case 3:
        {

            while (iChoice2 != 0)
            {
                cout << "Enter the Data type for your Singly  Circular LinkedList\n";
                cout << "1: INTEGER \n";

                cout << "2: FLOAT \n";

                cout << "3: CHARACTER \n";

                cout << "4: DOUBLE \n";

                cout << "0: TERMINATE\n";

                cout << "----------------------------------------------------------\n";

                cin >> iChoice2;

                switch (iChoice2)
                {

                case 1:
                {
                    SinglyCLL<int> SCobj1;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Insert your data At First \n";
                        cout << "2 : Insert your data At Last \n";
                        cout << "3 : Insert your data At Given Position \n";
                        cout << "4 : Delete your data At First \n";
                        cout << "5 : Delete your data At Last \n";
                        cout << "6 : Delete your data At Given Position \n";
                        cout << "7 : Display the data from your LinkedList \n";
                        cout << "8 : Count the elements from your LinkedList \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue;
                            SCobj1.InsertFirst(iValue);
                            break;

                        case 2:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue;
                            SCobj1.InsertLast(iValue);
                            break;

                        case 3:
                            cout << "Enter your data for Insertion\n";
                            cin >> iValue;
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            SCobj1.InsertAtPos(iValue, iPos);
                            break;

                        case 4:
                            SCobj1.DeleteFirst();
                            break;

                        case 5:
                            SCobj1.DeleteLast();
                            break;

                        case 6:
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            SCobj1.DeleteAtPos(iPos);
                            break;

                        case 7:
                            cout << "Elements from  your LinkedList is :\n";
                            SCobj1.Display();
                            break;

                        case 8:
                            iRet = SCobj1.Count();
                            cout << "Count of your elements from LinkedList is " << iRet << "\n";
                            break;

                        case 0:
                            cout << "Thankyou for using Generic Singly Circular LinkedList\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;

                case 2:
                {
                    SinglyCLL<float> SCobj2;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Insert your data At First \n";
                        cout << "2 : Insert your data At Last \n";
                        cout << "3 : Insert your data At Given Position \n";
                        cout << "4 : Delete your data At First \n";
                        cout << "5 : Delete your data At Last \n";
                        cout << "6 : Delete your data At Given Position \n";
                        cout << "7 : Display the data from your LinkedList \n";
                        cout << "8 : Count the elements from your LinkedList \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue2;
                            SCobj2.InsertFirst(iValue2);
                            break;

                        case 2:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue2;
                            SCobj2.InsertLast(iValue2);
                            break;

                        case 3:
                            cout << "Enter your data for Insertion\n";
                            cin >> iValue2;
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            SCobj2.InsertAtPos(iValue2, iPos);
                            break;

                        case 4:
                            SCobj2.DeleteFirst();
                            break;

                        case 5:
                            SCobj2.DeleteLast();
                            break;

                        case 6:
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            SCobj2.DeleteAtPos(iPos);
                            break;

                        case 7:
                            cout << "Elements from  your LinkedList is :\n";
                            SCobj2.Display();
                            break;

                        case 8:
                            fRet = SCobj2.Count();
                            cout << "Count of your elements from LinkedList is " << fRet << "\n";
                            break;

                        case 0:
                            cout << "Thankyou for using Generic Singly Circular LinkedList\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;
                case 3:
                {
                    SinglyCLL<char> SCobj3;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Insert your data At First \n";
                        cout << "2 : Insert your data At Last \n";
                        cout << "3 : Insert your data At Given Position \n";
                        cout << "4 : Delete your data At First \n";
                        cout << "5 : Delete your data At Last \n";
                        cout << "6 : Delete your data At Given Position \n";
                        cout << "7 : Display the data from your LinkedList \n";
                        cout << "8 : Count the elements from your LinkedList \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue3;
                            SCobj3.InsertFirst(iValue3);
                            break;

                        case 2:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue3;
                            SCobj3.InsertLast(iValue3);
                            break;

                        case 3:
                            cout << "Enter your data for Insertion\n";
                            cin >> iValue3;
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            SCobj3.InsertAtPos(iValue3, iPos);
                            break;

                        case 4:
                            SCobj3.DeleteFirst();
                            break;

                        case 5:
                            SCobj3.DeleteLast();
                            break;

                        case 6:
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            SCobj3.DeleteAtPos(iPos);
                            break;

                        case 7:
                            cout << "Elements from  your LinkedList is :\n";
                            SCobj3.Display();
                            break;

                        case 8:
                            cRet = SCobj3.Count();
                            cout << "Count of your elements from LinkedList is " << cRet << "\n";
                            break;

                        case 0:
                            cout << "Thankyou for using Generic Singly Circular LinkedList\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;
                case 4:
                {
                    SinglyCLL<double> SCobj4;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Insert your data At First \n";
                        cout << "2 : Insert your data At Last \n";
                        cout << "3 : Insert your data At Given Position \n";
                        cout << "4 : Delete your data At First \n";
                        cout << "5 : Delete your data At Last \n";
                        cout << "6 : Delete your data At Given Position \n";
                        cout << "7 : Display the data from your LinkedList \n";
                        cout << "8 : Count the elements from your LinkedList \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue4;
                            SCobj4.InsertFirst(iValue4);
                            break;

                        case 2:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue4;
                            SCobj4.InsertLast(iValue4);
                            break;

                        case 3:
                            cout << "Enter your data for Insertion\n";
                            cin >> iValue4;
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            SCobj4.InsertAtPos(iValue4, iPos);
                            break;

                        case 4:
                            SCobj4.DeleteFirst();
                            break;

                        case 5:
                            SCobj4.DeleteLast();
                            break;

                        case 6:
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            SCobj4.DeleteAtPos(iPos);
                            break;

                        case 7:
                            cout << "Elements from  your LinkedList is :\n";
                            SCobj4.Display();
                            break;

                        case 8:
                            dRet = SCobj4.Count();
                            cout << "Count of your elements from LinkedList is " << dRet << "\n";
                            break;

                        case 0:
                            cout << "Thankyou for using Generic Singly Circular LinkedList\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;
                }
            }
        }
        break;

        case 4:
        {

            while (iChoice2 != 0)
            {
                cout << "Enter the Data type for your Doubly Circular LinkedList\n";
                cout << "1: INTEGER \n";

                cout << "2: FLOAT \n";

                cout << "3: CHARACTER \n";

                cout << "4: DOUBLE \n";

                cout << "0: TERMINATE\n";

                cout << "----------------------------------------------------------\n";

                cin >> iChoice2;

                switch (iChoice2)
                {

                case 1:
                {
                    DoublyCLL<int> DCobj1;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Insert your data At First \n";
                        cout << "2 : Insert your data At Last \n";
                        cout << "3 : Insert your data At Given Position \n";
                        cout << "4 : Delete your data At First \n";
                        cout << "5 : Delete your data At Last \n";
                        cout << "6 : Delete your data At Given Position \n";
                        cout << "7 : Display the data from your LinkedList \n";
                        cout << "8 : Count the elements from your LinkedList \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue;
                            DCobj1.InsertFirst(iValue);
                            break;

                        case 2:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue;
                            DCobj1.InsertLast(iValue);
                            break;

                        case 3:
                            cout << "Enter your data for Insertion\n";
                            cin >> iValue;
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            DCobj1.InsertAtPos(iValue, iPos);
                            break;

                        case 4:
                            DCobj1.DeleteFirst();
                            break;

                        case 5:
                            DCobj1.DeleteLast();
                            break;

                        case 6:
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            DCobj1.DeleteAtPos(iPos);
                            break;

                        case 7:
                            cout << "Elements from  your LinkedList is :\n";
                            DCobj1.Display();
                            break;

                        case 8:
                            iRet = DCobj1.Count();
                            cout << "Count of your elements from LinkedList is " << iRet << "\n";
                            break;

                        case 0:
                            cout << "Thankyou for using Generic Doubly Circular LinkedList\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;

                case 2:
                {
                    DoublyCLL<float> DCobj2;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Insert your data At First \n";
                        cout << "2 : Insert your data At Last \n";
                        cout << "3 : Insert your data At Given Position \n";
                        cout << "4 : Delete your data At First \n";
                        cout << "5 : Delete your data At Last \n";
                        cout << "6 : Delete your data At Given Position \n";
                        cout << "7 : Display the data from your LinkedList \n";
                        cout << "8 : Count the elements from your LinkedList \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue2;
                            DCobj2.InsertFirst(iValue2);
                            break;

                        case 2:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue2;
                            DCobj2.InsertLast(iValue2);
                            break;

                        case 3:
                            cout << "Enter your data for Insertion\n";
                            cin >> iValue2;
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            DCobj2.InsertAtPos(iValue2, iPos);
                            break;

                        case 4:
                            DCobj2.DeleteFirst();
                            break;

                        case 5:
                            DCobj2.DeleteLast();
                            break;

                        case 6:
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            DCobj2.DeleteAtPos(iPos);
                            break;

                        case 7:
                            cout << "Elements from  your LinkedList is :\n";
                            DCobj2.Display();
                            break;

                        case 8:
                            fRet = DCobj2.Count();
                            cout << "Count of your elements from LinkedList is " << fRet << "\n";
                            break;

                        case 0:
                            cout << "Thankyou for using Generic Doubly Circular LinkedList\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;
                case 3:
                {
                    DoublyCLL<char> DCobj3;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Insert your data At First \n";
                        cout << "2 : Insert your data At Last \n";
                        cout << "3 : Insert your data At Given Position \n";
                        cout << "4 : Delete your data At First \n";
                        cout << "5 : Delete your data At Last \n";
                        cout << "6 : Delete your data At Given Position \n";
                        cout << "7 : Display the data from your LinkedList \n";
                        cout << "8 : Count the elements from your LinkedList \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue3;
                            DCobj3.InsertFirst(iValue3);
                            break;

                        case 2:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue3;
                            DCobj3.InsertLast(iValue3);
                            break;

                        case 3:
                            cout << "Enter your data for Insertion\n";
                            cin >> iValue3;
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            DCobj3.InsertAtPos(iValue3, iPos);
                            break;

                        case 4:
                            DCobj3.DeleteFirst();
                            break;

                        case 5:
                            DCobj3.DeleteLast();
                            break;

                        case 6:
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            DCobj3.DeleteAtPos(iPos);
                            break;

                        case 7:
                            cout << "Elements from  your LinkedList is :\n";
                            DCobj3.Display();
                            break;

                        case 8:
                            cRet = DCobj3.Count();
                            cout << "Count of your elements from LinkedList is " << cRet << "\n";
                            break;

                        case 0:
                            cout << "Thankyou for using Generic Doubly Circular LinkedList\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;
                case 4:
                {

                    DoublyCLL<double> DCobj4;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Insert your data At First \n";
                        cout << "2 : Insert your data At Last \n";
                        cout << "3 : Insert your data At Given Position \n";
                        cout << "4 : Delete your data At First \n";
                        cout << "5 : Delete your data At Last \n";
                        cout << "6 : Delete your data At Given Position \n";
                        cout << "7 : Display the data from your LinkedList \n";
                        cout << "8 : Count the elements from your LinkedList \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue4;
                            DCobj4.InsertFirst(iValue4);
                            break;

                        case 2:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue4;
                            DCobj4.InsertLast(iValue4);
                            break;

                        case 3:
                            cout << "Enter your data for Insertion\n";
                            cin >> iValue4;
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            DCobj4.InsertAtPos(iValue4, iPos);
                            break;

                        case 4:
                            DCobj4.DeleteFirst();
                            break;

                        case 5:
                            DCobj4.DeleteLast();
                            break;

                        case 6:
                            cout << "Enter your Position\n";
                            cin >> iPos;
                            DCobj4.DeleteAtPos(iPos);
                            break;

                        case 7:
                            cout << "Elements from  your LinkedList is :\n";
                            DCobj4.Display();
                            break;

                        case 8:
                            dRet = DCobj4.Count();
                            cout << "Count of your elements from LinkedList is " << dRet << "\n";
                            break;

                        case 0:
                            cout << "Thankyou for using Generic Doubly Circular LinkedList\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }

                break;
                }
            }
        }
        break;

        case 5:
        {

            while (iChoice2 != 0)
            {
                cout << "Enter the Data type for your Queue\n";

                cout << "1: INTEGER \n";

                cout << "2: FLOAT \n";

                cout << "3: CHARACTER \n";

                cout << "4: DOUBLE \n";

                cout << "0: TERMINATE\n";

                cout << "----------------------------------------------------------\n";

                cin >> iChoice2;

                switch (iChoice2)
                {

                case 1:
                {
                    Queue<int> Qobj1;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Enqueue\n";
                        cout << "2 : Dequeue \n";
                        cout << "3 : Display the data from your Queue \n";
                        cout << "4 : Count the elements from your Queue \n";
                        cout << "0 : Terminate your LinkedList \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue;
                            Qobj1.Enqueue(iValue);
                            break;

                        case 2:

                            Qobj1.Dequeue();
                            break;

                        case 3:

                            cout << "Elements from  your LinkedList is :\n";
                            Qobj1.Display();
                            break;

                        case 4:

                            iRet = Qobj1.Count();
                            cout << "Count of your elements from LinkedList is " << iRet << "\n";
                            break;

                            cout << "Thankyou for using Generic Queue\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;

                case 2:
                {
                    Queue<float> Qobj2;

                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Enqueue\n";
                        cout << "2 : Dequeue \n";
                        cout << "3 : Display the data from your Queue \n";
                        cout << "4 : Count the elements from your Queue \n";
                        cout << "0 : Terminate your Queue \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue2;
                            Qobj2.Enqueue(iValue2);
                            break;

                        case 2:

                            Qobj2.Dequeue();

                            break;

                        case 3:

                            cout << "Elements from  your Queue is :\n";
                            Qobj2.Display();
                            break;

                        case 4:

                            iRet = Qobj2.Count();
                            cout << "Count of your elements from Queue is " << iRet << "\n";
                            break;

                            cout << "Thankyou for using Generic Queue\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;
                case 3:
                {
                    Queue<char> Qobj3;

                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Enqueue\n";
                        cout << "2 : Dequeue \n";
                        cout << "3 : Display the data from your Queue \n";
                        cout << "4 : Count the elements from your Queue \n";
                        cout << "0 : Terminate your Queue \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue3;
                            Qobj3.Enqueue(iValue3);
                            break;

                        case 2:

                            Qobj3.Dequeue();

                            break;

                        case 3:

                            cout << "Elements from  your Queue is :\n";
                            Qobj3.Display();
                            break;

                        case 4:

                            iRet = Qobj3.Count();
                            cout << "Count of your elements from Queue is " << iRet << "\n";
                            break;

                            cout << "Thankyou for using Generic Queue\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;
                case 4:
                {

                    Queue<double> Qobj4;

                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : Enqueue\n";
                        cout << "2 : Dequeue \n";
                        cout << "3 : Display the data from your Queue \n";
                        cout << "4 : Count the elements from your Queue \n";
                        cout << "0 : Terminate your Queue\n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue4;
                            Qobj4.Enqueue(iValue4);
                            break;

                        case 2:

                            Qobj4.Dequeue();
                            break;

                        case 3:

                            cout << "Elements from  your Queue is :\n";
                            Qobj4.Display();
                            break;

                        case 4:

                            iRet = Qobj4.Count();
                            cout << "Count of your elements from Queue is " << iRet << "\n";
                            break;

                            cout << "Thankyou for using Generic Queue\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }

                    break;
                }
                }
            }
            break;

        case 6:
        {

            while (iChoice2 != 0)
            {
                cout << "Enter the Data type for your Stack\n";

                cout << "1: INTEGER \n";

                cout << "2: FLOAT \n";

                cout << "3: CHARACTER \n";

                cout << "4: DOUBLE \n";

                cout << "0: TERMINATE\n";

                cout << "----------------------------------------------------------\n";

                cin >> iChoice2;

                switch (iChoice2)
                {

                case 1:
                {
                    Stack<int> Sobj1;
                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : PUSH\n";
                        cout << "2 : POP \n";
                        cout << "3 : Display the data from your Stack \n";
                        cout << "4 : Count the elements from your Stack\n";
                        cout << "0 : Terminate your Stack \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue;
                            Sobj1.Push(iValue);
                            break;

                        case 2:

                            Sobj1.Pop();

                            break;

                        case 3:

                            cout << "Elements from  your Stack :\n";
                            Sobj1.Display();
                            break;

                        case 4:

                            iRet = Sobj1.Count();
                            cout << "Count of your elements from Stack is " << iRet << "\n";
                            break;

                            cout << "Thankyou for using Generic Stack\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;

                case 2:
                {
                    Stack<float> Sobj2;

                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : PUSH\n";
                        cout << "2 : POP \n";
                        cout << "3 : Display the data from your Stack \n";
                        cout << "4 : Count the elements from your Stack \n";
                        cout << "0 : Terminate your Stack \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue2;
                            Sobj2.Push(iValue2);
                            break;

                        case 2:

                            Sobj2.Pop();

                            break;

                        case 3:

                            cout << "Elements from  your Stack is :\n";
                            Sobj2.Display();
                            break;

                        case 4:

                            iRet = Sobj2.Count();
                            cout << "Count of your elements from Stack is " << iRet << "\n";
                            break;

                            cout << "Thankyou for using Generic Stack\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;
                case 3:
                {
                    Stack<char> Sobj3;

                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : PUSH\n";
                        cout << "2 : POP\n";
                        cout << "3 : Display the data from your Stack \n";
                        cout << "4 : Count the elements from your Stack \n";
                        cout << "0 : Terminate your Stack \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue3;
                            Sobj3.Push(iValue3);
                            break;

                        case 2:

                            Sobj3.Pop();

                            break;

                        case 3:

                            cout << "Elements from  your Stack is :\n";
                            Sobj3.Display();
                            break;

                        case 4:

                            iRet = Sobj3.Count();
                            cout << "Count of your elements from Stack is " << iRet << "\n";
                            break;

                            cout << "Thankyou for using Generic Stack\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }
                break;
                case 4:
                {

                    Stack<double> Sobj4;

                    while (iChoice != 0)
                    {

                        cout << "___________________________________________________\n";
                        cout << "Enter your Choice:\n";
                        cout << "1 : PUSH\n";
                        cout << "2 : POP\n";
                        cout << "3 : Display the data from your Stack \n";
                        cout << "4 : Count the elements from your Stack \n";
                        cout << "0 : Terminate your Stack \n";
                        cout << "___________________________________________________\n";
                        cin >> iChoice;

                        switch (iChoice)
                        {
                        case 1:

                            cout << "Enter your data for Insertion\n";
                            cin >> iValue4;
                            Sobj4.Push(iValue4);
                            break;

                        case 2:

                            Sobj4.Pop();
                            break;

                        case 3:

                            cout << "Elements from  your Stack is :\n";
                            Sobj4.Display();
                            break;

                        case 4:

                            iRet = Sobj4.Count();
                            cout << "Count of your elements from Stack is " << iRet << "\n";
                            break;

                            cout << "Thankyou for using Generic Stack\n";
                            break;

                        default:
                            cout << "INVALID DATA\n";
                        }
                    }
                }

                break;
                }
            }
        }
        break;
        }

        default:
            cout << "-------------------------------------------------\n";
            cout << "Thankyou for using ANUJ DALAVI's Generic Data Structures\n";
            cout << "-------------------------------------------------\n";
        }
    }

    return 0;
}