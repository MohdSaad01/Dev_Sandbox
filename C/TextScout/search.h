#ifndef SEARCH_H
#define SEARCH_H

#define MAX_LINE_LENGTH 1024

int contains_text(const char *line, const char *query);
void search_file(const char *filename, const char *query);
int is_supported_file(const char *filename);

#endif