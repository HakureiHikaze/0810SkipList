//
// Created by guoyao.wan on 2023/8/10.
//

#include "SkipListNode.h"
#include <iostream>
#include <exception>

template<typename Type>
SkipListNode<Type>::SkipListNode(unsigned char depth_, const IData<Type>& data) {
    depth = depth_;
    layers = (new SkipListNode<Type>())[this->depth];
    dataList = new std::vector<const IData<Type>&>(data);
    hash = data.hash();
}


template<typename Type>
SkipListNode<Type>::SkipListNode() = default;

template<typename Type>
SkipListNode<Type>::SkipListNode(const SkipListNode& origin) {
    layers = (new SkipListNode<Type>())[this->depth];
    for (int i = 0 ;i < origin.depth; i++) {
        layers[i] = origin.layers[i];
    }
    dataList = new std::vector<const IData<Type>&>(origin.dataList);
    hash = origin.hash;
}

template <typename Type>
SkipListNode<Type>::SkipListNode(SkipListNode&& origin) noexcept {
    layers = nullptr;
    dataList = nullptr;
    hash = origin.hash;
}

template<typename Type>
SkipListNode<Type>::~SkipListNode() {
    delete layers;
    delete dataList;
}

template<typename Type>
const IData<Type>& SkipListNode<Type>::GetData(const Type& index) {
    for(const auto& i : dataList){
        if(i.GetIndex() == index) return i;
    }
    throw std::exception();
}

template<typename Type>
unsigned char SkipListNode<Type>::GetDepth() {
    return depth;
}

template<typename Type>
const SkipListNode<Type>& SkipListNode<Type>::GetLayer(unsigned char depth_) {
    if(depth_ < depth) return layers[depth_];
    throw std::out_of_range("Index out of range!");
}

template<typename Type>
const SkipListNode<Type>*& SkipListNode<Type>::GetLayers() {
    return layers;
}


template<typename Type>
size_t SkipListNode<Type>::GetHash() {
    return 0;
}

