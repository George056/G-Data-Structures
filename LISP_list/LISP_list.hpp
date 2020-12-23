#pragma once
#include<memory>
#include<variant>
#include "LISP_atom.hpp"

namespace george_data_structures {

		class LISP_list;

		class cons__cell {
		private:

				bool __atom_flag : 1;
				bool __list_flag : 1;

				using list = LISP_list;

		public:
				std::variant<list, atom> __cell;

				cons__cell() = default;
				cons__cell(const cons__cell&) = default;
				cons__cell(cons__cell&&) = default;
				cons__cell& operator =(const cons__cell&) = default;
				cons__cell& operator =(cons__cell&&) = default;

				cons__cell(const atom& a) : __cell{ a }, __atom_flag{ true }, __list_flag{ false } {  }
				cons__cell(const list& ll) : __cell{ ll }, __atom_flag{ false }, __list_flag{ true } {  }
		};

		
		class LISP_list {
		protected:
				std::unique_ptr<cons__cell> __car;
				std::unique_ptr<cons__cell> __cdr;

				using list = LISP_list;
				using cell = cons__cell;

				LISP_list(const cell& c1, const cell& c2) {
						__car = std::make_unique<cell>(c1);
						__cdr = std::make_unique<cell>(c2);
				}

		public:

				LISP_list() = default;
				~LISP_list() = default;

				cell car() {
						return &(__car.get());
				}

				cell cdr() {
						return *__cdr;
				}

				static bool null(list ll) {
						ll.__car->__cell;

				}

				static list cons(cell c1, cell c2) {

				}
		};
}