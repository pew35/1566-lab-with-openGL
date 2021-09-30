typedef struct 
{
    /* data */
    float x;
    float y;
    float z;
    float w;

}vec4;

typedef struct{
    vec4 x;
    vec4 y;
    vec4 z;
    vec4 w;
}mat4;

void vprint(vec4 v);
vec4 addv(vec4 v1,vec4 v2);
vec4 SV(vec4 v,float s);
vec4 subversev(vec4 v1,vec4 v2);
float magnitude(vec4 v);
vec4 normalize(vec4 v);
float dotmultiplyv(vec4 v1, vec4 v2);
vec4 crossmultiplyv(vec4 v1,vec4 v2);
void mprint(mat4 m);
mat4 SM(mat4 m,float s);
mat4 addm(mat4 m1,mat4 m2);
mat4 subversem(mat4 m1,mat4 m2);
mat4 multiplym(mat4 m1,mat4 m2);
vec4 mxv(mat4 m,vec4 v);
mat4 minor(mat4 m);
mat4 cofactor(mat4 m);
float determinant(mat4 m1,mat4 m2);
mat4 inverse(mat4 m);
mat4 transpose(mat4 m);
mat4 transalte(mat4 m,vec4 v);
vec4 rotatex(vec4 point, float angle);
vec4 rotatey(vec4 point, float angle);
vec4 rotatez(vec4 point, float angle);
mat4 scale(vec4 factor,mat4 m);
mat4 look_at(float eyex,float eyey, float eyez,
 float atx, float aty, float atz, 
 float upx, float upy, float upz);
