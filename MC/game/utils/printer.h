#ifndef PRINTER_H
#define PRINTER_H

#include <glm.hpp>
#include <iostream>
#include <string>

namespace mc {
	class Printer {
	public:
		Printer() {
		}

		~Printer() {
		}

		static void printVec3(glm::vec3& v) {
			std::clog << v.x << " " << v.y << " " << v.z << std::endl;
		}

		static void printVec3(glm::vec3& v, std::string& msg) {
			std::clog << msg << ": " << v.x << " " << v.y << " " << v.z << std::endl;
		}
	};
}

#endif