#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include <fstream>
#include <math.h>
using namespace std;

int main(int argc, char** argv) {
    // argvをvector<string>に変換する
    vector<string> args(argv, argv + argc);


    if (args[1] == "view") {

        ifstream ifs(args[2], ios::in);
        string line;
            
        if (!ifs) {
            cerr << "err: file not opened" << endl;
            return 1;
        }

        while(getline(ifs, line)) {
            cout << line << endl;
        } 

    } else if(args[1] == "report") {
        char s;
        if (args[4] == "--csv") s = ',';
        else s = ' ';

        ifstream ifs(args[2], ios::in);
        string line;
            
        if (!ifs) {
            cerr << "err: file not opened" << endl;
            return 1;
        }

        ofstream ofs(args[3], ios::out);
        ofs << "# Reports\n" << endl;
        ofs << "This was generated in PDNK Labs' DataCraft.\n***" << endl;
        ofs << "|Mode|In1|In2|Out1|\n|----|----|----|----|" << endl;

        while (getline(ifs, line)) {
            vector<string> row;
            string cell;
            stringstream linestream(line);
            while (getline(linestream, cell, s)) {
                row.push_back(cell);
            }
            if (row[0] == "add") ofs << "|" << row[0] << "|" << row[1] << "|" << row[2] << "|" << stoi(row[1]) + stoi(row[2]) << "|\n";
            if (row[0] == "sub") ofs << "|" << row[0] << "|" << row[1] << "|" << row[2] << "|" << stoi(row[1]) - stoi(row[2]) << "|\n";
            if (row[0] == "mul") ofs << "|" << row[0] << "|" << row[1] << "|" << row[2] << "|" << stoi(row[1]) * stoi(row[2]) << "|\n";
            if (row[0] == "mov") ofs << "|" << row[0] << "|" << row[1] << "|" << row[2] << "|" << stoi(row[1]) / stoi(row[2]) << "|\n";
            if (row[0] == "mod") ofs << "|" << row[0] << "|" << row[1] << "|" << row[2] << "|" << stoi(row[1]) % stoi(row[2]) << "|\n";
            
        } 

        ofs.close();
    } else if(args[1] == "help") {
        cout << "Command Example:" << endl;
        cout << "        View File: datacraft view [Filename]" << endl;
        cout << "        Report Generation: datacraft report [In_Filename].csv [Out_Filename] --csv" << endl;
    }
    

    return 0;
}
