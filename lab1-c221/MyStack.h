#pragma once
#include "Point.h"
#include <utility>

template <typename T>
class MyStack
{
	class Node
	{
		T val;
		Node* next = nullptr;
	public:
		Node(T& _val) : val(_val) {};
		Node(T&& _val) : val(std::move(_val)) {};
	};
	Node* m_head = nullptr;
public:
	MyStack() = default;
	void push(T&& v)
	{
		Node* n = new Node(std::forward<Node>(v));
		n->next = m_head->next;
		m_head->next = n;
	}
	void pop()
	{
		if (m_head->next)
		{
			Node* tmp = m_head->next->next;
			delete m_head->next;
			m_head->next = tmp;
		}
	}
	void push(T&& v, T&&... args)
	{
		this->push(std::forward<T>(v));
		if constexpr (sizeof...(args) > 0)
			this->push(std::forward<T>(args));
	}
	MyStack(T&&... args)
	{
		if constexpr (sizeof...(args) > 0)
			push(std::forward<T>(args));
	}
	~MyStack()
	{
		while (m_head->next) pop();
	}
	MyStack(MyStack&) = delete;
	MyStack(MyStack&&) = delete;
	MyStack& operator=(MyStack&) = delete;
	MyStack& operator=(MyStack&&) = delete;
};
