#include "font_renderer.h"

// From learnopengl.org
namespace mc {
	FontRenderer* FontRenderer::_instance = NULL;

	FontRenderer::FontRenderer() : window_height(0), window_width(0) {
	}

	FontRenderer::~FontRenderer() {
		delete this->shader;
	}

	FontRenderer* FontRenderer::instance() {
		if (!_instance) _instance = new FontRenderer();

		return _instance;
	}

	void FontRenderer::setShader(mc::Shader* shader) {
		this->shader = shader;
	}
	
	void FontRenderer::setWindowParam(int window_width, int window_height) {
		this->window_width = window_width;
		this->window_height = window_height;
	}

	void FontRenderer::init() {		
		//this->projection = glm::ortho(0.0f, (float)this->window_width, 0.0f, (float)this->window_height);
		shader->use();
		projection = glm::ortho(0.0f, static_cast<GLfloat>(this->window_width), 0.0f, static_cast<GLfloat>(this->window_height));
		shader->setUniformMat4fv(projection, "projection", false);

		if (FT_Init_FreeType(&ft))
			std::cout << "ERROR::FREETYPE: Could not init FreeType Library" << std::endl;

		if (FT_New_Face(ft, "resources/fonts/arial.ttf", 0, &face))
			std::cout << "ERROR::FREETYPE: Failed to load font" << std::endl;

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		// We set width to 0 because we want to set this dynamically
		FT_Set_Pixel_Sizes(face, 0, 48);

		std::clog << "Success loading fonts" << std::endl;
		glPixelStorei(GL_UNPACK_ALIGNMENT, 1); //禁用字节对齐限制
		for (GLubyte c = 0; c < 128; c++)
		{
			// 加载字符的字形 
			if (FT_Load_Char(face, c, FT_LOAD_RENDER))
			{
				std::cout << "ERROR::FREETYTPE: Failed to load Glyph" << std::endl;
				continue;
			}

			// 生成纹理
			GLuint texture;
			glGenTextures(1, &texture);
			glBindTexture(GL_TEXTURE_2D, texture);
			glTexImage2D(
				GL_TEXTURE_2D,
				0,
				GL_RED,
				face->glyph->bitmap.width,
				face->glyph->bitmap.rows,
				0,
				GL_RED,
				GL_UNSIGNED_BYTE,
				face->glyph->bitmap.buffer
			);
			// 设置纹理选项
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
			// 储存字符供之后使用
			mc::Character character = {
				texture,
				glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
				glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
				(GLuint)face->glyph->advance.x
			};
			map.insert(std::pair<GLchar, Character>(c, character));
		}

		glBindTexture(GL_TEXTURE_2D, 0);
		FT_Done_Face(face);
		FT_Done_FreeType(ft);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glGenVertexArrays(1, &VAO);
		glGenBuffers(1, &VBO);
		glBindVertexArray(VAO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(GLfloat) * 6 * 4, NULL, GL_DYNAMIC_DRAW);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(GLfloat), 0);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void FontRenderer::addText(int tid, std::string text, GLfloat x, GLfloat y, GLfloat scale, glm::vec3 color) {
		texts[tid] = mc::Text(text, x, y, scale, color);
	}

	void FontRenderer::changeText(int tid, std::string newText) {
		if (texts.find(tid) == texts.end()) {
			std::cerr << "Error: No text with id " << tid << std::endl;
		}
		else {
			texts[tid].text = newText;
		}
	}

	void FontRenderer::render() {
		// Activate corresponding render state	
		glDisable(GL_CULL_FACE);
		shader->use();
		
		glActiveTexture(GL_TEXTURE0);
		glBindVertexArray(VAO);

		for (auto& iter: this->texts) {
			renderText(iter.second);
			glm::vec3 temp = iter.second.color;
			float r = (temp.x + 0.02);
			float g = (temp.y + 0.01);
			float b = (temp.z + 0.005);
			if (r > 1) r -= 1;
			if (g > 1) g -= 1;
			if (b > 1)b -= 1;
			iter.second.color = glm::vec3(r, g, b);
		}

		glBindVertexArray(0);
		glBindTexture(GL_TEXTURE_2D, 0);
	}

	void FontRenderer::renderText(mc::Text t)
	{
		shader->setUniform3f("textColor", t.color.x, t.color.y, t.color.z);

		// Iterate through all characters
		std::string::const_iterator c;
		GLuint x = t.x;
		for (c = t.text.begin(); c != t.text.end(); c++)
		{
			mc::Character ch = map[*c];

			GLfloat xpos = x + ch.bearing.x * t.scale;
			GLfloat ypos = t.y - (ch.size.y - ch.bearing.y) * t.scale;

			GLfloat w = ch.size.x * t.scale;
			GLfloat h = ch.size.y * t.scale;
			// Update VBO for each character
			GLfloat vertices[6][4] = {
				{ xpos,     ypos + h,   0.0, 0.0 },
				{ xpos + w, ypos,       1.0, 1.0 },
				{ xpos,     ypos,       0.0, 1.0 },

				{ xpos,     ypos + h,   0.0, 0.0 },
				{ xpos + w, ypos + h,   1.0, 0.0 },
				{ xpos + w, ypos,       1.0, 1.0 }
			};
			// Render glyph texture over quad
			glBindTexture(GL_TEXTURE_2D, ch.textureID);
			// Update content of VBO memory
			glBindBuffer(GL_ARRAY_BUFFER, VBO);
			glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
			// Render quad
			glDrawArrays(GL_TRIANGLES, 0, 6);

			// Now advance cursors for next glyph (note that advance is number of 1/64 pixels)
			x += (ch.advance >> 6) * t.scale; // Bitshift by 6 to get value in pixels (2^6 = 64)
		}		
	}
}