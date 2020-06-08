#include <iostream>
#include "ui.h"



using namespace std;
int main() {
    ui display;
    //system("dir"); //runs terminal commands remove this for final submition
    int menu=display.mainMenu();
    if (menu == 1)
    {
        cout<<"Put main program here"<<endl;
    }
    else if (menu == 2)
    {
        cout<<"Enter File Name"<<endl;
        string userInput = "";
        getline(cin,userInput);
        const string WXIMG= "sudo wxtoimg -s -e histeq -t n 090729\\ 1428\\ ";
        const string wav = ".wav > ";
        const string png = ".png";
        string wxImgCommand = WXIMG + userInput + wav + userInput + png;
        cout<<wxImgCommand<<endl;
        //system(wxImgCommand); //run terminal commands
    }
    else if (menu == 3)
    {
        cout<<"Put SDR program here"<<endl;
    }
    else if (menu == 4)
    {
        cout<<"Put Satellite tracking program here"<<endl;
    }

    cout << "Program Complete" << std::endl;
    return 0;
}
