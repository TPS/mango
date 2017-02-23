/*
    MANGO Multimedia Development Platform
    Copyright (C) 2012-2017 Twilight Finland 3D Oy Ltd. All rights reserved.
*/
#pragma once

#include "simd.hpp"

#ifdef MANGO_SIMD_INT_SSE

namespace mango {
namespace simd {

    // -----------------------------------------------------------------
    // helpers
    // -----------------------------------------------------------------

    #define simd_shuffle_epi(a, b, mask) \
        _mm_castps_si128(_mm_shuffle_ps(_mm_castsi128_ps(a), _mm_castsi128_ps(b), mask));

    static inline __m128i _mm_select_si128(__m128i mask, __m128i a, __m128i b)
    {
        return _mm_or_si128(_mm_and_si128(mask, a), _mm_andnot_si128(mask, b));
    }

    // -----------------------------------------------------------------
    // uint8x16
    // -----------------------------------------------------------------

    static inline uint8x16 uint8x16_zero()
    {
        return _mm_setzero_si128();
    }

    static inline uint8x16 uint8x16_set1(uint8 s)
    {
        return _mm_set1_epi8(s);
    }

    static inline uint8x16 uint8x16_add(uint8x16 a, uint8x16 b)
    {
        return _mm_add_epi8(a, b);
    }

    static inline uint8x16 uint8x16_sub(uint8x16 a, uint8x16 b)
    {
        return _mm_sub_epi8(a, b);
    }

    // saturated

    static inline uint8x16 uint8x16_adds(uint8x16 a, uint8x16 b)
    {
        return _mm_adds_epu8(a, b);
    }

    static inline uint8x16 uint8x16_subs(uint8x16 a, uint8x16 b)
    {
        return _mm_subs_epu8(a, b);
    }

    // logical

    static inline uint8x16 uint8x16_and(uint8x16 a, uint8x16 b)
    {
        return _mm_and_si128(a, b);
    }

    static inline uint8x16 uint8x16_nand(uint8x16 a, uint8x16 b)
    {
        return _mm_andnot_si128(a, b);
    }

    static inline uint8x16 uint8x16_or(uint8x16 a, uint8x16 b)
    {
        return _mm_or_si128(a, b);
    }

    static inline uint8x16 uint8x16_xor(uint8x16 a, uint8x16 b)
    {
        return _mm_xor_si128(a, b);
    }

    // compare

#if defined(MANGO_ENABLE_XOP)

    static inline uint8x16 uint8x16_not(uint8x16 a)
    {
        return _mm_xor_si128(a, _mm_comeq_epu8(a, a));
    }

    static inline uint8x16 uint8x16_compare_neq(uint8x16 a, uint8x16 b)
    {
        return _mm_comneq_epu8(a, b);
    }

    static inline uint8x16 uint8x16_compare_lt(uint8x16 a, uint8x16 b)
    {
        return _mm_comlt_epu8(a, b);
    }

    static inline uint8x16 uint8x16_compare_le(uint8x16 a, uint8x16 b)
    {
        return _mm_comle_epu8(a, b);
    }

    static inline uint8x16 uint8x16_compare_ge(uint8x16 a, uint8x16 b)
    {
        return _mm_comge_epu8(a, b);
    }

    static inline uint8x16 uint8x16_compare_eq(uint8x16 a, uint8x16 b)
    {
        return _mm_comeq_epu8(a, b);
    }

    static inline uint8x16 uint8x16_compare_gt(uint8x16 a, uint8x16 b)
    {
        return _mm_comgt_epu8(a, b);
    }

#else

    static inline uint8x16 uint8x16_compare_eq(uint8x16 a, uint8x16 b)
    {
        return _mm_cmpeq_epi8(a, b);
    }

    static inline uint8x16 uint8x16_compare_gt(uint8x16 a, uint8x16 b)
    {
        const __m128i sign = _mm_set1_epi32(0x80808080);
        return _mm_cmpgt_epi8(_mm_xor_si128(a, sign), _mm_xor_si128(b, sign));
    }

#endif

    static inline uint8x16 uint8x16_select(uint8x16 mask, uint8x16 a, uint8x16 b)
    {
        return _mm_select_si128(mask, a, b);
    }

    static inline uint8x16 uint8x16_min(uint8x16 a, uint8x16 b)
    {
        return _mm_min_epu8(a, b);
    }

    static inline uint8x16 uint8x16_max(uint8x16 a, uint8x16 b)
    {
        return _mm_max_epu8(a, b);
    }

    // -----------------------------------------------------------------
    // uint16x8
    // -----------------------------------------------------------------

    static inline uint16x8 uint16x8_zero()
    {
        return _mm_setzero_si128();
    }

