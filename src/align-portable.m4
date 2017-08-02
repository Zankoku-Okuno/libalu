// Defines: align_upto_uintptr_t
INLINE
uintptr_t align_upto_uintptr_t(uintptr_t a, size_t pre_alignment, bool* sticky_bit) {
    // TODO I can't find guidance on whether this is a good check
    if (pre_alignment > (size_t)UINTPTR_MAX) {
        *sticky_bit |= 1;
        return a;
    }
    uintptr_t alignment = (uintptr_t)pre_alignment;
    uintptr_t_divmod tmp = divmod_check_uintptr_t(a, alignment, sticky_bit);
    if (tmp.mod == 0) {
        return a;
    }
    else {
        uintptr_t adjust = sub_check_uintptr_t(alignment, tmp.mod, sticky_bit);
        return add_check_uintptr_t(a, adjust, sticky_bit);
    }
}

// Defines: align_backto_uintptr_t
INLINE
uintptr_t align_backto_uintptr_t(uintptr_t a, size_t pre_alignment, bool* sticky_bit) {
    // TODO I can't find guidance on whether this is a good check
    if (pre_alignment > (size_t)UINTPTR_MAX) {
        *sticky_bit |= 1;
        return a;
    }
    uintptr_t alignment = (uintptr_t)pre_alignment;
    uintptr_t_divmod tmp = divmod_check_uintptr_t(a, alignment, sticky_bit);
    return sub_check_uintptr_t(a, tmp.mod, sticky_bit);
}

// Defines: align_upto_voidptr
INLINE
void* align_upto_voidptr(void* a, size_t pre_alignment, bool* sticky_bit) {
    return (void*)align_upto_uintptr_t((uintptr_t)a, pre_alignment, sticky_bit);
}

// Defines: align_backto_voidptr
INLINE
void* align_backto_voidptr(void* a, size_t pre_alignment, bool* sticky_bit) {
    return (void*)align_backto_uintptr_t((uintptr_t)a, pre_alignment, sticky_bit);
}
