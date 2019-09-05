#include "game.h"

namespace mc {
	Game::Game(int window_width, int window_height) :
		window_width(window_width), window_height(window_height) {
		this->window = new Window(window_width, window_height, "Mindcraft");
		this->player = new mc::Player(0.f, 0.f, 0.f);
		this->window->setPlayer(player);
		this->window->init(4, 4, false);

		this->init();
	}

	Game::~Game() {
		delete player;
		delete material;
		delete mainController;
		delete window;
	}

	void Game::init() {
		mc::Shader* shaderWorld = new mc::Shader("resources/shaders/vertex_fix.glsl",
			"resources/shaders/fragment_core.glsl");

		this->material = new mc::Material(glm::vec3(0.1f), glm::vec3(1.f), glm::vec3(1.f));
		this->mainController = new MainController();

		this->window->setShader(shaderWorld);
		this->window->setMaterial(material);
		//this->window->initUniform();

		this->initController();

		// Warning:: need to refactor shader in window.cpp
		this->world = new World(shaderWorld, material);
		this->initWorld();
	}

	void Game::initController() {
		this->mainController->addController(new mc::MouseController(this->window->window, player));

		mc::KeyboardController* kc = new mc::KeyboardController(this->window->window);
		kc->addInputCommand(GLFW_KEY_ESCAPE, new mc::CloseWindowCommand(window->window));
		kc->addInputCommand(GLFW_KEY_W, new mc::MoveFrontCommand(player));
		kc->addInputCommand(GLFW_KEY_S, new mc::MoveBackCommand(player));
		kc->addInputCommand(GLFW_KEY_A, new mc::MoveLeftCommand(player));
		kc->addInputCommand(GLFW_KEY_D, new mc::MoveRightCommand(player));
		kc->addInputCommand(GLFW_KEY_SPACE, new mc::MoveUpCommand(player));
		kc->addInputCommand(GLFW_KEY_Q, new mc::MoveDownCommand(player));

		this->mainController->addController(kc);
	}

	void Game::initWorld() {
		/*
		for (int i = -30; i < 30; ++i) {
			for (int k = -30; k < -15; ++k) {
				if (!(k == -20 || k == -21 || k == -25 ||
					k == -26 || k == -19 || k == -24)) {
					for (int j = 0; j < 4; ++j) {
						Cube* g = new Grass(world, j, k, i);
						world->addObj(g);
					}
					for (int j = 4; j < 8; ++j) {
						Cube* g = new Sand(world, j, k, i);
						world->addObj(g);
					}
					for (int j = 8; j < 12; ++j) {
						Cube* g = new CobbleStone(world, j, k, i);
						world->addObj(g);
					}
					for (int j = 12; j < 16; ++j) {
						Cube* g = new DiamondBrick(world, j, k, i);
						world->addObj(g);
					}
					for (int j = 16; j < 20; ++j) {
						Cube* g = new Gravel(world, j, k, i);
						world->addObj(g);
					}
					for (int j = 20; j < 24; ++j) {
						Cube* g = new OakWood(world, j, k, i);
						world->addObj(g);
					}
					for (int j = 24; j < 28; ++j) {
						Cube* g = new Soil(world, j, k, i);
						world->addObj(g);
					}
					for (int j = 28; j < 32; ++j) {
						Cube* g = new Stone(world, j, k, i);
						world->addObj(g);
					}
					for (int j = 32; j < 36; ++j) {
						Cube* g = new Tnt(world, j, k, i);
						world->addObj(g);
					}
				}
			}
		}
		*/
		
		for (int k = 0; k < 2; ++k) {
			for (int i = 0; i < 3; ++i) {
				for (int j = 0; j < 3; ++j) {
					if (!(i == 1 && j == 1 && k == 1))
						world->addObj(new Soil(world, i, k, j));
				}
			}
		}


		this->world->updateMesh();
	}

	bool Game::shouldClose() {
		return this->window->shouldClose();
	}

	void Game::update() {
		this->mainController->updateInput();
	}

	void Game::render() {
		this->window->render(this->world);		
	}
}