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
                cout << "      record already exist" << endl;
                return;
            }
        }
        count++;
        id = count;
        Department* newRec = new Department(id,name);
        dep_list.push_back(newRec);
        cout<<"      recode added"<<endl;
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
        cout<<"      enter new name"<<endl;
        string nameEdit="";
        cin.ignore();
        getline(cin,nameEdit,'\n');
        auto it  =dep_list.begin();
        for(;it!=dep_list.end();it++){
            if((*it)->id==id){
                (*it)->name = nameEdit;
            }
        }
        cout<<"      record name edited"<<endl;
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
            return;
        }
        bool flag = false;
        auto it=dep_list.begin();
        for(;it!=dep_list.end();it++){
            if((*it)->id == id){
                flag=  true;
                break;
            }
        }
        if(flag) {
            dep_list.erase(it);
        }
        cout<<"      record deleted from department"<<endl;
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
                cout << "      record already exist" << endl;
                return;
            }
        }
        count1++;
        id = count1;
        Employment* newRec = new Employment(id,name,age);
        emp_list.push_back(newRec);
        cout<<"      record added"<<endl;
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
        cout<<"      enter new name:"<<endl;
        string nameEdit="";
        cin.ignore();
        getline(cin,nameEdit,'\n');
        int ageEdit;
        cout<<"      enter new age:"<<endl;
        cin>>ageEdit;
        auto it  =emp_list.begin();
        for(;it!=emp_list.end();it++){
            if((*it)->id==id){
                (*it)->name = nameEdit;
                (*it)->age = ageEdit;
            }
        }
        cout<<"      record edited for employee id: "<<id<<endl;
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
            return;
        }
        bool flag = false;
        auto it=emp_list.begin();
        for(;it!=emp_list.end();it++){
            if((*it)->id == id){
                flag = true;
                break;
            }
        }
        if(flag) {
            emp_list.erase(it);
            cout<<"      record deleted from employee list"<<endl;
        }
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
                string name="";
                cout<<"      add name of the employee: "<<endl;
                cin.ignore();
                getline(cin,name,'\n');
                cout<<"      add age of the employee: "<<endl;
                cin>>age;
                r1->add(name,age);
                break;
            }
            case 2:{
                int id;
                cout<<"      enter employee id: "<<endl;
                cin>>id;
                r1->edit(id);
                break;
            }
            case 3: {
                cout<<"      list of employees: "<<endl;
                r1->list();
                break;
            }
            case 4:{
                int id;
                cout<<"      enter employee id: "<<endl;
                cin>>id;
                r1->deleteId(id);
                break;
            }
            case 5:{
                string name;
                cout<<"      add name of the department: "<<endl;
                cin.ignore();
                getline(cin,name,'\n');
                r2->add(name,0);
                break;
            }
            case 6:{
                int id;
                cout<<"      enter id of department: "<<endl;
                cin>>id;
                r2->edit(id);
                break;
            }
            case 7:{
                cout<<"      list of departments: "<<endl;
                r2->list();
                break;
            }
            case 8:{
                int id;
                cout<<"      enter id of department: "<<endl;
                cin>>id;
                r2->deleteId(id);
                break;
            }
            case 9:
                c=9;
                break;
            default :
                cout<<"      invalid choice";
        }
    }
}
