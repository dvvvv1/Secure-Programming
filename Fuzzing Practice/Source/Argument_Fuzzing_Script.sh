#!/bin/bash
LC_ALL=C;
LANG=C;
for i in {1000..1010};
do
zzuf -r 0.1 -s $i < Argument_Fuzzing_Sample.txt > in_argument/$i-Argument_Input.txt
file=$( cat in_argument/$i-Argument_Input.txt )
touch in_argument/$file
./comp/encoder in_argument/$file test.jpg 40; echo $file;
done &> Argument_Fuzzing.log
