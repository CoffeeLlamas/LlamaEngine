#include "Audio.hpp"
#include <AL/al.h>
#include <AL/alc.h>
#include <iostream>
#include "AudioLoader.hpp"
namespace engine {
	namespace audio {

		ALCdevice* Audio::device;
		ALCcontext* Audio::context;
		void Audio::init() {
			Audio::device = alcOpenDevice(0);
			if (!device) {
				std::cout << "Could not initialise OpenAL!" << std::endl;
				return;
			}

			Audio::context = alcCreateContext(device, 0);
			alcMakeContextCurrent(context);
		}

		void Audio::deinit() {
			alcDestroyContext(Audio::context);
			alcCloseDevice(Audio::device);
		}

		Audio::Audio(AudioData* data) {
			alGenBuffers(1, &this->id);

			unsigned int error = alGetError();
			if (error != AL_NO_ERROR) {
				std::cout << "[OpenAL] buffer creation error " << error << std::endl;
				return;
			}

			alBufferData(this->id, AudioLoader::getFormat(data), data->data, data->size, data->sampleRate);
			this->source = data;
		}

		Audio::~Audio() {
			alDeleteBuffers(1, &this->id);
		}
	}
}