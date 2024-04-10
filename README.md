# Vector library
[![CI](https://github.com/osvegn/vector/actions/workflows/CI.yml/badge.svg)](https://github.com/osvegn/vector/actions/workflows/CI.yml)
[![codecov](https://codecov.io/gh/osvegn/vector/graph/badge.svg?token=ypMDuagiAq)](https://codecov.io/gh/osvegn/vector)

This is an implementation of a vector library for C language.

# Documentation
You can follow the technique documentation just [here](https://osvegn.github.io/vector/Vector/).

# Methods
- [x] constructor
- [x] destructor
- [x] operator=
- [ ] assign
- [ ] assign_range
- [ ] get_allocator
- ## Element access
- [x] at
- [ ] operator[]
- [x] front
- [x] back
- [ ] data
- ## Iterator
- [ ] begin
- [ ] end
- [ ] rbegin
- [ ] rend
- ## Capacity
- [x] empty
- [x] size
- [ ] max_size
- [ ] reserve
- [x] capacity
- [x] shrink_to_fit
- ## Modifier
- [x] clear
- [ ] insert
- [ ] insert_range
- [x] emplace
- [x] erase
- [ ] push_back
- [x] emplace_back
- [ ] append_range
- [x] pop_back
- [ ] resize
- [x] swap
- ## Operator
- [ ] eq
- [ ] neq
- [ ] lt
- [ ] le
- [ ] gt
- [ ] ge
- ## Printable
- [x] print_at
- [x] print