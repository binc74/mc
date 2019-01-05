#include "projection_matrix.h"

namespace engine {
	ProjectionMatrix::ProjectionMatrix(float fov, float near_plane, float far_plane) {
		this->fov = fov;
		this->near_plane = near_plane;
		this->far_plane = far_plane;
	}

	ProjectionMatrix::~ProjectionMatrix() {
		// Nothing
	}

	glm::mat4 ProjectionMatrix::getMatrix(int frame_buffer_width, int frame_buffer_height) {
		glm::mat4 proj_matrix(1.f);

		proj_matrix = glm::perspective(glm::radians(fov),
			(float) (frame_buffer_width) / frame_buffer_height,
			near_plane,
			far_plane);

		return proj_matrix;
	}
}