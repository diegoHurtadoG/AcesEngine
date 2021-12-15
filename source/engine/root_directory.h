/*
	This field was automatically created with CMake please don't modify it
*/
#pragma once

#include <filesystem>

namespace Grafica
{
	
static const char * const source_directory = "C:/Users/diego/OneDrive/Desktop/Ramos/2021-2/Arquitectura de Motores de Videojuegos/Proyecto/AcesEngine/";

static std::filesystem::path getPath(const std::string &relative_path){
	return source_directory + relative_path;
}
	
} // Grafica
