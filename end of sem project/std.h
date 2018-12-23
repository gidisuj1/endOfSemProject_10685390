#include<iostream>
#include<fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator> //for std::istream_iterator
#include <vector>
#include <iomanip>
using namespace std;


typedef struct student
{
 string rId;//for Registration No number
 string fName;//for student first name
 string lName;//for student last name
 string level;//for class info

};


void newStudentRegistration()
{
    fstream outfile ("studentInfo.txt",ios::app);
    student s1;
    cout<<"Student ID:";
    cin>>s1.rId;
    cout<<"FirstName:";
    cin>>s1.fName;
    cout<<"LastName:";
    cin>>s1.lName;
    cout<<"Level:";
    cin>>s1.level;
    outfile<<s1.rId<<" "<<s1.fName<<" "<<s1.lName<<" "<<s1.level<<" "<<endl;
    cout<<"\n**Successfully Added**\n";
    outfile.close();
    return;
}

void updateStudentInform()
{
    string rId;
    cout<<"\n Enter student ID:\n";
    cin>>rId;

    student s1;
    fstream infile ("studentInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
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
            cout<<"FirstName:";
            cin>>s1.fName;
            cout<<"LastName:";
            cin>>s1.lName;
            cout<<"Level:";
            cin>>s1.level;
            tempfile<<rId<<" "<<s1.fName<<" "<<s1.lName<<" "<<s1.level<<" "<<endl;
            cout<<"\n**Successfully updated**\n";
        }
        else
        {
            tempfile<<line<<endl;
        }


    }
    infile.close();
    tempfile.close();
    remove("studentInfo.txt");
    rename("tempInfo.txt","studentInfo.txt");

}

void deleteStudentInform()
{
    string rId;
    cout<<"\n Enter Student  ID:\n";
    cin>>rId;

    student s1;
    fstream infile ("studentInfo.txt");
    fstream tempfile ("tempInfo.txt",ios::app);
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
            tempfile<<line<<endl;
        }
        else
        {
            cout<<"\n **Deleted successfully**\n";
        }


    }
    infile.close();
    tempfile.close();
    remove("studentInfo.txt");
    rename("tempInfo.txt","studentInfo.txt");



}


void listOfStudents()
{
    ifstream file("studentInfo.txt");
    string content;
    cout<<endl<<"\t\t\t\t !** STUDENT LIST **!\t\t\n\n\n";
    cout << setw(15) <<"STD.ID:" << setw(15) << "F.NAME" << setw(15) << "L.NAME" <<setw(15) << "LEVEL"<<setw(15)<< endl<<endl;
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

