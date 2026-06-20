#include "diff.h"

#include <fstream>
#include <algorithm>

bool loadFile(const std::string& filename, std::vector<std::string>& lines)
{
    std::ifstream file(filename);

    if (!file.is_open())
    {
        return false;
    }

    std::string line;

    while (std::getline(file, line))
    {
        lines.push_back(line);
    }

    return true;
}

std::vector<Difference> compareFiles(
    const std::vector<std::string>& file1,
    const std::vector<std::string>& file2
)
{
    std::vector<Difference> differences;

    size_t maxLines = std::max(file1.size(), file2.size());

    for (size_t i = 0; i < maxLines; i++)
    {
        std::string line1 = "";
        std::string line2 = "";

        if (i < file1.size())
        {
            line1 = file1[i];
        }

        if (i < file2.size())
        {
            line2 = file2[i];
        }

        if (line1 != line2)
        {
            Difference diff;

            diff.lineNumber = static_cast<int>(i + 1);
            diff.file1Line = line1;
            diff.file2Line = line2;

            differences.push_back(diff);
        }
    }

    return differences;
}