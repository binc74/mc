#ifndef HASHING_H
#define HASHING_H

namespace game {
	class Hashing {
	public:
		Hashing();
		~Hashing();
		static int hashXYZ(float x, float y, float z);
		static int hashXZ(float x, float z);
	};
}

#endif
