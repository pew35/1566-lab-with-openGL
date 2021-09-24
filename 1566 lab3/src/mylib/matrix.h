typedef struct{
    float x;
    float y;
    float z;
    float w;
}vec4;

typedef struct 
{
    vec4 x;
    vec4 y;
    vec4 z;
    vec4 w;
} mat4;

void Vprint ( vec4 v);

vec4 S_Vmultiplication (float a, vec4 v);

vec4 V_Vaddition (vec4 v1, vec4 v2);

vec4 V_Vsubtraction (vec4 v1, vec4 v2);

float Vmagnitude(vec4 v);

vec4 Vnormalize(vec4 v);

float V_Vdot_product (vec4 v1, vec4 v2);

vec4 V_Vcross_product(vec4 v1, vec4 v2);

void Mprint(mat4 m);

mat4 S_Mmultiplication(float s, mat4 m);

mat4 M_Madditon(mat4 m1, mat4 m2);

mat4 M_Msubtraction(mat4 m1, mat4 m2);

mat4 M_Mmultiplication(mat4 m1, mat4 m2);

mat4 Mminor(mat4 m);

mat4 Mcofactor(mat4 m);

float Mdeterminant(mat4 m, mat4 cof);

mat4 M_Minverse(mat4 m);

mat4 M_Mtranspose(mat4 m);

mat4 M_Vmultiplication(mat4 m, vec4 v);
