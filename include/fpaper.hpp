// MIT License
//
// Copyright (c) 2021 Ferhat Geçdoğan All Rights Reserved.
// Distributed under the terms of the MIT License.
//
//

#ifndef FPAPER_FPAPER_HPP
#define FPAPER_FPAPER_HPP

#include <iostream>
#include <string>
#include <fstream>

class FPaper {
public:
    std::string raw;
public:
    FPaper() = default;
    ~FPaper()= default;

    void Init(std::string const filename) noexcept {
        std::ifstream file(filename);

        for(std::string temp; std::getline(file, temp);
            this->raw.append(temp + "\n"))
            ;
    }
};

#endif // FPAPER_FPAPER_HPP