    static inline uint16x8 uint16x8_set1(uint16 s)
    {
        return _mm_set1_epi16(s);
    }

    static inline uint16x8 uint16x8_add(uint16x8 a, uint16x8 b)
    {
        return _mm_add_epi16(a, b);
    }

    static inline uint16x8 uint16x8_sub(uint16x8 a, uint16x8 b)
    {
        return _mm_sub_epi16(a, b);
    }

    static inline uint16x8 uint16x8_mullo(uint16x8 a, uint16x8 b)
    {
        return _mm_mullo_epi16(a, b);
    }

    // saturated

    static inline uint16x8 uint16x8_adds(uint16x8 a, uint16x8 b)
    {
        return _mm_adds_epu16(a, b);
    }

    static inline uint16x8 uint16x8_subs(uint16x8 a, uint16x8 b)
    {
        return _mm_subs_epu16(a, b);
    }

    // logical

    static inline uint16x8 uint16x8_and(uint16x8 a, uint16x8 b)
    {
        return _mm_and_si128(a, b);
    }

    static inline uint16x8 uint16x8_nand(uint16x8 a, uint16x8 b)
    {
        return _mm_andnot_si128(a, b);
    }

    static inline uint16x8 uint16x8_or(uint16x8 a, uint16x8 b)
    {
        return _mm_or_si128(a, b);
    }

    static inline uint16x8 uint16x8_xor(uint16x8 a, uint16x8 b)
    {
        return _mm_xor_si128(a, b);
    }

    // compare

#if defined(MANGO_ENABLE_XOP)

    static inline uint16x8 uint16x8_not(uint16x8 a)
    {
        return _mm_xor_si128(a, _mm_comeq_epu16(a, a));
    }

    static inline uint16x8 uint16x8_compare_neq(uint16x8 a, uint16x8 b)
    {
        return _mm_comneq_epu16(a, b);
    }

    static inline uint16x8 uint16x8_compare_lt(uint16x8 a, uint16x8 b)
    {
        return _mm_comlt_epu16(a, b);
    }

    static inline uint16x8 uint16x8_compare_le(uint16x8 a, uint16x8 b)
    {
        return _mm_comle_epu16(a, b);
    }

    static inline uint16x8 uint16x8_compare_ge(uint16x8 a, uint16x8 b)
    {
        return _mm_comge_epu16(a, b);
    }

    static inline uint16x8 uint16x8_compare_eq(uint16x8 a, uint16x8 b)
    {
        return _mm_comeq_epu16(a, b);
    }

    static inline uint16x8 uint16x8_compare_gt(uint16x8 a, uint16x8 b)
    {
        return _mm_comgt_epu16(a, b);
    }

#else

    static inline uint16x8 uint16x8_compare_eq(uint16x8 a, uint16x8 b)
    {
        return _mm_cmpeq_epi16(a, b);
    }

    static inline uint16x8 uint16x8_compare_gt(uint16x8 a, uint16x8 b)
    {
        const __m128i sign = _mm_set1_epi32(0x80008000);
        return _mm_cmpgt_epi16(_mm_xor_si128(a, sign), _mm_xor_si128(b, sign));
    }

#endif

    static inline uint16x8 uint16x8_select(uint16x8 mask, uint16x8 a, uint16x8 b)
    {
        return _mm_select_si128(mask, a, b);
    }

#if defined(MANGO_ENABLE_SSE4_1)

    static inline uint16x8 uint16x8_min(uint16x8 a, uint16x8 b)
    {
        return _mm_min_epu16(a, b);
    }

    static inline uint16x8 uint16x8_max(uint16x8 a, uint16x8 b)
    {
        return _mm_max_epu16(a, b);
    }

#else

    static inline uint16x8 uint16x8_min(uint16x8 a, uint16x8 b)
    {
        const __m128i mask = uint16x8_compare_gt(a, b);
        return _mm_select_si128(mask, b, a);
    }

    static inline uint16x8 uint16x8_max(uint16x8 a, uint16x8 b)
    {
        const __m128i mask = uint16x8_compare_gt(a, b);
        return _mm_select_si128(mask, a, b);
    }

#endif
    
    // -----------------------------------------------------------------
    // uint32x4
    // -----------------------------------------------------------------

    // shuffle

    template <int x, int y, int z, int w>
    static inline uint32x4 uint32x4_shuffle(uint32x4 v)
    {
        // .generic
        return _mm_shuffle_epi32(v, _MM_SHUFFLE(w, z, y, x));
    }

    template <>
    inline uint32x4 uint32x4_shuffle<0, 1, 2, 3>(uint32x4 v)
    {
        // .xyzw
        return v;
    }

    // indexed access

#if defined(MANGO_ENABLE_SSE4_1)

