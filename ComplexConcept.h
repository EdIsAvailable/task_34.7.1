
#pragma once

#include <concepts>
#include <string>
#include <type_traits>

// Концепт ComplexConcept с ограничениями для типа T
template <typename T>
concept ComplexConcept = requires(T t) {
    // 1. Наличие у типа T метода hash(), который возвращает тип, конвертируемый в long
    { t.hash() } -> std::convertible_to<long>;
    
    // 2. Наличие у типа T метода toString(), который возвращает std::string
    { t.toString() } -> std::same_as<std::string>;
    
    // 3. Отсутствие у типа T виртуального деструктора
    requires !std::has_virtual_destructor<T>::value;
};

// Класс, удовлетворяющий концепту ComplexConcept
class ValidType {
public:
    long hash() const;
    std::string toString() const;
    // Обычный (не виртуальный) деструктор
    ~ValidType() = default;
};

// Класс, не удовлетворяющий концепту из-за виртуального деструктора
class InvalidType {
public:
    long hash() const;
    std::string toString() const;
    // Виртуальный деструктор
    virtual ~InvalidType() = default;
};

// Функция, принимающая только типы, удовлетворяющие концепту
template <ComplexConcept T>
void process(const T& obj);