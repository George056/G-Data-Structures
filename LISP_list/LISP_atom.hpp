#pragma once
#include <variant>
#include <string>

namespace george_data_structures {

		struct __atom__flags {
				bool int_flag : 1;
				bool double_flag : 1;
				bool string_flag : 1;
				bool bool_flag : 1;

				__atom__flags() : int_flag{ false }, double_flag{ false }, string_flag{ false }, bool_flag{ false } {}

				static bool set_int(__atom__flags a) {
						a.int_flag = true;

						if (a.double_flag) a.double_flag = false;
						else if (a.string_flag) a.string_flag = false;
						else if (a.bool_flag) a.bool_flag = false;

						return true;
				}

				static bool set_double(__atom__flags a) {
						a.double_flag = true;

						if (a.int_flag) a.int_flag = false;
						else if (a.string_flag) a.string_flag = false;
						else if (a.bool_flag) a.bool_flag = false;

						return true;
				}

				static bool set_string(__atom__flags a) {
						a.string_flag = true;

						if (a.int_flag) a.int_flag = false;
						else if (a.double_flag) a.double_flag = false;
						else if (a.bool_flag) a.bool_flag = false;

						return true;
				}

				static bool set_bool(__atom__flags a) {
						a.bool_flag = true;

						if (a.int_flag) a.int_flag = false;
						else if (a.double_flag) a.double_flag = false;
						else if (a.string_flag) a.string_flag = false;

						return true;
				}
		};

		class atom {
		private:
				std::variant<int, double, std::string, bool> __atom;
				__atom__flags __atom_type;

		public:
				atom() = default;
				atom(const atom&) = default;
				atom(atom&&) = default;

				atom(int i) : __atom{ i } { __atom__flags::set_int(__atom_type); }
				atom(double d) : __atom{ d } { __atom__flags::set_double(__atom_type); }
				atom(std::string s) : __atom{ s } { __atom__flags::set_string(__atom_type); }
				atom(bool b) : __atom{ b } { __atom__flags::set_bool(__atom_type); }

				~atom() = default;

				atom& operator =(const atom&) = default;
				atom& operator =(atom&&) = default;

				atom& operator =(const int& i) {
						__atom = i;
						__atom__flags::set_int(__atom_type);
						return *this;
				}

				atom& operator =(const double& d) {
						__atom = d;
						__atom__flags::set_double(__atom_type);
						return *this;
				}

				atom& operator =(const std::string& s) {
						__atom = s;
						__atom__flags::set_string(__atom_type);
						return *this;
				}

				atom& operator =(const bool& b) {
						__atom = b;
						__atom__flags::set_bool(__atom_type);
						return *this;
				}

		};

}