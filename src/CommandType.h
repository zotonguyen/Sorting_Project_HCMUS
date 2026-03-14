#pragma once
enum Mode
{
    Mode_invalid,
    Mode_Algorithm,
    Mode_Comparision
};
enum CommandType
{
    Command_Invalid,
    Command_1,
    Command_2,
    Command_3,
    Command_4,
    Command_5,
};
struct Command
{
    Mode mode;
    CommandType cmd;
    char inputfile[50];
    char algorithm_1[50];
    char algorithm_2[50];
    char inputOrder[50];
    long long inputsize=0;
    char output_param[50];
    Command(){
        mode = Mode_invalid;
        cmd = Command_Invalid;
        algorithm_1[0] = '\0';
        inputfile[0] = '\0';
        algorithm_2[0] = '\0';
        inputOrder[0] = '\0';
        inputsize = 0;
        output_param[0] = '\0';
    }
};
