//Test script
//Author: pz.yao
//Date: 23 Aug 2016

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/wait.h> 
#include <iostream>
#include <unistd.h> 
#include <string>
#include <sstream>

using namespace std;

int main(void)
{
  cout <<endl;
  cout <<"1. Fuzzing script for encoder start !"<<endl;
  cout <<"2. Generating Sample PNG pictures ..."<<endl;
  for(int i = 1000; i <= 3000; i++)
    {
      //generate testing PNG pictures
      string input1 = "zzuf -r 0.01 -s ";
      string input11 = " < \"example.png\" > ";
      string input2 = "\"in_dir/";
      ostringstream temp;  //temp as in temporary
      temp<<i;
      string inputI =  temp.str();
      string input4 = "-example.png\"";
      string input = input1 +inputI + input11+ input2 + inputI + input4;
      //cout <<input<<endl;
      const char * command = input.c_str();
      int sys = system(command);
    }
  cout <<"3. Generation success !"<<endl;
  cout <<"4. 2000 Sample Testing PNG pictures have been generated in in_dir folder"<<endl;
  cout <<"5. Start using PNG pictures as input to feed encode program ... " <<endl;
  cout <<"6. Clear previous fuzzing log" << endl;
  
  //clear previous fuzzing log
  string clearLog = "echo \"\" > PNG_Fuzzing.log";
  const char * clearCom = clearLog.c_str();
  int runCom = system(clearCom);

  cout <<"7. Start fuzzing ..."<<endl;
  //use generated PNG picture as input to feed encoder program
  for(int i = 1000; i <= 3000; i++)
    {
      string tmpS1 = "LC_ALL=C; LANG=C; timeout 3 comp/./encoder in_dir/";
      ostringstream temp;  //temp as in temporary
      temp<<i;
      string inputI =  temp.str();
      string tmpS3 = "-example.png /tmp/test.jpg 50 >> PNG_Fuzzing.log 2>&1";
      string input = tmpS1 + inputI + tmpS3;
      //cout << input << endl;
      const char * command2 = input.c_str();
      int sys = system(command2);
    }
  cout <<endl;

  //show result
  cout <<"8. Printing Error result ..."<<endl;
  cout <<endl;
  string print = "grep -C2 \"Segmentation fault\" PNG_Fuzzing.log";
  const char * printRes = print.c_str();
  int sysPrint = system(printRes);
  cout <<endl;
  cout <<"9. Completed ! Detail see PNG_Fuzzing.log"<<endl;
  cout <<endl;
  return 0;
}
