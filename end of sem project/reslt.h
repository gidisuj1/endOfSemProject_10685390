#include<iostream>
#include<fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <iterator> //for std::istream_iterator
#include <vector>
#include <iomanip>
using namespace std;



typedef struct course
{
 string rId;//for Registration No number
 string course1;
 string course2;
 string course3;
 string course4;
 string course5;
 string course6;
 string level;

};
typedef struct score
{
  int score1;
  int score2;
  int score3;
  int score4;
  int score5;
  int score6;
};


void newResultAdd()
{
   string rId;
   string level;
    fstream outfile ("resultInfo.txt",ios::app);
    course c1;
    score s1;
    cout<<"Registration Id:";
    cin>>rId;
    cout<<"Level:";
    cin>>level;
    cout<<"Enter Course:";
    cin>>c1.course1;
    cout<<"Enter score:";
    cin>>s1.score1;
    cout<<"Enter Course:";
    cin>>c1.course2;
    cout<<"Enter score:";
    cin>>s1.score2;
    cout<<"Enter Course:";
    cin>>c1.course3;
    cout<<"Enter score:";
    cin>>s1.score1;
    cout<<"Enter Course:";
    cin>>c1.course4;
    cout<<"Enter score:";
    cin>>s1.score4;
    cout<<"Enter Course:";
    cin>>c1.course5;
    cout<<"Enter score:";
    cin>>s1.score5;
    cout<<"Enter Course:";
    cin>>c1.course6;
    cout<<"Enter score:";
    cin>>s1.score6;
    outfile<<c1.rId<<" "<<level<<" "<<s1.score1<<" "<<s1.score2<<" "<<s1.score3<<" "<<s1.score4<<" "<<s1.score5<<" "<<s1.score6<<endl;
    cout<<"\n**Successfully Added**\n";
    outfile.close();
    return;

}
void updateResultAdd()
{
    string rId,level;
    cout<<"\n Enter student registration Id:\n";
    cin>>rId;
    cout<<"\n Enter student Level:\n";
    cin>>level;

    score s1;
    course c1;
    fstream infile ("resultInfo.txt");
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
            cout<<c1.course1;
            cin>>s1.score1;
            cout<<c1.course2;
            cin>>s1.score2;
            cout<<c1.course3;
            cin>>s1.score3;
            cout<<c1.course4;
            cin>>s1.score4;
            cout<<c1.course5;
            cin>>s1.score5;
            cout<<c1.course6;
            cin>>s1.score6;
            tempfile<<rId<<" "<<level<<" "<<s1.score1<<" "<<s1.score2<<" "<<s1.score3<<" "<<s1.score4<<" "<<s1.score5<<" "<<s1.score6<<endl;
            cout<<"\n**Successfully updated**\n";

        }
        else
        {
            tempfile<<line<<endl;

        }
    }
    infile.close();
    tempfile.close();
    remove("resultInfo.txt");
    rename("tempInfo.txt","resultInfo.txt");


}
void deleteResult()
{

        string rId,level;
    cout<<"\n Enter student registration Id:\n";
    cin>>rId;
    cout<<"\n Enter student Level:\n";
    cin>>level;

    score s1;
    fstream infile ("resultInfo.txt");
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
            cout<<"\n\n ** deleted successfully**\n\n";
        }
    }
    infile.close();
    tempfile.close();
    remove("resultInfo.txt");
    rename("tempInfo.txt","resultInfo.txt");



}

