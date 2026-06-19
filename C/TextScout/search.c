#include <stdio.h>
#include <string.h>
#include "search.h"

int contains_text(const char *line, const char *query)
{
    return strstr(line, query) != NULL;
}

int is_supported_file(const char *filename)
{
    const char *extensions[] = {
        ".txt",
        ".c",
        ".h",
        ".cpp",
        ".py",
        ".java",
        ".md",
        ".html",
        ".css",
        ".js",
        ".csv"
    };

    int count = sizeof(extensions) / sizeof(extensions[0]);

    const char *dot = strrchr(filename, '.');

    if (dot == NULL)
    {
        return 0;
    }

    for (int i = 0; i < count; i++)
    {
        if (strcmp(dot, extensions[i]) == 0)
        {
            return 1;
        }
    }

    return 0;
}

void search_file(const char *filename, const char *query)
{
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("\nError: Could not open file '%s'\n", filename);
        return;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;
    int matches = 0;

    printf("\n========================================\n");
    printf("Search Results\n");
    printf("========================================\n");
    printf("File: %s\n", filename);
    printf("Search Term: \"%s\"\n", query);
    printf("----------------------------------------\n");

    while (fgets(line, sizeof(line), file) != NULL)
    {
        line_number++;

        if (contains_text(line, query))
        {
            matches++;

            printf("[Line %d] %s", line_number, line);

            if (line[strlen(line) - 1] != '\n')
            {
                printf("\n");
            }
        }
    }

    printf("----------------------------------------\n");
    printf("Lines Checked : %d\n", line_number);
    printf("Matches Found : %d\n", matches);
    printf("========================================\n");

    fclose(file);
}