#include <iostream>
#include <gl/glew.h>
#include <GLFW/glfw3.h>
#include "graphics/Shader.hpp"
#include "graphics/Window.hpp"
#include "audio/AudioLoader.hpp"
#include "audio/Audio.hpp"
#include "audio/AudioSource.hpp"

int main() {
	using namespace engine;
	using namespace graphics;
	using namespace audio;
	Window* window = new Window(400, 600, "TestWindow");

	if (glewInit() != GLEW_OK) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		system("PAUSE");
		return -1;
	}
	Shader* shader = new Shader("res/shader/Basic.glsl");
	shader->bind();

	Audio::init();

	AudioData* audioSource = AudioLoader::loadWAVFile("res/audio/Guitar.wav");
	Audio* audio = new Audio(audioSource);
	AudioSource* audioSourcePlay = new AudioSource();
	audioSourcePlay->play(audio);
	while (!window->ShouldClose()) {
		glClearColor(1, 1, 1, 1);
		glClear(GL_COLOR_BUFFER_BIT);

		

		window->Update();
	}
	
	delete audioSource;
	delete audio;
	delete audioSourcePlay;
	delete(window);

	Audio::deinit();
	system("PAUSE");
}