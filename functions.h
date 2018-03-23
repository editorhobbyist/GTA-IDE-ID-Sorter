

void exit_check(string input){
    if (input == "exit")
{
    exit(1);
}
}
void log_header(){

    //Log headers
    flog << "=========================================================================================================================="<<endl;
    flog << "=                                     IPL Sorter Script Public Built v2.0 by Inan-Ahammad                                ="<<endl;
    flog << "=                                      For support contact here inan.ahammad17@gmail.com                                 ="<<endl;
    flog << "=========================================================================================================================="<<endl;
    flog <<endl;
    flog <<"------------Eternal  Works------------"<<endl;

}

void pro_header(){

    //Program Header
    cerr << "<=======================================Welcome to IDE Sorter Script Public Built v2.0=================================>"<< endl;
    cerr << "                        This tool is created by Inan-Ahammad. | Special Thanks to Parik for his help.                   "<< endl;
    cerr << "  This program only supports the objs section.other sections aren't supported.So just remove them or ur game will crash "<< endl;
    cerr << "  Type and press \"exit\" any time to exit the program. | For support/bug reposrting sent here inan.ahammad17@gmail.com "<< endl;
    cerr << "<======================================================================================================================>" << endl;
    cerr << endl;
    cerr << endl;
}

void file_ccheck(fstream& cinfile,string cname){

    //File creation check
    if(!cinfile){
        flog <<"-->Unable to create "<< cname <<endl;
        flog <<endl;
        exit(1);


    }else {flog<<"-->Sucessfully created " << cname <<endl;
            flog <<endl;
    }

}

void file_ocheck(fstream& oinfile,string oname){

    //File open check
    if(!oinfile){
        flog << oname <<" file does not exist.Creating it."<<endl;
        oinfile.open(oname, ios::out);
        file_ccheck(oinfile,oname);


    }else flog<<"Sucessfully opened " <<oname <<endl;


}







void log_ide_details(){

    flog << endl;
    flog <<"__________________IDE__________________"<<endl;
    flog <<"Found Obj ID            --> " << objid <<endl;
    flog <<"Found Extention         --> "<< extention<<"\n";
    flog <<"Full Line (UnModified)  --> " << tline << endl;
    flog <<"New Obj ID for Obj      --> " << newobjid <<endl;
    flog <<"Full Line (Modified)    --> " << ntline << endl;
    flog <<"_______________________________________"<<endl;
    flog << endl;

}

void pro_closing(){

modide <<"end"<<endl;
flog << endl;
flog <<"---------------------------------"<<endl;
flog <<"Total Changed Object IDs          --> "<<loop<<endl;
flog <<"---------------------------------"<<endl;
flog << endl;
flog <<"----------Finishing Up----------"<<endl;
flog <<"Closed Processed.ide"<<endl;
modide.close();
flog << "Closed IDE_Process.txt"<<endl;
idepro.close();


if( remove("IDE_Process.txt") != 0 ){
    flog << "Error deleting file IDE_Process.txt" <<endl;
    }else flog<< "IDE_Process.txt file successfully deleted" <<endl;
flog << "Closed IDE_Sorter.log"<<endl;
flog <<"---------------------------------"<<endl;
flog << "log ended."<<endl;
flog.close();

cerr << endl;
cerr << "<======================================================================================================================>" << endl;
cerr << endl;

}


