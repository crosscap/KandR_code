#define swap(t, x, y) \
    {\
        void __temp;\
        (t)__temp = (t)x;\
        (t)x = (t)y;\
        (t)y = (t)__temp;\
    }
