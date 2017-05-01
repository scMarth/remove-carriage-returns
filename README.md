# Remove Carriage Returns

Removes carriage returns from files.

## Usage:

1.) Compile with 'make'

2.) ./removecr Sample.txt cleanedSample.txt

**Sample.txt**
![Alt text](https://github.com/scMarth/remove-carriage-returns/blob/master/Screenshots/Sample.png?raw=true)

**cleanedSample.txt**
![Alt text](https://github.com/scMarth/remove-carriage-returns/blob/master/Screenshots/Cleaned%20Sample.png?raw=true)

## Notes:

In C, `printf("\r");` prints the carriage return character, which shows up in a hex editor as `0x0D`. The carriage return character moves the cursor to the beginning of the line. 

`printf("\n");` prints the line feed character, which shows up in a hex editor as `0x0A`. A line feed means moving one line forward.

In Windows, when you hit enter, it normally saves as 0x0D followed by 0x0A (as opposed to in Linux, where hitting enter saves as just 0x0A). Thus Windows text files are larger, because hitting enter at the end of the line generates two bytes instead of just one in Linux.

Sometimes, this difference causes problems across operating systems. For example:

```c++
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
```

compiling the above C++ program (provided in this repo as 'concat.cpp') then running it on both 'Sample.txt' and 'cleanedSample.txt' yields:
```
$ cat Sample.txt 
This text
file
was created
in Windows.

$ ./concat Sample.txt 
line1: This text
line2: file
fileatenated: This text

$ ./concat cleanedSample.txt 
line1: This text
line2: file
concatenated: This textfile
```

The concatenation fails on the Windows textfile, but works on the cleaned up file.

