

# def transpose(matrix):
#     transposed_matrix = []  # Initialize an empty list to store the transposed matrix

#     # Iterate over each column index i
#     for i in range(len(matrix[0])):
#         new_row = []  # Initialize an empty list for the i-th row of the transposed matrix
#         # Iterate over each row index j
#         for j in range(len(matrix)):
#             # Append the element at position (j, i) to the new row
#             new_row.append(matrix[j][i])
#         # Append the new row to the transposed matrix
#         transposed_matrix.append(new_row)

#     # Return the transposed matrix
#     return transposed_matrix

# def matrix_multiply(matrix1, matrix2):
#     result_matrix = []  # Initialize an empty list to store the result of matrix multiplication

#     # Iterate over each row in matrix1
#     for row in matrix1:
#         # Initialize an empty list for the resulting row
#         new_row = []
#         # Iterate over each column in the transposed matrix2
#         for col in zip(*matrix2):
#             # Calculate the dot product of row and col
#             dot_product = sum(a * b for a, b in zip(row, col))
#             # Append the dot product to the resulting row
#             new_row.append(dot_product)
#         # Append the resulting row to the result matrix
#         result_matrix.append(new_row)

#     # Return the result matrix
#     return result_matrix

# def matrix_inverse(matrix):
#     determinant = matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0]
#     if determinant == 0:
#         return None  # Singular matrix, no inverse
#     else:
#         return [[matrix[1][1] / determinant, -matrix[0][1] / determinant],
#                 [-matrix[1][0] / determinant, matrix[0][0] / determinant]]

# def pseudo_inverse(matrix):
#     transposed = transpose(matrix)
#     product = matrix_multiply(transposed, matrix)
#     inverse = matrix_inverse(product)
#     if inverse is None:
#         return None
#     else:
#         return matrix_multiply(inverse, transposed)

# # Example matrix
# matrix = [[4, 7]]

# # Calculate pseudo-inverse
# pseudo_inv = pseudo_inverse(matrix)

# # Print pseudo-inverse
# print("Pseudo-inverse of the matrix:")
# # for row in pseudo_inv:
# #    print(row)
    
# import numpy as np

# # Example matrix
# # matrix = np.array([[4, 7], [2, 6]])

# # Calculate pseudo-inverse
# pseudo_inv = np.linalg.pinv(matrix)

# # Print pseudo-inverse
# print("Pseudo-inverse of the matrix:")
# print(pseudo_inv)

import numpy as np

# Example 1x6 matrix
matrix_1x6 = np.array([[1, 2, 3, 4, 5, 6]])
print(matrix_1x6)

# Calculate the pseudo-inverse
pseudo_inv_matrix_1x6 = np.linalg.pinv(matrix_1x6)

# Print the pseudo-inverse matrix
print("Pseudo-inverse of the 1x6 matrix:")
print(pseudo_inv_matrix_1x6)
