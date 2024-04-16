#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Node {
public:
    string key;
    Node* next;
    Node()
    {
        key = " ";
        next = NULL;
    }
    Node(string k)
    {
        key = k;
        next = NULL;
    }
};

class task {
private:
    Node* head;
    Node* tail;
    int size;
public:
    task()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void insertFirst() {
        string task;

        cout << "WANT TO ADD MY FIRST TASK: " << endl;
        getline(cin, task);

        Node* temp = new Node(task);
        if (size == 0) {
            head = temp;
            tail = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }
        size++;

    }

    void insertLast() {
        string task;
        string ans;

        cout << "ADD MY TASK: " << endl; \
            getline(cin, task);


        Node* temp = new Node(task);
        if (size == 0) {
            head = temp;
            tail = temp;
        }
        else {
            tail->next = temp;
            tail = temp;
        }
        size++;
        cout << "WANT TO ADD ONE MORE TASK? y/n" << endl;
        getline(cin, ans);
        if (ans == "y" || ans == "Y") {
            insertLast();
        }


    }
    void inserAt() {
        int pos;
        string task;

        cout << "I WANT TO ADD AT : " << endl;
        cin >> pos;
        cin.ignore();



        if (pos == 1) insertFirst();

        else if (pos == size) {
            string task;
            string ans;

            cout << "ADD MY TASK: " << endl;
            getline(cin, task);


            Node* temp = new Node(task);
            if (size == 0) {
                head = temp;
                tail = temp;
            }
            else {
                Node* current = head;
                while (current->next != tail) {
                    current = current->next;
                }
                temp->next = tail;
                current->next = temp;
            }
            size++;
        }

        else {

            cout << "MY TASK IS : " << endl;
            getline(cin, task);

            Node* temp = new Node(task);

            Node* current = head;

            for (int i = 0; i <= pos - 3; i++) {
                current = current->next;
            }

            temp->next = current->next;
            current->next = temp;
        }
    }

    void deleteFirst() {
        if (tail == NULL) {
            cout << "EMPTY!!";
        }
        else {
            Node* temp = head;
            if (size == 1) {
                delete temp;
                head == NULL;
                tail == NULL;
            }
            else {
                head = head->next;
                delete temp;
            }
            size--;
        }
    }

    void deleteLast() {
        if (tail == NULL) {
            cout << "EMPTY!!";
        }
        else {
            Node* temp = tail;
            if (size == 1) {
                delete temp;
                head == NULL;
                tail == NULL;
            }
            else {
                Node* current = head;
                for (int i = 0; i < size - 2; i++) {
                    current = current->next;
                }
                tail = current;
                tail->next = NULL;
                delete temp;
            }
            size--;
        }
    }

    void deleteAt() {
        int pos;
        string task;

        cout << "I WANT TO DELETE AT : " << endl;
        cin >> pos;
        cin.ignore();
        if (tail == NULL) {
            cout << "TASK LIST IS EMPTY!";
        }
        else if (pos == 1) {
            deleteFirst();
        }
        else if (pos == size) {
            deleteLast();
        }
        else {
            Node* current = head;
            for (int i = 0; i < pos - 2; i++) {
                current = current->next;
            }
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
            cout << "TASK " << pos << " DELETED!" << endl;
            size--;
        }
        cin.get();
    }

    void display() {
        Node* current = head;
        int i = 0;
        while (current != NULL)
        {

            cout << i + 1 << " " << current->key << endl;
            current = current->next;
            i++;
        }
        cout << "THIS IS THE TASK LIST.PRESS 'Enter'  TO EXIT TO THE MAIN WINDOW" << endl;
        cin.get();
    }


    void search() {
        int pos;
        string task;

        cout << "I WANT TO KNOW MY TASK AT : " << endl;
        cin >> pos;
        cout << endl;
        cin.ignore();
        Node* current = head;
        for (int i = 0; i < pos - 1; i++) {
            current = current->next;
        }
        cout << current->key;
        cin.get();
    }

