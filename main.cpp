#include<iostream>
#include "sorts.h" 
#include "Command_Runner.h"
using namespace std;
int main(int argc,char *argv[]){
    Command cmd;
    if(!Handle_command(argc,argv,cmd)){
        cout << "No cmt";
    }
    RunCommand(cmd);
    
}