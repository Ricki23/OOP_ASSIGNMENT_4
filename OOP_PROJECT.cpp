#include<iostream>
#include<fstream>
using namespace std;
class Stud
{
    public:
        char *name;
        char *class_std;
        char sec[50];
        int roll_no;
        int *ptr;
        virtual void get_data()
        {
            name=new char[50];
            class_std=new char[50];
            cout<<"\nDefault constructor called:\n"<<endl;
            cout<<"Enter the name of student:"<<endl;
            getchar();
            gets(name);
            cout<<"Enter the branch of student:"<<endl;
            gets(class_std);
            cout<<"Enter the roll No of student:"<<endl;
            cin>>roll_no;
        }
        virtual void display_students()
        {
            cout<<"The details of the student:\n"<<endl;
            cout<<"Name:-"<<name<<endl;
            cout<<"Branch:-"<<class_std<<endl;
            cout<<"Roll No:-"<<roll_no<<endl;
        }       
};
class Lab_marks;
class Assign;
class Test:public Stud
{
    public:
        double marks_in_dsa;
        double marks_in_oop;
        double marks_in_hse;
        double marks_in_de;
        double tot;
        double per;
        void get_data()
        {
            cout<<"Enter the marks in DSA:";
            cin>>marks_in_dsa;
            cout<<"Enter the marks in DE:";
            cin>>marks_in_de;
            cout<<"Enter the marks in HSE:";
            cin>>marks_in_hse;
            cout<<"Enter the marks in OOP:";
            cin>>marks_in_oop;
        }
        friend void total_grade(Lab_marks l1,Test t1,Assign a1);

        Test operator ==(Test t1)
        {
            if(per>t1.per)
            {
                cout<<"\n\nFirst student has higher percentage than second student:"<<endl;
            }
            else
            {
                cout<<"\n\nSecond student has higher percentage than First student:"<<endl;
            }
            return t1;
        }
};
class Assign:public Stud
{
    public:
    int marks_in_submitting;
    int c;
    Assign()
    {
        cout<<"Has the student submitted his assignment (1 for yes and 2 for no):"<<endl;
        cin>>c;
        if(c==1)
        {
            cout<<"Enter the marks in assignment he submitted:"<<endl;
            cin>>marks_in_submitting;
        }
        else
        {
            cout<<"No marks allotted"<<endl;
        }
    }
    Assign(int s)
    {
        cout<<"Has the student submitted his assignment (1 for yes and 2 for no):"<<endl;
        cin>>c;
        if(c==1)
        {
            marks_in_submitting+=s;
        }
        else
        {
            cout<<"No marks allotted"<<endl;
        }
    }
    friend void total_grade(Lab_marks l1,Test t1,Assign a1);
    ~Assign()
    {
        cout<<"\nDestructor called";
    }
};
class Lab_marks:public Stud
{
    public:
    double lab_marks;
    double viva;
    Lab_marks()
    {
        cout<<"Enter the marks secured in viva (out of 50):";
        cin>>viva;
        cout<<"Enter the lab marks (out of 50):";
        cin>>lab_marks;
    }
    Lab_marks(double viva,double lab_marks)
    {
        cout<<"Enter the marks secured in viva (out of 50):";
        cin>>viva;
        cout<<"Enter the lab marks (out of 50):";
        cin>>lab_marks;
    }
    ~Lab_marks()
    {
        cout<<"\nDestructor called:";
    }
    friend void total_grade(Lab_marks l1,Test t1,Assign a1);
};
void total_grade(Lab_marks l1,Test t1,Assign a1)
{
    t1.tot=t1.marks_in_de + t1.marks_in_dsa + t1.marks_in_hse + t1.marks_in_oop + l1.viva + l1.lab_marks + a1.marks_in_submitting;
    t1.per=t1.tot/6;
    cout<<"Percentage of the student is:"<<t1.per<<endl;
    if(t1.per>=90 && t1.per<100)
    {
        cout<<"\nGrade of student is A+"<<endl;
    }
    if(t1.per>=80 && t1.per<90)
    {
        cout<<"\nGrade of student is A"<<endl;
    }
    if(t1.per>=70 && t1.per<80)
    {
        cout<<"\nGrade of student is B"<<endl;
    }
    if(t1.per>=60 && t1.per<70)
    {
        cout<<"\nGrade of student is C"<<endl;
    }
    if(t1.per>=50 && t1.per<60)
    {
        cout<<"\nGrade of student is D"<<endl;
    }
    if(t1.per>=40 && t1.per<50)
    {
        cout<<"\nGrade of Student is E"<<endl;
    }
    if(t1.per<40)
    {
        cout<<"\nStudent has failed"<<endl;
    }
}
template<class T> T total_grade2(Lab_marks l1,Test t1,Assign a1)
{
    T tot;
    tot=t1.marks_in_de + t1.marks_in_dsa + t1.marks_in_hse + t1.marks_in_oop + l1.viva + l1.lab_marks + a1.marks_in_submitting;
    T per;
    per=tot/6;
    cout<<"Percentage of the student is:"<<per<<endl;
    if(per>=90 && per<100)
    {
        cout<<"\nGrade of student is A+"<<endl;
    }
    if(per>=80 && per<90)
    {
        cout<<"\nGrade of student is A"<<endl;
    }
    if(per>=70 && per<80)
    {
        cout<<"\nGrade of student is B"<<endl;
    }
    if(per>=60 && per<70)
    {
        cout<<"\nGrade of student is C"<<endl;
    }
    if(per>=50 && per<60)
    {
        cout<<"\nGrade of student is D"<<endl;
    }
    if(per>=40 && per<50)
    {
        cout<<"\nGrade of Student is E"<<endl;
    }
    if(per<40)
    {
        cout<<"\nStudent has failed"<<endl;
    }
    return per;
}

