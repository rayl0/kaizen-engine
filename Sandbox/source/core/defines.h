#pragma once

#define NULL_COPY_AND_ASSIGN(x) \
    x(const x&);                \
    x&                          \
    operator=(const x&);
