#include "Files.h"

std::vector<std::string> Files::getFileList(std::string directory, std::string filter, bool getdirs)
{

	char path[MAX_PATH];
	GetCurrentDirectoryA(MAX_PATH,path);
	strcat_s(path, "\\");
	strcat_s(path, directory.c_str());
	
	std::string szSearch;

	szSearch = path;
	szSearch +=  "\\";

	if (getdirs)
		szSearch +=  "*";
	else
		szSearch += filter;

	WIN32_FIND_DATAA FindFileData;
	HANDLE  hFind = FindFirstFileA(szSearch.c_str(), &FindFileData);

	std::vector<std::string> files;

	if (hFind != INVALID_HANDLE_VALUE)
	{
		do
		{
			std::string FilePath;
			FilePath = directory;
			FilePath += FindFileData.cFileName;

			if (getdirs)
			{
				if ( FindFileData.dwFileAttributes == FILE_ATTRIBUTE_DIRECTORY )
				{
					if ( strcmp(FindFileData.cFileName, ".") && strcmp(FindFileData.cFileName, "..") )
						files.push_back(FilePath);
				}
			}
			else
				files.push_back(FilePath);
			
		}
		while (FindNextFileA(hFind, &FindFileData));

		FindClose(hFind);
	}

	return files;
}

std::vector<std::string> Files::getDirectoryList(std::string directory)
{
	return getFileList(directory, "", true);
}