    template <int Index>
    static inline uint32x4 uint32x4_set_component(uint32x4 a, uint32 s)
    {
        static_assert(Index >= 0 && Index < 4, "Index out of range.");
        return _mm_insert_epi32(a, s, Index);
    }

    template <int Index>
    static inline uint32 uint32x4_get_component(uint32x4 a)
    {
        static_assert(Index >= 0 && Index < 4, "Index out of range.");
        return _mm_extract_epi32(a, Index);
    }

#else

    template <int Index>
    static inline uint32x4 uint32x4_set_component(uint32x4 a, uint32 s);

    template <>
    inline uint32x4 uint32x4_set_component<0>(uint32x4 a, uint32 x)
    {
        const __m128i b = _mm_unpacklo_epi32(_mm_set1_epi32(x), a);
        return simd_shuffle_epi(b, a, _MM_SHUFFLE(3, 2, 3, 0));
    }

    template <>
    inline uint32x4 uint32x4_set_component<1>(uint32x4 a, uint32 y)
    {
        const __m128i b = _mm_unpacklo_epi32(_mm_set1_epi32(y), a);
        return simd_shuffle_epi(b, a, _MM_SHUFFLE(3, 2, 0, 1));
    }

    template <>
    inline uint32x4 uint32x4_set_component<2>(uint32x4 a, uint32 z)
    {
        const __m128i b = _mm_unpackhi_epi32(_mm_set1_epi32(z), a);
        return simd_shuffle_epi(a, b, _MM_SHUFFLE(3, 0, 1, 0));
    }

    template <>
    inline uint32x4 uint32x4_set_component<3>(uint32x4 a, uint32 w)
    {
        const __m128i b = _mm_unpackhi_epi32(_mm_set1_epi32(w), a);
        return simd_shuffle_epi(a, b, _MM_SHUFFLE(0, 1, 1, 0));
    }

    template <int Index>
    static inline uint32 uint32x4_get_component(uint32x4 a);

    template <>
    inline uint32 uint32x4_get_component<0>(uint32x4 a)
    {
        return _mm_cvtsi128_si32(a);
    }

    template <>
    inline uint32 uint32x4_get_component<1>(uint32x4 a)
    {
        return _mm_cvtsi128_si32(_mm_shuffle_epi32(a, 0x55));
    }

    template <>
    inline uint32 uint32x4_get_component<2>(uint32x4 a)
    {
        return _mm_cvtsi128_si32(_mm_shuffle_epi32(a, 0xaa));
    }

    template <>
    inline uint32 uint32x4_get_component<3>(uint32x4 a)
    {
        return _mm_cvtsi128_si32(_mm_shuffle_epi32(a, 0xff));
    }

#endif // defined(MANGO_ENABLE_SSE4_1)

    static inline uint32x4 uint32x4_zero()
    {
        return _mm_setzero_si128();
    }

    static inline uint32x4 uint32x4_set1(uint32 s)
    {
        return _mm_set1_epi32(s);
    }

    static inline uint32x4 uint32x4_set4(uint32 x, uint32 y, uint32 z, uint32 w)
    {
        return _mm_setr_epi32(x, y, z, w);
    }

    static inline uint32x4 uint32x4_uload(const uint32* source)
    {
        return _mm_loadu_si128(reinterpret_cast<const __m128i*>(source));
    }

    static inline void uint32x4_ustore(uint32* dest, uint32x4 a)
    {
        _mm_storeu_si128(reinterpret_cast<__m128i*>(dest), a);
    }

    static inline uint32x4 uint32x4_add(uint32x4 a, uint32x4 b)
    {
        return _mm_add_epi32(a, b);
    }

    static inline uint32x4 uint32x4_sub(uint32x4 a, uint32x4 b)
    {
        return _mm_sub_epi32(a, b);
    }

#if defined(MANGO_ENABLE_SSE4_1)

    static inline uint32x4 uint32x4_mullo(uint32x4 a, uint32x4 b)
    {
        return _mm_mullo_epi32(a, b);
    }

#else

    static inline uint32x4 uint32x4_mullo(uint32x4 a, uint32x4 b)
    {
        __m128i temp1 = _mm_mul_epu32(a, b);
        __m128i temp2 = _mm_mul_epu32(_mm_srli_si128(a, 4), _mm_srli_si128(b, 4));
        temp1 = _mm_shuffle_epi32(temp1, _MM_SHUFFLE(0, 0, 2, 0));
        temp2 = _mm_shuffle_epi32(temp2, _MM_SHUFFLE(0, 0, 2, 0));
        return _mm_unpacklo_epi32(temp1, temp2);
    }

#endif

    // saturated

