#include "ReportGenerator.h"

#include <fstream>
#include <ctime>
#include <iomanip>

void ReportGenerator::exportReport(
    const std::string& password,
    int score,
    double entropy,
    const std::string& strength
) {

    std::ofstream file("reports/security_report.txt");

    if (!file.is_open()) {
        return;
    }

    time_t now = time(0);

    file << "====================================\n";
    file << " PASSWORD SECURITY REPORT\n";
    file << "====================================\n\n";

    file << "Generated On : "
         << ctime(&now) << "\n";

    file << "Password Length : "
         << password.length() << "\n";

    file << "Password Score  : "
         << score << "/100\n";

    file << std::fixed << std::setprecision(2);

    file << "Entropy         : "
         << entropy << " bits\n";

    file << "Strength        : "
         << strength << "\n";

    file << "\n====================================\n";

    file.close();
}