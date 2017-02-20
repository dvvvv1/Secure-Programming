#!/bin/bash
LC_ALL=C;
LANG=C;
for i in {1000..2000};
do
zzuf -r 0.000001 -s $i < PNG_data_in_dir/PNG_data.txt > PNG_data_in_dir/$i-PNG.txt

cat PNG_data_in_dir/PNG_header.txt PNG_data_in_dir/$i-PNG.txt PNG_data_in_dir/PNG_end.txt> PNG_data_in_dir/$i-output.txt

xxd -r -ps PNG_data_in_dir/$i-output.txt > PNG_data_in_dir/$i-input.png

comp/./encoder PNG_data_in_dir/$i-input.png test.jpg 50;

done &> Fuzzing_Decimal.log