    void swap()
    {
        cout << " MY POSITION TO BE EXCHANGED" << endl;
        int pos1, pos2;
        cin >> pos1;
        cin.ignore();
        cin >> pos2;
        cout << endl;
        cin.ignore();
        int a = pos1;
        int b = pos2;
        if ((pos1 <= 0) || (pos2 <= 0) || (pos1 > size + 1) || (pos2 > size + 1))
        {
            cout << "INVALID INPUT!" << endl;
        }
        else if (pos1 == pos2) {
            cout << " HEY! SAME POSITION" << endl;
        }
        else if (pos1 < pos2)
        {
            Node* current = head;
            if (pos1 == 1)
            {
                Node* temp = head;
                do {
                    pos1++;
                    current = current->next;
                } while (pos1 < pos2);
                string tempstring;
                tempstring = temp->key;
                temp->key = current->key;
                current->key = tempstring;
                cout << a << " AND " << b << " WAS SWAPPED. DONE!" << endl;
            }
            else
            {
                for (int i = 0; i < pos1 - 1; i++)
                {
                    current = current->next;
                }
                Node* temp = current;
                while (pos1 < pos2) {
                    current = current->next;
                    pos1++;
                }
                string tempstring;
                tempstring = temp->key;
                temp->key = current->key;
                current->key = tempstring;
                cout << a << " AND " << b << " WAS SWAPPED. DONE!" << endl;
            }

        }
        else
        {

            Node* current = head;
            if (pos2 == 1) {
                Node* temp = head;
                do {
                    current = current->next;
                    pos2++;
                } while (pos1 > pos2);
                string tempstring;
                tempstring = temp->key;
                temp->key = current->key;
                current->key = tempstring;
                cout << b << " AND " << a << " WAS SWAPPED. DONE!" << endl;
            }
            else
            {
                for (int i = 0; i < pos2 - 1; i++)
                {
                    current = current->next;
                }
                Node* temp = current;
                while (pos1 > pos2) {
                    current = current->next;
                    pos2++;
                }
                string tempstring;
                tempstring = temp->key;
                temp->key = current->key;
                current->key = tempstring;
                cout << b << " AND " << a << " WAS SWAPPED. DONE!" << endl;
            }
        }
        cin.get();
    }
}
;

void interface()
{
    system("color 80");
    cout << ("\n\n\n\n");
    cout << ("\t""^^^^^^^^^^^^^^^^^^^^^^^^"
        "^^^^^^^^^^^^^^^^^^^^^^^^"
        "^^^^^^^^^^^^^^^^^^^^^^^^"
        "^^^^^^^^^^^^^^^^^^^^^^^^"
        "^^^^^^\n");
    cout << ("\t~~~~~~~~~~~~~~~~~~~~~~"
        "~~~~~~~~~~~~~~~~~~~~~~~"
        "~~~~~~~~~~~~~~~~~~~~~~~"
        "~~~~~~~~~~~~~~~~~~~~~~~~"
        "~~~~~~~~~~\n\n");
    cout << ("\t===================== "
        "================"
        "   MY DAILY TASK MANAGER"  "    ================= "
        "==================\n\n");
    cout << ("\t~~~~~~~~~~~~~~~~~~~~~"
        "~~~~~~~~~~~~~~~~~~~~~~~~"
        "~~~~~~~~~~~~~~~~~~~~~~~~~"
        "~~~~~~~~~~~~~~~~~~~~~~"
        "~~~~~~~~~~\n");
    cout << ("\t""^^^^^^^^^^^^^^^^^^^^^^^^"
        "^^^^^^^^^^^^^^^^^^^^^^^^"
        "^^^^^^^^^^^^^^^^^^^^^^^^"
        "^^^^^^^^^^^^^^^^^^^^^^^^"
        "^^^^^^\n");
    cout << ("\n\n\n\t\t\t\t\t\t\t"
        "\t\t       "
        "EG/2020/4115 Poornima K.N."
        "\t");
    cout << ("\n\t\t\t\t\t\t\t"
        "\t\t       "
        "EG/2020/4183 Samasthi H.G.S.R."
        "\t");
    cout << ("\n\t\t\t\t\t\t\t"
        "\t\t       "
        "EG/2020/4207 Senevirathna G.D.I.U.\n\n\n\n"
        "\n\n\n\t");

    cin.get();
}
int main()
{
    system("color 80");
    interface();
    task t1;


    while (1) {


        system("cls");

        cout << "\n\t\t\t\t\t\t\t01  ADD MY TASK" << endl;
        cout << "\t\t\t\t\t\t\t02  ADD MY TASK AT" << endl;
        cout << "\t\t\t\t\t\t\t03  SHOW MY TASKS" << endl;
        cout << "\t\t\t\t\t\t\t04  DELETE" << endl;
        cout << "\t\t\t\t\t\t\t05  SEARCH MY TASK AT" << endl;
        cout << "\t\t\t\t\t\t\t06  SWAP MY TASKS" << endl;
        cout << "\t\t\t\t\t\t\t07  EXIT" << endl;
        cout << "\n                ====================================Enter your choice====================================" << endl;

        int choice;
        cin >> choice;
        cin.ignore();
        system("cls");
        switch (choice) {
        case 1:
            t1.insertLast();
            break;
        case 2:
            t1.inserAt();
            break;
        case 3:
            t1.display();;
            break;
        case 4:
            t1.deleteAt();
            break;
        case 5:
            t1.search();
            break;
        case 6:
            t1.swap();
            break;
        case 7:
            exit(0);
        }
    }

}