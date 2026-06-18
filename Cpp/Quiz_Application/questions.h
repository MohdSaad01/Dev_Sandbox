#ifndef QUESTIONS_H
#define QUESTIONS_H

#include <string>
#include <vector>

using namespace std;

struct Question
{
    string questionText;
    vector<string> options;
    char correctAnswer;
};

inline vector<Question> loadQuestions()
{
    vector<Question> questions =
    {
        {
            "What does CPU stand for?",
            {
                "A. Central Processing Unit",
                "B. Computer Personal Unit",
                "C. Central Program Utility",
                "D. Control Processing User"
            },
            'A'
        },

        {
            "Which language is primarily used for web page structure?",
            {
                "A. CSS",
                "B. JavaScript",
                "C. HTML",
                "D. Python"
            },
            'C'
        },

        {
            "Which symbol is used for single-line comments in C++?",
            {
                "A. /*",
                "B. //",
                "C. ##",
                "D. <!--"
            },
            'B'
        },

        {
            "Which data type stores whole numbers?",
            {
                "A. float",
                "B. double",
                "C. string",
                "D. int"
            },
            'D'
        },

        {
            "Which loop is guaranteed to execute at least once?",
            {
                "A. for",
                "B. while",
                "C. do-while",
                "D. range-for"
            },
            'C'
        },

        {
            "Which operator is used for assignment?",
            {
                "A. ==",
                "B. =",
                "C. !=",
                "D. >="
            },
            'B'
        },

        {
            "What is the extension of a C++ source file?",
            {
                "A. .html",
                "B. .java",
                "C. .cpp",
                "D. .py"
            },
            'C'
        },

        {
            "Which keyword is used to define a class in C++?",
            {
                "A. object",
                "B. define",
                "C. struct",
                "D. class"
            },
            'D'
        },

        {
            "Which container stores dynamic arrays in C++?",
            {
                "A. vector",
                "B. map",
                "C. queue",
                "D. stack"
            },
            'A'
        },

        {
            "Which function is used to display output in C++?",
            {
                "A. scanf()",
                "B. print()",
                "C. cout",
                "D. input()"
            },
            'C'
        }
    };

    return questions;
}

#endif