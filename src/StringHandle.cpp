#include "StringHandle.h"

bool IsNumber(const char*s){
    if(s == 0 || s[0] == '\0') return false;
    for(int i= 0; s[i] != '\0';i++){
        if(!isdigit(s[i])) return false;
    }
    return true;
}
bool IsOutputParam(const char*s){
    return strcmp(s,"-time" ) == 0 || strcmp(s,"-comp") == 0|| strcmp(s,"-both") == 0;
}
bool IsInputOrder(const char *s){
    return strcmp(s,"-nsorted") == 0 || strcmp(s,"-rev") == 0||strcmp(s,"-rand") == 0 || strcmp(s,"-sorted") == 0;
}

