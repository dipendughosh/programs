# def calculate_basis_functions(x, degree):
#     basis_functions = []
#     for xi in x:
#         basis_function = []
#         for i in range(degree + 1):
#             basis_function.append(xi ** i)
#         basis_functions.append(basis_function)
#     return basis_functions

# # Example data
# x = [0, 1, 2, 3, 4, 5]
# degree = 3

# # Calculate basis functions
# basis_functions = calculate_basis_functions(x, degree)

# # Print basis functions
# for i, basis_function in enumerate(basis_functions):
#     print(f"Basis functions for x = {x[i]}:", basis_function)
    
# def calculate_design_matrix(x, y, degree):

#     # Function to calculate the power of a number
#     def power(num, n):
#         result = 1
#         for _ in range(n):
#             result *= num
#         return result
    
#     design_matrix = []
#     for xi, yi in zip(x, y):
#         row = []
#         for i in range(degree + 1):
#             row.append(power(xi, i) * yi)
#         design_matrix.append(row)
#     return design_matrix

# # Example data
# x = [0, 1, 2]
# y = [0, 1, 2]
# degree = 2

# # Calculate design matrix
# design_matrix = calculate_design_matrix(x, y, degree)

# # Print design matrix
# for row in design_matrix:
#     print(row)

# design matrix

# def calculate_design_matrix(x, y, degree):

#     # Function to calculate the power of a number
#     def power(num, n):
#         result = 1
#         for _ in range(n):
#             result *= num
#         return result
    
#     design_matrix = []
#     for xi in x:
#         print("xi ", xi)
#         row = []
#         for i in range(degree + 1):
#             row.append(power(xi, i))
#         design_matrix.append(row)
#     return design_matrix

# # Example data
# x = [0, 1, 2]
# y = [0, 0.1, 0.2]
# degree = 2

# # Calculate design matrix
# design_matrix = calculate_design_matrix(x, y, degree)

# # Print design matrix
# for row in design_matrix:
#     print(row)

# basis function

# def calculate_basis_functions(x, degree):

#     # Function to calculate the power of a number
#     def power(num, n):
#         result = 1
#         for _ in range(n):
#             result *= num
#         return result
    
#     basis_functions = []
#     for xi in x:
#         basis_function = []
#         for i in range(degree + 1):
#             basis_function.append(power(xi, i))
#         basis_functions.append(basis_function)
#     return basis_functions

# basis function

# # Example data
# x = [0, 1, 2, 3, 4, 5]
# degree = 3

# # Calculate basis functions
# basis_functions = calculate_basis_functions(x, degree)
# design_matrix = []

# # Print basis functions
# for i, basis_function in enumerate(basis_functions):
#     row = []
#     design_matrix.append(row.append(basis_function))
#     print(f"Basis functions for x = {x[i]}:", basis_function)
# print("Design Matrix ", design_matrix)


