#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <regex>

using namespace std;

int main(int argc, char** argv){
   if (argc != 2){
      printf("Usage: ./concat filename\n");
      exit(1);
   }
   ifstream infile(argv[1]);

   string line1;
   string line2;

   getline(infile, line1); // get the first line in the file
   getline(infile, line2); // get the second line in the file

   cout << "line1: " << line1 << endl;
   cout << "line2: " << line2 << endl << endl;

   // find the first token of line 1 before concatenating
   istringstream iss(line1);
   string pre_c_line1_ft;
   iss >> pre_c_line1_ft;
   cout << "pre-concat: the first token of line1 is: " << pre_c_line1_ft << endl;

   line1 += line2; // add line to to line 1
   cout << "line1 concatenated:\n" << line1 << endl;

   // find the first token of line 1 after concatenating
   istringstream iss3(line1);
   string post_c_line1_ft;
   iss3 >> post_c_line1_ft;
   cout << "post-concat: the first token of line1 is: " << post_c_line1_ft << endl;

   // find the first token of line 2
   istringstream iss2(line2);
   string line2_ft;
   iss2 >> line2_ft;
   cout << "The first token of line2 is: " << line2_ft << endl;

   //  does line1 contain the first token of line2?
   if (line1.find(line2_ft) != string::npos){
      // line1 contains that token
      cout << "line1 does contain: '" << line2_ft << "'\n";
   }else{
      // line1 does not contains that token
      cout << "line  does not contain: '" << line2_ft << "'\n";
   }

   // does regex_search agree about line1 containing the first token of
   // line1 (pre-concat)?
   smatch m;
   regex expr(pre_c_line1_ft);
   if (regex_search(line1, m, expr)){
      cout << "regex_search found '" << pre_c_line1_ft << "' in line1\n";
   }else{
      cout << "regex_search DID NOT find '" << pre_c_line1_ft << "' in line1\n";
   }

   // does regex_search agree about line1 containing the first token of
   // line2
   smatch n;
   regex expr2(line2_ft);
   if (regex_search(line1, n, expr2)){
      cout << "regex_search found '" << line2_ft << "' in line1\n";
   }else{
      cout << "regex_search DID NOT find '" << line2_ft << "' in line1\n";
   }

   smatch o;
   regex expr3(pre_c_line1_ft + "(.)*" + line2_ft);
   if (regex_search(line1, o, expr3)){
      cout << "regex_search found '" << pre_c_line1_ft << "(.)*" << line2_ft << "' in line1\n";
   }else{
      cout << "regex_search DID NOT find '" << pre_c_line1_ft << "(.)*" << line2_ft << "' in line1\n";
   }

   return 0;
}