#version 330 core

#ifdef VERTEX_SHADER

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

out vec3 myColor;

void main() {
    gl_Position = vec4(aPos, 1.0);
    myColor = aColor;
}

#endif

#ifdef FRAGMENT_SHADER

in vec3 myColor;

out vec4 FragColor;

void main() {
    FragColor = vec4(myColor, 1.0);
}

#endif
