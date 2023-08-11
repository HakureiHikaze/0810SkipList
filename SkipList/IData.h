//
// Created by guoyao.wan on 2023/8/11.
//
#pragma once


#include <cstddef>

template<typename T>
class IData {
public:
    virtual ~IData() = 0;
    virtual const T& GetIndex() = 0;
    virtual bool operator==(const IData& data_) = 0;
    virtual size_t hash() = 0;
    bool operator!=(const IData& data_){return *this == data_;}
};
