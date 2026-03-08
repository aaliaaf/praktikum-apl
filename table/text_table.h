#ifndef TEXT_TABLE_H
#define TEXT_TABLE_H

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

class TextTable {
public:
    TextTable(char horizontal = '-', char vertical = '|', char corner = '+')
        : h_(horizontal), v_(vertical), c_(corner) {}

    void add(std::vector<std::string> row) {
        rows_.push_back(row);
        for (size_t i = 0; i < row.size(); ++i) {
            if (i >= width_.size()) {
                width_.push_back(row[i].length());
            } else {
                width_[i] = std::max(width_[i], row[i].length());
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const TextTable& table) {
        // Top border
        os << table.c_;
        for (size_t j = 0; j < table.width_.size(); ++j) {
            for (size_t k = 0; k < table.width_[j] + 2; ++k) {
                os << table.h_;
            }
            os << table.c_;
        }
        os << "\n";
        
        // Header row (first row)
        if (!table.rows_.empty()) {
            os << table.v_;
            for (size_t j = 0; j < table.rows_[0].size(); ++j) {
                os << " " << std::left << std::setw(table.width_[j]) 
                   << table.rows_[0][j] << " " << table.v_;
            }
            os << "\n";
            
            // Separator line after header
            os << table.c_;
            for (size_t j = 0; j < table.width_.size(); ++j) {
                for (size_t k = 0; k < table.width_[j] + 2; ++k) {
                    os << table.h_;
                }
                os << table.c_;
            }
            os << "\n";
        }
        
        // Data rows (skip first row which is header)
        for (size_t i = 1; i < table.rows_.size(); ++i) {
            os << table.v_;
            for (size_t j = 0; j < table.rows_[i].size(); ++j) {
                os << " " << std::left << std::setw(table.width_[j]) 
                   << table.rows_[i][j] << " " << table.v_;
            }
            os << "\n";
        }
        
        // Bottom border
        os << table.c_;
        for (size_t j = 0; j < table.width_.size(); ++j) {
            for (size_t k = 0; k < table.width_[j] + 2; ++k) {
                os << table.h_;
            }
            os << table.c_;
        }
        os << "\n";
        
        return os;
    }

private:
    char h_, v_, c_;
    std::vector<std::vector<std::string>> rows_;
    std::vector<size_t> width_;
};

#endif