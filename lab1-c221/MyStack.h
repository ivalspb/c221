#pragma once
#include "Point.h"
#include <utility>

template <typename T, typename... Types>
class MyStack
{
	class Node
	{
		friend class MyStack;
		T val{};
		Node* next = nullptr;
	public:
		Node() =default;
		template<typename... Types>
		Node(Node* head, Types&&... args):val(std::forward<Types>(args)...)
		{
			next = head->next;
			head->next = this;
		}
	};
	Node m_head;
public:
	MyStack() {};
	
	T pop()
	{
		if (m_head.next)
		{
			Node* tmp = m_head.next->next;
			T res = m_head.val;
			delete m_head.next;
			m_head.next = tmp;
			return res;
		}
		else return T{};
	}
	template <typename... Types>
	void push(Types&&... args)
	{
		(new Node(&m_head,args),...);
	}

	template <typename... Types>
	void push_emplace(Types&&... args)
	{
		void* mem = new char[sizeof...(Types)*sizeof(T)];
		Node* n = new(mem)Node(&m_head, std::forward<Types>(args)...);
	}

	template <typename... Types>
	MyStack(Types&&... args)
	{
		if constexpr (sizeof...(args) > 0)
			push(std::forward<Types>(args)...);
	}
	~MyStack()
	{
		while (m_head.next) pop();
	}
	MyStack(MyStack&) = delete;
	MyStack(MyStack&&) = delete;
	MyStack& operator=(MyStack&) = delete;
	MyStack& operator=(MyStack&&) = delete;
};
