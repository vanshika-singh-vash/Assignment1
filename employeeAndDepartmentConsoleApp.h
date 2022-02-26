#include<iostream>
#include<string>
#include <vector>
using namespace std;
class Employment;
class Department;
class Record{
public:
    int id;
    string name;
    int age;
    vector<Department*> dep_list;
    vector<Employment*> emp_list;
    virtual void add(string name, int age){};
    virtual bool searchName(string name){};
    virtual void list(){};
    virtual void edit(int id){};
    virtual bool searchId(int id){};
    virtual void deleteId(int id){};
};

class Department:public Record{
public:
    static int count ;
    Department(){};
    Department(int id,string name,int age=0){
        this->id = id;
        this->name = name;
    }
    void add(string name,int age){
        if(!dep_list.empty()) {
            bool found = searchName(name);
            if (found) {
                cout << "      already exist" << endl;
                return;
            }
        }
        count++;
        id = count;
        Department* newRec = new Department(id,name);
        dep_list.push_back(newRec);
    }
    bool searchName(string name){
        auto it = dep_list.begin();
        for(;it!=dep_list.end();it++){
            if((*it)->name == name){
                return true;
            }
        }
        return false;
    }
    void list(){
        if(dep_list.empty()){
            cout<<"      no record present"<<endl;
            return;
        }
        auto it = dep_list.begin();
        cout<<"  id  "<<" | "<<"  name  "<<" "<<endl;
        for(;it!=dep_list.end();it++){
            cout<<"   "<<(*it)->id<<"       "<<(*it)->name<<endl;
        }
    }
    void edit(int id){
        bool find = searchId(id);
        if(!find){
            cout<<"      id doesn't exist"<<endl;
            return;
        }
        list();
        cout<<"      enter name of the department you want to edit"<<endl;
        string nameEdit;
        cin>>nameEdit;
        auto it  =dep_list.begin();
        for(;it!=dep_list.end();it++){
            if((*it)->id==id){
                (*it)->name = nameEdit;
            }
        }
    }
    bool searchId(int id){
        auto it = dep_list.begin();
        for(;it!=dep_list.end();it++){
            if((*it)->id == id){
                return true;
            }
        }
        return false;
    }
    void deleteId(int id){
        bool find =searchId(id);
        if(!find){
            cout<<"      record doesn't exist"<<endl;
        }
        auto it=dep_list.begin();
        for(;it!=dep_list.end();it++){
            if((*it)->id == id){
                break;
            }
        }
        dep_list.erase(it);
    }
};
int Department::count =0;
class Employment:public Record {
public:
    static int count1;
    Employment(){};
    Employment(int id, string name, int age) {
        this->id = id;
        this->name = name;
        this->age = age;
    }
    void add(string name,int age){
        if(!emp_list.empty()) {
            bool found = searchName(name);
            if (found) {
                cout << "      already exist" << endl;
                return;
            }
        }
        count1++;
        id = count1;
        Employment* newRec = new Employment(id,name,age);
        emp_list.push_back(newRec);

    }
    bool searchName(string name){
        auto it = emp_list.begin();
        for(;it!=emp_list.end();it++){
            if((*it)->name == name){
                return true;
            }
        }
        return false;
    }
    void list(){
        if(emp_list.empty()) {
            cout<<"      no record present"<<endl;
            return;
        }
        auto it = emp_list.begin();
        cout<<"  id  "<<" | "<<"  name  "<<" | "<<"  age"<<endl;
        for(;it!=emp_list.end();it++){
            cout<<"  "<<(*it)->id<<"       "<<(*it)->name<<"      "<<(*it)->age<<endl;
        }
    }
    void edit(int id){
        bool find = searchId(id);
        if(!find){
            cout<<"      id doesn't exist"<<endl;
            return;
        }
        list();
        cout<<endl;
        cout<<"      enter name and age to be edited  "<<endl;
        string nameEdit;
        int ageEdit;
        cin>>nameEdit;
        cin>>ageEdit;
        auto it  =emp_list.begin();
        for(;it!=emp_list.end();it++){
            if((*it)->id==id){
                (*it)->name = nameEdit;
                (*it)->age = ageEdit;
            }
        }
    }
    bool searchId(int id){
        auto it = emp_list.begin();
        for(;it!=emp_list.end();it++){
            if((*it)->id == id){
                return true;
            }
        }
        return false;
    }
    void deleteId(int id){
        bool find =searchId(id);
        if(!find){
            cout<<"      record doesn't exist"<<endl;
        }
        auto it=emp_list.begin();
        for(;it!=emp_list.end();it++){
            if((*it)->id == id){
                break;
            }
        }
        emp_list.erase(it);
    }
};
int Employment::count1=0;
int main(){
    Employment emp;
    Record* r1=&emp;
    Department dep;
    Record* r2 =& dep;
    int c=0;
    while(c!=9) {
        int choice;
        cout<<"_______________________________________________"<<endl;
        cout<<"      choose operation you want to preform:  "<<endl;
        cout<<"      1. add data in employee"<<endl;
        cout<<"      2. edit data in employee"<<endl;
        cout<<"      3. list all employee"<<endl;
        cout<<"      4. delete an employee"<<endl;
        cout<<"      5. add department"<<endl;
        cout<<"      6. edit department"<<endl;
        cout<<"      7. list all department"<<endl;
        cout<<"      8. delete a department"<<endl;
        cout<<"_______________________________________________"<<endl;
        cin >> choice;
        switch(choice){
            case 1: {
                int age;
                string name;
                cin>>name;
                cin>>age;
                r1->add(name,age);
                cout<<"      record added"<<endl;
                break;
            }
            case 2:{
                int id;
                cin>>id;
                r1->edit(id);
                cout<<"      data edited"<<endl;
                break;
            }
            case 3: {
                r1->list();
                break;
            }
            case 4:{
                int id;
                cin>>id;
                r1->deleteId(id);
                cout<<"      record deleted from employee"<<endl;
                break;
            }
            case 5:{
                string name;
                cin>>name;
                r2->add(name,0);
                cout<<"      record added"<<endl;
                break;
            }
            case 6:{
                int id;
                cin>>id;
                r2->edit(id);
                cout<<"      record edited"<<endl;
                break;
            }
            case 7:{
                r2->list();
                break;
            }
            case 8:{
                int id;
                cin>>id;
                r2->deleteId(id);
                cout<<"      record deleted from department"<<endl;
                break;
            }
            case 9:
                c=9;
                break;
            default :
                cout<<"invalid choice";
        }
    }
}
