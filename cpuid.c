/**
 * @file cpuid.c
 * @author Caleb Fonyuy (fonyuyca@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2022-07-18
 * 
 * @copyright Copyright (c) 2022
 * 
 */



#include <stdio.h>
#include <cpuid.h>
#include <string.h>
#include <stdlib.h>

void print_value(char* label, unsigned int reg){
    char output[5];
    strncpy(output, (char *)&reg, 4);
    output[4] = '\0';

    printf("%s: %s\n", label,output);
}
void print_raw_value(char* label, int reg){
    printf("%s: %x\n", label, reg);
}
int main(int argsz, char *args[]){
    unsigned int eax=0, ebx=0, ecx=0, edx=0;
    unsigned int eax_in, ecx_in;

    if(argsz<2){
        printf("EAX value not supplied. Exiting...\n\n");
        exit(1);
    }

    sscanf(args[1], "%x", &eax_in);
    if(argsz>2){
        sscanf(args[2], "%x", &ecx_in);
    }else{
        ecx_in = 0x01;
    }

    printf("INPUTS\n EAX: %d\n ECX: %d\n\nOUTPUTS\n", eax_in, ecx_in);

    if(!ecx_in){
        __get_cpuid_count(eax_in, ecx_in, &eax, &ebx, &ecx, &edx);
    }else{
        __get_cpuid(eax_in, &eax, &ebx, &ecx, &edx);
    }

    print_raw_value("EAX", eax);
    print_raw_value("EBX", ebx );
    // print_value("EBX", ebx );
    print_raw_value("EDX", edx );
    // print_value("EDX", edx );
    print_raw_value("ECX", ecx );
    // print_value("ECX", ecx );
}