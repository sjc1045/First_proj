/* Header:
   This project, developed Steven Cox, preforms various functions using one to two text files
   The various operations are copy, interleave, cut, more, grep, and stats (char count, longest word, etc)
   This code has been revised many times from 2/15/24 to 3/27/24
   Each function preformed by the program requires different arguments */

#include <stdio.h>
#include <string.h>
#include <ctype.h>

void printscreen(){
    printf("0:  Copy\n"
           "1:  Interleave\n"
           "2:  Cut\n"
           "3:  More\n"
           "4:  Grep\n"
           "5:  Word Count\n");
}

int main(int argc, char *argv[]) {
    int m, n;                              // most of these variables are used in later parts of project
    int val;                              // most of them are just counters that will get initialized to 0
    char ch;                              // used to hold character scanned in from input file... used in multiple sections
    int i = 0;
    int k = 0;
    int j = 0;
    int b = 0;
    int h = 0;
    int tmp;
    int size;
    int line_place = 0;
    int count = 0;
    char c;
    char grep_input[100];
    char grep_file[100];
    sscanf(argv[1], "%d", &val);              // scan in the users choice via command line
    //printf("%d\n", argc);

    if (val == 0 && argc != 4){
        printscreen();
    }
    if ((val == 1 || val == 2) && argc != 5){
        printscreen();
    }
    if ((val == 3 || val == 4 || val == 5) && argc > 3){
        printscreen();
    }

    if (val == 0) {                                    // if argv[1] is 0...
        FILE *a_file;
        FILE *b_file;
        a_file = fopen(argv[2], "r");
        b_file = fopen(argv[3], "w");

        if (a_file == NULL) {
            printf("file file1.txt cannot open");
        } else if (b_file == NULL) {
            printf("file file2.txt cannot open");
        }

        while ((ch = fgetc(a_file)) != EOF) {             // read in every character from the reading file
            fprintf(b_file, "%c", ch);            // write each character into the writing file
        }
        fclose(a_file);
        fclose(b_file);
    }

    if (val == 1) {                             // if argv[1] is 1
        FILE *a_file;
        FILE *b_file;
        FILE *c_file;
        a_file = fopen(argv[2], "r");
        b_file = fopen(argv[3], "r");
        c_file = fopen(argv[4], "w");
        if (a_file == NULL) {
            printf("file file1.txt cannot open");
        } else if (b_file == NULL) {
            printf("file file2.txt cannot open");
        } else if (c_file == NULL) {
            printf("file file3.txt cannot open");
        }

        int endfile1 = 0;           // switch variables used to exit out of scanning loop once EOF is detected
        int endfile2 = 0;
        int endline1 = 0;
        int endline2 = 0;

        while (1) {
            while (endfile1 == 0 && (ch = fgetc(a_file)) != '\n') {           // read in each line
                if (ch ==
                    EOF) {                                 // Once the end of the file is reached, terminate the endfile while loop and break
                    endfile1 = 1;                                // update endfile1 so program won't enter that while loop again
                    if (endfile2 ==
                        0) {                         // if the other reading file is still running, print a '\n'
                        fprintf(c_file, "\n");
                    }
                    break;
                } else {
                    fprintf(c_file, "%c", ch);       // if a regular character is scanned, write it in the output file
                }
            }

            if (endfile1 == 0) {                             // once EOF is reached, print a newline
                fprintf(c_file, "\n");
            }

            while (endfile2 == 0 && (ch = fgetc(b_file)) !=
                                    '\n') {       // same series as the above while loop, but with the second reading file
                if (ch ==
                    EOF) {                                               // update endfile2 so that the program won't enter the while loop again
                    endfile2 = 1;
                    if (endfile1 == 0) {
                        fprintf(c_file, "\n");
                    }
                    break;
                } else {
                    fprintf(c_file, "%c", ch);
                }
            }

            if (endfile2 == 0) {
                fprintf(c_file, "\n");
            }

            if (endfile1 == 1 && endfile2 ==
                                 1) {             // once the end of both files have been reached, terminate the infinite while loop
                break;
            }
        }

        fclose(c_file);
        fclose(a_file);
        fclose(b_file);
    }


    if (val == 2) {                                          // if argv[1] is 2...
        FILE *a_file;
        FILE *b_file;
        sscanf(argv[2], "%d-%d", &m, &n);
        a_file = fopen(argv[3], "r");
        b_file = fopen(argv[4], "w");

        if (a_file == NULL) {
            printf("file file1.txt cannot open");
        } else if (b_file == NULL) {
            printf("file file2.txt ccannot open");
        }

        i = 1;

        while ((ch = fgetc(a_file)) != EOF) {           // read in each character from the file until EOF is reached


            if (i >= (m) && i <=
                            (n)) {                           // if the character is within the bounds of the inputted range, write it to the output file
                fprintf(b_file, "%c", ch);
            }

            if (ch ==
                '\n') {                                // if the end of the line is reached, print a new line and rest the variable that keeps track of the range
                fprintf(b_file, "\n");
                i = 0;
            }
            i++;
        }
        fclose(a_file);
        fclose(b_file);
    }




    if (val == 3) {                                              // if argv[1] is 3
        int w=0;
        FILE *a_file;
        a_file = fopen(argv[2], "r");
        if (a_file == NULL) {
            printf("file file1.txt cannot open");
        }

        while ((ch = fgetc(a_file)) != EOF) {               // scan in each character from the file until EOF

            if (i == 10) {                                   // once 10 lines have been scanned in, store the current place in the file as tmp, then break
                tmp = ch;
                break;
            }
            if (ch == '\n') {                            // increment i for every line scanned in
                i++;
            }
            printf("%c", ch);

        }
//        if (i<10){
//            return 0;
//        }
        while (1) {
            printf("\nplease input 'n', 'p', or 'q':");
            scanf("%c", &c);
            if (c == 'p') {
                i = 10;
                printf("%c", tmp);

                while ((ch = fgetc(a_file)) != EOF) {

                    if (i == 20) {                           // once lines 10-20 have been scanned in, break
                        break;
                    }
                    if (ch == '\n') {                        // increment i each time a new line is detected
                        i++;
                    }
                    printf("%c", ch);

                }
            }

            else if (c == 'n') {
                if (w==0){
                    printf("%c", tmp);
                    w=1;
                }
               // printf("%c", tmp);                            // print first character of file since the last ten lines were printed
                while ((ch = fgetc(a_file)) != '\n') {          // scan in, then print the very next line
                    printf("%c", ch);
                }

            }

            else if (c == 'q') {
                fclose(a_file);
                return 0;
            }
        }


    }

    if (val == 4) {
        char line_array[100];                           // used to hold chars on one line
        FILE *a_file;
        a_file = fopen(argv[2], "r");
        if (a_file == NULL) {
            printf("file file1.txt cannot open");
        }

        printf("Input search String (10 chars max):");
        scanf("%10s", &grep_input);                     // scan in the string that the user enters
        rewind(a_file);

        while (fgets(line_array, 100, a_file)){     // scan in each line from file...
            if (strstr(line_array, grep_input)) {           // if the user input is found within a line...
                printf("%s", line_array);                       // printf out the line
            }
        }

        fclose(a_file);
    }


    if (val == 5) {                 // if argv[1] is 5...
        int lines = 1;              // number of lines in the file (starting at 1 to account for EOF)
        int spaces = 0;             // number of spaces in file
        int chars = 0;              // number of characters in the file
        int chars_line = 0;         // count of characters on each line... gets reset
        int word_line = 0;          // count of words on each line... gets reset
        int char_array[1000];        // array to hold characters to be
        int word_array[1000];        // array to hold words to find the line with the fewest words
        int length_array[1000];      // array to hold number of characters of each word
        char str;                   // holds each scanned in character for various functions
        int temp;                   // used to sort various arrays that find longest word, line, etc
        int words = 0;
        int p = 0, q = 0, g = 1, x = 0, y = 0, r = 0;    // general count variables
        char chars_in_line[1000];
        char chars_in_line2[1000];
        int con = 0;
        FILE *a_file;
        a_file = fopen(argv[2], "r");
        if (a_file == NULL) {
            printf("file file1.txt");
        }
//        fscanf(a_file, "%c", &ch);
//        if (isalpha(ch) != 0){
//            printf("alphanumeric\n");
//        } else{(printf("not alphnumeric\n"));}
//
//        rewind(a_file);
int ab = 0;
        while (fscanf(a_file, "%c", &ch) != EOF) {      //read in each character until the end of file is reached
            chars++;
          if ((isalpha(ch) == 0 && isdigit(ch) == 0) && con == 0 && ch != '\n') {       // if char isn't an alphabetic character
                //words++;
                con = 1;
                ab = 0;
                continue;
          } else if ((isalpha(ch) != 0 || isdigit(ch) != 0) && con == 1) {       // if char is an alphabetic character
               words++;
                con = 0;
                ab = 0;
          }   else if (ch == '\n') {// if new line detected, increment newline count
                if (ab == 1){
                    lines++;
                    con = 0;
                }
                else {
                    lines++;
                    words++;
                    con = 0;
                    ab = 1;
                }

            }
        }
        words++;
                        // abc 123,/hds ... sdf.sfd ... sdf /., sdg
                        // 3 words           2 words      2 words
        //lines++;                                           // increase spaces (word) count by 1 to account for EOF
        printf("lines: %d\n", lines);
        printf("words: %d\n", words);
        printf("characters: %d\n", chars);


        rewind(a_file);                                                 // reset file to beginning

        while (g <= lines) {
            while (fscanf(a_file, "%c", &ch) != EOF) {          //scan in the characters in each line and store them in char_array
                if (ch == '\n') {
                    break;
                } else {
                    chars_line++;
                }
            }
            char_array[g - 1] = chars_line;                     // put the chars on each line into char_array
            g++;
            chars_line = 0;
        }

        while (p < lines) {                                     // sort the char_array in increasing order
            for (q = 0; q < lines - 1; q++) {
                if (char_array[q] > char_array[q + 1]) {
                    temp = char_array[q];
                    char_array[q] = char_array[q + 1];
                    char_array[q + 1] = temp;
                }
            }
            p++;
        }
//        for (int h = 0; h< lines-1; h++){
//            printf("%d ", char_array[h]);
//        }

        printf("Line with least characters (%d): ", char_array[0]+1);
        rewind(a_file);
        while (y <= lines) {                            // scan and print the line with the fewest characters
            while (fscanf(a_file, "%c", &c) != EOF) {
                if (c == '\n') {
                    break;
                } else {
                    chars_in_line[x] = c;
                    x++;
                }
            }
                if (x == char_array[0]) {
                    for (int t = 0; t < char_array[0]; t++) {
                        printf("%c", chars_in_line[t]);
                    }
                    break;
                }
                x = 0;
                y++;
             ////////////////
        }
        printf("\n");
        rewind(a_file);
        g = 1, p = 0;                       // reset the general count variables to be used again
        while (g <= lines) {                                                // scan in the number of words on each line and store them into word_array
            while (fscanf(a_file, "%c", &ch) != EOF) {
                if (ch == '\n') {
                    break;
                } else if (ch == ' ' || ch == '.' || ch == '\'') {                  // if the end of the word is encountered, increment the word count on that line
                    word_line++;
                }
            }
            word_line++;                         // plus one because the \n doesn't get read in as a space
            word_array[g - 1] = word_line;
            g++;
            word_line = 0;
        }


        while (p < lines) {                                 // sort word_array in increasing order
            for (q = 0; q < lines - 1; q++) {
                if (word_array[q] > word_array[q + 1]) {
                    temp = word_array[q];
                    word_array[q] = word_array[q + 1];
                    word_array[q + 1] = temp;
                }
            }
            p++;
        }

        printf("Line with least words (%d): ", word_array[0]);
//        for (int d = 0; d<lines-1; d++){
//            printf("%d ", word_array[d]);
//        }
        //printf("end");
        rewind(a_file);
        x=0, y=0;
        while (y <= lines) {                                // scan and print the line with the fewest words
            while (fscanf(a_file, "%c", &c) != EOF) {
                if (c == ' '){
                    r++;
                    chars_in_line2[x] = c;
                }
                else if (c == '\n') {
                    break;
                }
                else {
                    chars_in_line2[x] = c;
                }
                x++;
            }
            r++;
            //printf("wa:%d r:%d\n", word_array[0], r);
            if (r == word_array[0]){
                for (int t = 0; t<x; t++) {
                    printf("%c", chars_in_line2[t]);
                }
                break;
            }
            x=0;
            r=0;
            y++;
        }


        rewind(a_file);


        int v = 0, e = 0;                      // counters for how many words are in array

        while (fscanf(a_file, "%c", &str) != EOF) {              // scan in each word in the file, find its length, e, and store it in length_array
            if (str != '\'' && str != '.' && str != ' ' && str != '\n') {
                e++;
            } else {
                length_array[v] = e;
                e = 0;
                v++;
            }
        }

        p = 0;
        while (p < v) {                             // sort length_array in increasing order
            for (q = 0; q < v - 1; q++) {
                if (length_array[q] > length_array[q + 1]) {
                    temp = length_array[q];
                    length_array[q] = length_array[q + 1];
                    length_array[q + 1] = temp;
                }
            }
            p++;
        }


        char z_array[100];              // used to hold the length of each word (again) to compare lengths to the ones found previously
        e = 0;
        printf("\n");
        int a = 0, f = 0, h = 0;        // all are counters used to make sure program wont read in the same word as first and second longest if there is a duplicate
        rewind(a_file);

        while (fscanf(a_file, "%c", &str) != EOF) {                 // scan in each word in the file, find its length, e, and store it in z_array
            if (str != '\'' && str != '.' && str != ' ' && str != '\n') {
                z_array[e] = str;
                e++;

            } else {
                if (e == length_array[v - 1] && a ==
                                                0) {                       // once a whole word has been detected, compare it to the n-th longest word (that has been stored in length_array)
                    printf("longest word: ");
                    for (int u = 0; u < e; u++) {
                        printf("%c", z_array[u]);
                    }
                    printf("\n");
                    a++;                                        // this increment of a makes sure the program wont print out the longest word more than once
                    e = 0;
                    continue;
                } else if (e == length_array[v - 2] && f == 0) {
                    printf("Second longest word: ");
                    for (int u = 0; u < e; u++) {
                        printf("%c", z_array[u]);
                    }
                    printf("\n");
                    f++;
                    e = 0;
                    continue;
                } else if (e == length_array[v - 3] && h == 0) {
                    printf("Third longest word: ");
                    for (int u = 0; u < e; u++) {
                        printf("%c", z_array[u]);
                    }
                    printf("\n");
                    h++;
                    e = 0;
                    continue;
                }
                e = 0;
            }
        }
        fclose(a_file);
    }

}
