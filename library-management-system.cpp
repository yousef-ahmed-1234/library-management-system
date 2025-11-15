#include <iostream>
using namespace std;

struct Book {
    int bookID;
    string title;
    string issueDate;
    string dueDate;
    Book* prev;
    Book* next;
};

class Library {
private:
    Book* head;
    Book* tail;

public:
  

    void addBook(int id, string title, string issue, string due) {
        Book* newBook = new Book{id, title, issue, due, nullptr, nullptr};
        if (!head) {
            head = tail = newBook;
        } else {
            tail->next = newBook;
            newBook->prev = tail;
            tail = newBook;
        }
    }

    void deleteBook(int id) {
        Book* temp = head;
        while (temp) {
            if (temp->bookID == id) {
                if (temp->prev) temp->prev->next = temp->next;
                else head = temp->next;
                if (temp->next) temp->next->prev = temp->prev;
                else tail = temp->prev;
                delete temp;
             
              
            }
            temp = temp->next;
        }
      
    }

    void displayForward() {
        Book* temp = head;
        while (temp) {
            cout << "ID: " << temp->bookID << ", Title: " << temp->title
                 << ", Issue: " << temp->issueDate << ", Due: " << temp->dueDate ;
            temp = temp->next;
        }
    }

    void displayBackward() {
        Book* temp = tail;
        while (temp) {
            cout << "ID: " << temp->bookID << ", Title: " << temp->title
                 << ", Issue: " << temp->issueDate << ", Due: " << temp->dueDate ;
            temp = temp->prev;
        }
    }

    void findBook(int id) {
        Book* temp = head;
        while (temp) {
            if (temp->bookID == id) {
                cout << "Found - Title: " << temp->title ;
                return;
            }
            temp = temp->next;
        }
        
    }

    void checkOverdue(string today) {
        Book* temp = head;
        while (temp) {
            if (temp->dueDate < today) {
                cout << "Overdue - ID: " << temp->bookID << ", Title: " << temp->title ;
            }
            temp = temp->next;
        }
    }
};




struct Worker {
    string name, surname, dob, job;
    int deptID = 0;
    float salary = 0;
};



struct Company {
    string companyName;
    Department IT, HR, Management;
    Company* next;
};





void listStandardWorkers() {
    Company* temp = list;
    while (temp) {
        for (getAllWorkers(temp)) {
            if (w.job == "standard") {
                cout << w.name << " " << w.surname ;
            }
        }
        temp = temp->next;
    }
}


void listWorkersInCompany(string cname) {
    Company* temp = list;
    while (temp) {
        if (temp->companyName == cname) {
            for (getAllWorkers(temp)) {
                cout << w.name << " " << w.surname << " - " << w.job ;
            }
            return;
        }
        temp = temp->next;
    }
   
}


void workersWithSalaryInRange(float minS, float maxS) {
    Company* temp = list;
    while (temp) {
        for (getAllWorkers(temp)) {
            if (w.salary >= minS && w.salary <= maxS) {
                cout << w.name << " " << w.surname << " - " << w.salary ;
            }
        }
        temp = temp->next;
    }
}


bool isStandardWorker(Worker w) {
    return w.job == "standard";
}


bool isInHR(Company* comp, Worker w) {
    for ( comp->HR.workers) {
        if (worker.name == w.name && worker.surname == w.surname)
            return true;
    }
    return false;
}


void listDepartmentWorkers(Company* comp, string dept) {
    
    if (dept == "IT") d = &comp->IT.workers;
    else if (dept == "HR") d = &comp->HR.workers;
    else if (dept == "Management") d = &comp->Management.workers;

    if (d) {
        for (d) {
            cout << w.name << " " << w.surname ;
        }
    } else {
        return
    }
}
