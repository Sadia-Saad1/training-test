#include <iostream>
using namespace std;

class employee
{
private:
public:
    int Emp_ID;
    string Emp_Name;
    string NIC;
    int Salary;
    int Bonus;
    employee(int value_ID = 0, string value_Name = "",
             string value_NIC = "",
             int value_Salary = 0,
             int value_Bonus = 0)
    {
        Emp_ID = value_ID;
        Emp_Name = value_Name;
        NIC = value_NIC;
        Salary = value_Salary;
        Bonus = value_Bonus;
    }

    void display()
    {
        cout << "\n\nEmp_ID = \t" << Emp_ID;
        cout << "\nEmp_Name = \t" << Emp_Name;

        cout << "\nNIC = \t" << NIC;

        cout << "\nSalary = \t" << Salary;

        cout << "\nBonus = \t" << Bonus;
    }
};

class node
{

public:
    employee data;
    node *next;

    node() { next = NULL; }
    ~node();
};

node::~node()
{
}

class List
{
private:
    node *head;
    node *last;

public:
    List(/* args */)
    {
        head = NULL;
        last = NULL;
    }

    void insert(const employee &data)
    {
        node *temp = new node;
        temp->data.Emp_ID = data.Emp_ID;
        temp->data.Emp_Name = data.Emp_Name;
        temp->data.NIC = data.NIC;
        temp->data.Salary = data.Salary;
        temp->data.Bonus = data.Bonus;

        if (head == NULL && last == NULL)
        {
            head = temp;
            last = temp;
        }
        else
        {
            last->next = temp;
            last = temp;
        }
    }

    bool isEmpty()
    {
        if (head == NULL && last == NULL)
            return true;
        return false;
    }

    void display()
    {
        node *temp = head;
        while ((temp->next != NULL))
        {
            temp->data.display();
            temp = temp->next;
        }
        temp->data.display();
    }

    void remove(int id)
    {
        node *temp = head;
        if (head->data.Emp_ID == id)
        {
            temp = head->next;
            head = temp;
        }       
        else
        {   //int i = 0;
                node *prev = NULL;

            while (temp->data.Emp_ID != id && temp->next != NULL)
            {
                // cout<<endl<<i++;
                prev = temp;
                temp = temp->next;
            }
            if (temp->next)
            {
                prev->next = temp->next;
                // temp->next = prev->next;
            }
            else
            {
                prev->next = NULL;
                last = prev;
            }
        }
    }

    ~List() {}
};

int main()
{
    employee obj1;
    employee obj2(1);
    employee obj3(2);
    employee obj4(3);

    List singlyList;

    singlyList.insert(obj1);
    singlyList.insert(obj2);
    singlyList.insert(obj3);
    singlyList.insert(obj4);
    singlyList.remove(3);
    singlyList.insert(obj4);

    singlyList.display();
}
