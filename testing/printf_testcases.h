    {

/* Be afraid. Be very afraid.
   Virtually everything in the printf() / scanf() test drivers is heavily
   depending on the platform, i.e. the width of the integer values. Since
   we need widths, string representations in hex, octal and decimal and
   whatnot, there is some heavy macro abuse coming up...
*/

#define sym2v( x ) #x
#define sym2s( x ) sym2v( x )

#if INT_MAX >> 15 == 1

#define UINT_DIG 5
#define INT_DIG  5
#define INT_DIG_LESS1 "4"
#define INT_DIG_PLUS1 "6"
#define INT_DIG_PLUS2 "7"
#define INT_HEXDIG "FFF"
#define INT_hexdig "fff"
#define INT_OCTDIG "177777"
#define INT_MAX_DEZ_STR  "32767"
#define INT_MIN_DEZ_STR  "32768"
#define UINT_MAX_DEZ_STR "65535"
#define INT_MAX_OCT_STR
#define INT_MIN_OCT_STR
#define UINT_MAX_OCT_STR
#define INT_MAX_HEX_STR
#define INT_MIN_HEX_STR
#define UINT_MAX_HEX_STR

#elif UINT_MAX >> 31 == 1

#define UINT_DIG 10
#define INT_DIG  10
#define INT_DIG_LESS1 "9"
#define INT_DIG_PLUS1 "11"
#define INT_DIG_PLUS2 "12"
#define INT_HEXDIG "FFFFFFF"
#define INT_hexdig "fffffff"
#define INT_OCTDIG "37777777777"
#define INT_MAX_DEZ_STR  "2147483647"
#define INT_MIN_DEZ_STR  "2147483648"
#define UINT_MAX_DEZ_STR "4294967295"
#define INT_MAX_OCT_STR
#define INT_MIN_OCT_STR
#define UINT_MAX_OCT_STR
#define INT_MAX_HEX_STR
#define INT_MIN_HEX_STR
#define UINT_MAX_HEX_STR

#elif UINT_MAX >> 63 == 1

#define UINT_DIG 20
#define INT_DIG  19
#define INT_DIG_LESS1 "18"
#define INT_DIG_PLUS1 "20"
#define INT_DIG_PLUS2 "21"
#define INT_HEXDIG "FFFFFFFFFFFFFFF"
#define INT_hexdig "fffffffffffffff"
#define INT_OCTDIG "1777777777777777777777"
#define INT_MAX_DEZ_STR   "9223372036854775807"
#define INT_MIN_DEZ_STR   "9223372036854775808"
#define UINT_MAX_DEZ_STR "18446744073709551615"
#define INT_MAX_OCT_STR
#define INT_MIN_OCT_STR
#define UINT_MAX_OCT_STR
#define INT_MAX_HEX_STR
#define INT_MIN_HEX_STR
#define UINT_MAX_HEX_STR

#else

#error Unsupported width of 'int' (neither 16, 32, nor 64 bit).

#endif


#if ULONG_MAX >> 31 == 1

#define ULONG_DIG 10
#define LONG_DIG  10
#define LONG_MAX_DEZ_STR  "2147483647"
#define LONG_MIN_DEZ_STR  "2147483648"
#define ULONG_MAX_DEZ_STR "4294967295"
#define LONG_MAX_OCT_STR
#define LONG_MIN_OCT_STR
#define ULONG_MAX_OCT_STR
#define LONG_MAX_HEX_STR
#define LONG_MIN_HEX_STR
#define ULONG_MAX_HEX_STR

#elif ULONG_MAX >> 63 == 1

#define ULONG_DIG 20
#define LONG_DIG  19
#define LONG_MAX_DEZ_STR   "9223372036854775807"
#define LONG_MIN_DEZ_STR   "9223372036854775808"
#define ULONG_MAX_DEZ_STR "18446744073709551615"
#define LONG_MAX_OCT_STR
#define LONG_MIN_OCT_STR
#define ULONG_MAX_OCT_STR
#define LONG_MAX_HEX_STR
#define LONG_MIN_HEX_STR
#define ULONG_MAX_HEX_STR

#else

#error Unsupported width of 'long' (neither 32 nor 64 bit).

#endif


#if ULLONG_MAX >> 63 == 1

#define ULLONG_DIG 20
#define LLONG_DIG  19
#define LLONG_MAX_DEZ_STR   "9223372036854775807"
#define LLONG_MIN_DEZ_STR   "9223372036854775808"
#define ULLONG_MAX_DEZ_STR "18446744073709551615"
#define LLONG_MAX_OCT_STR
#define LLONG_MIN_OCT_STR
#define ULLONG_MAX_OCT_STR
#define LLONG_MAX_HEX_STR
#define LLONG_MIN_HEX_STR
#define ULLONG_MAX_HEX_STR

#elif ULLONG_MAX >> 127 == 1

#define ULLONG_DIG 38
#define LLONG_DIG  38
#define LLONG_MAX_DEZ_STR  "170141183460469231731687303715884105727"
#define LLONG_MIN_DEZ_STR  "170141183460469231731687303715884105728"
#define ULLONG_MAX_DEZ_STR "340282366920938463463374607431768211455"
#define LLONG_MAX_OCT_STR
#define LLONG_MIN_OCT_STR
#define ULLONG_MAX_OCT_STR
#define LLONG_MAX_HEX_STR
#define LLONG_MIN_HEX_STR
#define ULLONG_MAX_HEX_STR

#else

#error Unsupported width of 'long long' (neither 64 nor 128 bit).

#endif


    PRINTF_TEST( 4,   "-128", "%hhd", CHAR_MIN );
    PRINTF_TEST( 3,    "127", "%hhd", CHAR_MAX );
    PRINTF_TEST( 1,      "0", "%hhd", 0 );
    PRINTF_TEST( 6, "-32768",  "%hd", SHRT_MIN );
    PRINTF_TEST( 5,  "32767",  "%hd", SHRT_MAX );
    PRINTF_TEST( 1,      "0",  "%hd", 0 );
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "%d", INT_MIN );
    PRINTF_TEST( INT_DIG, INT_MAX_DEZ_STR, "%d", INT_MAX );
    PRINTF_TEST( 1, "0", "%d", 0 );
    PRINTF_TEST( LONG_DIG + 1, "-" LONG_MIN_DEZ_STR, "%ld", LONG_MIN );
    PRINTF_TEST( LONG_DIG, LONG_MAX_DEZ_STR, "%ld", LONG_MAX );
    PRINTF_TEST( 1, "0", "%ld", 0l );
    PRINTF_TEST( LLONG_DIG + 1, "-" LLONG_MIN_DEZ_STR, "%lld", LLONG_MIN );
    PRINTF_TEST( LLONG_DIG, LLONG_MAX_DEZ_STR, "%lld", LLONG_MAX );
    PRINTF_TEST( 1, "0", "%lld", 0ll );
    PRINTF_TEST( 3, "255", "%hhu", UCHAR_MAX );
    PRINTF_TEST( 3, "255", "%hhu", (unsigned char)-1 );
    PRINTF_TEST( 5, "65535", "%hu", USHRT_MAX );
    PRINTF_TEST( 5, "65535", "%hu", (unsigned short)-1 );
    PRINTF_TEST( UINT_DIG, UINT_MAX_DEZ_STR, "%u", UINT_MAX );
    PRINTF_TEST( UINT_DIG, UINT_MAX_DEZ_STR, "%u", -1u );
    PRINTF_TEST( ULONG_DIG, ULONG_MAX_DEZ_STR, "%lu", ULONG_MAX );
    PRINTF_TEST( ULONG_DIG, ULONG_MAX_DEZ_STR, "%lu", -1ul );
    PRINTF_TEST( ULLONG_DIG, ULLONG_MAX_DEZ_STR, "%llu", ULLONG_MAX );
    PRINTF_TEST( ULLONG_DIG, ULLONG_MAX_DEZ_STR, "%llu", -1ull );
    PRINTF_TEST( (int)strlen( INT_HEXDIG ) + 1, "F" INT_HEXDIG, "%X", UINT_MAX );
    PRINTF_TEST( (int)strlen( INT_HEXDIG ) + 3, "0XF" INT_HEXDIG, "%#X", -1u );
    PRINTF_TEST( (int)strlen( INT_HEXDIG ) + 1, "f" INT_hexdig, "%x", UINT_MAX );
    PRINTF_TEST( (int)strlen( INT_HEXDIG ) + 3, "0xf" INT_hexdig, "%#x", -1u );
    PRINTF_TEST( (int)strlen( INT_OCTDIG ), INT_OCTDIG, "%o", UINT_MAX );
    PRINTF_TEST( (int)strlen( INT_OCTDIG ) + 1, "0" INT_OCTDIG, "%#o", -1u );
