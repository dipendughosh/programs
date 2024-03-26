import numpy as np


def calculate_basis_functions(x, degree):
    basis_functions = []
    for xi in x:
        basis_function = []
        for i in range(degree + 1):
            basis_function.append(xi**i)
        basis_functions.append(basis_function)
    return basis_functions


def construct_design_matrix(basis_functions):
    design_matrix = []
    for row in basis_functions:
        design_matrix.append(row)
    np_dm = np.array(design_matrix)
    return np_dm


# Example data
x = [1, 2]
degree = 3

# Calculate basis functions
basis_functions = calculate_basis_functions(x, degree)
# Print design matrix
print("Basis function:")
for row in basis_functions:
    print(row)

# Construct design matrix
design_matrix = construct_design_matrix(basis_functions)

# Print design matrix
print("Design matrix:")
for row in design_matrix:
    print(row)

pseudo_inv = np.linalg.pinv(design_matrix)

# Print pseudo-inverse
print("Pseudo-inverse of the matrix:")
print(pseudo_inv)
