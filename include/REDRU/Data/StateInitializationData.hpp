#pragma once

namespace re {

	using namespace std;

	class StateInitializationData {

	public:

		virtual ~StateInitializationData() { }

		template <class T>
		T* getData() {
			return dynamic_cast<T*>(this);
		}

	};

}
