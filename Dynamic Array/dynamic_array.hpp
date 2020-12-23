#include <memory>
#include <exception>

namespace george_data_structures {
		template <typename arrayType, int CAPACITY = 0>
		class dynamic_array {
		protected:
				std::unique_ptr<arrayType> __array = std::make_unique<arrayType[CAPACITY]>();
				size_t __size = 0;
				size_t __capacity = CAPACITY;

				class __Iterator__ {

				};

				static void copyArrays(const dynamic_array& source, dynamic_array& destination, size_t size);

		public:

				using iterator = __Iterator__;

				dynamic_array() = default;
				dynamic_array(dynamic_array&&) = default;
				dynamic_array operator =(dynamic_array&&) = default;

				static void copyArrays(const dynamic_array& source, dynamic_array& destination);

				dynamic_array(const dynamic_array& da) { copyArrays(da, *this); }
				dynamic_array operator =(const dynamic_array& da) { copyArrays(da, *this); )

				arrayType& operator [](size_t index) { return __array[index]; }

				size_t size() { return __size; }
				size_t capacity() { return __size; }
				void capacity(size_t newCapacity) {
						dynamic_array<arrayType, newCapacity> temp = *this;
						__array = nullptr;
						__array = temp.__array;
						__capacity = newCapacity;
				}
				
				dynamic_array& push_back(arrayType value) {
						__array[size++] = value;
						return *this;
				}

				arrayType pop_back() {
						if(size > 0)
								return __array[size--];
						throw std::out_of_bounds();
				}
		}


		template<typename arrayType, int CAPACITY>
		inline void dynamic_array<arrayType, CAPACITY>::copyArrays(const dynamic_array& source, dynamic_array& destination){
				destination.capacity(source.__capacity);
				for (arrayType at : source) {

				}
		}

		};
}