#include "linear_alg.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void vprint(vec4 v){
    printf("[%.4f %.4f %.4f %.4f]\n",v.x,v.y,v.z,v.w);
}
vec4 addv(vec4 v1, vec4 v2){
    vec4 sum;
    sum.x=(v1.x+v2.x);
    sum.y=(v1.y+v2.y);
    sum.z=(v1.z+v2.z);
    sum.w=(v1.w+v2.w);
    return sum;
}
vec4 SV(vec4 v,float s){
    vec4 result;
    result.x=v.x*s;
    result.y=v.y*s;
    result.z=v.z*s;
    result.w=v.w*s;
    return result;
}
vec4 substractv(vec4 v1, vec4 v2){
    vec4 sub;
    sub.x=(v1.x-v2.x);
    sub.y=(v1.y-v2.y);
    sub.z=(v1.z-v2.z);
    sub.w=(v1.w-v2.w); 
    return sub;
}
float magnitude(vec4 v){
    float result;
    result=sqrt(v.x*v.x+v.y*v.y+v.z*v.z+v.w*v.w);
    return result;
}
vec4 normalize(vec4 v){
     vec4 result;
    result=SV(v,(1/magnitude(v)));
    return result;
}
float dotmultiplyv(vec4 v1, vec4 v2){
    float product;
    product=((v1.x*v2.x)+(v1.y*v2.y)+(v1.z*v2.z)+(v1.w*v2.w));
    return product;
}
vec4 crossmultiplyv(vec4 v1,vec4 v2){
     vec4 product;
    product.x=(v1.y*v2.z)-(v1.z*v2.y);
    product.y=(v1.z*v2.x)-(v1.x*v2.z);
    product.z=(v1.x*v2.y)-(v1.y*v2.x);
    product.w=0;
    return product;
}
void mprint(mat4 m){
    printf("[%.4f %.4f %.4f %.4f]\n",m.x.x,m.y.x,m.z.x,m.w.x);
    printf("[%.4f %.4f %.4f %.4f]\n",m.x.y,m.y.y,m.z.y,m.w.y);
    printf("[%.4f %.4f %.4f %.4f]\n",m.x.z,m.y.z,m.z.z,m.w.z);
    printf("[%.4f %.4f %.4f %.4f]\n",m.x.w,m.y.w,m.z.w,m.w.w);
}
mat4 SM(mat4 m,float s){
mat4 product;
    product.x.x=s*m.x.x;
    product.y.x=s*m.y.x;
    product.z.x=s*m.z.x;
    product.w.x=s*m.w.x;
    product.x.y=s*m.x.y;
    product.y.y=s*m.y.y;
    product.z.y=s*m.z.y;
    product.w.y=s*m.w.y;
    product.x.z=s*m.x.z;
    product.y.z=s*m.y.z;
    product.z.z=s*m.z.z;
    product.w.z=s*m.w.z;
    product.x.w=s*m.x.w;
    product.y.w=s*m.y.w;
    product.z.w=s*m.z.w;
    product.w.w=s*m.w.w;
    return product;
}
mat4 addm(mat4 m1,mat4 m2){
    mat4 sum;
    sum.x.x=m1.x.x+m2.x.x;
    sum.y.x=m1.y.x+m2.y.x;
    sum.z.x=m1.z.x+m2.z.x;
    sum.w.x=m1.w.x+m2.w.x;
    sum.x.y=m1.x.y+m2.x.y;
    sum.y.y=m1.y.y+m2.y.y;
    sum.z.y=m1.z.y+m2.z.y;
    sum.w.y=m1.w.y+m2.w.y;
    sum.x.z=m1.x.z+m2.x.z;
    sum.y.z=m1.y.z+m2.y.z;
    sum.z.z=m1.z.z+m2.z.z;
    sum.w.z=m1.w.z+m2.w.z;
    sum.x.w=m1.x.w+m2.x.w;
    sum.y.w=m1.y.w+m2.y.w;
    sum.z.w=m1.z.w+m2.z.w;
    sum.w.w=m1.w.w+m2.w.w;
    return sum;
}
mat4 subversem(mat4 m1,mat4 m2){
     mat4 sub;
    sub.x.x=m1.x.x-m2.x.x;
    sub.y.x=m1.y.x-m2.y.x;
    sub.z.x=m1.z.x-m2.z.x;
    sub.w.x=m1.w.x-m2.w.x;
    sub.x.y=m1.x.y-m2.x.y;
    sub.y.y=m1.y.y-m2.y.y;
    sub.z.y=m1.z.y-m2.z.y;
    sub.w.y=m1.w.y-m2.w.y;
    sub.x.z=m1.x.z-m2.x.z;
    sub.y.z=m1.y.z-m2.y.z;
    sub.z.z=m1.z.z-m2.z.z;
    sub.w.z=m1.w.z-m2.w.z;
    sub.x.w=m1.x.w-m2.x.w;
    sub.y.w=m1.y.w-m2.y.w;
    sub.z.w=m1.z.w-m2.z.w;
    sub.w.w=m1.w.w-m2.w.w;
    return sub;
}
mat4 multiplym(mat4 m1,mat4 m2){
    mat4 result;
    result.x.x = (m2.x.x * m1.x.x) + (m2.x.y * m1.y.x) + (m2.x.z * m1.z.x) + (m2.x.w * m1.w.x);
	result.y.x = (m2.y.x * m1.x.x) + (m2.y.y * m1.y.x) + (m2.y.z * m1.z.x) + (m2.y.w * m1.w.x);
	result.z.x = (m2.z.x * m1.x.x) + (m2.z.y * m1.y.x) + (m2.z.z * m1.z.x) + (m2.z.w * m1.w.x);
	result.w.x = (m2.w.x * m1.x.x) + (m2.w.y * m1.y.x) + (m2.w.z * m1.z.x) + (m2.w.w * m1.w.x);

	result.x.y = (m2.x.x * m1.x.y) + (m2.x.y * m1.y.y) + (m2.x.z * m1.z.y) + (m2.x.w * m1.w.y);
	result.y.y = (m2.y.x * m1.x.y) + (m2.y.y * m1.y.y) + (m2.y.z * m1.z.y) + (m2.y.w * m1.w.y);
	result.z.y = (m2.z.x * m1.x.y) + (m2.z.y * m1.y.y) + (m2.z.z * m1.z.y) + (m2.z.w * m1.w.y);
	result.w.y = (m2.w.x * m1.x.y) + (m2.w.y * m1.y.y) + (m2.w.z * m1.z.y) + (m2.w.w * m1.w.y);

	result.x.z = (m2.x.x * m1.x.z) + (m2.x.y * m1.y.z) + (m2.x.z * m1.z.z) + (m2.x.w * m1.w.z);
	result.y.z = (m2.y.x * m1.x.z) + (m2.y.y * m1.y.z) + (m2.y.z * m1.z.z) + (m2.y.w * m1.w.z);
	result.z.z = (m2.z.x * m1.x.z) + (m2.z.y * m1.y.z) + (m2.z.z * m1.z.z) + (m2.z.w * m1.w.z);
	result.w.z = (m2.w.x * m1.x.z) + (m2.w.y * m1.y.z) + (m2.w.z * m1.z.z) + (m2.w.w * m1.w.z);

	result.x.w = (m2.x.x * m1.x.w) + (m2.x.y * m1.y.w) + (m2.x.z * m1.z.w) + (m2.x.w * m1.w.w);
	result.y.w = (m2.y.x * m1.x.w) + (m2.y.y * m1.y.w) + (m2.y.z * m1.z.w) + (m2.y.w * m1.w.w);
	result.z.w = (m2.z.x * m1.x.w) + (m2.z.y * m1.y.w) + (m2.z.z * m1.z.w) + (m2.z.w * m1.w.w);
	result.w.w = (m2.w.x * m1.x.w) + (m2.w.y * m1.y.w) + (m2.w.z * m1.z.w) + (m2.w.w * m1.w.w);
    return result;
}
vec4 mxv(mat4 m,vec4 v){
    vec4 reslut;
    reslut.x=((m.x.x*v.x)+(m.y.x*v.y)+(m.z.x*v.z)+(m.w.x*v.w));
    reslut.y=((m.x.y*v.x)+(m.y.y*v.y)+(m.z.y*v.z)+(m.w.y*v.w));
    reslut.z=((m.x.z*v.x)+(m.y.z*v.y)+(m.z.z*v.z)+(m.w.z*v.w));
    reslut.w=((m.x.w*v.x)+(m.y.w*v.y)+(m.z.w*v.z)+(m.w.w*v.w));
    return reslut;
}
mat4 minor(mat4 m){
     mat4 result;
    result.x.x= (m.y.y*m.z.z*m.w.w)+(m.y.z*m.z.w*m.w.y)+(m.y.w*m.z.y*m.w.z)-(m.y.w*m.z.z*m.w.y)-(m.y.z*m.z.y*m.w.w)-(m.y.y*m.z.w*m.w.z);
	result.x.y= (m.y.x*m.z.z*m.w.w)+(m.y.z*m.z.w*m.w.x)+(m.y.w*m.z.x*m.w.z)-(m.y.w*m.z.z*m.w.x)-(m.y.z*m.z.x*m.w.w)-(m.y.x*m.z.w*m.w.z);
	result.x.z= (m.y.x*m.z.y*m.w.w)+(m.y.y*m.z.w*m.w.x)+(m.y.w*m.z.x*m.w.y)-(m.y.w*m.z.y*m.w.x)-(m.y.y*m.z.x*m.w.w)-(m.y.x*m.z.w*m.w.y);
	result.x.w= (m.y.x*m.z.y*m.w.z)+(m.y.y*m.z.z*m.w.x)+(m.y.z*m.z.x*m.w.y)-(m.y.z*m.z.y*m.w.x)-(m.y.y*m.z.x*m.w.z)-(m.y.x*m.z.z*m.w.y);

	result.y.x= (m.x.y*m.z.z*m.w.w)+(m.x.z*m.z.w*m.w.y)+(m.x.w*m.z.y*m.w.z)-(m.x.w*m.z.z*m.w.y)-(m.x.z*m.z.y*m.w.w)-(m.x.y*m.z.w*m.w.z);
	result.y.y= (m.x.x*m.z.z*m.w.w)+(m.x.z*m.z.w*m.w.x)+(m.x.w*m.z.x*m.w.z)-(m.x.w*m.z.z*m.w.x)-(m.x.z*m.z.x*m.w.w)-(m.x.x*m.z.w*m.w.z);
	result.y.z= (m.x.x*m.z.y*m.w.w)+(m.x.y*m.z.w*m.w.x)+(m.x.w*m.z.x*m.w.y)-(m.x.w*m.z.y*m.w.x)-(m.x.y*m.z.x*m.w.w)-(m.x.x*m.z.w*m.w.y);
	result.y.w= (m.x.x*m.z.y*m.w.z)+(m.x.y*m.z.z*m.w.x)+(m.x.z*m.z.x*m.w.y)-(m.x.z*m.z.y*m.w.x)-(m.x.y*m.z.x*m.w.z)-(m.x.x*m.z.z*m.w.y);
	
	result.z.x= (m.x.y*m.y.z*m.w.w)+(m.x.z*m.y.w*m.w.y)+(m.x.w*m.y.y*m.w.z)-(m.x.w*m.y.z*m.w.y)-(m.x.z*m.y.y*m.w.w)-(m.x.y*m.y.w*m.w.z);
	result.z.y= (m.x.x*m.y.z*m.w.w)+(m.x.z*m.y.w*m.w.x)+(m.x.w*m.y.x*m.w.z)-(m.x.w*m.y.z*m.w.x)-(m.x.z*m.y.x*m.w.w)-(m.x.x*m.y.w*m.w.z);
	result.z.z= (m.x.x*m.y.y*m.w.w)+(m.x.y*m.y.w*m.w.x)+(m.x.w*m.y.x*m.w.y)-(m.x.w*m.y.y*m.w.x)-(m.x.y*m.y.x*m.w.w)-(m.x.x*m.y.w*m.w.y);
	result.z.w= (m.x.x*m.y.y*m.w.z)+(m.x.y*m.y.z*m.w.x)+(m.x.z*m.y.x*m.w.y)-(m.x.z*m.y.y*m.w.x)-(m.x.y*m.y.x*m.w.z)-(m.x.x*m.y.z*m.w.y);
	
	result.w.x= (m.x.y*m.y.z*m.z.w)+(m.x.z*m.y.w*m.z.y)+(m.x.w*m.y.y*m.z.z)-(m.x.w*m.y.z*m.z.y)-(m.x.z*m.y.y*m.z.w)-(m.x.y*m.y.w*m.z.z);
	result.w.y= (m.x.x*m.y.z*m.z.w)+(m.x.z*m.y.w*m.z.x)+(m.x.w*m.y.x*m.z.z)-(m.x.w*m.y.z*m.z.x)-(m.x.z*m.y.x*m.z.w)-(m.x.x*m.y.w*m.z.z);
	result.w.z= (m.x.x*m.y.y*m.z.w)+(m.x.y*m.y.w*m.z.x)+(m.x.w*m.y.x*m.z.y)-(m.x.w*m.y.y*m.z.x)-(m.x.y*m.y.x*m.z.w)-(m.x.x*m.y.w*m.z.y);
	result.w.w= (m.x.x*m.y.y*m.z.z)+(m.x.y*m.y.z*m.z.x)+(m.x.z*m.y.x*m.z.y)-(m.x.z*m.y.y*m.z.x)-(m.x.y*m.y.x*m.z.z)-(m.x.x*m.y.z*m.z.y);

	return result;
}
mat4 cofactor(mat4 m){
    mat4 result;
    result.x.x=m.x.x;
    result.x.y=(-1)*m.x.y;
    result.x.z=m.x.z;
    result.x.w=(-1)*m.x.w;

    result.y.x=(-1)*m.y.x;
    result.y.y=m.y.y;
    result.y.z=(-1)*m.y.z;
    result.y.w=m.y.w;

    result.z.x=m.z.x;
    result.z.y=(-1)*m.z.y;
    result.z.z=m.z.z;
    result.z.w=(-1)*m.z.w;

    result.w.x=(-1)*m.w.x;
    result.w.y=m.w.y;
    result.w.z=(-1)*m.w.z;
    result.w.w=m.w.w;
    return result;
}
float determinant(mat4 m,mat4 cofactor){
    float result, a,b,c,d;
    a=m.x.x*cofactor.x.x;
    b=m.x.y*cofactor.x.y;
    c=m.x.z*cofactor.x.z;
    d=m.x.w*cofactor.x.w;
    result=a+b+c+d;
    return result;
}
mat4 transpose(mat4 m){
    mat4 result;
    result.x.x=m.x.x;
    result.x.y=m.y.x;
    result.x.z=m.z.x;
    result.x.w=m.w.x;

    result.y.x=m.x.y;
    result.y.y=m.y.y;
    result.y.z=m.z.y;
    result.y.w=m.w.y;

    result.z.x=m.x.z;
    result.z.y=m.y.z;
    result.z.z=m.z.z;
    result.z.w=m.w.z;

    result.w.x=m.x.w;
    result.w.y=m.y.w;
    result.w.z=m.z.w;
    result.w.w=m.w.w;
    
    return result;
}
mat4 inverse(mat4 m){
    mat4 minor1=minor(m);
    mat4 cofactor1=cofactor(minor1);
    mat4 transpose1=transpose(cofactor1);
    float determinant1=determinant(m,cofactor1);
    mat4 result=SM(transpose1,(1/determinant1));
    return result;
}
mat4 transalte(mat4 m,vec4 v){
    mat4 result;
    mat4 translation={{1,0,0,0},{0,1,0,0},{0,0,1,0},{v.x,v.y,v.z,1}};
    result.x=mxv(translation,m.x);
    result.y=mxv(translation,m.y);
    result.z=mxv(translation,m.z);
    return result;
}
vec4 rotatex(vec4 point,float angle){
    float a=(M_PI/180)*angle;
    mat4 rorate={{1,0,0,0},{0,cos(a),sin(a),0},{0,(-1)*sin(a),cos(a),0},{0,0,0,1}};
    return mxv(rorate,point);
}
vec4 rotatey(vec4 point,float angle){
    float a=(M_PI/180)*angle;
    mat4 rorate={{cos(a),0,(-1)*sin(a),0},{0,1,0,0},{sin(a),0,cos(a),0},{0,0,0,1}};
    return mxv(rorate,point);
}
vec4 rotatez(vec4 point,float angle){
    float a=(M_PI/180)*angle;
    mat4 rorate={{cos(a),sin(a),0,0},{(-1)*sin(a),cos(a),0,0},{0,0,1,0},{0,0,0,1}};
    return mxv(rorate,point);
}
mat4 scale(vec4 v, mat4 m){
	mat4 scale1={{v.x,0,0,0},{0,v.y,0,0},{0,0,v.z,0},{0,0,0,1}};
	return multiplym(m,scale1);
}
mat4 look_at(float eyex, float eyey, float eyez, 
	float atx, float aty, float atz,
	float upx, float upy, float upz);