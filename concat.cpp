#include <iostream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char** argv){
   if (argc != 2){
      printf("Usage: ./concat filename\n");
      exit(1);
   }
   ifstream infile(argv[1]);

   string line1;
   string line2;

   getline(infile, line1);
   getline(infile, line2);

   cout << "line1: " << line1 << endl;
   cout << "line2: " << line2 << endl;

   line1 += line2;
   cout << "concatenated: " << line1 << endl;

   return 0;
}