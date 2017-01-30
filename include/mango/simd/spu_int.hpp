/*
    MANGO Multimedia Development Platform
    Copyright (C) 2012-2017 Twilight Finland 3D Oy Ltd. All rights reserved.
*/
#pragma once

#include "simd.hpp"

#ifdef MANGO_SIMD_INT_SPU

namespace mango {
namespace simd {

    // -----------------------------------------------------------------
    // helpers
    // -----------------------------------------------------------------

#define SPU_SH4(n, select) \
    (n * 4 + 0) | (select << 4), \
    (n * 4 + 1) | (select << 4), \
    (n * 4 + 2) | (select << 4), \
    (n * 4 + 3) | (select << 4)

    // -----------------------------------------------------------------
    // uint32x4
    // -----------------------------------------------------------------

    // shuffle

    template <int x, int y, int z, int w>
    static inline uint32x4 uint32x4_shuffle(uint32x4 v)
    {
		const vector unsigned char mask =
		{
            SPU_SH4(x, 0), SPU_SH4(y, 0), SPU_SH4(z, 0), SPU_SH4(w, 0)
		};
		return spu_shuffle(v, v, mask);
    }

    template <>
    inline uint32x4 uint32x4_shuffle<0, 1, 2, 3>(uint32x4 v)
    {
        // .xyzw
        return v;
    }

    // indexed access

    template <int Index>
    static inline uint32x4 uint32x4_set_component(uint32x4 a, uint32 s)
    {
        static_assert(Index >= 0 && Index < 4, "Index out of range.");
        return spu_insert(s, a, Index);
    }

    template <int Index>
    static inline uint32 uint32x4_get_component(uint32x4 a)
    {
        static_assert(Index >= 0 && Index < 4, "Index out of range.");
        return spu_extract(a, Index);
    }

    static inline uint32x4 uint32x4_zero()
    {
        return spu_splats(0);
    }

    static inline uint32x4 uint32x4_set1(uint32 s)
    {
        return spu_splats(s);
    }

    static inline uint32x4 uint32x4_set4(uint32 x, uint32 y, uint32 z, uint32 w)
    {
		const uint32x4 temp = { x, y, z, w };
		return temp;
    }

    static inline uint32x4 uint32x4_uload(const uint32* s)
    {
        uint32x4 temp = { s[0], s[1], s[2], s[3] };
        return temp;
    }

    static inline void uint32x4_ustore(uint32* dest, uint32x4 a)
    {
        dest[0] = spu_extract(a, 0);
        dest[1] = spu_extract(a, 1);
        dest[2] = spu_extract(a, 2);
        dest[3] = spu_extract(a, 3);
    }

    // logical

    static inline uint32x4 uint32x4_and(uint32x4 a, uint32x4 b)
    {
		return spu_and(a, b);
    }

    static inline uint32x4 uint32x4_nand(uint32x4 a, uint32x4 b)
    {
        return spu_nand(a, b);
    }

    static inline uint32x4 uint32x4_or(uint32x4 a, uint32x4 b)
    {
		return spu_or(a, b);
    }

    static inline uint32x4 uint32x4_xor(uint32x4 a, uint32x4 b)
    {
		return spu_xor(a, b);
    }

    static inline uint32x4 uint32x4_compare_eq(uint32x4 a, uint32x4 b)
    {
		return (uint32x4) spu_cmpeq(a, b);
    }

    static inline uint32x4 uint32x4_compare_gt(uint32x4 a, uint32x4 b)
    {
		return (uint32x4) spu_cmpgt(a, b);
    }

    static inline uint32x4 uint32x4_select(uint32x4 mask, uint32x4 a, uint32x4 b)
    {
		return spu_sel(b, a, mask);
    }

    static inline uint32x4 uint32x4_min(uint32x4 a, uint32x4 b)
    {
        return spu_sel(a, b, spu_cmpgt(a, b));
    }

    static inline uint32x4 uint32x4_max(uint32x4 a, uint32x4 b)
    {
        return spu_sel(b, a, spu_cmpgt(a, b));
    }

    // -----------------------------------------------------------------
    // int32x4
    // -----------------------------------------------------------------

    // shuffle

