#pragma once

#include "ITree.hpp"

namespace acdc
{

template<typename L, typename V = void>
class AstTree : public ITree
{
public:
	virtual size_t height() const override;

	virtual void setParent(ITree&) override;
	virtual ITree* parent() = 0;
	virtual const ITree* parent() const override;
	virtual void removeParent() override;
	virtual bool hasParent() const override;

	virtual void setLabel(const L& v) override;
	virtual L label() const override;

	template<typename = disableIfVoid<V>>
	virtual void setValue(const V& v) override;
	template<typename = disableIfVoid<V>>
	virtual V value() const override;

	virtual void addChildren(RangeIterator<ITree>) override;
	virtual RangeIterator<ITree> children() override;
	virtual RangeIterator<const ITree> children() const override;
	virtual bool removeChildren() override;
	virtual bool hasChildren() const override;
	virtual bool childrenCount() const override;

	virtual void addChild(ITree&) override;
	virtual ITree& child(const Label&) override;
	virtual const ITree& child(const Label&) const override;
	virtual void removeChild(const Label&) override;
	virtual void removeChild(const ITree&) override;
	virtual bool hasChild(const Label&) const override;
	virtual bool isChild(const ITree&) const override;
private:

};
