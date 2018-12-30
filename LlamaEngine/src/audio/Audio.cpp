#include "Audio.hpp"
#include <AL/al.h>
#include <AL/alc.h>
#include <iostream>
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
			unsigned int format;
			alGenBuffers(1, &this->id);

			unsigned int error = alGetError();
			if (error != AL_NO_ERROR)
				std::cout << "[OpenAL] buffer creation error " << error << std::endl;

			if (data->channels == 1) {
				if (data->bitsPerSample == 8)
					format = AL_FORMAT_MONO8;
				else
					format = AL_FORMAT_MONO16;
			} else {
				if (data->bitsPerSample == 8)
					format = AL_FORMAT_STEREO8;
				else
					format = AL_FORMAT_STEREO16;
			}

			alBufferData(this->id, format, data->data, data->size, data->sampleRate);
			this->source = data;
		}

		Audio::~Audio() {
			delete this->source->data;
			delete this->source;
			alDeleteBuffers(1, &this->id);
		}
	}
}