int main()
{
    Stud *s=new Stud;
    s->get_data();
    s->display_students();
    Test t1;
    s=&t1;
    s->get_data();
    Assign a1;
    Lab_marks l1;
    cout<<"\n\n*******Grade and percentage by using friend function*****\n\n"<<endl;
    total_grade(l1,t1,a1);
    cout<<"\n\n*******Grade and percentage by using template function*****\n"<<endl;
    total_grade2<float>(l1,t1,a1);

    Stud *s2=new Stud;
    s2->get_data();
    s2->display_students();
    Test t2;
    s2=&t2;
    s2->get_data();
    Assign a2;
    Lab_marks l2;
    cout<<"\n\n*******Grade and percentage by using friend function*****\n\n"<<endl;
    total_grade(l2,t2,a2);
    cout<<"\n\n*******Grade and percentage by using template function*****\n"<<endl;
    total_grade2<float>(l2,t2,a2);
    
    t1==t2;

    ofstream obj;
    obj.open("Student.txt");
    obj<<t1.marks_in_de<<endl;
    obj<<t1.marks_in_dsa<<endl;
    obj<<t1.marks_in_oop<<endl;
    obj<<t1.marks_in_hse<<endl;
    obj<<a1.marks_in_submitting<<endl;
    obj<<l1.lab_marks+l1.viva<<endl;
    double per2,tot2;
    tot2=t1.marks_in_de + t1.marks_in_dsa + t1.marks_in_hse + t1.marks_in_oop + l1.viva + l1.lab_marks + a1.marks_in_submitting;
    per2=tot2/6;
    obj<<per2<<endl;
    cout<<"File with marks and percentage written successfully:"<<endl;
    obj.close();

    ofstream obj2;
    obj2.open("Student2.txt");
    obj2<<t2.marks_in_de<<endl;
    obj2<<t2.marks_in_dsa<<endl;
    obj2<<t2.marks_in_oop<<endl;
    obj2<<t2.marks_in_hse<<endl;
    obj2<<a2.marks_in_submitting<<endl;
    obj2<<l2.lab_marks+l2.viva<<endl;
    double per22,tot22;
    tot22=t2.marks_in_de + t2.marks_in_dsa + t2.marks_in_hse + t2.marks_in_oop + l2.viva + l2.lab_marks + a2.marks_in_submitting;
    per22=tot22/6;
    obj<<per22<<endl;
    cout<<"File with marks and percentage written successfully:"<<endl;
    obj.close();
}