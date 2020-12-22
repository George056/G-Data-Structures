#include <memory>

namespace george_data_structures {
		template <typename arrayType, int CAPACITY>
		class dynamic_array {
		protected:
				std::unique_ptr<arrayType> = std::make_unique<arrayType[CAPACITY]>();
		public:

		};
}