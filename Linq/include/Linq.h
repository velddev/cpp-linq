#pragma once
#include <functional>

namespace linq 
{
	template<typename T>
	class Linq
	{
	public:
		Linq(T *t)
		{
			container = t;
		}

		template<typename Item>
		Linq &add(Item item)
		{
			container->push_back(item);
			return *this;
		}
		
		template<typename Item>
		Linq *where(std::function<bool(Item)> func)
		{
			T *c = new T();
			for (auto x : *container)
			{
				if (func(x))
				{
					c->push_back(x);
				}
			}
			return new Linq<T>(c);
		}

		T &toList()
		{
			return *container;
		}

		int &count() {
			return container->size();
		}

		T *container;
	};
}

/* example from aida
template <typename T, typename It>
class Linq
{
private:
It begin_, end_;

public:
Linq(It begin, It end) :
begin_{ begin },
end_  { end }
{}

template <typename New, typename Predicate>
Linq<New> select(Predicate&& transform) const;
template <typename Predicate>
Linq where(Predicate&& filter) const;

std::vector<T> to_vec() const;
};

template <typename It>
auto make_linq(It begin, It end)
-> Linq<typename std::iterator_traits<It>::value_type, It>
{
return { begin, end };
}

static void example()
{
std::vector<int> numbers = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
auto filtered = make_linq(numbers.begin(), numbers.end()).where([](int x) { return x % 2 == 0; }).to_vec();
}
*/