#pragma once

namespace re {

	using namespace std;

	class StateInitializationData {

	public:

		template <class T>
		T* getData() {
			return dynamic_cast<T*>(this);
		}

	};

}