    static inline uint32x4 uint32x4_adds(uint32x4 a, uint32x4 b)
    {
  	    const __m128i temp = _mm_add_epi32(a, b);
  	    return _mm_or_si128(temp, _mm_cmplt_epi32(temp, a));
    }

    static inline uint32x4 uint32x4_subs(uint32x4 a, uint32x4 b)
    {
  	    const __m128i temp = _mm_sub_epi32(a, b);
  	    return _mm_and_si128(temp, _mm_cmpgt_epi32(a, temp));
    }

    // logical

    static inline uint32x4 uint32x4_and(uint32x4 a, uint32x4 b)
    {
        return _mm_and_si128(a, b);
    }

    static inline uint32x4 uint32x4_nand(uint32x4 a, uint32x4 b)
    {
        return _mm_andnot_si128(a, b);
    }

    static inline uint32x4 uint32x4_or(uint32x4 a, uint32x4 b)
    {
        return _mm_or_si128(a, b);
    }

    static inline uint32x4 uint32x4_xor(uint32x4 a, uint32x4 b)
    {
        return _mm_xor_si128(a, b);
    }

    // shift

    template <int Count> 
    static inline uint32x4 uint32x4_sll(uint32x4 a)
    {
        return _mm_slli_epi32(a, Count);
    }

    template <int Count> 
    static inline uint32x4 uint32x4_srl(uint32x4 a)
    {
        return _mm_srli_epi32(a, Count);
    }

    template <int Count> 
    static inline uint32x4 uint32x4_sra(uint32x4 a)
    {
        return _mm_srai_epi32(a, Count);
    }

    // compare

#if defined(MANGO_ENABLE_XOP)

    static inline uint32x4 uint32x4_not(uint32x4 a)
    {
        return _mm_xor_si128(a, _mm_comeq_epu32(a, a));
    }

    static inline uint32x4 uint32x4_compare_neq(uint32x4 a, uint32x4 b)
    {
        return _mm_comneq_epu32(a, b);
    }

    static inline uint32x4 uint32x4_compare_lt(uint32x4 a, uint32x4 b)
    {
        return _mm_comlt_epu32(a, b);
    }

    static inline uint32x4 uint32x4_compare_le(uint32x4 a, uint32x4 b)
    {
        return _mm_comle_epu32(a, b);
    }

    static inline uint32x4 uint32x4_compare_ge(uint32x4 a, uint32x4 b)
    {
        return _mm_comge_epu32(a, b);
    }

    static inline uint32x4 uint32x4_compare_eq(uint32x4 a, uint32x4 b)
    {
        return _mm_comeq_epu32(a, b);
    }

    static inline uint32x4 uint32x4_compare_gt(uint32x4 a, uint32x4 b)
    {
        return _mm_comgt_epu32(a, b);
    }

#else

    static inline uint32x4 uint32x4_compare_eq(uint32x4 a, uint32x4 b)
    {
        return _mm_cmpeq_epi32(a, b);
    }

    static inline uint32x4 uint32x4_compare_gt(uint32x4 a, uint32x4 b)
    {
        const __m128i sign = _mm_set1_epi32(0x80000000);
        return _mm_cmpgt_epi32(_mm_xor_si128(a, sign), _mm_xor_si128(b, sign));
    }

#endif

    static inline uint32x4 uint32x4_select(uint32x4 mask, uint32x4 a, uint32x4 b)
    {
        return _mm_select_si128(mask, a, b);
    }

#if defined(MANGO_ENABLE_SSE4_1)

    static inline uint32x4 uint32x4_min(uint32x4 a, uint32x4 b)
    {
        return _mm_min_epu32(a, b);
    }

    static inline uint32x4 uint32x4_max(uint32x4 a, uint32x4 b)
    {
        return _mm_max_epu32(a, b);
    }

#else

    static inline uint32x4 uint32x4_min(uint32x4 a, uint32x4 b)
    {
        const uint32x4 mask = uint32x4_compare_gt(a, b);
        return _mm_select_si128(mask, b, a);
    }

    static inline uint32x4 uint32x4_max(uint32x4 a, uint32x4 b)
    {
        const uint32x4 mask = uint32x4_compare_gt(a, b);
        return _mm_select_si128(mask, a, b);
    }

#endif // defined(MANGO_ENABLE_SSE4_1)

    // -----------------------------------------------------------------
    // int8x16
    // -----------------------------------------------------------------

    static inline int8x16 int8x16_zero()
    {
        return _mm_setzero_si128();
    }

    static inline int8x16 int8x16_set1(int8 s)
    {
        return _mm_set1_epi8(s);
    }

    static inline int8x16 int8x16_add(int8x16 a, int8x16 b)
    {
        return _mm_add_epi8(a, b);
    }

