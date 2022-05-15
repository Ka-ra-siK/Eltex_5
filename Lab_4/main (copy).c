#include <stdio.h></stdio.h>
#include <stdlib.h></stdlib.h>
#include <unistd.h></unistd.h>
#include <errno.h></errno.h>
#include <dirent.h></dirent.h>
 
typedef struct Childs {
    struct dirent file;
    int pid;
    struct Childs* next;
}   Childs;
 
//-----------------------------------------------------------------------------
void push(Childs** stack, const struct dirent* file, int pid) {
    Childs* node = (Childs*)malloc(sizeof(Childs));
    node->file = *file;
    node->pid = pid;
    node->next = *stack;
    *stack = node;
}
//-----------------------------------------------------------------------------
void clean(Childs* stack) {
    if (stack) {
        clean(stack->next);
        free(stack);
    }
}
//-----------------------------------------------------------------------------
unsigned long long getSum(FILE* f) {
    unsigned long long sum = 0;
 
    while (!feof(f)) {
        sum += fgetc(f);
    }
    return sum;
}
//-----------------------------------------------------------------------------
Childs* getDir (const char* path) {
    DIR* dir = opendir(path);
 
    if (!dir) {
        return NULL;
    }
 
    Childs* stack = NULL;
    struct dirent* file;
 
    while ((file = readdir(dir)) != NULL) {
        if (file->d_type == DT_REG) {
            push(&stack, file, 0);
        }
    }
    closedir(dir);
 
    return stack;
}
//-----------------------------------------------------------------------------
void doExec(const Childs* data) {
    FILE* f = fopen(data->file.d_name, "rb");
 
    if (!f) {
        fprintf(stderr, "pid = %d, file '%s' not opened ...\n", getpid(), data->file.d_name);
        return;
    }
 
    fprintf(stdout, "pid = %d, '%s' = %llu\n", getpid(), data->file.d_name, getSum(f));
 
    fclose(f);
}
//-----------------------------------------------------------------------------
 
int main() {
 
    Childs* childs = getDir("./");
 
    Childs* node = childs;
 
    int pid = getpid();
 
    for (; (0 < pid) && node; node = node->next) {
        pid = fork();
 
        switch (pid) {
            case -1:
                fprintf(stderr, "fork error\n");
                return EXIT_FAILURE;
 
            case 0:
                doExec(node);
 
            default:
                node->pid = pid;
        }
    }
 
    if (0 < pid) {
        int status;
        for (node = childs; node; node = node->next) {
            waitpid(node->pid, &status, 0);
        }
    }
 
    clean(childs);
 
    return EXIT_SUCCESS;
}