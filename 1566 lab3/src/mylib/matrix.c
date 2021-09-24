#include "matrix.h" 
#include <stdlib.h>
#include <math.h>
#include <stdio.h>


void Vprint ( vec4 v){
        printf("[%.02f,%.02f,%.02f,%.02f]\n", v.x, v.y, v.z, v.w);
}

vec4 S_Vmultiplication (float a, vec4 v){
    vec4 newV = {a*v.x, a*v.y, a*v.z, a*v.w};
    return newV;
}

vec4 V_Vaddition (vec4 v1, vec4 v2){
    v1.x = v1.x + v2.x;
    v1.y = v1.y + v2.y;
    v1.z = v1.z + v2.z;
    v1.w = v1.w + v2.w;
    return v1;
}

vec4 V_Vsubtraction (vec4 v1, vec4 v2){
    v1.x = v1.x - v2.x;
    v1.y = v1.y - v2.y;
    v1.z = v1.z - v2.z;
    v1.w = v1.w - v2.w;
    return v1;
}

float Vmagnitude(vec4 v){
    float magnitude = v.x*v.x + v.y*v.y + v.z*v.z + v.w*v.w;
    magnitude = sqrt(magnitude);
    return magnitude;
}

vec4 Vnormalize(vec4 v){
    float norm = 1/Vmagnitude(v);
    vec4 newV = S_Vmultiplication(norm ,  v);
    return newV;
}

float V_Vdot_product (vec4 v1, vec4 v2){
    return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w) ;
}

vec4 V_Vcross_product(vec4 v1, vec4 v2){
    float a = v1.y * v2.z - v1.z * v2.y;
    float b = v1.z * v2.x - v1.x * v2.z;
    float c = v1.x * v2.y - v1.y * v2.x;
    v1.x = a;
    v1.y = b;
    v1.z = c;
    v1.w = 0.0;
    return v1;
}

void Mprint(mat4 m){
    printf("[%.3f %.3f %.3f %.3f]\n",m.x.x,m.y.x,m.z.x,m.w.x);
    printf("[%.3f %.3f %.3f %.3f]\n",m.x.y,m.y.y,m.z.y,m.w.y);
    printf("[%.3f %.3f %.3f %.3f]\n",m.x.z,m.y.z,m.z.z,m.w.z);
    printf("[%.3f %.3f %.3f %.3f]\n",m.x.w,m.y.w,m.z.w,m.w.w);
}

mat4 S_Mmultiplication(float s, mat4 m){
    m.x.x *= s;
    m.x.y *= s;
    m.x.z *= s;
    m.x.w *= s;
    m.y.x *= s;
    m.y.y *= s;
    m.y.z *= s;
    m.y.w *= s;
    m.z.x *= s;
    m.z.y *= s;
    m.z.z *= s;
    m.z.w *= s;
    m.w.x *= s;
    m.w.y *= s;
    m.w.z *= s;
    m.w.w *= s;
    return m;
}

mat4 M_Madditon(mat4 m1, mat4 m2){
    m1.x = V_Vaddition(m1.x, m2.x);
    m1.y = V_Vaddition(m1.y, m2.y);
    m1.z = V_Vaddition(m1.z, m2.z);
    m1.w = V_Vaddition(m1.w, m2.w);
    return m1;
}

mat4 M_Msubtraction(mat4 m1, mat4 m2){
    m1.x = V_Vsubtraction(m1.x, m2.x);
    m1.y = V_Vsubtraction(m1.y, m2.y);
    m1.z = V_Vsubtraction(m1.z, m2.z);
    m1.w = V_Vsubtraction(m1.w, m2.w);
    return m1;
}