    static inline int8x16 int8x16_sub(int8x16 a, int8x16 b)
    {
        return _mm_sub_epi8(a, b);
    }

    // saturated

    static inline int8x16 int8x16_adds(int8x16 a, int8x16 b)
    {
        return _mm_adds_epi8(a, b);
    }

    static inline int8x16 int8x16_subs(int8x16 a, int8x16 b)
    {
        return _mm_subs_epi8(a, b);
    }

    static inline int8x16 int8x16_abs(int8x16 a)
    {
#if defined(MANGO_ENABLE_SSSE3)
        return _mm_abs_epi8(a);
#else
        const __m128i zero = _mm_setzero_si128();
        const __m128i mask = _mm_cmpgt_epi8(zero, a);
        return _mm_select_si128(mask, _mm_sub_epi8(zero, a), a);
#endif
    }

    static inline int8x16 int8x16_neg(int8x16 a)
    {
        return _mm_sub_epi8(_mm_setzero_si128(), a);
    }

    // logical

    static inline int8x16 int8x16_and(int8x16 a, int8x16 b)
    {
        return _mm_and_si128(a, b);
    }

    static inline int8x16 int8x16_nand(int8x16 a, int8x16 b)
    {
        return _mm_andnot_si128(a, b);
    }

    static inline int8x16 int8x16_or(int8x16 a, int8x16 b)
    {
        return _mm_or_si128(a, b);
    }

    static inline int8x16 int8x16_xor(int8x16 a, int8x16 b)
    {
        return _mm_xor_si128(a, b);
    }

    // compare

#if defined(MANGO_ENABLE_XOP)

    static inline int8x16 int8x16_not(int8x16 a)
    {
        return _mm_xor_si128(a, _mm_comeq_epi8(a, a));
    }

    static inline int8x16 int8x16_compare_neq(int8x16 a, int8x16 b)
    {
        return _mm_comneq_epi8(a, b);
    }

    static inline int8x16 int8x16_compare_lt(int8x16 a, int8x16 b)
    {
        return _mm_comlt_epi8(a, b);
    }

    static inline int8x16 int8x16_compare_le(int8x16 a, int8x16 b)
    {
        return _mm_comle_epi8(a, b);
    }

    static inline int8x16 int8x16_compare_ge(int8x16 a, int8x16 b)
    {
        return _mm_comge_epi8(a, b);
    }

    static inline int8x16 int8x16_compare_eq(int8x16 a, int8x16 b)
    {
        return _mm_comeq_epi8(a, b);
    }

    static inline int8x16 int8x16_compare_gt(int8x16 a, int8x16 b)
    {
        return _mm_comgt_epi8(a, b);
    }

#else

    static inline int8x16 int8x16_compare_eq(int8x16 a, int8x16 b)
    {
        return _mm_cmpeq_epi8(a, b);
    }

    static inline int8x16 int8x16_compare_gt(int8x16 a, int8x16 b)
    {
        return _mm_cmpgt_epi8(a, b);
    }

#endif

    static inline int8x16 int8x16_select(int8x16 mask, int8x16 a, int8x16 b)
    {
        return _mm_select_si128(mask, a, b);
    }

#if defined(MANGO_ENABLE_SSE4_1)

    static inline int8x16 int8x16_min(int8x16 a, int8x16 b)
    {
        return _mm_min_epi8(a, b);
    }

    static inline int8x16 int8x16_max(int8x16 a, int8x16 b)
    {
        return _mm_max_epi8(a, b);
    }

#else

    static inline int8x16 int8x16_min(int8x16 a, int8x16 b)
    {
        const __m128i mask = _mm_cmpgt_epi8(a, b);
        return _mm_select_si128(mask, b, a);
    }

    static inline int8x16 int8x16_max(int8x16 a, int8x16 b)
    {
        const __m128i mask = _mm_cmpgt_epi8(a, b);
        return _mm_select_si128(mask, a, b);
    }

#endif

    // -----------------------------------------------------------------
    // int16x8
    // -----------------------------------------------------------------

    static inline int16x8 int16x8_zero()
    {
        return _mm_setzero_si128();
    }

    static inline int16x8 int16x8_set1(int16 s)
    {
        return _mm_set1_epi16(s);
    }

    static inline int16x8 int16x8_add(int16x8 a, int16x8 b)
    {
        return _mm_add_epi16(a, b);
    }

    static inline int16x8 int16x8_sub(int16x8 a, int16x8 b)
    {
        return _mm_sub_epi16(a, b);
    }

    static inline int16x8 int16x8_mullo(int16x8 a, int16x8 b)
    {
        return _mm_mullo_epi16(a, b);
    }

    // saturated

