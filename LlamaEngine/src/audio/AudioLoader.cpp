#include "AudioLoader.hpp"
#include <fstream>
#include <iostream>
namespace engine {
	namespace audio {

		static int bitsToDecimal(char* data, int pointer, int amt);

		long long len;
		AudioData* AudioLoader::loadWAVFile(const char* file) {
			std::ifstream stream(file);
			stream.seekg(0, stream.end);
			long long length = stream.tellg();
			stream.seekg(0, stream.beg);
			len = length;

			char* data = new char[length];
			stream.read(data, length);
			return AudioLoader::loadWAV(data);
		}

		AudioData* AudioLoader::loadWAV(char* data) {
			unsigned int sampleRate = bitsToDecimal(data, 24 * sizeof(char), 4);
			unsigned int channels = bitsToDecimal(data, 22 * sizeof(char), 2);
			unsigned int bitsPerSample = bitsToDecimal(data, 34 * sizeof(char), 2);
			unsigned int dataBytes = bitsToDecimal(data, 40 * sizeof(char), 4);
			
			char* audioData = new char[dataBytes];
			for (int i = 0; i < dataBytes; i++)
				audioData[i] = data[i + 44];
			
			return new AudioData {
				audioData,
				dataBytes,
				channels,
				sampleRate,
				bitsPerSample
			};
		}

		static int bitsToDecimal(char* data, int pointer, int amt) {

			int a = 0, b = 1;
			if (((char*)&b)[0]) // If little-endian
				for (int i = 0; i < amt; i++)
					((char*)&a)[i] = data[pointer + i];
			else
				for (int i = 0; i < amt; i++)
					((char*)&a)[3 - i] = data[pointer + i];
			return a;
		}

	}
}