    template <int x, int y, int z, int w>
    static inline int32x4 int32x4_shuffle(int32x4 v)
    {
		const vector unsigned char mask =
		{
            SPU_SH4(x, 0), SPU_SH4(y, 0), SPU_SH4(z, 0), SPU_SH4(w, 0)
		};
		return spu_shuffle(v, v, mask);
    }

    template <>
    inline int32x4 int32x4_shuffle<0, 1, 2, 3>(int32x4 v)
    {
        // .xyzw
        return v;
    }

    // indexed access

    template <int Index>
    static inline int32x4 int32x4_set_component(int32x4 a, int32 s)
    {
        static_assert(Index >= 0 && Index < 4, "Index out of range.");
        return spu_insert(s, a, Index);
    }

    template <int Index>
    static inline int32 int32x4_get_component(int32x4 a)
    {
        static_assert(Index >= 0 && Index < 4, "Index out of range.");
        return spu_extract(a, Index);
    }

    static inline int32x4 int32x4_zero()
    {
        return spu_splats(0);
    }

    static inline int32x4 int32x4_set1(int s)
    {
        return spu_splats(s);
    }

    static inline int32x4 int32x4_set4(int x, int y, int z, int w)
    {
		const int32x4 temp = { x, y, z, w };
		return temp;
    }

    static inline int32x4 int32x4_uload(const int* s)
    {
        int32x4 temp = { s[0], s[1], s[2], s[3] };
        return temp;
    }

    static inline void int32x4_ustore(int* dest, int32x4 a)
    {
        dest[0] = spu_extract(a, 0);
        dest[1] = spu_extract(a, 1);
        dest[2] = spu_extract(a, 2);
        dest[3] = spu_extract(a, 3);
    }

    static inline int32x4 int32x4_neg(int32x4 a)
    {
        return spu_sub(spu_splats(0), a);
    }

    static inline int32x4 int32x4_add(int32x4 a, int32x4 b)
    {
		return spu_add(a, b);
    }

    static inline int32x4 int32x4_sub(int32x4 a, int32x4 b)
    {
		return spu_sub(a, b);
    }

    // logical

    static inline int32x4 int32x4_and(int32x4 a, int32x4 b)
    {
		return spu_and(a, b);
    }

    static inline int32x4 int32x4_nand(int32x4 a, int32x4 b)
    {
        return spu_nand(a, b);
    }

    static inline int32x4 int32x4_or(int32x4 a, int32x4 b)
    {
		return spu_or(a, b);
    }

    static inline int32x4 int32x4_xor(int32x4 a, int32x4 b)
    {
		return spu_xor(a, b);
    }

    static inline int32x4 int32x4_sll(int32x4 a, int b)
    {
        return spu_sl(a, b);
    }

    static inline int32x4 int32x4_srl(int32x4 a, int b)
    {
        return spu_sr(a, b);
    }

    static inline int32x4 int32x4_sra(int32x4 a, int b)
    {
        return spu_sra(a, b);
    }

    static inline int32x4 int32x4_compare_eq(int32x4 a, int32x4 b)
    {
		return (int32x4) spu_cmpeq(a, b);
    }

    static inline int32x4 int32x4_compare_gt(int32x4 a, int32x4 b)
    {
		return (int32x4) spu_cmpgt(a, b);
    }

    static inline int32x4 int32x4_select(int32x4 mask, int32x4 a, int32x4 b)
    {
		return spu_sel(b, a, (vec_uint4)mask);
    }

    static inline int32x4 int32x4_min(int32x4 a, int32x4 b)
    {
        return spu_sel(a, b, spu_cmpgt(a, b));
    }

    static inline int32x4 int32x4_max(int32x4 a, int32x4 b)
    {
        return spu_sel(b, a, spu_cmpgt(a, b));
    }

    static inline uint32 int32x4_pack(int32x4 s)
    {
        unsigned int* p = (unsigned int*)&s;
        return p[0] | (p[1] << 8) | (p[2] << 16) | (p[3] << 24);
    }

    static inline int32x4 int32x4_unpack(uint32 s)
    {
        const int x = (s >> 0) & 0xff;
        const int y = (s >> 8) & 0xff;
        const int z = (s >> 16) & 0xff;
        const int w = (s >> 24);
        return int32x4_set4(x, y, z, w);
    }

#undef SPU_SH4

} // namespace simd
} // namespace mango

#endif // MANGO_SIMD_INT_SPU