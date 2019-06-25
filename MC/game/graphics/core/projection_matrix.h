#ifndef PROJECTION_MATRIX_H
#define PROJECTION_MATRIX_H

#include <glm.hpp>
#include <gtc\matrix_transform.hpp>

namespace mc {
	class ProjectionMatrix {
	private:
		float fov;
		float near_plane;
		float far_plane;

	public:
		ProjectionMatrix(float fov, float near_plane, float far_plane);
		~ProjectionMatrix();
		glm::mat4 getMatrix(int frame_buffer_width, int frame_buffer_height);
	};
}

#endif

