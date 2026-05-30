#ifndef REPORT_GENERATOR_H
#define REPORT_GENERATOR_H

#include <string>

class ReportGenerator {

public:

    void exportReport(
        const std::string& password,
        int score,
        double entropy,
        const std::string& strength
    );
};

#endif