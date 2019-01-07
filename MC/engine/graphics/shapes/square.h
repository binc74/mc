#ifndef SQUARE_H
#define SQUARE_H

#include "../mesh.h"

namespace engine {
	class Square : public Mesh {
	private:
	public:
		Square(engine::ModelMatrix* model_matrix,
			vector<engine::Vertex> vertices);
		Square(engine::ModelMatrix* model_matrix, vector<engine::Texture> textures,
			vector<engine::Vertex> vertices);
		~Square();
	};
}

#endif
