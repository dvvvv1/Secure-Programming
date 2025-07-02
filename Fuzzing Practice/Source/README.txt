## Secure Programming ##
## Assignment 1 Fuzzing##

Author: pz.yao
Email: a1205593@student.adelaide.edu.au
---------------------

## Instructions ##
## Prerequisite ##
Linux system and make sure all files in zip are successfully extracted. File list shown below:

"comp/": This folder contains the compiled code of Encoder.
"in_argument/": This folder contains the generated input argument files.
"in_dir/": This folder contains the generated sample PNG images.
"results/": This folder contains the founded bugs and its related input, output and debug information.
"PNG_data_in_dir/": This folder contains the decimal file of PNG header, data and end parts.

"Argument_Fuzzing_Script.sh": Fuzzing script is used to automatically generate argument files.
"Argument_Fuzzing_Sample.txt": Sample input for zzuf.
"Argument_Fuzzing.log": Fuzzing results of argument.
"example.png": Sample input for zzuf PNG generation.
"PNG_Fuzzing_Script.cpp": Fuzzing script for generating PNG images and feed in Encoder.
"PNG_Fuzzing.log": Fuzzing results of PNG images.
"Fuzzing_Decimal_Image_Script.sh": This script will fuzz the decimal data part of PNG files and generate new PNG images to test Encoder.
"Fuzzing_Decimal.log": Fuzzing results of decimal method.
"Makefile": It is used to compile the PNG_Fuzzing_Script.cpp.

## Run ##
## Fuzzing for PNG image input##

1. Go into the directory (Assignment 1).

2. Open a terminal and run the following commands (Compile the PNG_Fuzzing_Script.cpp).

   "$ Make" 

3. Run PNG_Fuzzing_Script (Generate 2000 Fuzzed PNG images in in_dir folder and test them with encoder)

   "$ ./PNG_Fuzzing_Script"

4. Read results in PNG_Fuzzing.log

5. Run following command in terminal to debug encoder.

   "$ gdb comp/./encoder"

6. In debug mode, run following command to debug each Segmentation fault.

   "$ run in_dir/xxxx-example.png test.jpg 50"

7. Quit debug mode.

8. Run following command in terminal to show memeroy info for Segmentation fault.

  "$ valgrind --leak-check=full -v comp/./encoder in_dir/xxxx-example.png test.jpg 50"

---------------------

## Fuzzing for argument input ##

1. Go into the directory (Assignment 1).

2. Open a terminal and run the following command to run the bash script.

   "$ bash Argument_Fuzzing_Script.sh" 

3. Read results in Argument_Fuzzing.log

4. Run following command in terminal to debug encoder.

   "$ gdb comp/./encoder"

5. In debug mode, run following command to debug each Segmentation fault.

   "$ run in_argument/�vv!ng* test.jpg 50"

6. Quit debug mode.

7. Run following command in terminal to show memeroy info for Segmentation fault.

  "$ valgrind --leak-check=full -v comp/./encoder in_argument/�vv!ng* test.jpg 50"

---------------------

## Fuzzing for Decimal PNG File ##

1. Go into the directory (Assignment 1).

2. Open a terminal and run the following command to run the bash script.

   "$ bash Fuzzing_Decimal_Image_Script.sh" 

3. Read results in Fuzzing_Decimal.log

4. No bug find in this fuzzing method.


## Instruction END ##
