#!/bin/bash
url="https://github.com/Snaipe/Criterion/releases/download/v2.4.2/criterion-2.4.2-linux-x86_64.tar.xz"
name="criterion.tar.xz"

curl -L $url -o $name
tar -xf $name
rm $name