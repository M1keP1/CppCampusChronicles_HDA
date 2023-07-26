#include <iostream> 
using namespace std;
class Node
{
public:
    Node(int Value, Node *Next) : value{Value}, next{Next} {}
    Node() : Node(0, nullptr) {}
    Node *getNode()
    {
        return next;
    }
    void setNode(Node *s)
    {
        next = s;
    }
    int getValue()
    {
        return value;
    }
    void setValue(int v)
    {
        value = v;
    }
    Node *push(int v)
    {
        if (this->getValue() == 0)
        {
            this->setValue(v);
            return this;
        }
        else
        {
            Node *newnode = new Node();
            newnode->setValue(v);
            newnode->setNode(this);
            return newnode;
        }
        return this;
    }
    void pop()
    {
        if (this->next == nullptr)
        {
            this->setValue(0);
        }
        else
        {
            Node *current = this;
            while (current->next->next != nullptr)
            {
                current = current->next;
            }
            delete current->next;
            current->next = nullptr;
        }
    }

private:
    int value;
    Node *next;
};
void printall(Node *s)
{
    cout << "Die Liste: ";
    if (s->getValue() == 0)
        cout << "Ist Leer";
    else
        while (s != nullptr)
        {
            cout << s->getValue() << " ";
            s = s->getNode();
        }
    cout << endl;
}
void printMenu()
{
    cout << "-- Menu --" << endl;
    cout << "1. Push (Ablegen)" << endl;
    cout << "2. Pop (Entfernen)" << endl;
    cout << "3. Print (Alles ausgeben)" << endl;
    cout << "4. Beenden" << endl;
    cout << "-----------" << endl;
    cout << "Bitte wählen Sie eine Option: ";
}
void runMain()
{

    printMenu();
    int choice{};
    Node *head = new Node();
    cin >> choice;
    while (choice != 4)
    {
        switch (choice)
        {
        case 1:
        {
            int value{};
            cout << "Bitte gebe einen Wert ein: ";
            cin >> value;
            head = head->push(value);
            break;
        }
        case 2:
            if (head->getValue() == 0)
                cout << "Liste ist Leer" << endl;
            else
                head->pop();
            break;
        case 3:
            printall(head);
            break;
        case 4: // Beenden
            cout << "Programm wird beendet." << endl;
            break;
        default:
            cout << "Nur eine der vier Auswahlmöglichkeiten" << endl;
        }
        printMenu();
        cin >> choice;
    }
}
int main()
{
    runMain();
    return 0;
}
