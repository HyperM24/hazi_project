#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define VERSION "v0.1"

void get_help() {
    printf("alap %s\n\n", VERSION);
    printf("Usage: alap <template_id> [option]\n\n");
    printf("Available options:\n");
    printf("-h, --help \t show this help\n");
    printf("-v, --version \t version info\n");
    printf("--stdout \t don't create source file, print result to stdout\n\n");
    printf("Available templates:\n");
    printf("* c \t - C source code [main.c]\n");
    printf("* sh \t - Bash source code [main.sh]\n");
    printf("* cs \t - C# source code [Program.cs]\n");
    printf("* py \t - Python source code [main.py]\n");
}

void fajlba(const char *fajl_nev, const char *tartalom) {
    FILE *file = fopen(fajl_nev, "w");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s", tartalom);
    fclose(file);
}

void kepernyore_kiir(const char *tartalom) {
    printf("%s", tartalom);
}

void mintak(const char *minta_id, int to_stdout) {
    const char *c = "#include <stdio.h>\n\nint main() {\n\tprintf(\"Hello World!\\n\");\n\treturn 0;\n}";
    const char *css = "namespace HelloWorld\n{\n\tclass Hello {\n\t\tstatic void Main(string[] args)\n\t\t{\n\t\t\tSystem.Console.WriteLine(\"Hello World!\");\n\t\t}\n\t}\n}";
    const char *py = "print(\"Hello World!\")";
    const char *sh = "#!/bin/bash\n\necho \"Hello Bash!\"";

    if (strcmp(minta_id, "c") == 0) {
        if (to_stdout) {
            kepernyore_kiir(c);
        } else {
            fajlba("main.c", c);
        }
    } else if (strcmp(minta_id, "cs") == 0) {
        if (to_stdout) {
            kepernyore_kiir(css);
        } else {
            fajlba("main.cs", css);
        }
    } else if (strcmp(minta_id, "py") == 0) {
        if (to_stdout) {
            kepernyore_kiir(py);
        } else {
            fajlba("main.py", py);
        }
    } else if (strcmp(minta_id, "sh") == 0) {
        if (to_stdout) {
            kepernyore_kiir(sh);
        } else {
            fajlba("main.sh", sh);
        }
    } else {
        printf("Error: Invalid template ID.\n");
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[]) {
    if (argc == 1 || (argc == 2 && (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0))) {
        get_help();
        return 0;
    }

    if (argc == 2 && (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0)) {
        printf("Alap version %s\n", VERSION);
        return 0;
    }

    if (argc < 2 || argc > 3) {
        printf("Error: Invalid number of arguments.\n");
        return 1;
    }

    if (argc == 2 || (argc == 3 && strcmp(argv[2], "--stdout") == 0)) {
        mintak(argv[1], (argc == 3 && strcmp(argv[2], "--stdout") == 0));
        return 0;
    }

    printf("Error: Invalid arguments.\n");
    return 1;
}
