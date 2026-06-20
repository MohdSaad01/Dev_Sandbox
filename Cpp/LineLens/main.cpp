#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

#include "diff.h"

void printHeader()
{
    std::cout << "=========================================\n";
    std::cout << "           LineDiff Viewer\n";
    std::cout << "=========================================\n\n";
}

void printSummary(
    const std::vector<std::string>& file1,
    const std::vector<std::string>& file2,
    const std::vector<Difference>& diffs
)
{
    std::cout << "\n------------- Summary -------------\n";
    std::cout << "File 1 Lines : " << file1.size() << '\n';
    std::cout << "File 2 Lines : " << file2.size() << '\n';
    std::cout << "Differences  : " << diffs.size() << '\n';
    std::cout << "-----------------------------------\n";
}

void printDifferences(const std::vector<Difference>& diffs)
{
    if (diffs.empty())
    {
        std::cout << "\nFiles are identical.\n";
        return;
    }

    std::cout << "\nDifferences Found:\n";

    for (const Difference& diff : diffs)
    {
        std::cout << "\n-----------------------------------\n";
        std::cout << "Line " << diff.lineNumber << '\n';

        std::cout << "File 1: ";

        if (diff.file1Line.empty())
        {
            std::cout << "<No Line>";
        }
        else
        {
            std::cout << diff.file1Line;
        }

        std::cout << '\n';

        std::cout << "File 2: ";

        if (diff.file2Line.empty())
        {
            std::cout << "<No Line>";
        }
        else
        {
            std::cout << diff.file2Line;
        }

        std::cout << '\n';
    }

    std::cout << "\n-----------------------------------\n";
}

int main()
{
    printHeader();

    std::string file1Name;
    std::string file2Name;

    std::cout << "Enter first file path: ";
    std::getline(std::cin, file1Name);

    std::cout << "Enter second file path: ";
    std::getline(std::cin, file2Name);

    std::vector<std::string> file1Lines;
    std::vector<std::string> file2Lines;

    if (!loadFile(file1Name, file1Lines))
    {
        std::cout << "\nError: Could not open first file.\n";
        return 1;
    }

    if (!loadFile(file2Name, file2Lines))
    {
        std::cout << "\nError: Could not open second file.\n";
        return 1;
    }

    std::vector<Difference> differences =
        compareFiles(file1Lines, file2Lines);

    printSummary(file1Lines, file2Lines, differences);

    printDifferences(differences);

    return 0;
}