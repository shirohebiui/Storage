
typedef unsigned int u_int;
u_int rol_32(u_int reg, u_int shift) {
    u_int left = (reg << shift) & 0xFFFFFFFF;
    u_int right = reg >> 32 - shift;
    return left | right;
}