mat4 M_Mmultiplication(mat4 m1, mat4 m2){
    float c11 = m1.x.x * m2.x.x + m1.y.x * m2.x.y + m1.z.x * m2.x.z + m1.w.x * m2.x.w;
    float c21 = m1.x.y * m2.x.x + m1.y.y * m2.x.y + m1.z.y * m2.x.z + m1.w.y * m2.x.w;
    float c31 = m1.x.z * m2.x.x + m1.y.z * m2.x.y + m1.z.z * m2.x.z + m1.w.z * m2.x.w;
    float c41 = m1.x.w * m2.x.x + m1.y.w * m2.x.y + m1.z.w * m2.x.z + m1.w.w * m2.x.w;
    /*c21= (a21×b11) + (a22×b21) + (a23×b31) + (a24×b41)
    c31= (a31×b11) + (a32×b21) + (a33×b31) + (a34×b41)
    c41= (a41×b11) + (a42×b21) + (a43×b31) + (a44×b41)*/
    float c12 = m1.x.x * m2.y.x + m1.y.x * m2.y.y + m1.z.x * m2.y.z + m1.w.x * m2.y.w;
    float c22 = m1.x.y * m2.y.x + m1.y.y * m2.y.y + m1.z.y * m2.y.z + m1.w.y * m2.y.w;
    float c32 = m1.x.z * m2.y.x + m1.y.z * m2.y.y + m1.z.z * m2.y.z + m1.w.z * m2.y.w;
    float c42 = m1.x.w * m2.y.x + m1.y.w * m2.y.y + m1.z.w * m2.y.z + m1.w.w * m2.y.w;
    /*c12= (a11×b12) + (a12×b22) + (a13×b32) + (a14×b42)
    c22= (a21×b12) + (a22×b22) + (a23×b32) + (a24×b42)
    c32= (a31×b12) + (a32×b22) + (a33×b32) + (a34×b42)
    c42= (a41×b12) + (a42×b22) + (a43×b32) + (a44×b42)*/
    float c13 = m1.x.x * m2.z.x + m1.y.x * m2.z.y + m1.z.x * m2.z.z + m1.w.x * m2.z.w; 
    float c23 = m1.x.y * m2.z.x + m1.y.y * m2.z.y + m1.z.y * m2.z.z + m1.w.y * m2.z.w;
    float c33 = m1.x.z * m2.z.x + m1.y.z * m2.z.y + m1.z.z * m2.z.z + m1.w.z * m2.z.w;
    float c43 = m1.x.w * m2.z.x + m1.y.w * m2.z.y + m1.z.w * m2.z.z + m1.w.w * m2.z.w;
    /*c13= (a11×b13) + (a12×b23) + (a13×b33) + (a14×b43)
    c23= (a21×b13) + (a22×b23) + (a23×b33) + (a24×b43)
    c33= (a31×b13) + (a32×b23) + (a33×b33) + (a34×b43)
    c43= (a41×b13) + (a42×b23) + (a43×b33) + (a44×b43)*/
    float c14 = m1.x.x * m2.w.x + m1.y.x * m2.w.y + m1.z.x * m2.w.z + m1.w.x * m2.w.w;
    float c24 = m1.x.y * m2.w.x + m1.y.y * m2.w.y + m1.z.y * m2.w.z + m1.w.y * m2.w.w;
    float c34 = m1.x.z * m2.w.x + m1.y.z * m2.w.y + m1.z.z * m2.w.z + m1.w.z * m2.w.w;
    float c44 = m1.x.w * m2.w.x + m1.y.w * m2.w.y + m1.z.w * m2.w.z + m1.w.w * m2.w.w;
    /*c14= (a11×b14) + (a12×b24) + (a13×b34) + (a14×b44)
    c24= (a21×b14) + (a22×b24) + (a23×b34) + (a24×b44)
    c34= (a31×b14) + (a32×b24) + (a33×b34) + (a34×b44)
    c44= (a41×b14) + (a42×b24) + (a43×b34) + (a44×b44)*/

    mat4 newM = {{c11,c21,c31,c41},{c12,c22,c32,c42}, {c13,c23,c33,c43},{c14,c24,c34,c44}};
    return newM;
}

mat4 Mminor(mat4 m){
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

mat4 Mcofactor(mat4 m){
    m.x.y=(-1)*m.x.y;
    m.x.w=(-1)*m.x.w;
    m.y.x=(-1)*m.y.x;
    m.y.z=(-1)*m.y.z;
    m.z.y=(-1)*m.z.y;
    m.z.w=(-1)*m.z.w;
    m.w.x=(-1)*m.w.x;
    m.w.z=(-1)*m.w.z;

    return m;
}

float Mdeterminant(mat4 m, mat4 cof){
    float a = m.x.x * cof.x.x + m.x.y * cof.x.y + m.x.z * cof.x.z + m.x.w * cof.x.w;
    return a;
}

mat4 M_Minverse(mat4 m){
    mat4 minor = Mminor(m);
    mat4 cofactor = Mcofactor(minor);
    mat4 transpose = M_Mtranspose(cofactor);
    float determinant = Mdeterminant(m, cofactor);
    mat4 a_inv = S_Mmultiplication(1/determinant, transpose);
    return a_inv;
}

mat4 M_Mtranspose(mat4 m){
    mat4 t;
    vec4 vx = {m.x.x , m.y.x , m.z.x , m.w.x};
    vec4 vy = {m.x.y , m.y.y , m.z.y , m.w.y};
    vec4 vz = {m.x.z , m.y.z , m.z.z , m.w.z};
    vec4 vw = {m.x.w , m.y.w , m.z.w , m.w.w};
    t.x = vx;
    t.y = vy;
    t.z = vz;
    t.w = vw;

    return t;
}
mat4 M_Vmultiplication(mat4 m, vec4 v){
    m.x = S_Vmultiplication(v.x , m.x);
    m.y = S_Vmultiplication(v.y , m.y);
    m.z = S_Vmultiplication(v.z , m.z);
    m.w = S_Vmultiplication(v.w , m.w);
    return m;
}