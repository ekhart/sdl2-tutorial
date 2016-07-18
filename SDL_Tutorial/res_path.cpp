#include "res_path.h"

using namespace std;

string getResourcePath(const string &subDir) {
	//We need to choose the path separator properly based on whic
	//platform we're running on, since Windows uses a diffrent
	//separator then most systems

#ifdef _WIN32
	const char PATH_SEPARATOR = '\\';
#else
	const char PATH_SEPARATOR = '/';
#endif 

	//This will hold the base resource path: Lessons/res/
	//We give it static lifetime so thath we'll only need to call
	//SDL_GetBasePath once to get the executable path

	static string baseRes;
	if (baseRes.empty()) {
		//SDL_GetBasePath will return NULL if something went wrong in retrvieving the path

		char *basePath = SDL_GetBasePath();
		if (basePath) {
			baseRes = basePath;
			SDL_free(basePath);
		}
		else {
			cerr << "Error gettin resource path: " << SDL_GetError() << endl;
			return "";
		}
		
		//We replace the last bin/ with res/ to get the resource path
		size_t index = baseRes.rfind("bin");
		baseRes = baseRes.substr(0, index) + "res" + PATH_SEPARATOR;
	}

	//If we want a specific subdirectory path in the resource direcory
	//append it to the base path. This would be something like Lessons/res/Lesson0
	return subDir.empty() ? baseRes : baseRes + subDir + PATH_SEPARATOR;
}