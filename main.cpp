#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <time.h>


using namespace std;

//Global Variables
int objid;
int newobjid;
int loop = 0;
string fname ;
string extention;
string idename;
string ideprint;
string tline;
string ntline;
fstream ide;
fstream flog;
fstream idepro;
fstream modide;
fstream proide;
string input;

#include "functions.h"

const string currentDateTime(){
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

int main()
{

pro_header();

    //Creating files.
   flog.open("IDE_Sorter.log");
   file_ocheck(flog,"IDE_Sorter.log");
   flog << "===================================================="<<currentDateTime() << "==================================================="<< endl;
   log_header();

   idepro.open("IDE_Process.txt");
   file_ocheck(idepro,"IDE_Process.txt");



while(1 > 0){
    cout << "Enter the IDE file name/location --> ";
    getline(cin,idename);
    exit_check(idename);


    ide.open(idename);
    if(!ide)
    {
        cerr <<endl;
        cout << "Error "<<idename<<" file does not exist"<<endl;
        flog << "***Error "<<idename<<" file does not exist***"<<endl;
        cerr <<endl;
        exit(1);
    }else{
    cerr <<endl;
    cout << "Successfully opened "<<idename<<" file."<<endl;
    cerr <<endl;

    }
    cout << "Enter the processed file name --> ";
    getline(cin,fname);

exit_check(fname);

    if(fname.empty())
    {
        fname = idename + "(mod).ide";
    }


    modide.open(fname);
    file_ocheck(modide,fname);

    cerr <<endl;
    cout << "Enter the start id no -->";
    cin >> newobjid;



     while(getline(ide,ideprint)){
      if(ideprint[0] == '#'){
      continue;
      }else if(ideprint[0] >='a'&&ideprint[0] <= 'z'){
      continue;
      }else if(ideprint[0] >='A'&& ideprint[0] <= 'Z'){
      continue;
      }else if(ideprint[0] ==' '){
      continue;
      }else {
          idepro << ideprint << endl;
}
     }


    modide <<"#This item defination file created by Inan-Ahammad's IDE Sorting Script."<<endl;
    modide <<"#Original File location --> "<<idename<<endl;
    modide <<"objs"<<endl;


    //Closing  process file
    ide.close();
    idepro.close();
    proide.open("IDE_Process.txt");

   file_ocheck(proide,fname);

   flog <<endl;
   flog << "--------------------------------------------------Objects ID Change Logs("<<idename<<")--------------------------------------------------"<<endl;

    while(proide >> objid)
    {
    getline(proide,extention);

    //Rebuilding all the ide values to one string.
    ntline =  to_string(newobjid) + string(extention);
    tline =  to_string(objid) + string(extention);

     modide <<ntline<<endl;


log_ide_details();

    newobjid++;
    loop++;
    }

    cout<<endl;
    cerr <<"Successfully sorted IDE lines"<<endl;
    cout<<endl;
    cerr <<"-----------------------------------------------"<<endl;
    cout <<"Total Changed Object IDs          --> "<<loop<<endl;
    cerr <<"-----------------------------------------------"<<endl;

pro_closing();

cin.ignore();
}

}
