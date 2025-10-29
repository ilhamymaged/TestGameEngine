#pragma once
#include <Renderer.h>
#include <vector>
#include <Entity.h>

class Scene
{
public:
	Scene(std::vector<Entity>& entities);

	std::vector<Entity>& getEntities() { return entities; }

private:
	std::vector<Entity> entities;

};