// Defines: align_uintptr_t
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

