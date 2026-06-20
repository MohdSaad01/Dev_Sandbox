#ifndef DIFF_H
#define DIFF_H

#include <string>
#include <vector>

struct Difference
{
    int lineNumber;
    std::string file1Line;
    std::string file2Line;
};

bool loadFile(const std::string& filename, std::vector<std::string>& lines);

std::vector<Difference> compareFiles(
    const std::vector<std::string>& file1,
    const std::vector<std::string>& file2
);

#endif