    static inline int16x8 int16x8_adds(int16x8 a, int16x8 b)
    {
        return _mm_adds_epi16(a, b);
    }

    static inline int16x8 int16x8_subs(int16x8 a, int16x8 b)
    {
        return _mm_subs_epi16(a, b);
    }

    static inline int16x8 int16x8_abs(int16x8 a)
    {
#if defined(MANGO_ENABLE_SSSE3)
        return _mm_abs_epi16(a);
#else
        __m128i mask = _mm_srai_epi16(a, 15);
        return _mm_sub_epi16(_mm_xor_si128(a, mask), mask);
#endif
    }

    static inline int16x8 int16x8_neg(int16x8 a)
    {
        return _mm_sub_epi16(_mm_setzero_si128(), a);
    }

    // logical

    static inline int16x8 int16x8_and(int16x8 a, int16x8 b)
    {
        return _mm_and_si128(a, b);
    }

    static inline int16x8 int16x8_nand(int16x8 a, int16x8 b)
    {
        return _mm_andnot_si128(a, b);
    }

    static inline int16x8 int16x8_or(int16x8 a, int16x8 b)
    {
        return _mm_or_si128(a, b);
    }

    static inline int16x8 int16x8_xor(int16x8 a, int16x8 b)
    {
        return _mm_xor_si128(a, b);
    }

    // compare

#if defined(MANGO_ENABLE_XOP)

    static inline int16x8 int16x8_not(int16x8 a)
    {
        return _mm_xor_si128(a, _mm_comeq_epi16(a, a));
    }

    static inline int16x8 int16x8_compare_neq(int16x8 a, int16x8 b)
    {
        return _mm_comneq_epi16(a, b);
    }

    static inline int16x8 int16x8_compare_lt(int16x8 a, int16x8 b)
    {
        return _mm_comlt_epi16(a, b);
    }

    static inline int16x8 int16x8_compare_le(int16x8 a, int16x8 b)
    {
        return _mm_comle_epi16(a, b);
    }

    static inline int16x8 int16x8_compare_ge(int16x8 a, int16x8 b)
    {
        return _mm_comge_epi16(a, b);
    }

    static inline int16x8 int16x8_compare_eq(int16x8 a, int16x8 b)
    {
        return _mm_comeq_epi16(a, b);
    }

    static inline int16x8 int16x8_compare_gt(int16x8 a, int16x8 b)
    {
        return _mm_comgt_epi16(a, b);
    }

#else

    static inline int16x8 int16x8_compare_eq(int16x8 a, int16x8 b)
    {
        return _mm_cmpeq_epi16(a, b);
    }

    static inline int16x8 int16x8_compare_gt(int16x8 a, int16x8 b)
    {
        return _mm_cmpgt_epi16(a, b);
    }

#endif

    static inline int16x8 int16x8_select(int16x8 mask, int16x8 a, int16x8 b)
    {
        return _mm_select_si128(mask, a, b);
    }

    static inline int16x8 int16x8_min(int16x8 a, int16x8 b)
    {
        return _mm_min_epi16(a, b);
    }

    static inline int16x8 int16x8_max(int16x8 a, int16x8 b)
    {
        return _mm_max_epi16(a, b);
    }

    // -----------------------------------------------------------------
    // int32x4
    // -----------------------------------------------------------------

    // shuffle

    template <int x, int y, int z, int w>
    static inline int32x4 int32x4_shuffle(int32x4 v)
    {
        // .generic
        return _mm_shuffle_epi32(v, _MM_SHUFFLE(w, z, y, x));
    }

    template <>
    inline int32x4 int32x4_shuffle<0, 1, 2, 3>(int32x4 v)
    {
        // .xyzw
        return v;
    }

    // indexed access

#if defined(MANGO_ENABLE_SSE4_1)

    template <int Index>
    static inline int32x4 int32x4_set_component(int32x4 a, int32 s)
    {
        static_assert(Index >= 0 && Index < 4, "Index out of range.");
        return _mm_insert_epi32(a, s, Index);
    }

    template <int Index>
    static inline int32 int32x4_get_component(int32x4 a)
    {
        static_assert(Index >= 0 && Index < 4, "Index out of range.");
        return _mm_extract_epi32(a, Index);
    }

#else

    template <int Index>
    static inline int32x4 int32x4_set_component(int32x4 a, int32 s);

    template <>
    inline int32x4 int32x4_set_component<0>(int32x4 a, int32 x)
    {
        const __m128i b = _mm_unpacklo_epi32(_mm_set1_epi32(x), a);
        return simd_shuffle_epi(b, a, _MM_SHUFFLE(3, 2, 3, 0));
    }

