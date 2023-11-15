#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

class File {
public:
    File(const string& name, int size) : name(name), size(size) {getDate();}
    File() : name("Unnamed"), size(0){getDate();} 
    string name;
    int size;
    string date;


private:

    void getDate(){
        time_t now = time(0);
        date = ctime(&now);
    }
};

class Folder {
public:
    Folder(const string& name) : name(name) {
        getDate();
    }
    
    int foldercount = 0;
    int filecount = 0;

    string name;
    Folder* subfolders[5];
    File files[10];
    string date;
    Folder* parent = nullptr;

    void addFolder(Folder* folder){
        if (foldercount < 5);
        subfolders[foldercount++] = folder;
        folder->parent=this;
    }

    void addFile (File file){
        if (filecount < 10);
        files[filecount++] = file;

    }


    Folder* pickFolder(){
        for (int i = 0; i < foldercount; i++){
            cout <<i <<". " << subfolders[i]->name << endl;
        }
            cout <<foldercount <<". " <<name <<endl;
        int input;
        cin >> input;
        if(cin.fail()){
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return this;
        }
        if (input < foldercount)
        {
            return subfolders[input];
        }else   {
            return this;
         }
    }

    void printFolders(){
        if(parent == nullptr)
        cout << "Folder: " << name << "  "<<date <<endl;
        else
        cout << "Folder: " <<parent->name<<"/"<< name <<"  " <<date <<endl;
        for (int i = 0; i<filecount; i++)
            cout << "File: " << files[i].name << " Size: "<<files[i].size << "mb" <<"  " <<files[i].date <<endl;
        for (int i = 0; i<foldercount; i++)
            subfolders[i]->printFolders();
}
    private:

        void getDate(){
            time_t now = time(0);
            date = ctime(&now);
        }    
};


