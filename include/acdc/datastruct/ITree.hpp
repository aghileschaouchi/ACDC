#pragma once

namespace acdc
{

template<typename L, typename V = void>
class ITree {
	template<typename T>
	using disableIfVoid = std::enable_if<std::is_same<T, void>>;

public:
	virtual size_t height() const = 0;

	virtual void setParent(ITree&) = 0;
	virtual ITree* parent() = 0;
	virtual const ITree* parent() const = 0;
	virtual void removeParent() = 0;
	virtual bool hasParent() const = 0;

	virtual void setLabel(const L& v) = 0;
	virtual L label() const = 0;

	template<typename = disableIfVoid<V>>
	virtual void setValue(const V& v) = 0;
	template<typename = disableIfVoid<V>>
	virtual V value() const = 0;

	// TODO utiliser les iterator ranges de boost
	virtual void addChildren(RangeIterator<ITree>) = 0;
	virtual RangeIterator<ITree> children() = 0;
	virtual RangeIterator<const ITree> children() const = 0;
	virtual bool removeChildren() = 0;
	virtual bool hasChildren() const = 0;
	virtual bool childrenCount() const = 0;

	virtual void addChild(ITree&) = 0;
	virtual ITree& child(const Label&) = 0;
	virtual const ITree& child(const Label&) const = 0;
	virtual void removeChild(const Label&) = 0;
	virtual void removeChild(const ITree&) = 0;
	virtual bool hasChild(const Label&) const = 0;
	virtual bool isChild(const ITree&) const = 0;
};

}