    template <>
    inline int32x4 int32x4_set_component<1>(int32x4 a, int32 y)
    {
        const __m128i b = _mm_unpacklo_epi32(_mm_set1_epi32(y), a);
        return simd_shuffle_epi(b, a, _MM_SHUFFLE(3, 2, 0, 1));
    }

    template <>
    inline int32x4 int32x4_set_component<2>(int32x4 a, int32 z)
    {
        const __m128i b = _mm_unpackhi_epi32(_mm_set1_epi32(z), a);
        return simd_shuffle_epi(a, b, _MM_SHUFFLE(3, 0, 1, 0));
    }

    template <>
    inline int32x4 int32x4_set_component<3>(int32x4 a, int32 w)
    {
        const __m128i b = _mm_unpackhi_epi32(_mm_set1_epi32(w), a);
        return simd_shuffle_epi(a, b, _MM_SHUFFLE(0, 1, 1, 0));
    }

    template <int Index>
    static inline int32 int32x4_get_component(int32x4 a);

    template <>
    inline int32 int32x4_get_component<0>(int32x4 a)
    {
        return _mm_cvtsi128_si32(a);
    }

    template <>
    inline int32 int32x4_get_component<1>(int32x4 a)
    {
        return _mm_cvtsi128_si32(_mm_shuffle_epi32(a, 0x55));
    }

    template <>
    inline int32 int32x4_get_component<2>(int32x4 a)
    {
        return _mm_cvtsi128_si32(_mm_shuffle_epi32(a, 0xaa));
    }

    template <>
    inline int32 int32x4_get_component<3>(int32x4 a)
    {
        return _mm_cvtsi128_si32(_mm_shuffle_epi32(a, 0xff));
    }

#endif // defined(MANGO_ENABLE_SSE4_1)

    static inline int32x4 int32x4_zero()
    {
        return _mm_setzero_si128();
    }

    static inline int32x4 int32x4_set1(int s)
    {
        return _mm_set1_epi32(s);
    }

    static inline int32x4 int32x4_set4(int x, int y, int z, int w)
    {
        return _mm_setr_epi32(x, y, z, w);
    }

    static inline int32x4 int32x4_uload(const int* source)
    {
        return _mm_loadu_si128(reinterpret_cast<const __m128i*>(source));
    }

    static inline void int32x4_ustore(int* dest, int32x4 a)
    {
        _mm_storeu_si128(reinterpret_cast<__m128i*>(dest), a);
    }

    static inline int32x4 int32x4_abs(int32x4 a)
    {
#if defined(MANGO_ENABLE_SSSE3)
        return _mm_abs_epi32(a);
#else
        __m128i mask = _mm_srai_epi32(a, 31);
        return _mm_sub_epi32(_mm_xor_si128(a, mask), mask);
#endif
    }

    static inline int32x4 int32x4_neg(int32x4 a)
    {
        return _mm_sub_epi32(_mm_setzero_si128(), a);
    }

    static inline int32x4 int32x4_add(int32x4 a, int32x4 b)
    {
        return _mm_add_epi32(a, b);
    }

    static inline int32x4 int32x4_sub(int32x4 a, int32x4 b)
    {
        return _mm_sub_epi32(a, b);
    }

#if defined(MANGO_ENABLE_SSE4_1)

    static inline int32x4 int32x4_mullo(int32x4 a, int32x4 b)
    {
        return _mm_mullo_epi32(a, b);
    }

#else

    static inline int32x4 int32x4_mullo(int32x4 a, int32x4 b)
    {
        __m128i temp1 = _mm_mul_epu32(a, b);
        __m128i temp2 = _mm_mul_epu32(_mm_srli_si128(a, 4), _mm_srli_si128(b, 4));
        temp1 = _mm_shuffle_epi32(temp1, _MM_SHUFFLE(0, 0, 2, 0));
        temp2 = _mm_shuffle_epi32(temp2, _MM_SHUFFLE(0, 0, 2, 0));
        return _mm_unpacklo_epi32(temp1, temp2);
    }

#endif

    // saturated

    static inline int32x4 int32x4_adds(int32x4 a, int32x4 b)
    {
        const __m128i v = _mm_add_epi32(a, b);
        a = _mm_srai_epi32(a, 31);
        __m128i temp = _mm_xor_si128(b, v);
        temp = _mm_xor_si128(temp, _mm_cmpeq_epi32(temp, temp));
        temp = _mm_or_si128(temp, _mm_xor_si128(a, b));
        return _mm_select_si128(_mm_cmpgt_epi32(_mm_setzero_si128(), temp), v, a);
    }

