#include "CommandHandle.h"

bool AlgorithmHandle(int agrc, char *agrv[], Command &command)
{
    command.mode = Mode_Algorithm;
    // command line 1
    // groupid.[exe] -a Algorithm Input_file Output_parameter
    if (agrc == 5 && !IsNumber(agrv[3]) && IsOutputParam(agrv[4]))
    {
        command.cmd = Command_1;
        strcpy(command.algorithm_1, agrv[2]);
        strcpy(command.output_param, agrv[4]);
        strcpy(command.inputfile, agrv[3]);
        return true;
    }
    // command line 2
    // groupid.[exe] -a Algorithm Input_size Input_order Output_parameter
    if (agrc == 6 && IsNumber(agrv[3]) && IsInputOrder(agrv[4]) && IsOutputParam(agrv[5]))
    {
        command.cmd = Command_2;
        strcpy(command.algorithm_1, agrv[2]);
        strcpy(command.inputOrder, agrv[4]);
        strcpy(command.output_param, agrv[5]);
        command.inputsize = atoi(agrv[3]);
        return true;
    }
    // command line 3
    // > groupid.[exe] -a Algorithm Input_size Output_parameter
    if (agrc == 5 && IsNumber(agrv[3]) && IsOutputParam(agrv[4]))
    {
        command.cmd = Command_3;
        strcpy(command.algorithm_1, agrv[2]);
        command.inputsize = atoi(agrv[3]);
        strcpy(command.output_param, agrv[4]);
        return true;
    }
    return false;
}
bool ComparsionMode(int agrc, char *agrv[], Command &command)
{
    command.mode = Mode_Comparision;
    // command line 4
    // groupid.[exe] -c Algorithm_1 Algorithm_2 Input_file
    if (agrc == 5 && !IsNumber(agrv[4]))
    {
        command.cmd = Command_4;
        strcpy(command.algorithm_1, agrv[2]);
        strcpy(command.algorithm_2, agrv[3]);
        strcpy(command.inputfile, agrv[4]);
        return true;
    }
    // command line 5
    //> groupid.[exe] -c Algorithm_1 Algorithm_2 Input_size Input_order
    if (agrc == 6 && IsNumber(agrv[4]) && IsInputOrder(agrv[5]))
    {
        command.cmd = Command_5;
        strcpy(command.algorithm_1, agrv[2]);
        strcpy(command.algorithm_2, agrv[3]);
        command.inputsize = atoi(agrv[4]);
        strcpy(command.inputOrder,agrv[5]);
        return true;
    }
    return false;
}
bool Handle_command(int agrc,char *agrv[],Command &cmd){
    if (agrc < 2) return false;
    if(strcmp(agrv[1] , "-c") == 0) return ComparsionMode(agrc,agrv,cmd);
    if(strcmp(agrv[1] , "-a") == 0) return AlgorithmHandle(agrc,agrv,cmd);
    return false;
}