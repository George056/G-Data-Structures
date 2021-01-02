#ifndef CONTAINER
#define CONTAINER
#pragma once
/*
This is an abstract class used as a base for all container types
*/

namespace george_data_structures {

		template <typename dataType>
		class container {
		protected:
				size_t __size;

		public:
				container() : __size{ 0 } {}
				vitrual container(const container&) = 0;
				container(container&&) = default;

				virtual ~container() = default;

				virtual container& operator =(const container&) = 0;
				virtual container& operator =(container&&) = 0;
				virtual dataType& operator [](size_t index) = 0;

				virtual dataType& at(size_t index) = 0;

				virtual size_t size() { return __size; }

		};

}

#endif
