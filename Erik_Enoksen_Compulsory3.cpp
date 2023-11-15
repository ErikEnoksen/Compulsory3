#pragma warning(disable : 4996)//to fix time

#include "header.h"
#include <cstdlib>
#include <ctime>

Folder mainFolder("mainfolder");
Folder* CurrentFolder = &mainFolder;

int main() {
    srand(static_cast<unsigned>(time(NULL))); // makes seed for random

    while (true) {
        cout << "You are currently in: " <<CurrentFolder->name <<endl;
        cout << "1. Create folder\n";
        cout << "2. Create file\n";
        cout << "3. Rename folder\n";
        cout << "4. List folders and files\n";
        cout << "5. Choose Folder\n";
        cout << "6. Go Back\n";
        cout << "7. Find Largest File\n";
        cout << "8. Rename File\n";
        cout << "9. Exit\n";

        int choice;
        cin >> choice;

        if (choice == 1) {
            string folderName;
            cout << "Enter folder name: ";
            cin >> folderName;

        Folder* newFolder = new Folder(folderName);
        CurrentFolder->addFolder(newFolder);
    
} else if (choice == 2) {
            string fileName;
            int filesize = rand() % 100;
            cout << "Enter file name: ";
            cin >> fileName;
            CurrentFolder->addFile(File(fileName,rand() % 100));           
} 
        else if (choice == 3) {
            string newName;
            cout << "Enter new folder name: ";
            cin >> newName;
          Folder* folder = CurrentFolder->pickFolder();
          folder->name = newName;
} 
        else if (choice == 4) {
           CurrentFolder->printFolders();           
} 
        else if (choice == 5){
            Folder* folder = CurrentFolder->pickFolder();
            CurrentFolder = folder;
        }
        else if (choice == 6){
            
        if (CurrentFolder->parent != nullptr)
        {
            CurrentFolder = CurrentFolder->parent;
        }
        }else if (choice == 7){
            File* biggestFile = nullptr;
            for (int i = 0; i < CurrentFolder->filecount; i++){
            
            if (biggestFile == nullptr){
                biggestFile = &CurrentFolder->files[i];
            }else if (biggestFile->size < CurrentFolder->files[i].size)
            {
                biggestFile = &CurrentFolder->files[i];
            }
        }
            if(biggestFile!=nullptr)
            cout << "File: " << biggestFile->name << " Size: "<<biggestFile->size << "mb" <<"  " <<biggestFile->date <<endl;
        
        }else if (choice == 8){
             string newName;
                cout << "Enter new file name: ";
                cin >> newName;
            for (int i = 0; i < CurrentFolder->filecount; i++)
                cout <<i <<". " <<CurrentFolder->files[i].name <<endl;
            int input;
            cin >> input;
            CurrentFolder->files[input].name = newName;
        }
        else if (choice == 9) {
            break;
} 
         else {
            cout << "Invalid choice. Please try again.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

    return 0;
}
