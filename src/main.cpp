#include <iostream>
#include <iomanip>

#include "PasswordAnalyzer.h"
#include "ReportGenerator.h"

using namespace std;

void analyzePassword() {

    PasswordAnalyzer analyzer;
    ReportGenerator report;

    string password;

    cout << "\nEnter Password: ";
    cin >> password;

    int score = analyzer.calculateScore(password);

    double entropy =
        analyzer.calculateEntropy(password);

    string strength =
        analyzer.getStrength(score);

    cout << "\n====================================";
    cout << "\n      PASSWORD SECURITY REPORT";
    cout << "\n====================================\n";

    cout << "Password Length : "
         << password.length() << endl;

    cout << "Password Score  : "
         << score << "/100" << endl;

    cout << fixed << setprecision(2);

    cout << "Entropy         : "
         << entropy << " bits" << endl;

    cout << "Strength        : "
         << strength << endl;

    cout << "\nWarnings:\n";

    bool warningFound = false;

    if (analyzer.isCommonPassword(password)) {

        cout << "- Common Password Detected\n";
        warningFound = true;
    }

    if (analyzer.hasKeyboardPattern(password)) {

        cout << "- Keyboard Pattern Detected\n";
        warningFound = true;
    }

    if (analyzer.hasRepeatedCharacters(password)) {

        cout << "- Repeated Characters Detected\n";
        warningFound = true;
    }

    if (!warningFound) {

        cout << "- No Major Security Issues Found\n";
    }

    report.exportReport(
        password,
        score,
        entropy,
        strength
    );

    cout << "\nReport saved successfully.\n";
}

int main() {

    int choice;

    do {

        cout << "\n====================================";
        cout << "\n   PASSWORD SECURITY ANALYZER";
        cout << "\n====================================\n";

        cout << "1. Analyze Password\n";
        cout << "2. Exit\n";

        cout << "\nEnter Choice: ";
        cin >> choice;

        switch (choice) {

        case 1:

            analyzePassword();
            break;

        case 2:

            cout << "\nThank You!\n";
            break;

        default:

            cout << "\nInvalid Choice!\n";
        }

    } while (choice != 2);

    return 0;
}