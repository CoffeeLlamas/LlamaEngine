#pragma once
namespace engine {
	namespace audio {

		struct AudioData {
			char* data;
			unsigned int size;
			unsigned int channels;
			unsigned int sampleRate;
			unsigned int bitsPerSample;
		};

	}
}