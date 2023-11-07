
//Class Folder                           Class File                                    Public
//Private:                                Private                                       Folder(string nName){}          
//String name, int size, int date,        string name, int size , int date,             Folder(string nName int Date){} 
//File files[10]                                                                        Folder(string nName,int nDate, int nSize)           Size = rand(100)
//Folder folders[5]
//                                                                                      getName()return name;{}     getSize(){}return name;     getDate(){}return date otName                                                                                 

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class File {
public:
    File(const std::string& name, int size) : name(name), size(size) {}

    string name;
    int size;
};

class Folder {
public:
    Folder(const std::string& name) : name(name) {}

    string name;
    vector<Folder> subfolders;
    vector<File> files;
};

std::vector<Folder> folders;

void printFolders(const std::vector<Folder>& folders, int depth = 0) {
    for (const Folder& folder : folders) {
        for (int i = 0; i < depth; ++i) {
            std::cout << "  ";
        }
        std::cout << "Folder: " << folder.name << std::endl;
        for (const File& file : folder.files) {
            for (int i = 0; i < depth + 1; ++i) {
                std::cout << "  ";
            }
            std::cout << "File: " << file.name << " (" << file.size << "MB)" << std::endl;
        }
        printFolders(folder.subfolders, depth + 1);
    }
}

int main() {
    while (true) {
        cout << "1. Create folder\n";
        cout << "2. Create file\n";
        cout << "3. Rename folder\n";
        cout << "4. List folders and files\n";
        cout << "5. Exit\n";
        int choice;
        std::cin >> choice;

        if (choice == 1) {
            string folderName;
            cout << "Enter folder name: ";
            cin >> folderName;
            folders.emplace_back(folderName);
        } else if (choice == 2) {
            std::string fileName;
            int fileSize;
            cout << "Enter file name: ";
            cin >> fileName;
            cout << "Enter file size (in MB): ";
            cin >> fileSize;
            folders.back().files.emplace_back(fileName, fileSize);
        } else if (choice == 3) {
            string newName;
            cout << "Enter new folder name: ";
            std::cin >> newName;
            folders.back().name = newName;
        } else if (choice == 4) {
            printFolders(folders);
        } else if (choice == 5) {
            // Save data to your laptop (not implemented)
            break;
        } else {
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
