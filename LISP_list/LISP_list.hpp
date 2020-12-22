#pragma once
#include<memory>
#include "LISP_atom.hpp"

namespace george_data_structures {


		class cons__cell {

		};

		template <typename T>
		class LISP_list {
		protected:
				T* __car;
				LISP_list<T>* __cdr;

		public:

				LISP_list() = default;
				~LISP_list() = default;

				public T car() {

				}
		};
}