#ifndef PASSWORD_ANALYZER_H
#define PASSWORD_ANALYZER_H

#include <string>

class PasswordAnalyzer {
public:
    int calculateScore(const std::string& password);
    double calculateEntropy(const std::string& password);
    std::string getStrength(int score);

    bool isCommonPassword(const std::string& password);
    bool hasKeyboardPattern(const std::string& password);
    bool hasRepeatedCharacters(const std::string& password);
};

#endif