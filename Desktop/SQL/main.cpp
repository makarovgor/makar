#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int period_of_issues(string date);
int max(int zlostnost[]);

class Publishing_House {
public:
    Publishing_House() { this->name = ""; }
    Publishing_House(const string &name) {
        this->name = name;
        this->id = rand() % 200 + rand() % 5;
    }
    void get_Name() { cout << "Имя : " << name << endl; }
    
protected:
    unsigned long id;
    string name;
};

class   Full_Name {
public:
    Full_Name(const string &first_name = string(), const string &middle_name = string(), const string &last_name = string()) {
        this->first_name = first_name;
        this->middle_name = middle_name;
        this->last_name = last_name;
        this->id = (first_name.length() + middle_name.length() + last_name.length() + rand() % 10);
    }
    
protected:
    unsigned long id;
    string first_name;
    string middle_name;
    string last_name;
};

class   Author : public Full_Name {
public:
    Author(const string &first_name = string(), const string &middle_name = string(), const string &last_name = string()) : Full_Name(first_name, middle_name, last_name) {
        this->full_name_id = Full_Name::id;
        this->id = this->full_name_id + rand() % 10;
    }
    void get_Full_Name_Author() {
        cout << "id : " << this->id << "\tfull_name_id : " << full_name_id << "\tFirst Name : " << first_name << "\tMiddle Name"
             << middle_name << "\tLast Name : " << last_name << endl;
    }
    
protected:
    unsigned long id;
    unsigned long full_name_id;
};

class   Student : public Full_Name {
public:
    Student(const string &first_name = string(), const string &middle_name = string(), const string &last_name = string()) : Full_Name(first_name, middle_name, last_name) {
        this->full_name_id = Full_Name::id;
        this->id = this->full_name_id + rand() % 10;
    }
    void get_Full_Name_Student() {
        cout << "id : " << this->id << "\tfull_name_id : " << full_name_id << "\tFirst Name : " << first_name << "\tMiddle Name"
             << middle_name << "\tLast Name : " << last_name << endl;
    }
    
protected:
    unsigned long id;
    unsigned long full_name_id;
};

class   Book_His : public Student {
public:
    Book_His() {
        this->id = rand() % 100;
    }
    void set_Student_id(Student &student) {
        students[counter_students] = Student::id;
        ++counter_students;
    }
    void set_Date_issue(string &date_of_issue) {
        issues[counter_issues] = date_of_issue;
        ++counter_issues;
    }
    void set_Date_returnes(string &return_date) {
        returnes[counter_returnes] = return_date;
        ++counter_returnes;
    }
    
    void get_Book_His_info() {
        cout << "id : " << id << endl;
        for (int i = 0; i < counter_issues; ++i) {
            cout << students[i] << "\t" << issues[i] << "\t" << returnes[i] << endl;
        }
    }
    int is_zlostnii_chitatel() {
        for (int i = 0; i < counter_issues; ++i) {
            if (period_of_issues(returnes[i]) - period_of_issues(issues[i]) > 30) {
                zlostnost[students[i]] += period_of_issues(returnes[i]) - period_of_issues(issues[i]);
            }
        }
        return max(zlostnost);
    }
    
    friend int period_of_issues(string date);
    friend int max(int zlostnost[]);

protected:
    string issues[100] = {};
    int counter_issues = 0;
    string returnes[100] = {};
    int counter_returnes = 0;
    unsigned long students[100] ={};
    int counter_students = 0;
    unsigned long id;
    unsigned long student_id;
    string date_of_issue;
    string return_date;
    int zlostnost[500] = {};
    int counter_zlostnost;
};

class Book : public Book_His, public Author, public Publishing_House {
public:
    Book(const string &name, const string &publication_date, const int &books_num) {
        this->id = rand() % 100 + rand() % 33;
        this->name = name;
        this->author_id = Author::id;
        this->publication_date = publication_date;
        this->publishing_house_id = Publishing_House::id;
        this->books_num = books_num;
        this->books_his_id = Book_His::id;
    }
    
    void get_Book_info() {
        cout << id << endl;
        cout << name << endl;
        cout << author_id << endl;
        cout << publication_date << endl;
        cout << publishing_house_id << endl;
        cout << books_num << endl;
        cout << books_his_id << endl;
        
    }
    
protected:
    unsigned long id;
    string name;
    unsigned long author_id;
    string publication_date;
    unsigned long publishing_house_id;
    int books_num;
    unsigned long books_his_id;
};

class   Library : public Book{
public:
    void set_Books(Book &book) {
        books[i] = Book::id;
        ++i;
    }
    
protected:
    unsigned long id = rand() % 999;
    unsigned long book_id;
    string books[100];
    int i = 0;
};

int period_of_issues(string date) {
    for (int j = 0; j < date.length(); ++j) {
        if (date[j] == '-' || date[j] == '/' || date[j] == '.' || date[j] == ' ') {
            date.erase(j, 1);
        }
    }
    int sum_days = (date[1] * 100 + date[2] * 10 + date[3]) * 365 + (date[4] * 10 + date[5]) * 31 + (date[6] * 10 + date[7]);
    return sum_days;
}

int max(int zlostnost[]) {
    int max = 0;
    for (int i = 0; i < 500; ++i) {
        if (zlostnost[i] > max) {
            max = zlostnost[i];
        }
    }
    return max;
}


int         main(int argc, char *argv[]) {
    //Author a("asd", "asdasd", "asdasdasda");
    //a.Get_info();
    //Student st("xcv", "klqwe", "oikmlk");
    //st.Get_info();
    //Book_His bh;
    
}