    static inline int32x4 int32x4_subs(int32x4 a, int32x4 b)
    {
        const __m128i v = _mm_sub_epi32(a, b);
        a = _mm_srai_epi32(a, 31);
        __m128i temp = _mm_and_si128(_mm_xor_si128(a, b), _mm_xor_si128(a, v));
        return _mm_select_si128(_mm_cmpgt_epi32(_mm_setzero_si128(), temp), a, v);
    }

    // logical

    static inline int32x4 int32x4_and(int32x4 a, int32x4 b)
    {
        return _mm_and_si128(a, b);
    }

    static inline int32x4 int32x4_nand(int32x4 a, int32x4 b)
    {
        return _mm_andnot_si128(a, b);
    }

    static inline int32x4 int32x4_or(int32x4 a, int32x4 b)
    {
        return _mm_or_si128(a, b);
    }

    static inline int32x4 int32x4_xor(int32x4 a, int32x4 b)
    {
        return _mm_xor_si128(a, b);
    }

    // shift

    template <int Count> 
    static inline int32x4 int32x4_sll(int32x4 a)
    {
        return _mm_slli_epi32(a, Count);
    }

    template <int Count> 
    static inline int32x4 int32x4_srl(int32x4 a)
    {
        return _mm_srli_epi32(a, Count);
    }

    template <int Count> 
    static inline int32x4 int32x4_sra(int32x4 a)
    {
        return _mm_srai_epi32(a, Count);
    }

    // compare

#if defined(MANGO_ENABLE_XOP)

    static inline int32x4 int32x4_not(int32x4 a)
    {
        return _mm_xor_si128(a, _mm_comeq_epi32(a, a));
    }

    static inline int32x4 int32x4_compare_neq(int32x4 a, int32x4 b)
    {
        return _mm_comneq_epi32(a, b);
    }

    static inline int32x4 int32x4_compare_lt(int32x4 a, int32x4 b)
    {
        return _mm_comlt_epi32(a, b);
    }

    static inline int32x4 int32x4_compare_le(int32x4 a, int32x4 b)
    {
        return _mm_comle_epi32(a, b);
    }

    static inline int32x4 int32x4_compare_ge(int32x4 a, int32x4 b)
    {
        return _mm_comge_epi32(a, b);
    }

    static inline int32x4 int32x4_compare_eq(int32x4 a, int32x4 b)
    {
        return _mm_comeq_epi32(a, b);
    }

    static inline int32x4 int32x4_compare_gt(int32x4 a, int32x4 b)
    {
        return _mm_comgt_epi32(a, b);
    }

#else

    static inline int32x4 int32x4_compare_eq(int32x4 a, int32x4 b)
    {
        return _mm_cmpeq_epi32(a, b);
    }

    static inline int32x4 int32x4_compare_gt(int32x4 a, int32x4 b)
    {
        return _mm_cmpgt_epi32(a, b);
    }

#endif

    static inline int32x4 int32x4_select(int32x4 mask, int32x4 a, int32x4 b)
    {
        return _mm_select_si128(mask, a, b);
    }

    static inline uint32 int32x4_get_mask(int32x4 a)
    {
        return _mm_movemask_ps(_mm_castsi128_ps(a));
    }

    static inline uint32 int32x4_pack(int32x4 s)
    {
        __m128i s16 = _mm_packs_epi32(s, s);
        __m128i s8 = _mm_packus_epi16(s16, s16);
        return _mm_cvtsi128_si32(s8);
    }

#if defined(MANGO_ENABLE_SSE4_1)

    static inline int32x4 int32x4_min(int32x4 a, int32x4 b)
    {
        return _mm_min_epi32(a, b);
    }

    static inline int32x4 int32x4_max(int32x4 a, int32x4 b)
    {
        return _mm_max_epi32(a, b);
    }

    static inline int32x4 int32x4_unpack(uint32 s)
    {
        const __m128i i = _mm_cvtsi32_si128(s);
        return _mm_cvtepu8_epi32(i);
    }

#else

    static inline int32x4 int32x4_min(int32x4 a, int32x4 b)
    {
        const __m128i mask = _mm_cmpgt_epi32(a, b);
        return _mm_select_si128(mask, b, a);
    }

    static inline int32x4 int32x4_max(int32x4 a, int32x4 b)
    {
        const __m128i mask = _mm_cmpgt_epi32(a, b);
        return _mm_select_si128(mask, a, b);
    }

    static inline int32x4 int32x4_unpack(uint32 s)
    {
        const __m128i zero = _mm_setzero_si128();
        const __m128i i = _mm_cvtsi32_si128(s);
        return _mm_unpacklo_epi16(_mm_unpacklo_epi8(i, zero), zero);
    }

#endif // defined(MANGO_ENABLE_SSE4_1)

#undef simd_shuffle_epi

} // namespace simd
} // namespace mango

#endif // MANGO_SIMD_INT_SSE
