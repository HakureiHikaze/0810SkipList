//
// Created by guoyao.wan on 2023/8/10.
//
#pragma once
#include <vector>
#include "IData.h"


template <typename Type>
class SkipListNode {
public:
    SkipListNode(unsigned char depth_, const IData<Type>& data);
    SkipListNode(const SkipListNode& origin_);
    SkipListNode(SkipListNode&& origin_) noexcept;
    ~SkipListNode();
    const IData<Type>& GetData(const Type& index);
    size_t GetHash();
    const SkipListNode<Type>& GetLayer(unsigned char depth_);
    const SkipListNode<Type>*& GetLayers();
    unsigned char GetDepth();
private:
    SkipListNode();
    SkipListNode<Type>* layers;
    std::vector<const IData<Type>&> dataList;
    size_t hash;
    unsigned char depth = 3;
};
