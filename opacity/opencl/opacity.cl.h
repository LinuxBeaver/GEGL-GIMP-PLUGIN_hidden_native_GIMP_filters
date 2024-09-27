static const char* opacity_cl_source =
"__kernel void gegl_opacity_RaGaBaA_float (__global const float4     *in,      \n"
"                                          __global const float      *aux,     \n"
"                                          __global       float4     *out,     \n"
"                                          float value)                        \n"
"{                                                                             \n"
"  int gid = get_global_id(0);                                                 \n"
"  float4 in_v  = in [gid];                                                    \n"
"  float  aux_v = (aux)? aux[gid] : 1.0f;                                      \n"
"  float4 out_v;                                                               \n"
"  out_v = in_v * aux_v * value;                                               \n"
"  out[gid]  =  out_v;                                                         \n"
"}                                                                             \n"
"__kernel void gegl_opacity_RGBA_float (__global const float4     *in,         \n"
"                                       __global const float      *aux,        \n"
"                                       __global       float4     *out,        \n"
"                                       float value)                           \n"
"{                                                                             \n"
"  int gid = get_global_id(0);                                                 \n"
"  float4 in_v  = in [gid];                                                    \n"
"  float  aux_v = (aux)? aux[gid] : 1.0f;                                      \n"
"  float4 out_v = (float4)(in_v.x, in_v.y, in_v.z, in_v.w * aux_v * value);    \n"
"  out[gid]  =  out_v;                                                         \n"
"}                                                                             \n"
;
