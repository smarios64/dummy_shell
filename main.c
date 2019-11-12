#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void processCommand(char *cmd) 
{
    if (strcmp(cmd, "help") == 0) {
        printf("Commands are...\n"
            "  help\t\tprint this message\n"
            "  quit\t\texit the program\n"
        );
    }
    else if (strcmp(cmd, "quit") == 0) {
        exit(0);
    }
    else {
        printf("unrecognised command... type 'help' if needed\n");
    }
}

int main(int argc, char **argv)
{
    char *buffer;
    size_t buf_size = 32;
    buffer = (char*)malloc(sizeof(char) * buf_size);
    if (buffer == NULL) {
        perror("Unable to allocate buffer.");
        exit(1);
    }
    while (1) {
        printf("dummy_shell> ");
        getline(&buffer, &buf_size, stdin);
        buffer[strlen(buffer) - 1] = 0; // remove carriage return
        if (strlen(buffer) > 0) {
            processCommand(buffer);
        }
    }
    return 0;
}
