#pragma once

namespace Kick_Engine::Graphics
{
	struct Model;

	namespace ModelIO
	{
		bool SaveModel(std::filesystem::path filePath, const Model& model);
		bool LoadModel(std::filesystem::path filePath, Model& model);		
		
		bool SaveMaterial(std::filesystem::path filePath, const Model& model);
		bool LoadMaterial(std::filesystem::path filePath, Model& model);

		bool SaveSkeleton(std::filesystem::path filePath, Model& model);
		bool LoadSkeleton(std::filesystem::path filePath, Model& model);
	}
}