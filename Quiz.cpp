#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("questions.txt");
    if (!file) {
        cerr << "Error: Could not open questions.txt\n";
        return 1;
    }

    string question, option;
    char correctAnswer, userAnswer;
    int score = 0, total = 0;

    while (getline(file, question)) {
        if (question.empty()) continue; // skip empty lines

        cout << "\n" << question << "\n";

        // Print 4 options
        for (int i = 0; i < 4; i++) {
            getline(file, option);
            cout << option << "\n";
        }

        // Read correct answer
        file >> correctAnswer;
        file.ignore(); // skip newline after correct answer

        cout << "Your answer (a/b/c/d): ";
        cin >> userAnswer;

        if (tolower(userAnswer) == tolower(correctAnswer)) {
            cout << "Correct!\n";
            score++;
        } else {
            cout << "Wrong! Correct answer was " << correctAnswer << ".\n";
        }
        total++;
    }

    cout << "\n===== Quiz Finished =====\n";
    cout << "Your score: " << score << "/" << total << "\n";

    return 0;
}
