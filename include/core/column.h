#ifndef MY_SQLITE_COLUMN_H
#define MY_SQLITE_COLUMN_H

#include <memory>
#include <string>
#include <vector>
#include <stdexcept>

template<typename T>
class Column {
private:
    std::string name_;
    std::vector<std::shared_ptr<T>> values_;
public:
    explicit Column(const std::string& name);
    Column(const Column&) = delete;
    Column& operator=(const Column&) = delete;
    Column(Column&&) = default;
    Column& operator=(Column&&) = default;

    void addValue(std::shared_ptr<T> value);

    std::shared_ptr<T> getValue(size_t index) const;

    const std::string& getName() const { return name_; }

    size_t size() const { return values_.size(); }

    bool empty() const { return values_.empty(); }
};

class ColumnException : public std::runtime_error {
public:
    explicit ColumnException(const std::string& msg)
        : std::runtime_error("Column error: " + msg) {}
};

#endif //MY_SQLITE_COLUMN_H