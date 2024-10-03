#!/bin/bash
git submodule update --init --recursive

cd submodules/Criterion
meson setup build
meson compile -C build