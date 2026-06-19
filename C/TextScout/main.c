#include <stdio.h>
#include <string.h>
#include "search.h"

void clear_input_buffer(void)
{
    int ch;

    while ((ch = getchar()) != '\n' && ch != EOF)
    {
    }
}

int main(void)
{
    char filename[256];
    char query[256];
    int choice;

    printf("========================================\n");
    printf("          LineFinder Utility\n");
    printf("========================================\n");

    while (1)
    {
        printf("\nMenu\n");
        printf("1. Search File\n");
        printf("2. Exit\n");
        printf("Choose an option: ");

        if (scanf("%d", &choice) != 1)
        {
            printf("Invalid input.\n");
            clear_input_buffer();
            continue;
        }

        clear_input_buffer();

        switch (choice)
        {
            case 1:

                printf("\nEnter file name: ");
                fgets(filename, sizeof(filename), stdin);

                filename[strcspn(filename, "\n")] = '\0';

                if (strlen(filename) == 0)
                {
                    printf("File name cannot be empty.\n");
                    break;
                }

                if (!is_supported_file(filename))
                {
                    printf("\nUnsupported file type.\n");
                    printf("Supported types:\n");
                    printf(".txt  .c  .h  .cpp\n");
                    printf(".py   .java  .md\n");
                    printf(".html .css   .js\n");
                    printf(".csv\n");
                    break;
                }

                printf("Enter search text: ");
                fgets(query, sizeof(query), stdin);

                query[strcspn(query, "\n")] = '\0';

                if (strlen(query) == 0)
                {
                    printf("Search text cannot be empty.\n");
                    break;
                }

                search_file(filename, query);
                break;

            case 2:
                printf("Exiting TextScout...\n");
                return 0;

            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}