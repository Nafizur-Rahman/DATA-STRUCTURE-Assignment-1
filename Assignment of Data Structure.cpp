#include<iostream>
#include<iomanip>
#define FIXED 3

using namespace std;


class Course_Details{

private:

    float Earned_Credits;
    float Obtained_grade;



public:

    void set_credit(){
        cin>>Earned_Credits;
    }
    float get_credit(){
        return Earned_Credits;
    }
    void set_Obtained_grade(float Obtained_grade){
        Obtained_grade=Obtained_grade;
    }
    float get_Obtained_grade(){
        return Obtained_grade;
    }
};

class Student{


private:

    Course_Details total_number_of_Course_Details[FIXED];
    int student_ID;
    float Obtained_grade;
    float CGPA;

public:
    int Position_by_roll_position;
    float getcgpa(){
      return CGPA;
    }
    int get_ID(){
        return student_ID;
    }


    void get_student_information(int k){

        float total_credit=0.00;
        float Total_credits=0.00;
      cout<<"Enter the Student ID:"<<endl;
      cin>>student_ID;


      for(int i=0;i<FIXED;i++)
      {
        cout<<"Course_Details:"<<i+1<<endl;
        cout<<"Obtained_grade:"<<endl;


        cin>>Obtained_grade;
        total_number_of_Course_Details[i].set_Obtained_grade(Obtained_grade);
        cout<<"Earned_Credits:"<<endl;


        total_number_of_Course_Details[i].set_credit();
        total_credit = total_credit+total_number_of_Course_Details[i].get_credit();
        Total_credits = Total_credits+total_number_of_Course_Details[i].get_credit()*Obtained_grade;
      }
       CGPA= Total_credits/total_credit;
    }
};



 void get_Position_by_roll(Student student[],int N){
    for(int i=0;i<N;i++){

        int Position_by_roll=0;
        for(int j=0;j<N;j++){
            if(student[i].getcgpa()<student[j].getcgpa()) Position_by_roll++;
        }

    student[i].Position_by_roll_position=Position_by_roll+1;

    }
 }



void result(Student student[],int num_s,int i)
{
    cout<<"Student ID:"<<student[i].get_ID()<<endl;

  cout<<"CGPA:"<<fixed<<setprecision(2)<<student[i].getcgpa()<<endl;

  cout<<"Position_by_roll:"<<student[i].Position_by_roll_position<<endl;
}

int main(){


    cout<<"Number of students: ";
    int num_s;

    cin>>num_s;
    Student *student=new Student[num_s];

    for(int i=0;i<num_s;i++)
        {
       student[i].get_student_information(i);
    }

      get_Position_by_roll(student,num_s);


    for(int i=0;i<num_s;i++)
    {
       result(student,num_s,i);
    }


    return 0;
}
