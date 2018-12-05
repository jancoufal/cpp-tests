#pragma once

#include <utility>

template<class Fun>
class ScopeGuard
{
private:

	Fun fun;
	bool active;

public:

	ScopeGuard() = delete;
	ScopeGuard(const ScopeGuard&) = delete;
	ScopeGuard& operator=(const ScopeGuard&) = delete;

	ScopeGuard(Fun fun)
		: fun(std::move(fun))
		, active(true)
	{
	}

	ScopeGuard(ScopeGuard && that)
		: fun(std::move(that->fun))
		, active(that->active)
	{
		that->dismiss();
	}

	virtual ~ScopeGuard()
	{
		if (this->active)
		{
			fun();
		}
	}

	void dismiss()
	{
		this->active = false;
	}
};

template <class Fun>
ScopeGuard<Fun> makeScopeGuard(Fun fun)
{
	return ScopeGuard<Fun>(std::move(fun));
}