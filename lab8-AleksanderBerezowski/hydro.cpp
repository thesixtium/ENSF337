#include <iostream>
using namespace std;

#include "list.h"
#include "hydro.h"

int main(){
    FlowList list;
    int entries = readData(file, &list);
    displayHeader();
    menu(&entries, list);
}

void displayHeader(){
    cout << "\nProgram: Flow Studies–Fall 2020\n";
    cout << "Version: 1.0\n";
    cout << "Lab section: B04\n";
    cout << "Produced By: Aleksander Berezowski\n";
}

int readData(const string& filePath, FlowList *list){
    ifstream inObj;
    string s;
    int lineCount = 0;
    inObj.open(filePath);
    if (!inObj){
        cout << "Error: cannot open the file" << endl;
        exit(1);
    }

    while(!inObj.eof()){
        getline(inObj, s);
        lineCount++;
    }

    inObj.clear();
    inObj.seekg(0, ios::beg);
    while(!inObj.eof()){
        int year;
        double flow;
        ListItem insertItem;

        inObj >> insertItem.year >> insertItem.flow;
        list->insert(insertItem);
        getline(inObj, s);
    }

    inObj.close();
    return lineCount;
}

void menu(int *entries, FlowList list){
    int choice = 0;
    int exitStatus = 1;
    while (exitStatus) {
        while (!choice) {
            pressEnter();

            cout << "\nPlease select on the following operations\n";
            cout << "\t1.\tDisplay flow list, and the average.\n";
            cout << "\t2.\tAdd data.\n";
            cout << "\t3.\tSave data into the file.\n";
            cout << "\t4.\tRemove data..\n";
            cout << "\t5.\tQuit.\n";
            cout << "\tEnter your choice (1, 2, 3, 4, or 5):\n";
            cin >> choice;
            clearBuffer();

            if(choice==1){
                display(list);
                choice = 0;
            } else if(choice==2){
                addData(list, entries);
                cout << "Data Added" << endl;
                choice = 0;
            } else if(choice==3){
                saveData(file, list);
                cout << "Data Saved" << endl;
                choice = 0;
            } else if(choice==4){
                removeData(list, entries);
                cout << "Data Removed" << endl;
                choice = 0;
            } else if(choice==5){
                cout << "Exiting Program" << endl;
                exitStatus = 0;
            }
        }
    }
}

void display(FlowList list){
    list.print();
    cout << "\nThe annual average of the flow is: " << average(list) << " billions cubic metres" << endl;
}

double average(FlowList list){
    return list.average();
}

void addData(FlowList list, const int *entries){
    ListItem newItem;
    cout<<"\nYear: ";
    cin>>newItem.year;
    cout<<"\nFlow: ";
    cin>>newItem.flow;

    list.insert(newItem);
    clearBuffer();
    pressEnter();
    entries += 1;
}

void saveData(const string& filePath, FlowList list){
    list.save(filePath);
}

void removeData(FlowList list, const int *entries){
    string year;
    cout<<"\nYear: ";
    cin>>year;

    list.remove(year);
    pressEnter();
    entries -= 1;
}

void pressEnter(){
    cout << "\n<<< Press Enter Twice to Continue >>>";
    cin.get();
    clearBuffer();
}

void clearBuffer(){
    cin.clear();
    cin.ignore(10000,'\n');
}