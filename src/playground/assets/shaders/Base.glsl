#version 330 core

#ifdef VERTEX_SHADER

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;
layout (location = 2) in vec2 aTexCoord;

out vec3 myColor;
out vec2 texCoord;

uniform mat4 transform;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * transform * vec4(aPos, 1.0);
    myColor = aColor;
    texCoord = aTexCoord;
}

#endif

#ifdef FRAGMENT_SHADER

in vec3 myColor;
in vec2 texCoord;

out vec4 FragColor;

uniform sampler2D myTexture1;
uniform sampler2D myTexture2;

void main() {
    FragColor = mix(texture(myTexture1, texCoord), texture(myTexture2, texCoord), 0.2) * vec4(myColor, 1.0);
}

#endif