#if 0
    /* TODO: This test case is broken, doesn't test what it was intended to. */
    PRINTF_TEST( 5, "%.0#o", "%.0#o", 0 );
#endif
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "%+d", INT_MIN );
    PRINTF_TEST( INT_DIG + 1, "+" INT_MAX_DEZ_STR, "%+d", INT_MAX );
    PRINTF_TEST( 2, "+0", "%+d", 0 );
    PRINTF_TEST( UINT_DIG, UINT_MAX_DEZ_STR, "%+u", UINT_MAX );
    PRINTF_TEST( UINT_DIG, UINT_MAX_DEZ_STR, "%+u", -1u );
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "% d", INT_MIN );
    PRINTF_TEST( INT_DIG + 1, " " INT_MAX_DEZ_STR, "% d", INT_MAX );
    PRINTF_TEST( 2, " 0", "% d", 0 );
    PRINTF_TEST( UINT_DIG, UINT_MAX_DEZ_STR, "% u", UINT_MAX );
    PRINTF_TEST( UINT_DIG, UINT_MAX_DEZ_STR, "% u", -1u );
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "%" INT_DIG_LESS1 "d", INT_MIN );
    PRINTF_TEST( INT_DIG, INT_MAX_DEZ_STR, "%" INT_DIG_LESS1 "d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "%" sym2s(INT_DIG) "d", INT_MIN );
    PRINTF_TEST( INT_DIG, INT_MAX_DEZ_STR, "%" sym2s(INT_DIG) "d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "%" INT_DIG_PLUS1 "d", INT_MIN );
    PRINTF_TEST( INT_DIG + 1, " " INT_MAX_DEZ_STR, "%" INT_DIG_PLUS1 "d", INT_MAX );
    PRINTF_TEST( INT_DIG + 2, " -" INT_MIN_DEZ_STR, "%" INT_DIG_PLUS2 "d", INT_MIN );
    PRINTF_TEST( INT_DIG + 2, "  " INT_MAX_DEZ_STR, "%" INT_DIG_PLUS2 "d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "%-" INT_DIG_LESS1 "d", INT_MIN );
    PRINTF_TEST( INT_DIG, INT_MAX_DEZ_STR, "%-" INT_DIG_LESS1 "d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "%-" sym2s(INT_DIG) "d", INT_MIN );
    PRINTF_TEST( INT_DIG, INT_MAX_DEZ_STR, "%-" sym2s(INT_DIG) "d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "%-" INT_DIG_PLUS1 "d", INT_MIN );
    PRINTF_TEST( INT_DIG + 1, INT_MAX_DEZ_STR " ", "%-" INT_DIG_PLUS1 "d", INT_MAX );
    PRINTF_TEST( INT_DIG + 2, "-" INT_MIN_DEZ_STR " ", "%-" INT_DIG_PLUS2 "d", INT_MIN );
    PRINTF_TEST( INT_DIG + 2, INT_MAX_DEZ_STR "  ", "%-" INT_DIG_PLUS2 "d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "%0" INT_DIG_LESS1 "d", INT_MIN );
    PRINTF_TEST( INT_DIG, INT_MAX_DEZ_STR, "%0" INT_DIG_LESS1 "d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "%0" sym2s(INT_DIG) "d", INT_MIN );
    PRINTF_TEST( INT_DIG, INT_MAX_DEZ_STR, "%0" sym2s(INT_DIG) "d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "%0" INT_DIG_PLUS1 "d", INT_MIN );
    PRINTF_TEST( INT_DIG + 1, "0" INT_MAX_DEZ_STR, "%0" INT_DIG_PLUS1 "d", INT_MAX );
    PRINTF_TEST( INT_DIG + 2, "-0" INT_MIN_DEZ_STR, "%0" INT_DIG_PLUS2 "d", INT_MIN );
    PRINTF_TEST( INT_DIG + 2, "00" INT_MAX_DEZ_STR, "%0" INT_DIG_PLUS2 "d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "%-0" INT_DIG_LESS1 "d", INT_MIN );
    PRINTF_TEST( INT_DIG, INT_MAX_DEZ_STR, "%-0" INT_DIG_LESS1 "d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "%-0" sym2s(INT_DIG) "d", INT_MIN );
    PRINTF_TEST( INT_DIG, INT_MAX_DEZ_STR, "%-0" sym2s(INT_DIG) "d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "%-0" INT_DIG_PLUS1 "d", INT_MIN );
    PRINTF_TEST( INT_DIG + 1, INT_MAX_DEZ_STR " ", "%-0" INT_DIG_PLUS1 "d", INT_MAX );
    PRINTF_TEST( INT_DIG + 2, "-" INT_MIN_DEZ_STR " ", "%-0" INT_DIG_PLUS2 "d", INT_MIN );
    PRINTF_TEST( INT_DIG + 2, INT_MAX_DEZ_STR "  ", "%-0" INT_DIG_PLUS2 "d", INT_MAX );
    /* FIXME: This test not yet 32/64 bit agnostic */
    PRINTF_TEST( 30, "          00000000002147483647", "%030.20d", INT_MAX );
    PRINTF_TEST( (int)strlen( INT_HEXDIG ) + 1, "f" INT_hexdig, "%.6x", UINT_MAX );
    PRINTF_TEST( (int)strlen( INT_HEXDIG ) + 3, "0xf" INT_hexdig, "%#6.3x", UINT_MAX );
    PRINTF_TEST( (int)strlen( INT_HEXDIG ) + 3, "0xf" INT_hexdig, "%#3.6x", UINT_MAX );
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "%.6d", INT_MIN );
    PRINTF_TEST( INT_DIG + 1, "-" INT_MIN_DEZ_STR, "%6.3d", INT_MIN );
    PRINTF_TEST( INT_DIG + 1., "-" INT_MIN_DEZ_STR, "%3.6d", INT_MIN );
    PRINTF_TEST( UINT_DIG, "0xf" INT_hexdig, "%#0.6x", UINT_MAX );
    PRINTF_TEST( UINT_DIG, "0xf" INT_hexdig, "%#06.3x", UINT_MAX );
    PRINTF_TEST( UINT_DIG, "0xf" INT_hexdig, "%#03.6x", UINT_MAX );
    PRINTF_TEST( INT_DIG, INT_MAX_DEZ_STR, "%#0.6d", INT_MAX );
    PRINTF_TEST( INT_DIG, INT_MAX_DEZ_STR, "%#06.3d", INT_MAX );
    PRINTF_TEST( INT_DIG, INT_MAX_DEZ_STR, "%#03.6d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "+" INT_MAX_DEZ_STR, "%#+.6d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "+" INT_MAX_DEZ_STR, "%#+6.3d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "+" INT_MAX_DEZ_STR, "%#+3.6d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "+" INT_MAX_DEZ_STR, "%+0.6d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "+" INT_MAX_DEZ_STR, "%+06.3d", INT_MAX );
    PRINTF_TEST( INT_DIG + 1, "+" INT_MAX_DEZ_STR, "%+03.6d", INT_MAX );
#ifndef TEST_CONVERSION_ONLY
    PRINTF_TEST( INT_DIG + 2, "- " INT_MAX_DEZ_STR, "- %d", INT_MAX );
    PRINTF_TEST( INT_DIG * 2 + 6, "- " INT_MAX_DEZ_STR " % -" INT_MIN_DEZ_STR, "- %d %% %d", INT_MAX, INT_MIN );
#endif
    PRINTF_TEST( 1, "x", "%c", 'x' );
    PRINTF_TEST( 6, "abcdef", "%s", "abcdef" );
    /* FIXME: This test not yet 32/64 bit agnostic */
    PRINTF_TEST( 10, "0xdeadbeef", "%p", (void *)0xdeadbeef );
    PRINTF_TEST( 6, "   0x1", "%#6x", 1 );
#ifndef TEST_CONVERSION_ONLY
    {
        int val1, val2;
        PRINTF_TEST( 9, "123456789", "123456%n789%n", &val1, &val2 );
        TESTCASE( val1 == 6 );
        TESTCASE( val2 == 9 );
    }
#endif
    }