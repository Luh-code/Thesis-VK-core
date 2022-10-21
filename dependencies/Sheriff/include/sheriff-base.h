#pragma once
#include <cstdint>
#include <iostream>
#include <functional>

//#define IF_SHF_ERR(ret) if (shf::RetV err = t.test(); err.m_value != err.p_territory->m_noErr)
#define IF_SHF_ERR(ret) if (shf::RetV& err = *ret; !err)

namespace shf
{
	struct ReturnValue;
	
	class Territory
	{
	public:
		Territory(const char* _where, int32_t _noErr = 0)
			: p_where(_where), m_noErr(_noErr) {}

		const char* p_where;
		int32_t m_noErr;
	};

	using RetV = ReturnValue;
	struct ReturnValue
	{
	public:
		Territory* p_territory;

		int32_t m_value;

		ReturnValue(Territory& _terr, int32_t _val)
			: p_territory(&_terr), m_value(_val) {}

		operator ReturnValue*()
		{
			return this;
		}

		operator const char*() const
		{
			return p_territory->p_where;
		}

		operator int() const
		{
			return m_value;
		}

		operator int()
		{
			return m_value;
		}

		operator bool()
		{
			return m_value == p_territory->m_noErr;
		}

		operator bool() const
		{
			return m_value == p_territory->m_noErr;
		}
	};

	static std::function<void(RetV)> PrintErr = [](RetV err) -> void {
		std::cout << "Error at " << err.p_territory->p_where << " -> code " << err.m_value << std::endl;
	};
}
