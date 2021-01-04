#ifndef CONTAINER
#define CONTAINER
#pragma once
/*
This is an abstract class used as a base for all container types
*/
#include "../Iterator/Iterator.hpp"

namespace george_data_structures {

		template <typename dataType, class iterator_type>
		class container {
		protected:
				size_t __size;

				using iterator = iterator_type;

		public:
				container() : __size{ 0 } {}
				virtual container(const container&) = 0;
				container(container&&) = default;

				virtual ~container() = default;

				virtual container& operator =(const container&) = 0;
				virtual container& operator =(container&&) = 0;
				virtual dataType& operator [](size_t index) = 0;

				virtual dataType& at(size_t index) = 0;

				virtual size_t size() { return __size; }
				virtual bool empty() { return __size == 0; }

				virtual iterator begin() = 0;
				virtual iterator end() = 0;

				virtual output_iterator cbegin() = 0;
				virtual output_iterator cend() = 0;

		};

}

#endif
