#include "projection_matrix.h"

namespace mc {
	ProjectionMatrix::ProjectionMatrix(float fov, float near_plane, float far_plane) {
		this->fov = fov;
		this->near_plane = near_plane;
		this->far_plane = far_plane;
	}

	ProjectionMatrix::~ProjectionMatrix() {
		// Nothing
	}

	glm::mat4 ProjectionMatrix::getMatrix(int frame_buffer_width, int frame_buffer_height) {
		return glm::perspective(glm::radians(fov),
			static_cast<float>(frame_buffer_width) / frame_buffer_height,
			near_plane,
			far_plane);
	}
}