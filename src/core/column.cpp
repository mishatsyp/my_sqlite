#include "../../include/core/column.h"

template<typename T>
Column<T>::Column(const std::string& name) : name_(name) {}

template<typename T>
void Column<T>::addValue(std::shared_ptr<T> value) {
    values_.push_back(value);
}

template<typename T>
std::shared_ptr<T> Column<T>::getValue(size_t index) const {
    if (index >= values_.size()) {
        throw ColumnException("Index " + std::to_string(index) + 
                             " out of range (size: " + std::to_string(values_.size()) + ")");
    }
    return values_[index];
}

template class Column<int>;
template class Column<double>;
template class Column<std::string>;