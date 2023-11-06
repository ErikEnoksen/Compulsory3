#include <iostream>             
#include <fstream>
#include <string> 
//Class Folder                           Class File                                    Public
//Private:                                Private                                       Folder(string nName){}          
//String name, int size, int date,        string name, int size , int date,             Folder(string nName int Date){} 
//File files[10]                                                                        Folder(string nName,int nDate, int nSize)           Size = rand(100)
//Folder folders[5]
//                                                                                      getName()return name;{}     getSize(){}return name;     getDate(){}return date otName                                                                                 

using namespace std;

void menu(){

    cout <<"##### Menu Options #####\n";
    cout <<"1.Create File\n";
    cout <<"2.Create Folder\n";
    cout <<"3.Select a Folder\n";
    cout <<"4.Print Folder\n";

}