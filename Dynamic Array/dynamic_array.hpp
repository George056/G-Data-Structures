#include <memory>
#include <exception>
#include <utility>

#ifdef golden_growth && GROWTH_RATE
		#define GROWTH_RATE 1.6180339887
#else
		#define GROWTH_RATE 2
#endif

namespace george_data_structures {
		template <typename arrayType, int CAPACITY = 0>
		class dynamic_array {
		protected:
				std::unique_ptr<arrayType> __array = std::make_unique<arrayType[CAPACITY]>();
				size_t __size = 0;
				size_t __capacity = CAPACITY;

				class __Iterator__ {

				};

				static void copyArrays(const dynamic_array& source, dynamic_array& destination);

		public:

				using iterator = __Iterator__;

				dynamic_array() = default;
				dynamic_array(dynamic_array&&) = default;
				dynamic_array operator =(dynamic_array&&) = default;

				dynamic_array(const dynamic_array& da) { copyArrays(da, *this); }
				dynamic_array operator =(const dynamic_array& da) { copyArrays(da, *this); }

				arrayType& operator [](size_t index) { return __array[index]; }

				size_t size() { return __size; }
				size_t capacity() { return __size; }
				void capacity(size_t newCapacity) {
						size_t newCapacity = (int)(newCapacity);
						std::unique_ptr<arrayType> temp = std::make_unique<arrayType[newCapacity]>();
						copyArrays(*this, temp); //copy the values in this to temp
						delete[] __array.release(); //delete this array
						__array = temp.release(); //transfer temp to this
				}
				
				dynamic_array& push_back(arrayType value) {
						if(__size <= __capacity)
								__array[__size++] = value;
						else {
								//growthrate is user controled, defaults to 2, efficent is golden ration
								size_t newCapacity = (int)(__capacity * GROWTH_RATE);
								capacity(newCapacity);
								__array[__size++] = value;
						}
						return *this;
				}

				arrayType pop_back() {
						if(size > 0)
								return __array[size--];
						throw std::out_of_bounds();
				}
		};

		template<typename arrayType, int CAPACITY>
		inline void george_data_structures::dynamic_array<arrayType, CAPACITY>::copyArrays(const dynamic_array& source, dynamic_array& destination)
		{
				if(destination.__capacity < source.__capacity)
						destination.capacity(source.__capacity);

				for (int i = 0; i < source.__size; ++i) {
						destination.__array[i] = std::move(source.__array[i]);
				}
		}


};