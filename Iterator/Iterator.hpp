#ifndef ITERATOR
#define ITERATOR
#pragma once

namespace george_data_structures {

		template <class T>
		class iterator_base {
		private:
				using iterator = iterator_base;
		public:

				typedef value_type = T;

				iterator_base() : __itr{ nullptr } {}
				iterator_base(iterator_base&&) = default;
				iterator_base(const iterator_base&) = default;
				virtual ~iterator_base() = default;

				virtual iterator& operator =(const iterator&) = default;
				virtual iterator& operator =(iterator&&) = default;

				iterator& operator ++() { ++__itr; return *this; }
				iterator& operator ++(int) {
						iterator result = *this;
						++__itr;
						return result;
				}

		protected:
				value_type* __itr;

		};

		template <class T>
		class input_iterator : public iterator_base<T> {
		private:
				using iterator = input_iterator;
				
		public:
				input_iterator() : iterator_base() {}
				input_iterator(const input_iterator&) = default;
				input_iterator(input_iterator&&) = default;
				virtual ~input_iterator() = default;

				virtual iterator& operator =(const iterator&) = default;
				virtual iterator& operator =(iterator&&) = default;

				virtual inline T&& operator *() { return std::move(*iterator_base<T>::__itr); }
				virtual inline T&& operator ->() { return std::move(&*iterator_base<T>::__itr); }

				inline bool operator ==(const iterator& itr) { return iterator_base<T>::__itr == itr.iterator_base<T>::__itr;	}
				inline bool operator !=(const iterator& itr) { return !(*this == itr); }
		};

		template <class T>
		class output_iterator : public iterator_base {
		private:
				using iterator = input_iterator;

		public:
				output_iterator() : iterator_base() {}
				output_iterator(const output_iterator&) = default;
				output_iterator(output_iterator&&) = default;
				virtual ~output_iterator() = default;

				virtual iterator& operator =(const iterator&) = default;
				virtual iterator& operator =(iterator&&) = default;

				virtual inline const T& operator *() { return *iterator_base<T>::__itr; }
				virtual inline const T& operator ->() { return &*iterator_base<T>::__itr; }

		};

		template <class T>
		class forward_iterator : public input_iterator, output_iterator {
		private:
				using iterator = input_iterator;

		public:
		};

		template <class T>
		class bidirectional_iterator : public forward_iterator {
		private:
				using iterator = input_iterator;

		public:
		};

		template <class T>
		class random_access_iterator : public bidirectional_iterator {
		private:
				using iterator = input_iterator;

		public:
		};
}

#endif
