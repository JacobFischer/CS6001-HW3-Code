/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*-
 *
 * Copyright (c) 2016 Michael Catanzaro <michael.catanzaro@mst.edu>
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 *    this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#include "polynomial.h"

#ifdef NDEBUG
#undef NDEBUG
#endif
#include <cassert>

using namespace multinv;

// Test cases from https://en.wikipedia.org/wiki/Finite_field_arithmetic#Addition_and_subtraction
static void addSubtract1() {
    Polynomial p1(0b00001011);
    Polynomial p2(0b00001100);
    Polynomial p3(0b00000111);

    assert(p1 + p2 == p3);
    assert(p1 - p2 == p3);
}

static void addSubtract2() {
    Polynomial p1(0b00010100);
    Polynomial p2(0b01000100);
    Polynomial p3(0b01010000);

    assert(p1 + p2 == p3);
    assert(p1 - p2 == p3);
}

static void addSubtract3() {
    Polynomial p1(0b00000011);
    Polynomial p2(0b00000101);
    Polynomial p3(0b00000110);

    assert(p1 + p2 == p3);
    assert(p1 - p2 == p3);
}

static void addSubtract4() {
    Polynomial p1(0b00001010);
    Polynomial p2(0b00000101);
    Polynomial p3(0b00001111);

    assert(p1 + p2 == p3);
    assert(p1 - p2 == p3);
}

static void addSubtract5() {
    Polynomial p1(0b00000110);
    Polynomial p2(0b00000110);
    Polynomial p3(0b00000000);

    assert(p1 + p2 == p3);
    assert(p1 - p2 == p3);
}

static void multiply1() {
    // Example in section 4.2 of FIPS 197.
    uint16_t ip = 0b0000000100011011;
    Polynomial p1(0x57, ip, 8);
    Polynomial p2(0x83, ip, 8);

    assert(p1 * p2 == 0xc1);
}

static void multiply2() {
    // Example in section 4.2.1 of FIPS 197.
    uint16_t ip = 0b0000000100011011;
    Polynomial p1(0x57, ip, 8);
    Polynomial p2(0x13, ip, 8);

    assert(p1 * p2 == 0xfe);
}

static void multiply3() {
    // https://en.wikipedia.org/wiki/Finite_field_arithmetic#Rijndael.27s_finite_field
    uint16_t ip = 0b0000000100011011;
    Polynomial p1(0x53, ip, 8);
    Polynomial p2(0xca, ip, 8);

    assert(p1 * p2 == 0x01);
}

static void multiply4() {
    // Stinson example 6.6
    uint16_t ip = 0b0000000000001011;
    Polynomial p1(0b00000101, ip, 3);
    Polynomial p2(0b00000111, ip, 3);

    assert(p1 * p2 == 0b00000110);
}

int main() {
    addSubtract1();
    addSubtract2();
    addSubtract3();
    addSubtract4();
    addSubtract5();
    multiply1();
    multiply2();
    multiply3();
    multiply4();
}
