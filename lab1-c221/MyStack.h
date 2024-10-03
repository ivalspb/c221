#pragma once
#include "Point.h"

template <typename T>
class MyStack
{
	class Node
	{
		T val;
		Node* next=nullptr;
	public:
		Node(T _val) : val(std::move(_val)) {};
	};
	Node* m_head = nullptr;
public:
	MyStack() = default;
	MyStack(T&&... args)
	{
		if constexpr (sizeof...(args)>0)
	}
};


