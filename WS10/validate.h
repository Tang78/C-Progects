#pragma once
#ifndef SICT_VALIDATE_H
#define SICT_VALIDATE_H
template<typename T>
bool validate(const T& min, const T* testValues, size_t numTestValues, bool* results) {
    bool allValid = true;
    for (size_t i = 0; i < numTestValues; ++i) {
        results[i] = (testValues[i] >= min);
        allValid = allValid && results[i];
    }
    return allValid;
}
#endif