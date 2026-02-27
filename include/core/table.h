#ifndef MY_SQLITE_TABLE_H
#define MY_SQLITE_TABLE_H

#include <memory>
#include <string>
#include <vector>
#include <unordered_map>
#include <any>
#include <stdexcept>
#include <algorithm>
#include "column.h"
#include "row.h"

class Table {
private:
    std::string name_;
    std::unordered_map<std::string, std::any> columns_;
    std::vector<std::unique_ptr<Row>> rows_;
public:
    void ensureColumnExists(const std::string& columnName) const;
    void ensureRowIndex(size_t rowIndex) const;

    template<typename T>
    Column<T>& getColumnRef(const std::string& columnName) {
        auto it = columns_.find(columnName);
        if (it == columns_.end()) {
            throw std::runtime_error("Column '" + columnName + "' does not exist");
        }
        return *std::any_cast<std::unique_ptr<Column<T>>>(it->second);
    }

    template<typename T>
    const Column<T>& getColumnRef(const std::string& columnName) const {
        auto it = columns_.find(columnName);
        if (it == columns_.end()) {
            throw std::runtime_error("Column '" + columnName + "' does not exist");
        }
        return *std::any_cast<const std::unique_ptr<Column<T>>>(it->second);
    }
    //...?
};

#endif //MY_SQLITE_TABLE_H