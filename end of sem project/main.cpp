#include <iostream>
#include<stdio.h>
#include<stdlib.h>

#include "std.h"
#include "staff.h"
#include "reslt.h"
#include "course.h"
using namespace std;

int main()
{
    int ch;
    for(;;)
    {
            cout <<endl<<endl;
            cout << "\t\t\t\t/////// WELCOME TO SCHOOL MANAGEMENT SYSTEM ///////"<< endl<<endl;
            cout << "1. Student Information"<< endl;
            cout << "2. Staff Information"<< endl;
            cout << "3. Result Information"<< endl;
            cout << "4. Course Information"<< endl;
            cout << "5. Exit"<< endl;
            cout << "Enter your choice:"<< endl;
            cin>>ch;
            switch(ch)
            {
                case 1:
                            int studentC;
                            cout <<endl;
                            cout << " /// STUDENT PORTAL /// "<< endl;
                            cout << "1. Add a New Registration"<< endl;
                            cout << "2. Update already existing student information"<< endl;
                            cout << "3. Delete student information"<< endl;
                            cout << "4. List All students with respective informations"<< endl;
                            cout << "5. Exit"<< endl;
                            cout << "Enter your choice:"<< endl;
                            cin>>studentC;
                            switch(studentC)
                            {
                                case 1:
                                    newStudentRegistration();
                                    break;
                                case 2:
                                    updateStudentInform();
                                    break;
                                case 3:
                                    deleteStudentInform();
                                    break;
                                case 4:
                                    listOfStudents();
                                    break;
                                case 5:exit(0);
                                break;
                                default:
                                        cout<<"Incorrect entry, please check and try again!";
                            }
                    break;
                case 2:
                            int staffC;

                            cout <<endl;
                            cout << " /// STAFF PORTAL /// "<< endl;
                            cout << "1. Add a New Registration"<< endl;
                            cout << "2. Update already existing staff information"<< endl;
                            cout << "3. Delete staff information"<< endl;
                            cout << "4. List All staff members"<< endl;
                            cout << "5. Exit"<< endl;
                            cout << "Enter your choice:"<< endl;
                            cin>>staffC;
                            switch(staffC)
                            {
                            case 1:
                                newStaffRegistration();
                                break;
                            case 2:
                                    updateStaffInform();
                                    break;
                            case 3:
                                    deleteStaffInform();
                                    break;
                            case 4:
                                    listOfStaffs();
                                    break;

                            case 5:exit(0);
                            break;
                            default:
                                    cout<<"wrong option, please retry";
                            }
                    break;

                case 3:
                            int resultC;
                            cout <<endl;
                            cout << " /// RESULT /// "<< endl;
                            cout << "1. Add Result "<< endl;
                            cout << "2. Update Result"<< endl;
                            cout << "3. Delete Result"<< endl;
                            cout << "4. Over All class Result"<< endl;
                            cout << "5. School Annual Result"<< endl;
                            cout << "6. Student Result"<< endl;
                            cout << "7. Exit"<< endl;
                            cout << "Enter your choice:"<< endl;
                            cin>>resultC;
                            switch(resultC)
                            {
                            case 1:
                                    newResultAdd();
                                    break;
                            case 2:
                                    updateResultAdd();
                                    break;
                            case 3:
                                    deleteResult();
                                    break;
                            case 4:
                                    overAllClassResult();
                                    break;
                            case 5:
                                    schoolResult();
                                    break;
                            case 6:
                                    studentResult();
                                    break;
                            case 7:exit(0);
                                break;
                                default:
                                        cout<<"wrong option, please retry";
                            }
                    break;
                case 4:
                            int courseC;
                            cout <<endl;
                            cout << " /// FEE /// "<< endl;
                            cout << "1. Add New Course( Only 6 )"<< endl;
                            cout << "2. Update Course Information"<< endl;
                            cout << "3. Delete Course information"<< endl;
                            cout << "4. List All Courses"<< endl;
                            cout << "5. Exit"<< endl;
                            cout << "Enter your choice:"<< endl;
                            cin>>courseC;
                            switch(courseC)
                            {
                                case 1:
                                    addcourse();
                                    break;
                                case 2:
                                    updateCourseInform();
                                    break;
                                case 3:
                                    deleteCourseInform();
                                    break;
                                case 4:
                                    listOfCourse();
                                    break;
                                case 5:
                                    exit(0);
                                    break;
                                default:
                                    cout<<"Incorrect entry, please check and try again!";
                            }
                            break;
                case 5:exit(0);
                        break;
                default:cout<<"Incorrect entry, please check and try again!";
            }
    }
    return 0;
}
