#shader vertex
#version 330 core

layout(location = 0) in vec3 position;
layout(location = 1) in vec2 texCoord;
layout(location = 2) in vec3 normal;


out vec2 v_TexCoord;
out vec3 vertexNormal;
out vec3 fragPos;

uniform mat4 u_Projection;
uniform mat4 u_View;
uniform mat4 u_Model;

void main()
{
    mat4 mvp = u_Projection * u_View * u_Model;
    gl_Position = mvp * vec4(position, 1.0);
    fragPos = vec3(u_Model * vec4(position, 1.0));
    vertexNormal = mat3(transpose(inverse(u_Model))) * normal;
    v_TexCoord = texCoord;
};

#shader fragment
#version 330 core

layout(location = 0) out vec4 color;

in vec3 vertexNormal;
in vec2 v_TexCoord;
in vec3 fragPos;

uniform vec4 u_Color;
uniform sampler2D u_Texture;
uniform bool u_UseTexture;
uniform vec3 u_ViewPos;
uniform vec3 u_LightPos;
uniform vec3 u_LightColor = vec3(1.0, 1.0, 1.0);
uniform float u_AmbientStrength = 0.3;
uniform float u_SpecularStrength = 0.5;


void main()
{
    vec3 ambient = u_AmbientStrength * u_LightColor;

    vec3 norm = normalize(vertexNormal);
    vec3 lightDir = normalize(u_LightPos - fragPos);

    float diff = max(dot(norm, lightDir), 0.0);
    vec3 diffuse = diff * u_LightColor;

    vec3 viewDir = normalize(u_ViewPos - fragPos);
    vec3 reflectDir = reflect(-lightDir, norm);

    float spec = pow(max(dot(viewDir, reflectDir), 0.0), 32);
    vec3 specular = u_SpecularStrength * spec * u_LightColor;

    if (u_UseTexture) {
        vec4 texColor = texture(u_Texture, v_TexCoord);
        color = texColor;
    }
    else {
        vec3 result = (ambient + specular + diffuse);
        vec3 col = (norm + vec3(1.0, 1.0, 1.0))/2;
        color = vec4(result, 1.0);
    }
};