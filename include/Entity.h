#pragma once
#include <glm/mat4x4.hpp> 
#include <glm/ext/matrix_transform.hpp> 
#include <glm/ext/matrix_clip_space.hpp> 

#include <Mesh.h>

struct Transform
{
	glm::vec3 pos;
	glm::vec3 rot;
	glm::vec3 scale;

	Transform(glm::vec3 pos = glm::vec3(0.0f),
		glm::vec3 rot = glm::vec3(0.0f),
		glm::vec3 scale = glm::vec3(1.0f))
		: pos(pos), rot(rot), scale(scale) {
	}

	glm::mat4 getModelMatrix() {
		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, pos);
		model = glm::rotate(model, rot.x, glm::vec3(1.0, 0.0, 0.0));
		model = glm::rotate(model, rot.y, glm::vec3(0.0, 1.0, 0.0));
		model = glm::rotate(model, rot.z, glm::vec3(0.0, 0.0, 1.0));
		model = glm::scale(model, scale);
		return model;
	}
};

class Entity
{
public:
	Entity(Mesh& mesh, Transform& transform, Shader& shader);
	~Entity() = default;

	inline Mesh& getMesh() { return mesh; }
	inline Transform& getTransform() { return transform; }
	inline Shader& getShader() { return shader; }

private:
	Mesh& mesh;
	Transform transform;
	Shader& shader;
};

