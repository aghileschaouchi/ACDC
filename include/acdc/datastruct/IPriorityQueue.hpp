#pragma once

namespace acdc
{

template <typename T>
class IPriorityQueue
{
public:
	struct Pair {unsigned int priority; T& value;};

	virtual void push(unsigned int, const T&) = 0;
	virtual void pop() = 0;

	virtual unsigned int topPriority() const = 0;

	virtual T& topvalue() = 0;
	virtual const T& topValue() const = 0;

	virtual Pair top() = 0;
	virtual const Pair top() const = 0;
};
}