#include<iostream>
#include<fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator> //for std::istream_iterator
#include <vector>
#include <iomanip>
using namespace std;


typedef struct cours
{
 string rId;//for Registration No number
 string course1;
 string course2;
 string course3;
 string course4;
 string course5;
 string course6;
 string level;//for class info

};


void addcourse()
{
    fstream outfile ("CourseInfo.txt",ios::app);
    cours s1;

    cout<<"Student ID:";
    cin>>s1.rId;
    cout<<"Course 1:";
    cin>>s1.course1;
    cout<<"Course 2:";
    cin>>s1.course2;
    cout<<"Course 3:";
    cin>>s1.course3;
    cout<<"Course 4:";
    cin>>s1.course4;
    cout<<"Course 5:";
    cin>>s1.course5;
    cout<<"Course 6:";
    cin>>s1.course6;
    outfile<<s1.rId<<" "<<s1.course1<<" "<<s1.course2<<" "<<s1.course3<<" "<<s1.course4<<" "<<s1.course5<<" "<<s1.course6<<endl;
    cout<<"\n**Successfully Added**\n";
    outfile.close();
    return;
}

void updateCourseInform()
{
    string rId;
    cout<<"\n Enter student ID:\n";
    cin>>rId;

    course s1;
    fstream infile ("CourseInfo.txt");
    fstream temfile ("temInfo.txt",ios::app);
    string line;

    while(std::getline(infile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && rId==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag==1)
        {

    cout<<"Student ID:";
    cin>>s1.rId;
    cout<<"Course 1:";
    cin>>s1.course1;
    cout<<"Course 2:";
    cin>>s1.course2;
    cout<<"Course 3:";
    cin>>s1.course3;
    cout<<"Course 4:";
    cin>>s1.course4;
    cout<<"Course 5:";
    cin>>s1.course5;
    cout<<"Course 6:";
    cin>>s1.course6;
         temfile<<s1.rId<<" "<<s1.course1<<" "<<s1.course2<<" "<<s1.course3<<" "<<s1.course4<<" "<<s1.course5<<" "<<s1.course6<<endl;
            cout<<"\n**Successfully updated**\n";
        }
        else
        {
            temfile<<line<<endl;
        }


    }
    infile.close();
    temfile.close();
    remove("CourseInfo.txt");
    rename("temInfo.txt","CourseInfo.txt");

}

void deleteCourseInform()
{
    string rId;
    cout<<"\n Enter Student  ID:\n";
    cin>>rId;

    student s1;
    fstream infile ("CourseInfo.txt");
    fstream temfile ("temInfo.txt",ios::app);
    string line;

    while(std::getline(infile, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;
        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int i=0,flag=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            if(i==0 && rId==*it)
            {
                flag=1;
            }
            else
                break;
            i++;
        }
        if(flag!=1)
        {
            temfile<<line<<endl;
        }
        else
        {
            cout<<"\n **Deleted successfully**\n";
        }


    }
    infile.close();
    temfile.close();
    remove("CourseInfo.txt");
    rename("temInfo.txt","CourseInfo.txt");



}


void listOfCourse()
{
    ifstream file("CourseInfo.txt");
    string content;
    cout<<endl<<"\t\t\t\t !** COURSE LIST **!\t\t\n\n\n";
    cout << setw(15) <<"STD.ID:" << setw(15) << "COURSE 1" << setw(15) << "COURSE 2" <<setw(15) << "COURSE 3"<<setw(15)<<"COURSE 4"<<setw(15)<<"COURSE 5"<<setw(15)<<"COURSE 6"<< endl<<endl;
    string line;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;

        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {

                cout<<setw(15)<<*it;// prints d.

        }
        std::cout << '\n';

    }


}



