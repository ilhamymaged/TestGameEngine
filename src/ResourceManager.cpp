#include <ResourceManager.h>

std::vector<Entity> ResourceManager::entities;

std::vector<Entity>& ResourceManager::getEntitiesScene()
{
	return entities;
}

void ResourceManager::loadAssets()
{
	ResourceManager::loadEntities();
}

void ResourceManager::loadEntities()
{
	Mesh triangleMesh = Mesh::getTriangleMesh();
	Transform transform;
	Shader shader("simple");
	Entity entity(triangleMesh, transform, shader);
	entities.push_back(entity);
}
