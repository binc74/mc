#include <iostream>
#include <fstream>
#include <string>
#include <glm.hpp>

#include "libs.h"
#include "engine/window/game.h"
#include "engine/graphics/shader.h"
#include "engine/graphics/core/model_matrix.h"
#include "engine/graphics/core/projection_matrix.h"
#include "engine/camera/camera.h"
#include "engine/graphics/texture.h"

#include "engine/graphics/shapes/triangle.h"

using namespace engine;

int main() {
	Window window(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	window.init(4, 4, false);

	// Init texture
	Texture texture("resources/images/123.png", 0, T2D);

	// Init shader
	Shader shader(VERTEX_CORE_FILE_PATH, FRAG_CORE_FILE_PATH);

	ProjectionMatrix pm(90, 0.1f, 1000);

	Camera cam;
	cam.setCameraFront(0, 0, -1);
	cam.setCameraPosition(0, 0, 0);
	cam.setDirectionUp(0, 1, 0);

	shader.use();

	shader.setUniformMat4fv(cam.getViewMatrix(), "view_matrix");
	shader.setUniformMat4fv(pm.getMatrix(window.frame_buffer_width, window.frame_buffer_height),
		"projection_matrix");

	glm::vec3 light_pos(0.f, 0.f, 1.f);

	shader.setUniform3fv(light_pos, "light_pos0");
	shader.setUniform3fv(cam.camera_position, "camera_pos");

	shader.unuse();

	window.initShader(&shader);

	ModelMatrix model(0, 0, 0);
	model.setRotation(0, 0, 0);
	model.setScale(1, 1, 1);

	// Main loop
	while (!window.shouldClose()) {
		window.update();
	}

	// Free resources and end program
	window.~Window();

	return 0;
}