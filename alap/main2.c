#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define version "v0.1"

void get_help(){
printf("alap %s\n\n",version);
printf("Usage: alap <template_id> [option]\n\n");
printf("Avaliable options:\n\n");
printf("-h, --help \t show this help\n");
printf("-v, --version \t version info\n");
printf("--stdout \t don't create source file, print result to stdout\n\n");
printf("Avaliable templates:\n\n");
printf("* c \t - C source code [main.c]\n");
printf("* sh \t - Bash source code [main.sh]\n");
printf("* cs \t - C# source code [Program.cs]\n");
printf("* py \t - Python source code [main.py]\n");
}

void get_c(){

char* nev = "main.c";
FILE *file;
file = fopen(nev, "r");
if (file != NULL)
{
    printf("Hiba!");
}
else{
fclose(file);
file = fopen(nev, "w");
fprintf(file,"#include <stdio.h>\n\nint main(){\n\n\tprintf(\"Hello World!\");\n\n\treturn 0;\n}");
}
}


void get_cs(){
    
char* nev = "main.cs";
FILE *file;
file = fopen(nev, "r");
if (file != NULL)
{
    printf("Hiba!");
}
else{
fclose(file);
file = fopen(nev, "w");
fprintf(file,"namespace HelloWorld\n{\n\tclass Hello {\n\t\tstatic void Main(string[] args)\n\t\t{\n\t\t\tSystem.Console.WriteLine(\"Hello World!\");\n\t\t}\n\t}\n}");
}
}

void get_py(){

char* nev = "main.py";
FILE *file;
file = fopen(nev, "r");
if (file != NULL)
{
    printf("Hiba!");
}
else{
fclose(file);
file = fopen(nev, "w");
fprintf(file,"print(\"Hello World!\")");
}
}

void get_sh(){

char* nev = "main.sh";
FILE *file;
file = fopen(nev, "r");
if (file != NULL)
{
    printf("Hiba!");
}
else{
fclose(file);
file = fopen(nev, "w");
fprintf(file,"#!bin/bash\n\necho \"Hello Bash!\"");
}
}

int main(int argc, char *argv[]){

if (argc == 1)
{
    get_help(); 
    return 0;

}
if (argc > 3)
{
    printf("Hiba!");
    return 1;
}

if (argc == 2)
{
    if (strcmp(argv[1], "c") == 0)
    {
        get_c();
        return 0;
    }

    if (strcmp(argv[1],"cs") == 0)
    {
        get_cs();
        return 0;
    }
    
    if (strcmp(argv[1], "py") == 0)
    {
        get_py();
        return 0;
    }

    if (strcmp(argv[1],"sh") == 0)
    {
        get_sh();
        return 0;
    }
    
    printf("Hiba!");
    return 1;
    
}


if (argc == 3)
{
    if (strcmp(argv[2], "--stdout") == 0)
    {
    if (strcmp(argv[1], "c") == 0)
    {
        printf("#include <stdio.h>\n\nint main(){\n\n\tprintf(\"Hello World!\");\n\n\treturn 0;\n}");   
        return 0;
    }

    if (strcmp(argv[1],"cs") == 0)
    {
        printf("namespace HelloWorld\n{\n\tclass Hello {\n\t\tstatic void Main(string[] args)\n\t\t{\n\t\t\tSystem.Console.WriteLine(\"Hello World!\");\n\t\t}\n\t}\n}");
        return 0;
    }
    
    if (strcmp(argv[1], "py") == 0)
    {
        printf("print(\"Hello World!\");");
        return 0;
    }

    if (strcmp(argv[1],"sh") == 0)
    {
        printf("#!bin/bash\n\necho \"Hello Bash!\"");
        return 0;
    }
    
    printf("Hiba!");
    return 1;

    }
    else{
        printf("Hiba!");
        return 1;
    }
    
}




}