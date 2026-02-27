#ifndef MY_SQLITE_ROW_H
#define MY_SQLITE_ROW_H

#include <memory>
#include <vector>
#include <stdexcept>

class Row {
    private:
    std::vector<std::shared_ptr<void>> values_;
public:
    Row() = default;
    Row(const Row&) = delete;
    Row& operator=(const Row&) = delete;
    Row(Row&&) = default;
    Row& operator=(Row&&) = default;

    template<typename T>
    void addValue(std::shared_ptr<T> value);

    template<typename T>
    std::shared_ptr<T> getValue(size_t columnIndex) const;

    constexpr size_t size() const { return values_.size(); }

    constexpr bool empty() const { return values_.empty(); }

    // все значения (для тестов)
    const std::vector<std::shared_ptr<void>>& getValues() const { return values_; }
};

class RowException : public std::runtime_error {
public:
    explicit RowException(const std::string& msg)
        : std::runtime_error("Row error: " + msg) {}
};

#endif //MY_SQLITE_ROW_H