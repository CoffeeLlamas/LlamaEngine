#vertex
#version 330 core

layout(location = 0) in vec2 position;
void main() {
	gl_Position = vec4(position, 0, 1);
}

#fragment
#version 330 core

out vec4 colour;
void main() {
	colour = vec4(0, 0, 0, 1);
}