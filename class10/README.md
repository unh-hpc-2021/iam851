
# Class 10 (moved -> 11) Solutions

## `print_matrix()`

The `print_matrix()` function prints the matrix as a matrix, and the elements are initialized so that the first digit gives the row, and the second digit gives the column, and that's what the result looks like, as expected (taking into account that C starts counting at zero).

```sh
print_matrix:
 00 01 02 03
 10 11 12 13
 20 21 22 23

```

## `print_matrix_linear()`

We just pass a pointer to the first (0th) element to `print_matrix_linear()`, and it then prints out the numbers stored starting there, just linearly, in the order the elements are stored in memory:

```sh
print_matrix_linear:
 00 01 02 03 10 11 12 13 20 21 22 23
```

What we can tell from this is that C stores a matrix in "row-major" order, ie., it stores the 0th row, followed by row 1, followed by row 2.

## `print_matrix_double_pointer()`

Well, it turns out it's tricky to even call this function without getting a warning, but if one manages, it still doesn't work right -- usually one just gets a segmentation fault. The reason for that is that the `double **` really expects an array of pointers, one for each row, where each of those pointers then points to the beginning of where the corresponding row is stored in memory. I've made this work in the repository by creating such an array of pointers, but in the end, this really isn't a great way of handling multi-dimensional arrays in C -- though there are people who use it. Besides the complicated setup, it's also not very efficient, because to find a given `A[i][j]` element, one has to not follow just one, but two pointers, which isn't great for performance.

## `print_matrix()` in Fortran

This works just fine, as Fortran has good built-in support for multi-dimensional arrays:

```sh
print_matrix
 11. 12. 13. 14.
 21. 22. 23. 24.
 31. 32. 33. 34.
```

The only difference from C is that the counting starts at 1 (which is the Fortran default, but one can actually change the array lower limits to be 0, or anything else, for that matter).

## `print_matrix_linear()` in Fortran

I implemented that in the repo, looks much like the C version. It prints this:

```sh
print_matrix_linear
 11. 21. 31. 12. 22. 32. 13. 23. 33. 14. 24. 34.
```

We notice that, in contrast to when we did this in C, the elements are printed (and hence stored in memory) in a column-by-column ("column-major") layout. There's nothing fundamentally good or bad about this, but it happens to be different from C/C++.

## Printing C matrix from Fortran

I added this is an example of what happens if part of a code is writting in Fortran, while another part is written in C/C++. This is a situation which often happens when gradually adopting legacy Fortran codes to do part of the job in C/C++ (e.g., when porting to GPUs).

```sh
print_matrix:
 00 01 02 03
 10 11 12 13
 20 21 22 23

[...]

print_matrix (fortran):
  0.  3. 12. 21.
  1. 10. 13. 22.
  2. 11. 20. 23.
```

Notice how the matrix, when printed from C vs Fortran, does have the same elements, but when printed from Fortran, the order is rather messed up -- that's because Fortran expects the underlying data to be stored in column-major order, but it's actually row-major.

Possible ways to deal with this is to 
* transpose the matrix (ie., change the layout from row-major to column-major or vice versa) -- That's expensive, though
* transpose the dims of the matrix (ie., make the 3x4 matrix in C into a 4x3 matrix in Fortran, and access it as `A(j, i)`)
* Use column-major order in C, too. That's not what usually happens in C, but due to its poor multi-d arrays support, one often implements one's own class anyway, like the `struct matrix`, and in that case one has a choice of how to store the data.