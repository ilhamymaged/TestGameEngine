#pragma once
#include <glad/glad.h>
#include <iostream>
#include <vector>

#include <Shader.h>

#include <glm/ext/matrix_clip_space.hpp> 
#include <glm/ext/matrix_transform.hpp> 
#include <glm/mat4x4.hpp> 

struct Vertex
{
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
};

class Mesh
{
public:
	Mesh(const std::vector<Vertex>& vertices, const std::vector<unsigned int>& indices);
	~Mesh();

	void render();

	static Mesh& getTriangleMesh();
private:
	std::vector<Vertex> vertices;
	std::vector<unsigned int> indices;
	//std::vector<Texture> textures;
	GLuint VBO, VAO, EBO;
};