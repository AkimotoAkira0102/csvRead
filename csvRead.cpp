#include <iostream>
#include <cstdlib>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> vec(string,char);
string left_Trim(string&,char);

int main(void){
    fstream file;
    file.open("Data.csv");

    if(!file){
        cout << "error" << endl;
        return 0;
    }

    string fileLine;

    class param{
        public:
            float a,b;
    };

    while(getline(file,fileLine)){
        vector<string> line_split;
        line_split = vec(fileLine,',');
    
        for(int i = 0;i < line_split.size();i++){
            if(line_split[i].find("=") != string::npos){
                cout << left_Trim(line_split[i],'=') << endl;
            }
        }  
    }    
    system("PAUSE");
    return 0;
}

vector<string> vec(string s,char delim){
    vector<string> result;
    istringstream is(s);
    string str;
    while(getline(is,str,delim)){
        result.push_back(str);
    }
    return result;
}

string left_Trim(string& str,char ch){
    str.erase(0,str.find_first_of(ch)+1);
    return str;
}