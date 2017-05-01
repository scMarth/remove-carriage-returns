## Notes:

In C, `printf("\r");` prints the carriage return character, which shows up in a hex editor as `0x0D`. The carriage return character moves the cursor to the beginning of the line. 

`printf("\n");` prints the line feed character, which shows up in a hex editor as `0x0A`. A line feed means moving one line forward.

In Windows, when you hit enter, it normally saves as 0x0D followed by 0x0A (as opposed to in Linux, where hitting enter saves as just 0x0A). Thus Windows text files are larger, because hitting enter at the end of the line generates two bytes instead of just one in Linux.

