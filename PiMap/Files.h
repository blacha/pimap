#pragma once

#include <windows.h>
#include <vector>

class Files { // tolua_export


public:
	//tolua_begin

	std::vector<std::string> getFileList(std::string directory, std::string filter = "*.lua", bool getdirs = false );
	std::vector<std::string> getDirectoryList(std::string directory);
	
};

// tolua_end