#include "../../include/core/row.h"

template<typename T>
void Row::addValue(std::shared_ptr<T> value) {
    values_.push_back(std::static_pointer_cast<void>(value));
}

template<typename T>
std::shared_ptr<T> Row::getValue(size_t columnIndex) const {
    if (columnIndex >= values_.size()) {
        throw RowException("Column index " + std::to_string(columnIndex) + 
                          " out of range (size: " + std::to_string(values_.size()) + ")");
    }
    return std::static_pointer_cast<T>(values_[columnIndex]);
}

template void Row::addValue<int>(std::shared_ptr<int>);
template void Row::addValue<double>(std::shared_ptr<double>);
template void Row::addValue<std::string>(std::shared_ptr<std::string>);

template std::shared_ptr<int> Row::getValue<int>(size_t) const;
template std::shared_ptr<double> Row::getValue<double>(size_t) const;
template std::shared_ptr<std::string> Row::getValue<std::string>(size_t) const;