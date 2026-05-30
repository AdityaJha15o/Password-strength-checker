#include "PasswordAnalyzer.h"
#include <cctype>
#include <cmath>
#include <vector>

int PasswordAnalyzer::calculateScore(const std::string& password) {

    int score = 0;

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    if (password.length() >= 8)
        score += 20;

    for (char ch : password) {

        if (std::isupper(ch))
            hasUpper = true;

        else if (std::islower(ch))
            hasLower = true;

        else if (std::isdigit(ch))
            hasDigit = true;

        else
            hasSpecial = true;
    }

    if (hasUpper)
        score += 20;

    if (hasLower)
        score += 20;

    if (hasDigit)
        score += 20;

    if (hasSpecial)
        score += 20;

    return score;
}

double PasswordAnalyzer::calculateEntropy(const std::string& password) {

    int poolSize = 0;

    bool hasUpper = false;
    bool hasLower = false;
    bool hasDigit = false;
    bool hasSpecial = false;

    for (char ch : password) {

        if (std::isupper(ch))
            hasUpper = true;

        else if (std::islower(ch))
            hasLower = true;

        else if (std::isdigit(ch))
            hasDigit = true;

        else
            hasSpecial = true;
    }

    if (hasUpper)
        poolSize += 26;

    if (hasLower)
        poolSize += 26;

    if (hasDigit)
        poolSize += 10;

    if (hasSpecial)
        poolSize += 32;

    if (poolSize == 0)
        return 0;

    return password.length() * std::log2(poolSize);
}

std::string PasswordAnalyzer::getStrength(int score) {

    if (score >= 80)
        return "STRONG";

    if (score >= 50)
        return "MEDIUM";

    return "WEAK";
}

bool PasswordAnalyzer::isCommonPassword(const std::string& password) {

    std::vector<std::string> commonPasswords = {
        "123456",
        "12345678",
        "password",
        "qwerty",
        "admin",
        "welcome",
        "password123",
        "admin123"
    };

    for (const auto& common : commonPasswords) {

        if (password == common)
            return true;
    }

    return false;
}

bool PasswordAnalyzer::hasKeyboardPattern(const std::string& password) {

    std::vector<std::string> patterns = {
        "qwerty",
        "asdfgh",
        "zxcvbn",
        "123456",
        "654321"
    };

    for (const auto& pattern : patterns) {

        if (password.find(pattern) != std::string::npos)
            return true;
    }

    return false;
}

bool PasswordAnalyzer::hasRepeatedCharacters(const std::string& password) {

    int count = 1;

    for (size_t i = 1; i < password.length(); i++) {

        if (password[i] == password[i - 1]) {

            count++;

            if (count >= 3)
                return true;
        }
        else {
            count = 1;
        }
    }

    return false;
}