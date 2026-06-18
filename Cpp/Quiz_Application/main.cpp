#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <limits>
#include <cctype>

#include "questions.h"

using namespace std;

// =====================================
// Quiz Class
// =====================================

class Quiz
{
private:
    vector<Question> questions;
    int score;
    int correctAnswers;
    int incorrectAnswers;

public:
    Quiz()
    {
        questions = loadQuestions();
        score = 0;
        correctAnswers = 0;
        incorrectAnswers = 0;
    }

    void resetQuiz()
    {
        score = 0;
        correctAnswers = 0;
        incorrectAnswers = 0;
    }

    char getValidAnswer()
    {
        char answer;

        while (true)
        {
            cout << "\nEnter your answer (A/B/C/D): ";
            cin >> answer;

            answer = toupper(answer);

            if (answer == 'A' ||
                answer == 'B' ||
                answer == 'C' ||
                answer == 'D')
            {
                return answer;
            }

            cout << "Invalid choice. Please enter A, B, C, or D.\n";
        }
    }

    void startQuiz()
    {
        resetQuiz();

        vector<Question> shuffledQuestions = questions;

        random_device rd;
        mt19937 generator(rd());

        shuffle(
            shuffledQuestions.begin(),
            shuffledQuestions.end(),
            generator);

        cout << "\n========================================\n";
        cout << "              QUIZ STARTED\n";
        cout << "========================================\n";

        for (size_t i = 0; i < shuffledQuestions.size(); i++)
        {
            cout << "\n----------------------------------------\n";
            cout << "Question " << i + 1 << "\n";
            cout << "----------------------------------------\n";

            cout << shuffledQuestions[i].questionText << "\n\n";

            for (const string& option : shuffledQuestions[i].options)
            {
                cout << option << endl;
            }

            char userAnswer = getValidAnswer();

            if (userAnswer == shuffledQuestions[i].correctAnswer)
            {
                cout << "Correct!\n";
                score++;
                correctAnswers++;
            }
            else
            {
                cout << "Incorrect!\n";
                cout << "Correct Answer: "
                     << shuffledQuestions[i].correctAnswer
                     << "\n";

                incorrectAnswers++;
            }
        }

        displayResults();
    }

    void displayResults()
    {
        double percentage =
            (static_cast<double>(score) / questions.size()) * 100;

        cout << "\n========================================\n";
        cout << "             QUIZ RESULTS\n";
        cout << "========================================\n";

        cout << "Total Questions : " << questions.size() << endl;
        cout << "Correct Answers : " << correctAnswers << endl;
        cout << "Wrong Answers   : " << incorrectAnswers << endl;
        cout << "Score           : "
             << score
             << "/"
             << questions.size()
             << endl;

        cout << "Percentage      : "
             << percentage
             << "%\n";

        cout << "\nPerformance: ";

        if (percentage >= 90)
        {
            cout << "Excellent\n";
        }
        else if (percentage >= 70)
        {
            cout << "Good\n";
        }
        else if (percentage >= 50)
        {
            cout << "Average\n";
        }
        else
        {
            cout << "Needs Improvement\n";
        }

        cout << "========================================\n";
    }

    void displayInstructions()
    {
        cout << "\n========================================\n";
        cout << "             INSTRUCTIONS\n";
        cout << "========================================\n";

        cout << "1. The quiz contains 10 questions.\n";
        cout << "2. Each question has four options.\n";
        cout << "3. Enter A, B, C, or D.\n";
        cout << "4. Each correct answer earns 1 point.\n";
        cout << "5. Results are displayed at the end.\n";

        cout << "========================================\n";
    }
};

// =====================================
// Utility Functions
// =====================================

int getValidMenuChoice()
{
    int choice;

    while (true)
    {
        cout << "\nEnter your choice: ";

        if (cin >> choice)
        {
            if (choice >= 1 && choice <= 3)
            {
                return choice;
            }
        }

        cout << "Invalid menu choice. Please try again.\n";

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

// =====================================
// Main Function
// =====================================

int main()
{
    Quiz quiz;
    int choice;

    do
    {
        cout << "\n========================================\n";
        cout << "           QUIZ APPLICATION\n";
        cout << "========================================\n";

        cout << "1. Start Quiz\n";
        cout << "2. View Instructions\n";
        cout << "3. Exit\n";

        choice = getValidMenuChoice();

        switch (choice)
        {
        case 1:
            quiz.startQuiz();
            break;

        case 2:
            quiz.displayInstructions();
            break;

        case 3:
            cout << "\nThank you for using Quiz Application.\n";
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid choice.\n";
        }

    } while (choice != 3);

    return 0;
}