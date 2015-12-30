#define CAT_(a, b) a##b
#define CAT(a, b) CAT_(a, b)
#define POLY(name) CAT(name##_, TVAR)