void overAllClassResult()
{
    string level;
    cout<<"Enter the class:";
    cin>>level;

    int failCount=0,passCount=0,totalCount=0;

    ifstream file("resultInfo.txt");
    string line;
    int check_fail=0;
    while(std::getline(file, line))
    {
            check_fail=0;
            istringstream ss(line);
            std::istream_iterator<std::string> begin(ss), end;
            //putting all the tokens in the vector
            std::vector<std::string> arrayTokens(begin, end);
            vector<string>::iterator it;
            int flag=0,i=0;
            for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
            {
                string p=*it;
                stringstream geek(p);
                // The object has the value 12345 and stream
                // it to the integer x
                int x = 0;
                geek >> x;
                if(flag==1)
                {
                    if(x<35)
                    {
                        check_fail=1;
                        failCount++;
                        break;
                    }
                    else
                    {
                        continue;
                    }

                }
                if(level==(*it) && i==1)
                {
                        flag=1;
                        totalCount++;
                }
                i++;

            }
            if(check_fail==0 && flag==1)
            {
                passCount++;
            }

        }
        cout<<endl<<"\t\t\t\t !** CLASS "<<level<<" RESULT**!\t\t\n\n\n";
        cout<<"Total No. of Failed Students:"<<failCount<<endl;
        cout<<"Total No. of Passed Students:"<<passCount<<endl;
        cout<<"Total No. of Students:"<<totalCount<<endl;
        cout<<"School Annual Result(%):"<<(double)(100*passCount)/totalCount<<"%";
        cout<<endl;

}

void schoolResult()
{
    int failCount=0,passCount=0,totalCount=0;
    ifstream file("resultInfo.txt");
    string line;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int flag=0,i=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            string p=*it;
            stringstream geek(p);
            // The object has the value 12345 and stream
            // it to the integer x
            int x = 0;
            geek >> x;

            if(x<35 && i>1)
            {
                flag=1;
                failCount++;
                break;
            }
            i++;

        }
        if(flag==0)
        {
            passCount++;

        }


        totalCount++;
    }

    cout<<"Total No. of Failed Students:"<<failCount<<endl;
    cout<<"Total No. of Passed Students:"<<passCount<<endl;
    cout<<"Total No. of Students:"<<totalCount<<endl;
    cout<<"School Annual Result(%):"<<(double)(100*passCount)/totalCount<<"%";
    cout<<endl;
}

void studentResult()
{
   course c1;
    string rId;
    cout<<"\nEnter student Reg.ID:";
    cin>>rId;
    ifstream file("resultInfo.txt");
    string line;
    int s_result=1;
    string r1;
    int total=0;
    while(std::getline(file, line))
    {
        istringstream ss(line);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        int flag=0,i=0;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
             string p=*it;
             stringstream geek(p);
             // The object has the value 12345 and stream
             // it to the integer x
             int x = 0;
            geek >> x;
            if(flag==1)
            {
                total+=x;
                if(x<35)
                {
                    s_result=0;
                    break;
                }
                else
                {
                    continue;
                }

            }
            if(rId==(*it) && i==0)
            {
                flag=1;
                it++;
                r1=line;
            }
            else
                break;

        }
    }
        cout<<endl<<"\t\t\t\t !** STUDENT RESULT **!\t\t\n\n\n";
        cout<<setw(10)<<"Reg.Id";
        cout<<setw(10)<<"Level";
        cout<<setw(10)<<c1.course1;
        cout<<setw(10)<<c1.course2;
        cout<<setw(10)<<c1.course3;
        cout<<setw(10)<<c1.course4;
        cout<<setw(10)<<c1.course5;
        cout<<setw(10)<<c1.course6;
        cout<<endl;
        istringstream ss(r1);
        std::istream_iterator<std::string> begin(ss), end;

        //putting all the tokens in the vector
        std::vector<std::string> arrayTokens(begin, end);

        vector<string>::iterator it;
        for(it = arrayTokens.begin(); it != arrayTokens.end(); it++)
        {
            cout<<setw(10)<<*it;
        }

        if(s_result==0)
        {
            cout<<"**Result is Fail**";
        }
        else
        {
            cout<<"\n\n\tTotal Score->"<<total<<endl;
            cout<<"\tTotal Percentage(%)->"<<((double)total/500)*100<<"%"<<endl;
            cout<<"\t**Result is Pass**";
        }
        cout<<endl;
}

