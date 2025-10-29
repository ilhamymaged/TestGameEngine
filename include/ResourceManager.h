#pragma once
#include <Entity.h>
#include <vector>


class ResourceManager
{
public:
	static std::vector<Entity>& getEntitiesScene();

	static void loadAssets();

private:
	static void loadEntities();

private:
	static std::vector<Entity> entities;
};